#include <iostream>
#include <memory>

using namespace std;

class Pizza
{
  public:
    virtual void prepare() = 0;
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;
    virtual ~Pizza(){};
};

class NyStyleCheesePizza: public Pizza
{
  public:
    void prepare() {cout << "Preparing NY Cheese Pizza!\n";}
    void bake() {cout << "Baking NY Cheese Pizza!\n";}
    void cut() {cout << "Cutting NY Cheese Pizza!\n";}
    void box() {cout << "Boxing NY Cheese Pizza!\n";}
};

class NyStylePepperoniPizza: public Pizza
{
  public:
    void prepare() {cout << "Preparing NY Pepperoni Pizza!\n";}
    void bake() {cout << "Baking NY Pepperoni Pizza!\n";}
    void cut() {cout << "Cutting NY Pepperoni Pizza!\n";}
    void box() {cout << "Boxing NY Pepperoni Pizza!\n";}
};

class ChicagoStyleCheesePizza: public Pizza
{
  public:
    void prepare() {cout << "Preparing Chicago Cheese Pizza!\n";}
    void bake() {cout << "Baking Chicago Cheese Pizza!\n";}
    void cut() {cout << "Cutting Chicago Cheese Pizza!\n";}
    void box() {cout << "Boxing Chicago Cheese Pizza!\n";}
};

class ChicagoStylePepperoniPizza: public Pizza
{
  public:
    void prepare() {cout << "Preparing Chicago Pepperoni Pizza!\n";}
    void bake() {cout << "Baking Chicago Pepperoni Pizza!\n";}
    void cut() {cout << "Cutting Chicago Pepperoni Pizza!\n";}
    void box() {cout << "Boxing Chicago Pepperoni Pizza!\n";}
};

class PizzaFactory 
{
  public:
    virtual unique_ptr<Pizza> createPizza(string type) = 0;
    virtual ~PizzaFactory(){}
};

class NyPizzaFactory: public PizzaFactory
{
  public:
    unique_ptr<Pizza> createPizza(string type)
    {
        if (type == "cheese")
        {
            return make_unique<NyStyleCheesePizza>();
        }
        else
        {
            return make_unique<NyStylePepperoniPizza>();
        }
    }
};

class ChicagoPizzaFactory: public PizzaFactory
{
  public:
    unique_ptr<Pizza> createPizza(string type)
    {
        if (type == "cheese")
        {
            return make_unique<ChicagoStyleCheesePizza>();
        }
        else
        {
            return make_unique<ChicagoStylePepperoniPizza>();
        }
    }
};


class PizzaStore
{
  unique_ptr<PizzaFactory> factory;
  public:
    PizzaStore(unique_ptr<PizzaFactory> factoryIn) : factory(move(factoryIn)){}
    unique_ptr<Pizza> orderPizza(string type)
    {
        unique_ptr<Pizza> pizza = factory->createPizza(type);

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }
};

int main ()
{
    unique_ptr<NyPizzaFactory> ny_factory = make_unique<NyPizzaFactory>();
    PizzaStore ny_store(move(ny_factory));
    ny_store.orderPizza("cheese");

    unique_ptr<ChicagoPizzaFactory> chicago_factory = make_unique<ChicagoPizzaFactory>();
    PizzaStore chicago_store(move(chicago_factory));
    chicago_store.orderPizza("pepperoni");

    return 1;
}
