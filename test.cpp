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

vector<int> calculateNext(const string& p) {
    vector<int> next(p.size(), -1);
    for (int j = 0 ; j < p.size()-1; j++) {
        int k = next[j];
        while (k != -1 && p[k] != p[j]) {
            k = next[k];
        }
        if (p[j+1] != p[k+1])
            next[j+1] = k+1;
        else
            next[j+1] = next[k];
    }
    return next;

    /*
    vector<int> max(p.size(), 0);
    for (int j = 1 ; j < p.size(); j++) {
        int k = max[j-1];
        while (k != 0 && p[k] != p[j]) {
            k = max[k];
        }
        if (p[j] == p[k])
            max[j] = k+1;
        else
            max[j] = k;
    }
    return max;
    */
 
}

int substr(string text, string pattern) {
    vector<int> next= calculateNext(pattern);
    cout << endl;
    for (auto i : next)
        cout << i;
    cout << endl;
    int i = 0;
    int j = 0;
    while(i < (int)text.size() && j < (int) pattern.size()) {
        cout << i << "," <<  j << endl;
        if (j == -1 || text[i] == pattern[j]) {
            cout << 'a' << endl;
            i++;
            j++;
        }
        else {
            cout << 'b' << endl;
            j = next[j]; 
        }
    }

    if (j == pattern.size())
        return i-j;
    else
        return -1;

}

int main()
{
    //cout << substr("aaac", "aac");
    /*
    vector<int> next= calculateNext("abab");
    cout << endl;
    for (auto i : next)
        cout << i << " ";
    cout << endl;
    */
    set<int> s;
    s.insert(5);
    s.insert(8);
    s.insert(4);
    s.insert(9);
    s.insert(6);
    auto it = s.find(4);
    cout << *it << endl;
    it-=1;
    cout << *it << endl;

    return 0;
}
