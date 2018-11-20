#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;

class BinaryIndexTree {
    vector<int> bit;
    vector<int> num;

    int lowbit(int x) { 
        return x & (-x); 
    }

public:
    BinaryIndexTree(int n) {
        if (n <= 0)
            return;
        num.resize(n, 0);
        bit.resize(n+1, 0);
    }

    BinaryIndexTree(vector<int> nums) {
        if (nums.size() == 0)
            return;
        num = nums;
        bit.resize(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); i++) {
            update(i, nums[i]);
        }
        for (int i = 0; i < bit.size(); i++)
            cout << bit[i] << endl;
    }

    void print() {
        cout << "nums: ";
        for (auto i : num)
            cout << i << " ";
        cout << endl;
        cout << "bits: ";
        for (auto i : bit)
            cout << i << " ";
        cout << endl;
    }
    
    void update(int index, int val) {
        int delta = val - num[index];
        num[index] = val;
        index++;
        while(index < bit.size()) {
            bit[index] += delta;
            index += lowbit(index);
        }
    }
    
    int firstXSum(int index) {
        index++;
        int answer = 0;
        while(index > 0) {
            answer += bit[index];
            index -= lowbit(index);
        }
        return answer;
    }
};

class SegmentTree {
    struct Node {
        int value;
        pair<int, int> range;
        Node* left;
        Node* right;
        Node(int valueIn, pair<int, int> rangeIn)
            : value(valueIn), range(rangeIn), left(NULL), right(NULL){}
    };
    Node* root;
    vector<int> num;
public:
    SegmentTree(vector<int> nums) {
        if (nums.size() == 0)
            return;
        num = nums;
        root = buildTree(0, 0, nums.size()-1);
    }

    void update(int index, int val) {
        updateTree(root, index, val - num[index]);
        num[index] = val;

    }

    int sumRange(int i, int j) {
        return query(root, i, j);
    } 

    void print() {
        printHelper(root);
    }

private:
    Node* buildTree(int curr,
                   int start,
                   int end) {
        if (start > end)
            return NULL;
        else if (start == end) {
            Node* node = new Node(num[start], make_pair(start, end));
            return node;
        }
        else {
            int mid = (start + end) / 2;
            Node* left = buildTree(curr*2+1, start, mid);
            Node* right = buildTree(curr*2+2, mid+1, end);
            Node* node = new Node(0, make_pair(start, end));
            if (left) {
                node->value += left->value;
                node->left = left;
            }
            if (right) {
                node->value += right->value;
                node->right = right;
            }
            return node;
        } 
    }

    void printHelper(Node* curr) {
        if (!curr)
            return;
        cout << "value: " << curr->value << ", range:"<< curr->range.first << ","<< curr->range.second << endl;
        if (curr->left)
            printHelper(curr->left);
        if (curr->right)
            printHelper(curr->right);        
    }    

    void updateTree(Node* curr,
                    int index,
                    int delta) {
        if (!curr)
            return;
        if (curr->range.first == curr->range.second) {
            if (curr->range.first == index)
                curr->value += delta;
            return;
        }
        else if (index < curr->range.first || curr->range.second < index)
            return;
        else {
            curr->value += delta;
            int mid = (curr->range.first + curr->range.second) / 2;
            if (index <= mid)
                updateTree(curr->left, index, delta);
            else
                updateTree(curr->right, index, delta);            
        }
    }

    int query(Node* curr,
              int left, int right) {
        if (!curr)
            return 0;
        if (right < curr->range.first || curr->range.second < left)
            return 0;
        else if (left <= curr->range.first && curr->range.second <= right)
            return curr->value;
        else
            return query(curr->left, left, right) + query(curr->right, left, right);
    }    
};

int main()
{
    BinaryIndexTree bit(3);
    bit.update(0, 1);
    bit.update(1, 3);
    bit.update(2, 5);
    bit.print();
    cout << bit.firstXSum(0);
    cout << bit.firstXSum(1);
    cout << bit.firstXSum(2);

    /*
    SegmentTree st(vector<int>{1,3,5});
    st.print();
    cout << st.sumRange(0,2) << endl;
    cout << st.sumRange(0,1) << endl;
    cout << st.sumRange(1,2) << endl;
    cout << st.sumRange(2,2) << endl;
    */

    return 0;
}
