#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Beverage
{
  protected:
    string description = "unknown";
    int size = 16;
  public:
    virtual string getDescription() {return description;} 
    virtual double cost() = 0;
    void setSize(int s) {size = s;}
    int getSize() {return size;}
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
    double cost() {
        if (Beverage::getSize() == 16)
            return Condiment::cost()  + 0.4;
        else if (Beverage::getSize() == 20)
            return Condiment::cost()  + 0.8;
        else if (Beverage::getSize() == 24)
            return Condiment::cost()  + 1.2;
        else
            return Condiment::cost();

    }
};

void printCoffee(Beverage *b)
{
    cout << b->getSize() << "oz " << b->getDescription() << ": $" << b->cost() << endl;
}
int main ()
{
    Beverage *b1 = new Espresso();
    Beverage *b2 = new SoyMilk(b1);
    Beverage *b3 = new SoyMilk(b2);
    Beverage *b4 = new Whip(b3);
    Beverage *b5 = new SoyMilk(b4);

    printCoffee(b5);
    b5->setSize(20);
    printCoffee(b5);
    b5->setSize(24);
    printCoffee(b5);

    return 1;
}
