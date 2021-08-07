#include <iostream>
#include <string>
using namespace std;

class President {
private:
    President() {}
    President(const President&);
    President& operator= (const President&);
    string name;
public:
    static President& getInstance() {
        static President pre;
        return pre;
    }
    const string& getName() const { return name; }
    void setName(string newname) { name = newname; }
};

int main()
{
    President& onlyone = President::getInstance();
    onlyone.setName("alibaba");
    cout << onlyone.getName();
}