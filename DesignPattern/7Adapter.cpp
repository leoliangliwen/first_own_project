#include <iostream>
#include <memory>

using namespace std;

class Duck
{
  public:
      virtual void quack() = 0;
      virtual void fly() = 0;
      virtual ~Duck(){};
};

class Turkey
{
  public:
      void gobble() {cout << "Gobble gobble\n";};
      void fly() {cout << "I'm flying a short distance\n";}
};

class TurkeyObjectAdaptor: public Duck
{
    unique_ptr<Turkey> turkey;
  public:
    TurkeyObjectAdaptor(unique_ptr<Turkey> turkeyIn) 
        : turkey(move(turkeyIn)){};
    void quack() {turkey->gobble();}
    void fly() {turkey->fly();}
};

class TurkeyClassAdaptor: public Duck, public Turkey
{
    public:
      void quack() {Turkey::gobble();}
      void fly() {Turkey::fly();}
};


int main ()
{
    unique_ptr<Duck> duck1 = 
        make_unique<TurkeyObjectAdaptor>(make_unique<Turkey>());
    duck1->quack();
    duck1->fly();

    unique_ptr<Duck> duck2 = make_unique<TurkeyClassAdaptor>();
    duck2->quack();
    duck2->fly();

    return 1;
}
