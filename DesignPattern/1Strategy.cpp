#include <iostream>
#include <memory>

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
    unique_ptr<FlyBehavior> flyBehavior;
  public:
    virtual void display() = 0;
    void performFly() {flyBehavior->fly();}
    virtual void setFlyBehavior(unique_ptr<FlyBehavior> flyBehaviorIn) {
        flyBehavior = move(flyBehaviorIn);
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
    MallardDuck() {flyBehavior = make_unique<FlyWithWings>();}
    void display() {cout << "\nI'm a Mallard Duck\n";}
};

class RubberDuck: public Duck
{
    // hide setFlyBehavior in child class
    void setFlyBehavior(FlyBehavior *flyBehaviorIn) {
        cout << "RubberDuck cannot set fly behavior.\n";
    }
  public:
    RubberDuck() {flyBehavior = make_unique<FlyNoWay>();}
    void display() {cout << "\nI'm a Rubber Duck\n";}
};


int main ()
{
    unique_ptr<Duck> d1 = make_unique<MallardDuck>();
    d1->display();
    d1->performFly();

    unique_ptr<Duck> d2 = make_unique<RubberDuck>();
    d2->display();
    d2->performFly();
    // Duck pointer CAN change fly behavior
    d2->setFlyBehavior(make_unique<FlyWithWings>()); 
    d2->performFly();
    
    unique_ptr<RubberDuck> d3 = make_unique<RubberDuck>();
    d3->display();
    d3->performFly();
    // RubberDuck pointer CANNOT call setFlyBehavior because it is hidden.
    //d3->setFlyBehavior(make_uniqu<eFlyWithWings>());
    //d3->performFly();

    return 1;
}
