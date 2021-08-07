#include <iostream>
using namespace std;

class Vehicle {
protected:
    Vehicle(float s, int t):speed(s), total(t){}
public:
    virtual void showMember() = 0;
protected:
    float speed;
    int total;
};

class Car : public Vehicle{
public:
    Car(int a, float s, int t):aird(a), Vehicle(s,t){}
    void showMember() {
        cout << "aird : " << aird;
        cout << "speed : " << speed;
        cout << "total : " << total; 
    }
private:
    int aird;
};

int main()
{
    Car car(1, 60.66, 4);
    car.showMember();
}