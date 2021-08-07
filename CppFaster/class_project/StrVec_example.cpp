#include <string>
#include <memory>
#include <vector>
#include <utility>
#include <iostream>

class StrVec {
public:
    typedef std::string valueType;
    typedef std::string* iterator;
    StrVec():elements(nullptr), first_free(nullptr), cap(nullptr){}
    StrVec(const StrVec&);
    StrVec(StrVec&&) noexcept;
    StrVec& operator= (const StrVec&);
    StrVec& operator= (StrVec&&) noexcept;
    ~StrVec() { free(); }
    void push_back(const valueType&);
    void push_back(valueType&&) noexcept;
    size_t size() const { return end() - begin(); }
    size_t capacity() const { return last() - begin(); }
    iterator begin() const { return elements; }
    iterator end() const { return first_free; }
private:
    static std::allocator<valueType> alloc; // 个人理解 alloc就是一个中间层 我们只需要将对应的指针修改为alloc中的指针即可，内存分配和释放交给alloc
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }  // 判断内存是否满了
    std::pair<iterator, iterator> alloc_n_copy(const iterator, const iterator);
    void free();
    void reallocate();
    iterator last() const { return cap; }
    iterator elements;
    iterator first_free;
    iterator cap;
};

std::allocator<StrVec::valueType> StrVec::alloc;

void StrVec::push_back(const valueType& val) {
    chk_n_alloc();
    alloc.construct(first_free++, val);
}

void StrVec::push_back(valueType&& val) noexcept {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(val));
}

std::pair<StrVec::iterator, StrVec::iterator> StrVec::alloc_n_copy(
                        const StrVec::iterator b, const StrVec::iterator e) 
{
    auto data = alloc.allocate(e - b);  // start iterator
    return {data, std::uninitialized_copy(b, e, data)}; // {start iterator, end iterator}
}

void StrVec::free() {
    if (begin()) {
        for (auto p = end(); p != begin();)
            alloc.destroy(--p);
        alloc.deallocate(begin(), last()-begin());
    }
}

StrVec::StrVec(const StrVec& other) {
    auto newdata = alloc_n_copy(other.begin(), other.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec&& other) noexcept : elements(other.elements), first_free(other.first_free), cap(other.cap){
    other.elements = other.first_free = other.cap = nullptr;
}

StrVec& StrVec::operator= (const StrVec& other) {   // alloc负责管理所有的内存对象,这里释放了本对象不会影响其他对象的内存，alloc静态对象的作用体现在此。
    if (&other != this) {
        free(); // 释放不影响其他对象的内存，因为alloc是静态的
        auto newdata = alloc_n_copy(other.begin(), other.end());
        elements = newdata.first;
        first_free = cap = newdata.second;
    }
    return *this;
}

StrVec& StrVec::operator= (StrVec&& other) noexcept {
    if (&other != this) {
        free();
        elements = other.elements;  // 接管ohter的资源，可以认为就是直接拷贝了其指针.
        first_free = other.first_free;
        cap = other.cap;
        other.elements = other.first_free = other.cap = nullptr;
    }
    return *this;
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto newelem = alloc.allocate(newcapacity);
    auto dest = newelem;
    auto old = elements;
    for (int i=0; i<size(); i++)
        alloc.construct(dest++, std::move(*old++));
    free();
    elements = newelem;
    first_free = dest;
    cap = newelem + newcapacity;
}

int main()
{
    // std::vector<int> vec{1,2,3,4};
    // std::allocator<int> alloc;
    // auto p = alloc.allocate(vec.size() * 2);
    // auto q = std::uninitialized_copy(vec.begin(), vec.end(), p);
    // std::uninitialized_fill_n(q, vec.size(), 42);

    StrVec sv;
    sv.push_back("hello");
    sv.push_back("please");
    for (auto p = sv.begin(); p != sv.end(); ++p) {
        std::cout << *p << std::endl;
    }
}