#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<queue>
#include<math.h>
using namespace std;

void print(vector<int>& array) {
    for (auto i : array)
        cout << i;
    cout << endl;
}

void swap(vector<int>& array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void heapify(vector<int>& array, int index, int end) {
    cout << index << end << endl;
    print(array);
    if (index > end)
        return;

    int largest = index;
    int l = index * 2 + 1;
    if (l <= end && array[l] > array[largest]) {
        largest = l;
    }
    int r = index * 2 + 2;
    if (r <= end && array[r] > array[largest]) {
        largest = r;
    }

    if (largest != index) {
        swap(array, index, largest);
        heapify(array, largest, end);
    }
}

void heapSort(vector<int>& array) {
    for (int i = array.size()/2; i >= 0; i--) {
        heapify(array, i, array.size() - 1);
    }
        cout << "Before: ";
        print(array);


    for (int i = array.size()-1; i >= 0; i--) {
        cout << "Start: ";
        print(array);

        swap(array, i, 0);
        cout << "After swap: ";
        print(array);

        heapify(array, 0, i-1);
        cout << "After heap: ";
        print(array);
    }
}

int main()
{
    unordered_map<int, int> m;
    cout << m[3] << endl;
    cout << m.size() << endl;
    m[0]++;
    cout << m[0] << endl;
    cout << m.size() << endl;
    return 1;

    vector<int> a {5,3,1,4,2};
    heapSort(a);
    for (auto i : a) {
        cout << i << endl;
    }
    return 0;
}
