#include <iostream>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

template <typename T>
void show(T arg)
{
    cout << arg << endl;
}

template <typename T>
bool too_big(T arg)
{
    return arg > 5;
}

template <typename T>
class TooBig
{
    T m_benchmart;
  public:
    TooBig(T benchmart) {m_benchmart = benchmart;}
    bool operator() (T arg) {return arg > m_benchmart;}
};

int main ()
{
    list<int> a{1,2,3,4,5,6};
    for_each(a.begin(), a.end(), show<int>);
    cout << endl;

    a.remove_if(too_big<int>);
    for_each(a.begin(), a.end(), show<int>);
    cout << endl;

    TooBig<int> tb(4);
    a.remove_if(tb);
    for_each(a.begin(), a.end(), show<int>);
    cout << endl;

    a.remove_if(bind2nd(greater<int>(), 3));
    for_each(a.begin(), a.end(), show<int>);
    cout << endl;
    
    a.remove_if( [] (int input) {return input > 2;} );
    for_each(a.begin(), a.end(), show<int>);
    cout << endl;

    auto lambda_function = [] (int input)->bool {return input > 1;};
    a.remove_if( lambda_function );
    for_each(a.begin(), a.end(), show<int>);
    cout << endl;
 
    while (true)
    {
    }



    return 1;
}
