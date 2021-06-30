template <typename T>
class Parent{
public:
    Parent(T a):p(a){}
private:
    T p;
};

// 如果子类不是模板类，需要指明父类的具体类型
class Children : public Parent<int> {
public:
    Children(int a, int b) : Parent(a), cone(b) {}
private:
    int cone;
};

// 如果子类是模板类，可以用子类型的泛型来表示父类
template <typename T>
class Children2 : public Parent<T> {
public:
    Children2(T a, T b) : Parent<T>(a), cone(b) {} 
private:
    T cone;
};
