#include <iostream>
#include <string>

using namespace std;

class Singleton 
{
    static Singleton *instance;
    Singleton(){}
  public:
    static Singleton *getInstance() {
        static Singleton *instance = new Singleton();
        return instance;
    }
};

int main ()
{
    Singleton *instance1 = Singleton::getInstance();
    cout << "instance1 address: " << instance1 << endl;
    Singleton *instance2 = Singleton::getInstance();
    cout << "instance2 address: " << instance2 << endl;
    return 1;
}
