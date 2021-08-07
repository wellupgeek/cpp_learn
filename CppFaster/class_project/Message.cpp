#include <string>
#include <unordered_set>

class Message;
class Folder {
public:
    Folder(){}
    void addMsg(const Message& mess);
    void remMsg(const Message& mess);
    ~Folder(){}
private:
    Folder(const Folder&){}
    Folder& operator= (const Folder&){}
    std::unordered_set<const Message*> messages;
};

void Folder::addMsg(const Message& mess) {
    messages.insert(&mess);
}

void Folder::remMsg(const Message& mess) {
    messages.erase(&mess);
}

class Message {
    friend class Folder;
public:
    explicit Message(const std::string &mess = std::string()):pContent(new std::string(mess)){}
    Message(const Message&);
    Message& operator= (const Message&);
    friend inline void swap(Message&, Message&);
    // Message& operator= (Message);
    void save(Folder&);
    void remove(Folder&);
    ~Message();
private:
    std::unordered_set<Folder*> folders;
    std::string* pContent;
    // 拷贝构造、拷贝赋值运算符和析构函数使用的工具函数
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};

Message::Message(const Message& mess):pContent(new std::string(*mess.pContent)), folders(mess.folders) {
    // 此时的Message与mess应该在同一Folder下,且对应的Foler中应该加入本Message
    add_to_Folders(mess);
}

Message& Message::operator= (const Message& mess) {
    remove_from_Folders();
    delete pContent;
    pContent = new std::string(*mess.pContent);
    add_to_Folders(mess);
    folders = mess.folders;
    return *this;
}

void Message::save(Folder& fold) {
    folders.insert(&fold);
    fold.addMsg(*this);
}

void Message::remove(Folder& fold) {
    folders.erase(&fold);
    fold.remMsg(*this);
}

void Message::add_to_Folders(const Message& mess) {
    for (auto *fold : mess.folders)
        fold->addMsg(*this);
}

void Message::remove_from_Folders() {
    for (auto *fold : folders)
        fold->remMsg(*this);
}

Message::~Message() {
    // 我要把本message删除，需要把folder包含本message的全部删除
    remove_from_Folders();
    delete pContent;
}

void swap(Message& lhs, Message& rhs) {
    using std::swap;
    // 这里的交换还包括这个Folders
    for (auto *fold : lhs.folders) {
        fold->remMsg(lhs);
        fold->addMsg(rhs);
    }
    for (auto *fold : rhs.folders) {
        fold->remMsg(rhs);
        fold->addMsg(lhs);
    }
    // 现在交换pContent
    swap(lhs.pContent, rhs.pContent);

    // 交换folders
    swap(lhs.folders, rhs.folders);
}