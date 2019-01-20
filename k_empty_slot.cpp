class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {

        ///////////////////////////////////////////////////////////////////////
        // for timely process, we need to know 
        // if there is a flower already bloomed have distince K
        ///////////////////////////////////////////////////////////////////////

        // Set(Balance Tree) nlgn
        /*
        set<int> bloom;
        for (int i = 0; i < flowers.size(); i++) {
            int index = flowers[i];
            auto it = bloom.insert(index).first;
            
            if (it != bloom.begin()) {
                it--;
                if (*it == index - k - 1)
                    return i+1;
                it++;
                
            }
            it++;
            if (it != bloom.end()) {
                if (*it == index + k + 1)
                    return i+1;
            }
        }
        return -1;
        */


        // Binary Index Tree
        /*
        class BinaryIndexTree {
            vector<int> bit;
            vector<int> num;
            int lowbit(int x) { 
                return x & (~x+1); 
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
        
        BinaryIndexTree bit(flowers.size());
        unordered_set<int> bloom;
        for (int i = 0; i < flowers.size(); i++) {
            int index = flowers[i] - 1;
            bloom.insert(index);
            bit.update(index, 1);

            if (bloom.find(index-k-1) != bloom.end() &&
                bit.firstXSum(index) == 1 + bit.firstXSum(index - k - 1))
                return i+1;

            if (bloom.find(index+k+1) != bloom.end() &&
                1 + bit.firstXSum(index) == bit.firstXSum(index + k + 1))
                return i+1;
        }
        return -1;
        */

        ///////////////////////////////////////////////////////////////////////
        // For space process, we need to know if
        // there is flower bloom before one and one's neighbour
        ///////////////////////////////////////////////////////////////////////

        // priority queue O(nlgn)
        /*
        struct Node {
            int position;
            int day;
            Node(int pIn, int dIn) : position(pIn), day(dIn){}
        };
        struct NodeComparator {
            bool operator() (const Node& lhs, const Node& rhs) {
                return lhs.day > rhs.day;
            }
        };
        priority_queue<Node, vector<Node>, NodeComparator> pq;
        
        vector<int> days(flowers.size());
        for (int i = 0; i < flowers.size(); i++) {
            days[flowers[i]-1] = i+1;
        }
        
        int answer = INT_MAX;
        priority_queue<Node, vector<Node>, NodeComparator> pq;
        for (int i = 0; i < days.size(); i++) {
            if (i-k-1 >= 0) {
                int day = max(days[i], days[i-k-1]);
                while(!pq.empty() && 
                      (pq.top().index <= i-k-1))
                      pq.pop();
                if (pq.empty() || pq.top().day  > day) {
                    answer = min(answer, day);
                }
            }
            Node node(i, days[i]);
            pq.push(node);
        }
        return answer == INT_MAX ? -1 : answer;
        */
        
        // dequeue O(n)
        /*
        struct Node {
            int position;
            int day;
            Node(int pIn, int dIn) : position(pIn), day(dIn){}
        };

        vector<int> days(flowers.size());
        for (int i = 0; i < flowers.size(); i++) {
            days[flowers[i]-1] = i+1;
        }
        
        int answer = INT_MAX;
        deque<Node> dq;
        for (int i = 0; i < days.size(); i++) {
            if (i-k-1 >= 0) {
                int day = max(days[i], days[i-k-1]);
                while(!dq.empty() && 
                      (dq.front().index <= i-k-1))
                      dq.pop_front();
                if (dq.empty() || dq.front().day  > day) {
                    answer = min(answer, day);
                }
            }
            Node node(i, days[i]);
            while(!dq.empty() && dq.back().day > days[i])
                dq.pop_back();
            dq.push_back(node);
        }
        return answer == INT_MAX ? -1 : answer;
        */
    }
};
