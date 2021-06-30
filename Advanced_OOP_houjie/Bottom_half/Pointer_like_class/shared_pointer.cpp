
template <typename T>
class shared_ptr{
public:
    shared_ptr(T* p):pt(t){}
    T& operator * () const{
        return *pt;
    }
    T* operator -> () const{
        return pt;
    }
private:
    T* pt;
};

struct Foo
{
    void Method(void);
};

int main()
{
    shared_ptr<Foo> sp(new Foo);
    Foo f(*sp);
    sp->Method();   // pt->Method(), 解释是->会一直传递下去而不会消失，`->`操作符是一个特例
}