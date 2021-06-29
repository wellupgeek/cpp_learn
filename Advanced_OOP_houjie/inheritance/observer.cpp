#include <vector>

class Observer;
class Subject{
private:
    int m_value;
    std::vector<Observer*> m_views;
public:
    void attach(Observer* ob) {
        m_views.push_back(ob);
    }
    void set_value(int value) {
        m_value = value;
        notify();
    }
    void notify() {
        for (int i=0; i<m_views.size(); i++) {
            m_views[i]->update(this, m_value);
        }
    }
};

class Observer{
public:
    virtual void update(Subject*, int) = 0;
};