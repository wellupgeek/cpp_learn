#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
// book 书名、编号、作者
// reader 姓名、借书证、借书数量

class book;
class reader;
class Library {
public:
    const unordered_multimap<book*, reader*>& getBookReaderMap() const { return book_read_map; }
    void setBookReader(book* b, reader* r) {
        book_read_map.insert(make_pair(b, r));
        book_record[&*b] -= 1;
        reader_record[&*r] += 1;
    }
private:
    unordered_multimap<book*, reader*> book_read_map;
    unordered_map<reader*, int> reader_record;
    unordered_map<book*, int> book_record;
};

class book : virtual public Library{
public:
    const string& getBookId() const { return id; }
private:
    string name;
    string id;
    string author;
};

class reader : virtual public Library{
public:
    void rentbook(book&);
private:
    string name;
    string rentid;
};

void reader::rentbook(book& b) {
    book* bp = &b;
    setBookReader(bp, this);
}