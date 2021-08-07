#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class smart_ptr {
    T* new_ptr;
public:
    smart_ptr(T* ptr):new_ptr(ptr){}
    ~smart_ptr(){ delete new_ptr; cout << "delete done!";}

    smart_ptr(const smart_ptr& sp) {
        new_ptr = nullptr;
        if (sp.new_ptr != nullptr)
            new_ptr = sp.new_ptr;
    }
    smart_ptr& operator= (const smart_ptr& sp) {
        delete new_ptr;
        if (sp.new_ptr != nullptr)
            new_ptr = sp.new_ptr;
    }
    T& operator* () const {
        return *new_ptr;
    }
    T* operator-> () const {
        return new_ptr;
    }
};

class Test{
    int a;
public:
    Test(int x):a(x){}
    void print() const { cout << "this is Test" << endl; }
};

int main()
{
    unique_ptr<char> alpha(new char);
    *alpha = 's';
    auto lambda = [capture=move(alpha)]{
        cout << *capture << endl;
    };
    lambda();
}