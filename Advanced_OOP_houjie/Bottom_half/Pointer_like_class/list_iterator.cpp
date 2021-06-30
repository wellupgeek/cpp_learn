
template <typename T>
struct __list_node{
    void* prev;
    void* next;
    T data;
};

template <class T, class Ref, class Ptr>
struct __list_iterator{
    typedef __list_iterator<T, Ref, Ptr> self;  // like class *this
    typedef __list_node<T>* nodeType;
    typedef Ref reference;
    typedef Ptr pointer;
    nodeType node; // node = pointer to __list_node
    reference operator * () const { return (*node).data; }  // iterator should like a general pointer
    pointer operator -> () const { return &(operator*()); }
    bool operator == (const self& x) const { return node == x.node; }
    bool operator != (const self& x) const { return node != x.node; };
    self& operator ++ () { node = (nodeType)((*node).next); return *this; } // ++i = i.operator++()
    self operator ++ (int) { self temp = *this; ++*this; return temp; }     // i++ = i.operator++(0), return i then operator++()
    self& operator -- () { node = (nodeType)((*node).next); return *this; }
    self operator -- (int) { self temp = *this; --*this; return temp; }
};