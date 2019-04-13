// QUESTION:
//
// Given an array of envelopes, find the longest sequence
// such that you are able to fit a envelope inside another 
// for all envelopes in that sequence. Visualize this like the
// “Russian doll” toy.
//
// The envelopes can be rotated 90 degrees in order to fit inside another envelope. 
// An envelope fits inside another if both side lengths are strictly less.
//
// NOTE: note the distinction of “subsequence” from 
// “subarray” and “subset”. Subarray must be contiguous, 
// which a subsequence does not require. Subsequence
// requires order is preserved, which subset does not require.
//
// Ex.                                                           {8,3}
// Envelopes =  { {2,2}, {10,10}, {2,1}, {10,8}, {9,9}, {20,20}, {8,3}, {6,1}, {7, 2}, {1,1}, {4,3}, {20,20} }
//                  2       5       1      4      4       4        3      1      2       1       1       1
/*

*/
// Ret: { {10,10}, {9,9}, {3,8}, {7,2}, {1,1} }
//
// Envelopes =  { {2,2}, {3,3}, {4,5}, {6,8}, {9,9}, {20,100} }
// Ret: { any one element }


#include <iostream>
#include <string>
#include <vector>
using namespace std;

pair<int, int> rotation(pair<int, int>) {
    
}

vector<pair<int, int>> findEnvelops(vector<pair<int, int>> envelopes) {
    vector<int> counts(envelopes.size(), 1);     // store the len of evelops from right until this element
    vector<int> index(envelopes.size() );     // store the len of evelops from right until this element
    for (int i = 0; i < index.size(); i++)
        index[i] = i;
    
    vector<pair<int, int>> answer;
    int answerLen = 0;
    int answerIndex = -1;
    for (int i = envelopes.size()-1; i>= 0; i--) {
        int currLen = envelopes[i].first;
        int currWide = envelopes[i].second;
        if (currLen < currWide) {
            int temp = currLen;
            currLen = currWide;
            currWide = temp;
        }
        
        for (int j = i+1; j < envelopes.size()-1; j++) {
            int nextLen = envelopes[j].first;
            int nextWide = envelopes[j].second;
            if (nextLen < nextWide) {
                int temp = nextLen;
                nextLen = nextWide;
                nextWide = temp;
            }
            if (currLen > nextLen && currWide > nextWide) {
                if (counts[i] < counts[j] + 1) {
                    counts[i] = counts[j] + 1;
                    index[i] = j;
                }
            }
        }
        
        if (counts[i] > answerLen) {
            answerLen = counts[i];
            answerIndex = i;
        }
    }
    
    int next = answerIndex;
    while(true) {
        answer.push_back(envelopes[next]);
        if (next == index[next])
            break;
        next = index[next];
    }
    
    return answer;
}

using namespace std;

int main() {
    vector<pair<int, int>> input {
        {2,2}, {10,10}, {2,1}, {10,8}, {9,9}, {20,20}, {8,3}, {6,1}, {7, 2}, {1,1}, {4,3}, {20,20}        
    };
    
    vector<pair<int, int>> output = findEnvelops(input);
    for (auto i : output)
        cout << i.first << ", " << i.second << endl;
    return 0; 
}
