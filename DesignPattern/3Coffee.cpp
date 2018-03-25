#include <iostream>
#include <string>

using namespace std;

class Beverage
{
  protected:
    string description = "unknown";
  public:
    virtual string getDescription() {return description;} 
    virtual double cost() = 0;
    virtual ~Beverage() {};
};

class Espresso: public Beverage
{
  public:
    Espresso() {description = "Espresso";}
    double cost() {return 1.99;}
};

class HouseBlend: public Beverage
{
  public:
    HouseBlend() {description = "House Blend";}
    double cost() {return 0.89;}
};


class Condiment: public Beverage
{
    Beverage *beverage;
  public:
    Condiment(Beverage *beverageIn) {beverage = beverageIn;}
    string getDescription() {return beverage->getDescription();}
    double cost() {return beverage->cost();}
};

class Mocha: public Condiment
{
  public:
    Mocha(Beverage *beverageIn) : Condiment(beverageIn) {}
    string getDescription() {return Condiment::getDescription() + ", Mocha";}
    double cost() {return Condiment::cost() + 0.99;}
};

class Whip: public Condiment
{
  public:
    Whip(Beverage *beverageIn) : Condiment(beverageIn) {} 
    string getDescription() {return Condiment::getDescription() + ", Whip";}
    double cost() {return Condiment::cost()  + 0.2;}
};

class SoyMilk: public Condiment
{
  public:
    SoyMilk(Beverage *beverageIn) : Condiment(beverageIn) {}
    string getDescription() {return Condiment::getDescription() + ", SoyMilk";}
    double cost() {return Condiment::cost()  + 0.4;}
};

void printCoffee(Beverage *b)
{
    cout << b->getDescription() << ": $" << b->cost() << endl;
}
int main ()
{
    Beverage *b1 = new Espresso();
    printCoffee(b1);
    Beverage *b2 = new SoyMilk(b1);
    printCoffee(b2);
    Beverage *b3 = new SoyMilk(b2);
    printCoffee(b3);
    delete b1;
    Beverage *b4 = new Whip(b3);
    printCoffee(b4);
    return 1;
}
