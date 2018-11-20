#include <queue>          // std::queue
#include <stack>  
#include <vector>  
#include <map>  
#include <set>  
#include <iostream>  
#include <algorithm>  
#include <math.h>
using namespace std;
class Solution {
 public:
  int maxSubArrayLen(vector<int> nums, int k) {
    int answer = 0;
    map<int, int> m;	// value->index of prefix;
    int prefixSum = 0;
    m[prefixSum] = -1;
    for (int i = 0; i < nums.size(); i++)
    {
      prefixSum += nums[i];
      int target = prefixSum - k;
      if (m.find(target) != m.end())
      {
        int localAnswer = i - m[target] - 1;
        answer = answer > localAnswer? answer: localAnswer;
      }
      else
      	m[prefixSum] = -1;
    }
    return answer;
  }
};


int main()
{
    vector<int> input{-2,-1,2,1};
    Solution s;
    cout << s.maxSubArrayLen(input, 2);
    return 0;
}
