#include <iostream>

using namespace std;

class FlyBehavior   // flying interface
{
  public:
    virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior
{
    void fly() {cout << "flying with wings\n";}
};

class FlyNoWay : public FlyBehavior
{
    void fly() {cout << "cannot fly\n";}
};

class Duck 
{
    FlyBehavior *flyBehavior;
  public:
    Duck(FlyBehavior *flyBehaviorIn) {flyBehavior = flyBehaviorIn;}
    void swim() {cout << "swiming\n";}
    void display() {cout << "displayDuck\n";}
    void performFly() {flyBehavior->fly();}
    void setFlyBehavior(FlyBehavior *flyBehaviorIn) {flyBehavior = flyBehaviorIn;}
};

class MallardDuck: public Duck
{
    FlyWithWings flyWithWings;
  public:
    MallardDuck(): Duck(&flyWithWings){}
};

class RubberDuck: public Duck
{
    FlyNoWay flyNoWay;
  public:
    RubberDuck(): Duck(&flyNoWay){}
};


int main ()
{
    cout << "haha" << endl;
    Duck *d1 = new MallardDuck ;
    d1->performFly();

    Duck *d2 = new RubberDuck;
    d2->performFly();
    d2->setFlyBehavior(new FlyWithWings);
    d2->performFly();

    
    return 1;
}
