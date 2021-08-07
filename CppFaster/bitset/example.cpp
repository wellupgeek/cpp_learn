#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // bitset<8> fb("1001011");
    // fb[1] = 0;
    // fb.flip();
    // cout << fb << endl;

    vector<bool> boolFlags(10, true);
    for (auto i : boolFlags)
        cout << i << endl;
    boolFlags.flip();
    for (auto i : boolFlags)
        cout << i << endl;
}