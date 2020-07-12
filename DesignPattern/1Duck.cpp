#include <iostream>

using namespace std;

class FlyBehavior   // flying interface
{
  public:
    virtual void fly() = 0;
    virtual ~FlyBehavior() {};
};

class FlyWithWings : public FlyBehavior
{
    void fly() {cout << "I'm flying with wings\n";}
};

class FlyNoWay : public FlyBehavior
{
    void fly() {cout << "I cannot fly\n";}
};

class Duck 
{
  protected:
    FlyBehavior *flyBehavior;
  public:
    virtual void display() = 0;
    void performFly() {flyBehavior->fly();}
    virtual void setFlyBehavior(FlyBehavior *flyBehaviorIn) {
        flyBehavior = flyBehaviorIn;
    }
    virtual ~Duck() {};
};

class MallardDuck: public Duck
{
    // hide setFlyBehavior in child class
    void setFlyBehavior(FlyBehavior *flyBehaviorIn) {
        cout << "MallardDuck cannot set fly behavior.\n";
    }
  public:
    MallardDuck() {flyBehavior = new FlyWithWings();}
    ~MallardDuck() {delete flyBehavior;}
    void display() {cout << "\nI'm a Mallard Duck\n";}
};

class RubberDuck: public Duck
{
    // hide setFlyBehavior in child class
    void setFlyBehavior(FlyBehavior *flyBehaviorIn) {
        cout << "RubberDuck cannot set fly behavior.\n";
    }
  public:
    RubberDuck() {flyBehavior = new FlyNoWay();}
    ~RubberDuck() {delete flyBehavior;}
    void display() {cout << "\nI'm a Rubber Duck\n";}
};


int main ()
{
    Duck *d1 = new MallardDuck ;
    d1->display();
    d1->performFly();
    delete d1;

    Duck *d2 = new RubberDuck;
    d2->display();
    d2->performFly();
    // Duck pointer CANNOT change fly behavior
    d2->setFlyBehavior(new FlyWithWings); 
    d2->performFly();
    delete d2;
    
    RubberDuck *d3 = new RubberDuck;
    d3->display();
    d3->performFly();
    // RubberDuck pointer CANNOT call setFlyBehavior because it is hidden.
    //d3->setFlyBehavior(new FlyWithWings);
    //d3->performFly();
    delete d3;


    
    return 1;
}
