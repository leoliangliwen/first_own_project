#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;

class MyClass
{
public:
    MyClass(int aa, int bb): a(aa), b(bb){}
    int a;
    int b;
};

// default max heap
// left > right ==> Min Heap
// check empty before top/pop
struct Comparator
{
    bool operator() (const MyClass& lhs, const MyClass& rhs) const
    {
            return lhs.a > rhs.a;
    }
};


int main()
{
    priority_queue<MyClass,vector<MyClass>,Comparator> pq;
    MyClass a(1,2);
    MyClass b(1,3);
    MyClass c(1,4);
    MyClass d(3,2);
    MyClass e(4,2);
    pq.push(a);
    pq.push(b);
    pq.push(c);
    pq.push(d);
    pq.push(e);
    for (int i = 0; i < 5; i++)
    {
        MyClass curr = pq.top();
        cout << curr.a << curr.b << endl;
        pq.pop();
    }

    cout << "==============="<< endl;

    priority_queue<int, vector<int>, greater<int>> minH;
    minH.push(5);
    minH.push(3);
    minH.push(4);
    minH.push(1);
    minH.push(2);
    for (int i = 0; i < 5; i++)
    {
        cout << minH.top() << endl;
        minH.pop();
    }

    cout << "==============="<< endl;

    priority_queue<int, vector<int>, less<int>> maxH;
    maxH.push(5);
    maxH.push(3);
    maxH.push(4);
    maxH.push(1);
    maxH.push(2);
    for (int i = 0; i < 5; i++)
    {
        cout << maxH.top() << endl;
        maxH.pop();
    }

    return 0;
}
