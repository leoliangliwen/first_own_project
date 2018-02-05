#include <iostream>

using namespace std;

class Pizza
{
  public:
    virtual void prepare() = 0;
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;
};

class CheesePizza: public Pizza
{
  public:
    void prepare() {cout << "Preparing Cheese Pizza!\n";}
    void bake() {cout << "Baking Cheese Pizza!\n";}
    void cut() {cout << "Cutting Cheese Pizza!\n";}
    void box() {cout << "Boxing Cheese Pizza!\n";}
};

class PepperoniPizza: public Pizza
{
  public:
    void prepare() {cout << "Preparing Pepperoni Pizza!\n";}
    void bake() {cout << "Baking Pepperoni Pizza!\n";}
    void cut() {cout << "Cutting Pepperoni Pizza!\n";}
    void box() {cout << "Boxing Pepperoni Pizza!\n";}
};

class SimplePizzaFactory
{
  public:
    Pizza createPizza(string type)
    {
        if (type == "cheese")
        {
            CheesePizza cheesePizza;
            return cheesePizza;
        }
        else
        {
            PepperoniPizza pepperoniPizza;
            return pepperoniPizza;
        }
    }
};

class PizzaStore
{
    SimplePizzaFactory* pizzaFactory;
  public:
    PizzaStore(SimplePizzaFactory* pizzaFactoryIn) {pizzaFactory = pizzaFactoryIn;}
    Pizza orderPizza(string type)
    {
        Pizza pizza = pizzaFactory->createPizza(type);

        pizza.prepare();
        pizza.bake();
        pizza.cut();
        pizza.box();
        return pizza;
    }
};

int main ()
{
    SimplePizzaFactory pizzaFactoryIn;
    PizzaStore store(&pizzaFactoryIn);
    store.orderPizza("cheese");
    return 1;
}
