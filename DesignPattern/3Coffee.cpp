#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Beverage
{
  int size = 16;
  protected:
    string description = "unknown";
  public:
    virtual string getDescription() {return description;} 
    virtual double cost() = 0;
    virtual void setSize(int s) {size = s;}
    virtual int getSize() const {return size;}
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
  protected:
    Beverage *beverage;
  public:
    Condiment(Beverage *beverageIn) {beverage = beverageIn;}
    string getDescription() {return beverage->getDescription();}
    double cost() {return beverage->cost();}
    void setSize(int s) { beverage->setSize(s);}
    int getSize() const { return beverage->getSize();}

};

class Whip: public Condiment
{
  public:
    Whip(Beverage *beverageIn) : Condiment(beverageIn) {} 
    string getDescription() {
        return beverage->getDescription() + " with Whip";
    }
    double cost() {return beverage->cost() + 0.2;}
};

class SoyMilk: public Condiment
{
  public:
    SoyMilk(Beverage *beverageIn) : Condiment(beverageIn) {} 
    string getDescription() {
        return beverage->getDescription() + " with SoyMilk";
    }
    double cost() {
        if (beverage->getSize() <= 16)
            return beverage->cost()  + 0.4;
        else if (beverage->getSize() <= 20)
            return beverage->cost()  + 0.8;
        else 
            return beverage->cost()  + 1.2;
    }
};

void printCoffee(Beverage *b)
{
    cout << endl << b->getSize() << "oz " << b->getDescription() 
         << ": $" << b->cost() << endl << endl;
}

int main ()
{
    Beverage *espresso = new Espresso();
    Beverage *espresso_soy_milk = new SoyMilk(espresso);
    Beverage *espresso_double_soy_milk = new SoyMilk(espresso_soy_milk);
    printCoffee(espresso_double_soy_milk);

    espresso_double_soy_milk->setSize(20);
    printCoffee(espresso_double_soy_milk);

    Beverage *espresso_double_soy_milk_whipped= new Whip(espresso_double_soy_milk);
    printCoffee(espresso_double_soy_milk_whipped);
    return 1;
}
