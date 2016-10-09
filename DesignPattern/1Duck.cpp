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
    // hide setFlyBehavior in child class
    void setFlyBehavior() {cout << "MallardDuck cannot set fly behavior.\n";}
  public:
    MallardDuck(): Duck(&flyWithWings){}
};

class RubberDuck: public Duck
{
    FlyNoWay flyNoWay;
    // hide setFlyBehavior in child class
    void setFlyBehavior() {cout << "RubberDuck cannot set fly behavior.\n";}
  public:
    RubberDuck(): Duck(&flyNoWay){}
};


int main ()
{
    cout << "duck1\n";
    Duck *d1 = new MallardDuck ;
    d1->performFly();

    cout << "duck2\n";
    Duck *d2 = new RubberDuck;
    d2->performFly();
    // Duck pointer CAN change fly behavior
    d2->setFlyBehavior(new FlyWithWings); 
    d2->performFly();
    
    cout << "duck3\n";
    RubberDuck *d3 = new RubberDuck;
    d3->performFly();
    // RubberDuck pointer CANNOT change fly behavior
    //d3->setFlyBehavior(new FlyWithWings);
    //d3->performFly();


    
    return 1;
}
