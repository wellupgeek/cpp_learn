#include <string>
#include <iostream>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    HasPtr(const HasPtr& hp):ps(hp.ps), i(hp.i), use(hp.use) { ++*use; }
    HasPtr& operator= (const HasPtr&);
    HasPtr& operator= (HasPtr);
    friend void swap(HasPtr&, HasPtr&);
    std::size_t getUseNum() const { return *use; }
    ~HasPtr();
private:
    std::string *ps;
    int i;
    std::size_t *use;
};

void swap(HasPtr& lhs, HasPtr& rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

HasPtr::~HasPtr() {
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator= (HasPtr rhs) {
    swap(*this, rhs);
    return *this;
}

HasPtr& HasPtr::operator= (const HasPtr& rhs) {
    ++*rhs.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

int main()
{
    HasPtr p("hello");
    HasPtr q(p);
    HasPtr m(q);
    std::cout << q.getUseNum() << std::endl;
    m.~HasPtr();
    std::cout << q.getUseNum() << std::endl;
}