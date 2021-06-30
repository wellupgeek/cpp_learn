#include <vector>

class Component{
    int value;
public:
    Component(int v) : value(v){}
    virtual void add(Component*) {}
    virtual ~Component();
};

class Primitive : public Component{
public:
    Primitive(int v) : Component(v) {}
};

class Composite : public Component{
    std::vector<Component*> vcomp;
public:
    Composite(int v) : Component(v) {}
    void add(Component* comp) {
        vcomp.push_back(comp);
    }
};