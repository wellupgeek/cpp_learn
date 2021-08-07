#include <memory>
#include <iostream>
using namespace std;

int main()
{
    unique_ptr<int> up1(new int(11));
    cout << *up1 << endl;
    unique_ptr<int> up2 = move(up1);
    cout << *up2 << endl;
    up2.reset();

    shared_ptr<int> up3(new int(22));
    shared_ptr<int> up4 = up3;

    cout << *up3 << endl;
    cout << *up4 << endl;

    up3.reset();
    up4.reset();
    cout << *up4 << endl;
}