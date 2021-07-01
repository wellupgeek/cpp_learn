// #include <initializer_list>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

template <typename F, typename T>
auto apply(F&& f, T value) -> int
{
    return f(value);
}

class foo
{
    int x_;
public:
    foo(int const x = 0) : x_{x} {}
    int& get() {return x_;}
};

auto proxy_get(foo& f) -> int& {return f.get();}

int main()
{
    // auto i = 1;
    // auto j = 2.5;
    // auto f = {1, 2, 3};

    // for (auto a : f)
    //     std::cout << a << '\n';

    // auto b = new char[10]{0};
    // auto s1 = std::string{"text"};
    // auto v1 = std::vector<int> {1,2,3};
    // auto p  = std::make_shared<int>(42);
    // std::cout << *p << '\n';

    // auto upper = [](char const c) {return toupper(c);};
    // auto add = [](int const a, int const b) {return a+b;};

    auto f = foo{42};
    auto& x = proxy_get(f);
    x = 12;
    std::cout << proxy_get(f) << std::endl;
}