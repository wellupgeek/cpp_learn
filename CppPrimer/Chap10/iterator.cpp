#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Book{
public:
    Book(const string& s = "null", double p = 0.0, unsigned n = 0):id(s), price(p), number(n), sale(p*n){}
    const string& isbn() const { return id; }
    friend istream& operator >> (istream& is, Book& b) {
        is >> b.id >> b.price >> b.number;
        b.sale = b.price * b.number;
        return is;
    }
    friend ostream& operator << (ostream& os, const Book& b) {
        os << b.id << " " << b.price << " " << b.sale << endl;
        return os;
    }
    Book& operator += (const Book& b) {
        this->sale += b.sale;
        return *this;
    }

private:
    string id;
    double price;
    unsigned number;
    double sale = 0.0;
};

int main()
{
    vector<int> a;
    // istream_iterator<int> int_it(cin);
    // istream_iterator<int> int_eof;
    ifstream in("afile");
    istream_iterator<string> str_it(in);

    // while (int_it != int_eof) {
    //     a.push_back(*int_it++);
    // }

    // for (auto i : a)
    //     cout << i << endl;

    // vector<int> vec(int_it, int_eof);
    // cout << accumulate(int_it, int_eof, 0) << endl;
    vector<int> vec{1,2,3,4,5};
    ostream_iterator<int> out_iter(cout, " ");
    for (auto i : vec)
        *out_iter++ = i;
    cout << endl;
    copy(vec.cbegin(), vec.cend(), out_iter);
    cout << endl;

    istream_iterator<Book> book_item(cin), eof;
    ostream_iterator<Book> out_item(cout);

    Book sum = *book_item++;
    while(book_item != eof) {
        if (book_item->isbn() == sum.isbn()) {
            sum += *book_item++;
        } else {
            out_item = sum;
            sum = *book_item++;
        }
    }
    out_item = sum;
}