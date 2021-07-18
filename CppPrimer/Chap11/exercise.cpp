#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;


map<string, string> buildMap(ifstream &f){
    map<string, string> tran_map;
    string word;
    string value;
    while (f >> word && getline(f, value)) {
        if (value.size() > 1) {
            tran_map[word] = value.substr(1);
            // tran_map.insert({word, value.substr(1)});
        } else {
            throw runtime_error("no rule for " + word);
            // tran_map[word] = word;
        }
    }
    return tran_map;
}

const string& transform(const string &word, map<string, string> &mss){
    auto iter = mss.find(word);
    if (iter != mss.cend())
        return iter->second;
    else
        return word;
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);
    string text;
    while(getline(input, text)) {
        istringstream stream(text);
        string word;
        bool first = true;
        while(stream >> word) {
            if (first)
                first = false;
            else {
                cout << " ";
            }
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}

int main()
{
    ifstream map_file("rule.txt");
    ifstream input("transform.txt");
    word_transform(map_file, input);
}