#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>

using namespace std;

void output_file(const string& inf, const string& outf1, const string& outf2) {
    ifstream in(inf);
    istream_iterator<int> ii(in), eof;
    ofstream out1(outf1), out2(outf2);
    ostream_iterator<int> oo1(out1, " "), oo2(out2, "\n");

    while (ii != eof) {
        if ((*ii) % 2 != 0) {
            oo1 = *ii++;
        } else {
            oo2 = *ii++;
        }
    }
}

int main()
{
    // istream_iterator<int> ii(cin), eof;
    // ostream_iterator<int> oo(cout, " ");
    // vector<int> a(ii, eof);
    // sort(a.begin(), a.end());
    // unique_copy(a.cbegin(), a.cend(), oo);
    // copy(a.cbegin(), a.cend(), oo);
    
    string inf = "in.txt";
    string outf1 = "out1.txt", outf2 = "out2.txt";
    output_file(inf, outf1, outf2);
}