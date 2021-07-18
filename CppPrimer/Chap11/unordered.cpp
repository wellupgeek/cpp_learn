#include <unordered_set>
#include <string>

using namespace std;

class Book{
public:
    Book(string _id = " "):id(_id){}
    string isbn() const {return id;}
private:
    string id;
};

size_t hasher(const Book &b) {
    return hash<string>()(b.isbn());
}

bool equalOp(const Book &a, const Book &b) {
    return a.isbn() == b.isbn();
}

int main()
{
    using Book_multiset = unordered_multiset<Book, decltype(hasher)*, decltype(equalOp)*>;
    Book_multiset book(42, hasher, equalOp);    // 参数是桶大小、哈希函数指针和相等性判断运算符指针
}