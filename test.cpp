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

string covertToBinary(int n) {
    if (n == 0)
        return "0";
    string answer;
    while(n) {
        int mode = n % 2;
        answer += mode + '0';
        n /= 2;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int binaryToInt(string s) {
    int answer = 0;
    for (int i = 0; i < s.size(); i++) {
        answer = answer * 2 + (s[i] - '0');
    }
    return answer;
}

int nextSparseNumber(int n) {
    string binary = covertToBinary(n);
    int carry = 0;
    for (int i = binary.size() - 2; i >= 0; i--) {
        int curr = binary[i] - '0' + carry;
        if (curr == 2) {
            curr = 0;
            carry = 1;
        }
        else {
            carry = 0;
        }
        binary[i] = '0' + curr;

        if (binary[i] == '1' && binary[i+1] == '1') {
            binary[i] = '0';
            carry = 1;
        }
    }
    if (carry == 1)
        binary = "1" + binary;

    return binaryToInt(binary);
}

int main()
{
    cout << covertToBinary(44) << endl;
    int next = nextSparseNumber(44);
    cout << covertToBinary(next) << endl;


    return 0;
}

