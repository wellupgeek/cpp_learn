#include <iostream>
using namespace std;

class vehicle {
public:
    vehicle(double we, int wh=4):weight(we), wheels(wh){}
    void print() { cout << "wheels : " << wheels << " weight: " << weight << endl; }
protected:
    int wheels;
    double weight;
};

class car : private vehicle {
public:
    car(int pl=4, double w=800):passenger_load(pl), vehicle(w){}
    void print() { cout << "passenger_load : " << passenger_load << endl; }
private:
    int passenger_load;
};

class truck : private vehicle {
public:
    truck(int pl, double pload, double w=800):passenger_load(pl), payload(pload), vehicle(w){}
    void print() { cout << "passenger_laod : " << passenger_load << " payload: " << payload << endl; }
private:
    int passenger_load;
    double payload;
};

int main()
{
    car c;
    truck t(6, 1000);
    c.print();
    t.print();
}