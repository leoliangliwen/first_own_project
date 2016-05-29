#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include <unordered_set>
using namespace std;
// *********************** Class 5 Dynamic Programming II **********************
// *********************** Class 5 Dynamic Programming II **********************
// *********************** Class 5 Dynamic Programming II **********************

// Word Break
// http://www.lintcode.com/en/problem/word-break/
bool wordBreak(string s, unordered_set<string> &dict) {
    if (s.length() == 0) return true;

    int max_length = 0;
    for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++)
    {
        max_length = max(max_length, (int)it->length());
    }


    // state answer[x] means first s letter is word(s)
    bool answer[s.length() + 1];

    answer[0] = true;

    for (int i = 1; i <= s.length(); i++)
    {
        answer[i] = false;
        for (int j = i-1; j >= i-max_length; j--)
        {
            if (answer[j] && dict.find(s.substr(j, i-j)) != dict.end())
            {
                answer[i] = true;
                break;
            }
        }
    }

    return answer[s.length()];
}

// Palindrome Partitioning II
// http://www.lintcode.com/en/problem/palindrome-partitioning-ii/
int minCut(string s) {
    int len = s.length();

    bool palindrome[len][len];

    for (int i = 0; i < len; i++) {
        palindrome[i][i] = true;
        if (i + 1 < len) {
            palindrome[i][i + 1] = (s[i] == s[i + 1]);
        }
    }

    for (int i = len-1; i >= 0; i--)
    {
        for (int j = i + 2; j < len; j++)
        {
            palindrome[i][j] = palindrome[i + 1][j - 1] && (s[i] == s[j]);
        }
    }

    int answer[s.length() + 1];

    answer[0] = 0;

    for (int i = 1; i <= s.length(); i++)
    {
        answer[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (palindrome[j][i - 1])
                answer[i] = min(answer[i], answer[j] + 1);
        }
    }
    return answer[s.length()] - 1;
}

// Longest Common Subsequence
// http://www.lintcode.com/en/problem/longest-common-subsequence/
int longestCommonSubsequence(string A, string B) {
    int a_len = A.length();
    int b_len = B.length();

    int answer[a_len + 1][b_len + 1];

    for (int i = 0; i < a_len + 1; i++)
    {
        answer[i][0] = 0;
    }

    for (int j = 0; j < b_len + 1; j++)
    {
        answer[0][j] = 0;
    }

    for (int i = 1; i < a_len + 1; i++)
    {
        for (int j = 1; j < b_len + 1; j++)
        {
            if (A[i-1] == B[j-1])
            {
                answer[i][j] = max(answer[i-1][j], answer[i][j-1]);
                answer[i][j] = max(answer[i][j], answer[i-1][j-1] + 1);
            }
            else
            {
                answer[i][j] = max(answer[i-1][j], answer[i][j-1]);
            }
        }
    }

    return answer[a_len][b_len];
}

// Longest Common Substring
// http://www.lintcode.com/en/problem/longest-common-substring/
int longestCommonSubstring(string &A, string &B) {
    int a_len = A.length();
    int b_len = B.length();

    int answer[a_len + 1][b_len + 1];

    for (int i = 0; i < a_len + 1; i++)
    {
        answer[i][0] = 0;
    }

    for (int j = 0; j < b_len + 1; j++)
    {
        answer[0][j] = 0;
    }

    int longest = 0;
    for (int i = 1; i < a_len + 1; i++)
    {
        for (int j = 1; j < b_len + 1; j++)
        {
            if (A[i-1] == B[j-1])
            {
                answer[i][j] = answer[i-1][j-1] + 1;
                longest = max(longest, answer[i][j]);
            }
            else
            {
                answer[i][j] = 0;
            }
        }
    }

    return longest;
}

// Edit Distance
// http://www.lintcode.com/en/problem/edit-distance/
int minDistance(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();

    int answer[len1 + 1][len2 + 2];

    for (int i = 0; i < len1 + 1; i++)
    {
        answer[i][0] = i;
    }

    for (int j = 0; j < len2 + 1; j++)
    {
        answer[0][j] = j;
    }

    for (int i = 1; i < len1 + 1; i++)
    {
        for (int j = 1; j < len2 + 1; j++)
        {
            if (word1[i-1] == word2[j-1])
            {
                answer[i][j] = min(answer[i-1][j] + 1, answer[i][j-1] + 1);
                answer[i][j] = min(answer[i][j], answer[i-1][j-1]);
            }
            else
            {
                answer[i][j] = min(answer[i-1][j] + 1, answer[i][j-1] + 1);
                answer[i][j] = min(answer[i][j], answer[i-1][j-1] + 1);
            }
        }
    }

    return answer[len1][len2];
}

// Distinct Subsequences
// http://www.lintcode.com/en/problem/distinct-subsequences/
int numDistinct(string &S, string &T) {
    int s_len = S.length();
    int t_len = T.length();

    int answer[s_len + 1][t_len + 1];

    for (int i = 0; i < s_len + 1; i++)
    {
        answer[i][0] = 1;
    }
    for(int j = 1; j < t_len + 1; j++)
    {
        answer[0][j] = 0;
    }

    for (int i = 1; i < s_len + 1; i++)
    {
        for (int j = 1; j < t_len + 1; j++)
        {
            if (S[i-1] == T[j-1])
            {
                answer[i][j] = answer[i-1][j] + answer[i-1][j-1];
            }
            else
            {
                answer[i][j] = answer[i-1][j];
            }
        }
    }

    return answer[s_len][t_len];
}

// Interleaving String
// http://www.lintcode.com/en/problem/interleaving-string/
bool isInterleave(string s1, string s2, string s3) {
    int len1 = s1.length();
    int len2 = s2.length();

    if (len1 + len2 != s3.length()) return false;

    bool answer[len1 + 1][len2 + 1];
    answer[0][0] = s3.length() == 0;
    for (int i = 1; i < len1 + 1; i++)
    {
        answer[i][0] = s1.substr(0, i) == s3.substr(0, i);
    }
    for (int j = 1; j < len2 + 1; j++)
    {
        answer[0][j] = s2.substr(0, j) == s3.substr(0, j);
    }

    for (int i = 1; i < len1 + 1; i++)
    {
        for (int j = 1; j < len2 + 1; j++)
        {
            answer[i][j] = (answer[i-1][j] && s1[i-1] == s3[i+j-1])
            || (answer[i][j-1] && s2[j-1] == s3[i+j-1]);
        }
    }

    return answer[len1][len2];
}

int main()
{
    //std::cout << strStr("", "") << std::endl;

    //vector<int> input = {1, 2, 3};
    //print_array_of_array(subsets(input));

    //vector<int> input = {1, 2, 2};
    //print_array_of_array(subsetsWithDup(input));

    //vector<int> input = {1,2,3};
    //print_array_of_array(permute(input));

    //vector<int> input = {1,2,2};
    //print_array_of_array(permuteUnique(input));

    //vector<int> input = {1,2,3};
    //cout << searchInsert(input, 1) << endl;

    //vector<int> input1 = {1,2,3,4,5,6};
    //ArrayReader input{input1};
    //cout << searchBigSortedArray(&input, 6) << endl;

    //cout << sqrt(999999999);

    //vector<int> input = {2147483644,2147483645,2147483646,2147483647};
    //cout << woodCut(input, 4) << endl;
    //std::string a = "bb";
    //cout << minCut(a) << endl;

    //cout << uniquePaths(2, 62);

    cout << longestCommonSubsequence("abc","abd");
    return 0;
}
