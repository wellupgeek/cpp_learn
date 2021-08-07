#include <string>
#include <vector>
#include <memory>
#include <cassert>
#include <iostream>

class StrVec {  // vector<string>
public:
    typedef std::string valueType;
    typedef std::string* iterator;
    StrVec(const valueType& str="", size_t n=1);
    StrVec(const StrVec&);
    StrVec(StrVec&&);
    void push_back(const valueType&);
    void erase(const valueType&);
    void erase(iterator);
    valueType& operator[] (size_t);
    StrVec& operator= (const StrVec&);
    StrVec& operator= (StrVec&&);
    iterator begin() const { return elements; }
    iterator end() const { return first_free; }
    size_t size() const { return end() - begin(); }
    size_t capacity() const { return last() - begin(); }
    ~StrVec() { free(); }
private:
    iterator elements;
    iterator first_free;
    iterator cap;
    iterator last() const { return cap; }
    void alloc_n_copy(size_t, const valueType&);
    void free();
    bool chk_n_alloc();
    bool reallocate();
};

StrVec::StrVec(const valueType& str, size_t n):elements(nullptr),first_free(nullptr),cap(nullptr){
    alloc_n_copy(n, str);
}

StrVec::StrVec(const StrVec& other) {
    if (&other != this && other.size() > 0) {
        free();
        std::ptrdiff_t distance = other.end() - other.begin();
        assert(distance > 0);
        elements = new valueType[other.last() - other.begin()];
        iterator pelem = elements;
        cap = pelem + (other.last() - other.begin());
        for (iterator p = other.begin(); p != other.end();)
            *pelem++ = *p++;
        first_free = pelem;
    }
}

StrVec::StrVec(StrVec&& other) {
    if (&other != this && other.size() > 0) {
        free();
        elements = other.elements;
        first_free = other.first_free;
        cap = other.cap;
        other.elements = 0;
        other.first_free = 0;
        other.cap = 0;
    }
}

void StrVec::push_back(const valueType& val) {
    assert(chk_n_alloc());
    *first_free++ = val;
}

void StrVec::erase(const valueType& val) {
    for (auto p = begin(); p != end() && first_free - elements >0 ;) {
        if (*p == val) {
            for (auto temp = p+1; temp != end(); temp++)
                swap(*(temp), *(temp-1));
            first_free -= 1;
            assert(first_free - elements >= 0);
        } else
            p++;
    }
    assert(first_free - elements >= 0);
}

void StrVec::erase(iterator iter) {
    std::ptrdiff_t distance = iter - begin();
    std::ptrdiff_t distance2 = end() - iter;
    assert(distance >= 0 && distance2 > 0);
    for (auto p = iter+1; p != end(); ++p)
        swap(*p, *(p-1));
    first_free -= 1;
    assert(first_free - elements >= 0);
}

void StrVec::alloc_n_copy(size_t n, const valueType& val) {
    if (elements != nullptr)
        delete[] elements;
    elements = new valueType[n+1];
    first_free = elements + n;
    cap = elements + (n + 1);
    for (auto p = begin(); p != end(); p++)
        *p = val;
}

void StrVec::free() {
    if (elements != nullptr) {
        delete[] elements;
        elements = nullptr;
        first_free = nullptr;
        cap = nullptr;
    }
}

bool StrVec::chk_n_alloc() {
    if (end() < last())
        return true;
    else
        return reallocate();
}

bool StrVec::reallocate() {
    std::ptrdiff_t len = capacity();
    iterator new_element = new valueType[2*len];
    if (!new_element)   return false;
    iterator new_first_free = new_element + (end() - begin());
    iterator new_cap = new_element + 2*len;
    iterator pelem = new_element;
    for (auto p = begin(); p != end();)
        *pelem++ = *p++;
    delete[] elements;
    elements = new_element;
    first_free = new_first_free;
    cap = new_cap;
    return true;
}

StrVec::valueType& StrVec::operator[] (size_t i) {
    assert(i >=0 && i < size());
    return *(begin() + i);
}

StrVec& StrVec::operator= (const StrVec& other) {
    if (&other != this && other.size() > 0) {
        free();
        std::ptrdiff_t distance = other.end() - other.begin();
        assert(distance > 0);
        elements = new valueType[other.last() - other.begin()];
        iterator pelem = elements;
        cap = pelem + (other.last() - other.begin());
        for (auto p = other.begin(); p != other.end();)
            *pelem++ = *p++;
        first_free = pelem;
    }
    return *this;
}

StrVec& StrVec::operator= (StrVec&& other) {
    if (&other != this && other.size() > 0) {
        free();
        elements = other.elements;
        first_free = other.first_free;
        cap = other.cap;
        other.elements = 0;
        other.first_free = 0;
        other.cap = 0;
    }
    return *this;
}

// int main()
// {
//     StrVec vec("hehe");
//     vec.push_back("hehe");
//     vec = vec;
//     // for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
//     //     std::cout << *iter << std::endl;
//     // }
//     // vec.push_back("hehe");
//     // for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
//     //     std::cout << *iter << std::endl;
//     // }
//     // vec.push_back("kiki");
//     // std::cout << vec.capacity() << std::endl;
//     // auto iter = vec.begin();
//     // std::cout << "--------\n";
//     vec.erase("hehe");
//     // std::cout << vec.end() - vec.begin() << std::endl;
//     for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
//         std::cout << *iter << std::endl;
//     }
// }