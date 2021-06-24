#include "myString.h"

int main()
{
    String s1();
    const char* a = "hello";
    String s2("world");

    String s3(s2);
    std::cout << s3 << '\n';
    s3 = s2;

    s3 = "yukko";

    std::cout << s3 << '\n';

    s3 = s3 += " hhhh";
    std::cout << s3 << '\n';
}