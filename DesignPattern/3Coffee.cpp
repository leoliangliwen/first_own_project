#include <iostream>
#include <string>

using namespace std;

class Beverage
{
    string description = "unknown";
    int size = 16;
  public:
    virtual string getDescription() {return description;} 
    virtual double cost() = 0;
    void setSize(int sizeIn) {size = sizeIn;}
    int getSize() {return size;}
};

class Espresso: public Beverage
{
    string description = "Espresso";
  public:
    string getDescription() {return description;} 
    double cost() {return 1.99;}
};

class HouseBlend: public Beverage
{
    string description = "House Blend";
  public:
    string getDescription() {return description;} 
    double cost() {return 0.89;}
};


class Condiment: public Beverage
{
  public:
    virtual string getDescription() = 0; 
    virtual double cost() = 0;
};

class Mocha: public Condiment
{
    Beverage *beverage;
  public:
    Mocha(Beverage *beverageIn) {beverage = beverageIn;}
    string getDescription() {return beverage->getDescription() + ", Mocha";}
    double cost() {return beverage->cost() + 0.99;}
};

class Whip: public Condiment
{
    Beverage *beverage;
  public:
    Whip(Beverage *beverageIn) {beverage = beverageIn;}
    string getDescription() {return beverage->getDescription() + ", Whip";}
    double cost() {return beverage->cost() + 0.2;}
};

class SoyMilk: public Condiment
{
    Beverage *beverage;
  public:
    SoyMilk(Beverage *beverageIn) {beverage = beverageIn;}
    string getDescription() {return beverage->getDescription() + ", Whip";}
    double cost() {
        cout << "size: " << this->getSize() << endl;
        if (this->getSize() == 16)
            return beverage->cost() + 0.4;
        else if (this->getSize() == 20)
            return beverage->cost() + 0.6;
        else // 24
            return beverage->cost() + 0.8;
    }
};

int main ()
{
    /*
    HouseBlend houseBlend;
    cout << houseBlend.getDescription() << endl;
    cout << houseBlend.cost() << endl;
    Mocha mocha(&houseBlend);
    cout << mocha.getDescription() << endl;
    cout << mocha.cost() << endl;
    Whip whip(&mocha);
    cout << whip.getDescription() << endl;
    cout << whip.cost() << endl;
    Whip whip1(&whip);
    cout << whip1.getDescription() << endl;
    cout << whip1.cost() << endl;
    */

    Beverage *b1 = new Espresso;
    Beverage *b2 = new SoyMilk(b1);
    cout << b2->cost() << endl;
    Beverage *b3 = new SoyMilk(b1);
    b3->setSize(24);
    b3->setSize(16);
    cout << b3->cost() << endl;
    return 1;
}
