
class A{
public:
    static A& getInstance();
    void setup();
private:
    A(){};
    A(const A&);
    A& operator=(const A&);
};

A& A::getInstance() {
    static A a;
    return a;
}

// call setup()
// A::getInstance.setup()