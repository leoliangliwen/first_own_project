#include <iostream>

#define ABC 123
using namespace std;
int *pa;

void fun1(int a)
{
    cout << "inside fun1: &a=" << &a << endl;
    a++;
    pa = &a;
}

void fun1(int a, int b)
{

}

int main ()
{
    // this is comment
    int a = 5;
    cout << "inside main: &a=" << &a << endl;
    fun1(a);
    cout << *pa << endl;
    int b = 7;
    cout << "inside main: &b=" << &b << endl;
    cout << *pa << endl;
    cout << ABC << endl;
    return 1;
}
