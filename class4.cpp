#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
// *********************** Class 4 Dynamic Programming I ***********************
// *********************** Class 4 Dynamic Programming I ***********************
// *********************** Class 4 Dynamic Programming I ***********************

// Unique Paths
// http://www.lintcode.com/en/problem/unique-paths/
int uniquePaths(int m, int n) {
    if (m == 0) return 0;

    // state
    int answer[m][n];

    // Initialization
    for (int row = 0; row < m; row++)
        answer[row][0] = 1;
    for (int col = 0; col < n; col++)
        answer[0][col] = 1;

    //function
    for (int row = 1; row < m; row++)
    {
        for (int col = 1; col < n; col++)
        {
            answer[row][col] = answer[row-1][col] + answer[row][col-1];
        }
    }

    // answer
    return answer[m-1][n-1];
}

// Unique Paths II
// http://www.lintcode.com/en/problem/unique-paths-ii/
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if (m == 0) return 0;
    if (m == 1 || n == 1) return 1;

    // state
    int answer[m+1][n+1];

    // initialization
    for (int row = 0; row < m+1; row++)
    {
        answer[row][0] = 0;
    }
    for (int col = 0; col < n+1; col++)
    {
        answer[0][col] = 0;
    }
    answer[1][1] = 1;

    // function
    for (int row = 1; row < m+1; row++)
    {
        for (int col = 1; col < n+1; col++)
        {
            if (obstacleGrid[row][col] != 1)
                answer[row][col] = answer[row-1][col] + answer[row][col-1];
            else
                answer[row][col] = 0;
        }
    }

    // answer
    return answer[m][n];
}

// Climbing Stairs
// http://www.lintcode.com/en/problem/climbing-stairs/
int climbStairs(int n) {
    if (n == 0 ) return 1;

    // state
    int answer[n];
    // initialization
    answer[0] = 1;
    answer[1] = 2;
    // function
    for (int i = 2; i < n; i++)
        answer[i] = answer[i-1] + answer[i-2];
    // answer
    return answer[n-1];
}

// Minimum Path Sum
// http://www.lintcode.com/en/problem/minimum-path-sum/
int minPathSum(vector<vector<int> > &grid) {
    int row = grid.size();
    int col = grid[0].size();

    // state
    int answer[row][col];

    // Initialization
    answer[0][0] = grid[0][0];

    // function
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0) continue;
            else if (i == 0)
            {
                answer[i][j] = answer[i][j - 1] + grid[i][j];
            }
            else if (j == 0)
            {
                answer[i][j] = answer[i - 1][j] + grid[i][j];
            }
            else
            {
                answer[i][j] = min(answer[i][j-1], answer[i-1][j]) + grid[i][j];
            }
        }
    }

    // answer
    return answer[row-1][col-1];
}

// Triangle
// http://www.lintcode.com/en/problem/triangle/
int minimumTotal(vector<vector<int> > &triangle) {
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0) triangle[i][j] = triangle[i-1][j] + triangle[i][j];
            else if(j == triangle[i].size()-1) triangle[i][j] = triangle[i-1][j-1] + triangle[i][j];
            else triangle[i][j] = min(triangle[i-1][j-1], triangle[i-1][j]) + triangle[i][j];
        }
    }


    int answer = triangle[triangle.size()-1][0];
    for (int j = 1; j < triangle[triangle.size()-1].size(); j++)
    {
        answer = min(answer, triangle[triangle.size()-1][j]);
    }
    return answer;
}

// Jump Game
// http://www.lintcode.com/en/problem/jump-game/
bool canJump(vector<int> A) {
    bool answer[A.size()];
    for (int i = 0; i < A.size(); i++) answer[i] = false;
    answer[0] = true;
    for (int i = 0; i < A.size(); i++)
    {
        if (answer[i])
        {
            for (int j = 1; j <= A[i] && i + j < A.size(); j++)
                answer[i+j] = true;
        }
        else
        {
            continue;
        }
    }
    return answer[A.size()-1];
}

// Jump Game II
// http://www.lintcode.com/en/problem/jump-game-ii/
int jump(vector<int> A) {
    int answer[A.size()];
    answer[0] = 0;

    for (int i = 1; i < A.size(); i++)
    {
        answer[i] = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (answer[j] != INT_MAX && j + A[j] >= i)
            {
                answer[i] = min(answer[i], answer[j] + 1);
                break;
            }
        }
    }
    return answer[A.size() - 1];
}

// Longest Increasing Subsequence
// http://www.lintcode.com/en/problem/longest-increasing-subsequence/#
int longestIncreasingSubsequence(vector<int> nums) {
    if (nums.size() == 0) return 0;
    int answer[nums.size()];
    answer[0] = 1;
    int final_answer = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        answer[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] <= nums[i])
            {
                answer[i] = max(answer[i], answer[j]+1);
                final_answer = max(final_answer, answer[i]);
            }
        }
    }
    return final_answer;
}

int main()
{
    return 0;
}
