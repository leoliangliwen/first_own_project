#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
// *************************** Class 1 Binary Search ***************************
// *************************** Class 1 Binary Search ***************************
// *************************** Class 1 Binary Search ***************************

// strStr
// http://www.lintcode.com/en/problem/strstr/
int strStr(const char *source, const char *target) {
    if (target == NULL || source == NULL) return -1;
    if (*target == '\0') return 0;
    for (int index_source = 0; *(source + index_source) != '\0'; index_source++)
    {
        for (int index_target = 0;
             *(target + index_target) != '\0'
             && *(source + index_source + index_target) != '\0';
             index_target++)
        {
            if (*(target + index_target) != *(source + index_source + index_target)) {
                break;
            }
            if (*(target + index_target + 1) == '\0') {
                return index_source;
            }
        }
    }
    return -1;
}

void print_array(vector<int> answer)
{
    cout << "<";
    for (int i = 0; i < answer.size(); i++) {
            std::cout << answer[i];
    }
    cout << ">\n";
}

void print_array_of_array(vector<vector<int> > answer)
{
    cout << "{\n";
    for (int i = 0; i < answer.size(); i++) {
        cout << "     ";
        print_array(answer[i]);
    }
    cout << "}\n";
}

// Subsets
// http://www.lintcode.com/en/problem/subsets/#
void subsets_helper (vector<vector<int>> &answer,
                     const vector<int> &nums,
                     vector<int> &current,
                     int start_index)
{
    answer.push_back(current);
    for (int i = start_index; i < nums.size(); i++)
    {
        current.push_back(nums[i]);
        subsets_helper(answer, nums, current, i+1);
        current.pop_back();
    }
}

vector<vector<int> > subsets(vector<int> &nums) {
    vector<vector<int> > answer;
    if (nums.size() == 0) return answer;

    sort(nums.begin(), nums.end());

    vector<int> current;
    subsets_helper(answer, nums, current, 0);
    return answer;
}

// Subsets II
// http://www.lintcode.com/en/problem/subsets-ii/#
void subsetsWithDup_Helper(vector<vector<int> > &answer,
                           const vector<int> &S,
                           vector<int> &current,
                           int start_index)
{
    answer.push_back(current);
    for (int i = start_index; i < S.size(); i++)
    {
        if (i != start_index && S[i] == S[i-1]) continue;
        current.push_back(S[i]);
        subsetsWithDup_Helper(answer, S, current, i + 1);
        current.pop_back();
    }

}

vector<vector<int> > subsetsWithDup( vector<int> &S) {
    vector<vector<int> > answer;

    vector<int> S_copy{S};
    sort(S_copy.begin(), S_copy.end());
    vector<int> current;

    subsetsWithDup_Helper(answer, S_copy, current, 0);
    return answer;
}

// Permutations
// http://www.lintcode.com/en/problem/permutations/#
void permute_helper(vector<vector<int>> &answer,
                    const vector<int> &nums,
                    vector<bool> &nums_used,
                    vector<int> &current)
{
    if (current.size() == nums.size())
    {
        answer.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums_used[i]) continue;

        current.push_back(nums[i]);
        nums_used[i] = true;
        permute_helper(answer, nums, nums_used, current);
        current.pop_back();
        nums_used[i] = false;
    }
}

vector<vector<int> > permute(vector<int> nums) {
    vector<vector<int> > answer;
    if (nums.size() == 0) return answer;
    sort(nums.begin(), nums.end());
    vector<int> current;
    vector<bool> nums_used(nums.size(), false);

    permute_helper(answer, nums, nums_used, current);
    return answer;
}

// Permutations II
// http://www.lintcode.com/en/problem/permutations-ii/#
void permuteUnique_helper(vector<vector<int> > &answer,
                          vector<int> &nums,
                          vector<bool> &nums_used,
                          vector<int> &current)
{
    if (current.size() == nums.size())
    {
        answer.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums_used[i])   continue;
        current.push_back(nums[i]);
        nums_used[i] = true;
        permuteUnique_helper(answer, nums, nums_used, current);
        current.pop_back();
        nums_used[i] = false;
        while (i < nums.size()-1 && nums[i] == nums[i+1]) {
            i++;
        }
    }
}

vector<vector<int> > permuteUnique(vector<int> &nums) {
    vector<vector<int> > answer;
    if (nums.size() == 0) return answer;

    sort(nums.begin(), nums.end());
    vector<bool> nums_used(nums.size(), false);
    vector<int> current;
    permuteUnique_helper(answer, nums, nums_used, current);

    return answer;
}

int main()
{
    return 1;
}
