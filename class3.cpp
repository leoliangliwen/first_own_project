#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

// ******************** Class 2 Binary Tree & Divide Conquer *******************
// ******************** Class 2 Binary Tree & Divide Conquer *******************
// ******************** Class 2 Binary Tree & Divide Conquer *******************

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

// Binary Tree Preorder Traversal
// http://www.lintcode.com/en/problem/binary-tree-preorder-traversal/#
// Divide & Conquer
vector<int> preorderTraversal1(TreeNode *root) {
    vector<int> answer;
    if (root == NULL) return answer;

    answer.push_back(root->val);
    if (root->left != NULL) {
        vector<int> answer_left = preorderTraversal1(root->left);
        answer.insert(answer.end(), answer_left.begin(), answer_left.end());
    }
    if (root->right != NULL) {
        vector<int> answer_right = preorderTraversal1(root->right);
        answer.insert(answer.end(), answer_right.begin(), answer_right.end());
    }

    return answer;
}
// Traverse
void preorderTraversal_helper(TreeNode *root, vector<int> &answer) {
    if (root == NULL) return;

    answer.push_back(root->val);
    preorderTraversal_helper(root->left, answer);
    preorderTraversal_helper(root->right, answer);
}

vector<int> preorderTraversal2(TreeNode *root) {

    vector<int> answer;
    if (root == NULL) return answer;
    preorderTraversal_helper(root, answer);
    return answer;
}

// Binary Tree Inorder Traversal
// http://www.lintcode.com/en/problem/binary-tree-inorder-traversal/
// Binary Tree Postorder Traversal
// http://www.lintcode.com/en/problem/binary-tree-postorder-traversal/

// Maximum Depth of Binary Tree
// http://www.lintcode.com/en/problem/maximum-depth-of-binary-tree/
int maxDepth(TreeNode *root) {
    if (root == NULL) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
}
// Minimum Depth of Binary Tree
// http://www.lintcode.com/en/problem/minimum-depth-of-binary-tree/
int minDepth_help(TreeNode *root) {
    if (root == NULL) return INT_MAX;
    if (root->left == NULL && root->right == NULL) return 1;

    int left = minDepth_help(root->left);
    int right = minDepth_help(root->right);
    return min(left, right) + 1;
}
int minDepth(TreeNode *root) {
    if (root == NULL) return 0;
    return minDepth_help(root);
}

//  Balanced Binary Tree
// http://www.lintcode.com/en/problem/balanced-binary-tree/
int isBalanced_helper (TreeNode *root)  // return the depth of the tree if balanced, -1 for not balanced
{
    if (root == NULL) return 0;

    int left = isBalanced_helper(root->left);
    int right = isBalanced_helper(root->right);

    if (left == -1 || right == -1 || abs(left - right) > 1) return -1;
    return max(left, right) + 1;
}

bool isBalanced(TreeNode *root) {
    return isBalanced_helper(root) != -1;
}

// Lowest Common Ancestor
// http://www.lintcode.com/en/problem/lowest-common-ancestor/
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
    if (root == NULL || root == A || root == B) return root;

    TreeNode * left = lowestCommonAncestor(root->left, A, B);
    TreeNode * right = lowestCommonAncestor(root->right, A, B);

    if (left != NULL && right != NULL) return root;
    if (left != NULL) return left;
    if (right != NULL) return right;
    return NULL;
}

// Validate Binary Search Tree
// http://www.lintcode.com/en/problem/validate-binary-search-tree/#
struct ResultType {
    bool is_balance;
    int max_val;
    int min_val;
};

ResultType isValidBST_helper(TreeNode *root) {
    ResultType answer{true, INT_MIN, INT_MAX };
    if (root == NULL) return answer;

    ResultType left_answer = isValidBST_helper(root->left);
    ResultType right_answer = isValidBST_helper(root->right);

    if (!left_answer.is_balance || !right_answer.is_balance ||
        (root->left != NULL && left_answer.max_val >= root->val) ||
        (root->right != NULL && right_answer.min_val <= root->val)) {
        answer.is_balance = false;
        return answer;
    }
    else {
        answer.max_val = max(root->val, right_answer.max_val);
        answer.min_val = min(root->val, left_answer.min_val);
        return answer;
    }
}

bool isValidBST(TreeNode *root) {
    return isValidBST_helper(root).is_balance;
}

// Binary Tree Level Order Traversal
// http://www.lintcode.com/en/problem/binary-tree-level-order-traversal/
#include <queue>
vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> answer;
    if (root == NULL) return answer;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> a_level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *head = q.front();
            q.pop();
            a_level.push_back(head->val);
            if (head->left != NULL) q.push(head->left);
            if (head->right != NULL) q.push(head->right);
        }
        answer.push_back(a_level);
    }
    return answer;
}

// Binary Tree Maximum Path Sum
// http://www.lintcode.com/en/problem/binary-tree-maximum-path-sum/
struct ResultType1 {
    int max_to_parent;
    int max_within_node;
};

ResultType1 maxPathSumHelper(TreeNode *root)
{
    ResultType1 answer {0, INT_MIN};
    if (root == NULL) return answer;

    ResultType1 left_answer = maxPathSumHelper(root->left);
    ResultType1 right_answer = maxPathSumHelper(root->right);

    int max_to_parent = max(left_answer.max_to_parent, right_answer.max_to_parent) + root->val;
    answer.max_to_parent = max(max_to_parent, 0);           // if less than 0, return 0

    int max_within_node = left_answer.max_to_parent + right_answer.max_to_parent + root->val;
    max_within_node = max(max_within_node, left_answer.max_within_node);
    max_within_node = max(max_within_node, right_answer.max_within_node);
    answer.max_within_node = max_within_node;
    return answer;
}

int maxPathSum(TreeNode *root) {
    return maxPathSumHelper(root).max_within_node;
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


    return 0;
}
