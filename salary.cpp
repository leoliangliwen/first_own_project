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


int main()
{
    int signOn = 0;
    double base = 14.3;
    double bonus = 1.3;

    double rsu = 28/42.0*55;
    int rsuYear = 4;

    double refresh = 6;
    int refreshYear = 4;

    int year = 30;
    vector<double> salary(year, 0);
    salary[0] += signOn;
    for (int i = 0; i < rsuYear; i++)
        salary[i] += rsu/rsuYear;
    for (int i = 0; i < 20; i++) {
        salary[i] += base+bonus;
        base *= 1.05;
        bonus *= 1.05;
        for (int j = 1; j <= refreshYear; j++)
            salary[i+j] += refresh/refreshYear;
    }

    for (int i = 0; i < 20; i++)
        cout << "Year " << i+1 << ": " << salary[i] << endl;

    return 0;
}

