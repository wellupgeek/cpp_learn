#include <map>
#include <string>

using namespace std;

template <typename T>
struct RevertSort {
    bool operator() (const T& a, const T& b) const {
        return a < b;
    }
};

int main()
{
    map<int, string> ismap;
    ismap.insert(make_pair(100, "well"));
    ismap.insert(pair<int, string>(100, "jjj"));
    ismap.insert(map<int, string>::value_type(3, "hh"));
    ismap[100] = "ppp";
    ismap[100] = "soha";
    map<int, string, RevertSort<int>()> isrmap(ismap.begin(), ismap.end());
    isrmap[1] = "aoteman";
    isrmap[1] = "jijijij";
}