#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int strStr(const char *source, const char *target) {
    if (target == NULL || source == NULL) return -1;
    if (*source == '\0' && *target == '\0') return 0;
    int index1 = 0;
    int index2 = 0;
    while( * (source + index1) != '\0')
    {
        int i = 0;
        while ( * (target + index2 + i) != '\0')
        {
            if (*(source + index1 + i) != *(target + index2 + i))
            {
                index1++;
                index2 = 0;
                break;
            }
            else
            {
                i++;
                
            }
        }
        if (* (target + index2 + i) == '\0')
        {
            return index1;
        }
    }
    // write your code here
    return -1;
}

vector<vector<int>> subsets(vector<int> &nums) {
    //cout << pow(2, nums.size());
    vector< vector<int>> answer;
    if (nums.size() == 1) {
        vector<int> temp_array;
        answer.push_back( temp_array );
        temp_array.push_back(nums[0]);
        answer.push_back( temp_array );
    }
    else {
        int last_number = nums[nums.size()-1];
        nums.pop_back();
        vector< vector<int>> sub_answer = subsets(nums);
        for (int i = 0; i < sub_answer.size(); i++) {
            vector<int> a_array = sub_answer[i];
            answer.push_back(a_array);
            a_array.push_back(last_number);
            answer.push_back(a_array);
        }
    }
    return answer;
}

void print_array_of_array(vector<vector<int>> answer)

{
    for (int i = 0; i < answer.size(); i++) {
        cout << "<";
        for (int j = 0; j < answer[i].size(); j++) {
            std::cout << answer[i][j];
        }
        cout << ">\n";
    }
}
int main()
{
    //std::cout << strStr("", "") << std::endl;
    vector<int> input = {1, 2, 3, 4};
    vector<vector<int>> answer = subsets(input);
    print_array_of_array(answer);
    return 0;
}
