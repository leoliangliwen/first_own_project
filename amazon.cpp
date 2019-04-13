q. Identify all combinations where one words can be composed of two or more words of the same list, and print them. 
You are given a (potentially large) List of words. Some of these are compounds, where all parts are also in the List. 
Example List:

[arockstar, rock, star, rocks, tar, stars, rockstars, super, highway, high, way, superhighway, abc, a,b,c]

The task is to identify all combinations where one word is a composite of two or more words from the same 
list and print them.

Example:

rockstar -> rock + star 
superhighway -> super + highway 
superhighway -> super + high + way
highway -> high + way

abc -> a + b + c
(superhighway)                  (rockstart)
   /    \
(super) (highway)               
         /   \
     (high) (way)

struct TreeNode {
    string word;
    vector<TreeNode*> children;
};
{
    {rockstar}, {rock}, {start}
    {superhighway}, {super},{high},{way}
}

bool helper(const unordered_set<string>& s,
                      const string& word,
                      vector<string>& answer,
                      int index) {
    if (index = word.size()) {
        return;
    }

    int end = index             
    while(end != word.size()) {
        string temp = word.substr(index, end-index+1);
        if (s.find(temp) != s.end()) {
            answer.push_back(temp);
            helper(s, word, answer, end+1);
            answer.pop_back();
            end++;
        }
        else {
            end++;
        }
    }
    
}

vector<vector<string>> combinations(vector<stirng> words) {
    unordered_set<string> s(words.begin(), words.end());
    
    vector<vector<string>> answer;
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        vector<string> localAnswer = helper(s, word, 0);
        if (localAnswer.size() != 0)
            answer.push_back(localAnswer);
    }
    
    
    return answer;
}


