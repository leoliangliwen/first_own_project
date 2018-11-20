#include <queue>          // std::queue
#include <stack>  
#include <vector>  
#include <map>  
#include <set>  
#include <iostream>  
#include <algorithm>  
#include <math.h>
using namespace std;


struct Node
{
    bool isWord = false;
    int count = 0;
    vector<Node*> children = vector<Node*>(26, NULL);
};

void printTrie(Node* root, string path)
{
    if (!root)
        return;
    if (root->isWord)
        cout << "<"<< path << ">" << endl;
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i])
        {
            char c = 'a' + i;
            printTrie(root->children[i], path+c);
        }
    }

}

class Trie
{
    Node* root;
public:
    Trie()
    {
        root = new Node;
    }
    
    void print()
    {
        printTrie(root, "");
    }


    bool findWord(string s) 
    {
        Node * curr = root;
        for (int i = 0; i < s.size(); i++)
        {
            int childIndex = s[i] - 'a';
            if (!curr->children[childIndex])
            {
                return false;
            }
            curr = curr->children[childIndex];
        }

        return curr->isWord;
    }

    void insertWord(string s) 
    {
        if (findWord(s))
            return;

        Node * curr = root;
        for (int i = 0; i < s.size(); i++)
        {
            int childIndex = s[i] - 'a';
            if (!curr->children[childIndex])
            {
                // create new node;
                curr->children[childIndex] = new Node;
            }
            curr->children[childIndex]->count++;
            curr = curr->children[childIndex];
        }
        curr->isWord = true;
    }

    void deleteWord(string s)
    {
        if (findWord(s))
        {
            Node * curr = root;
            for (int i = 0; i < s.size(); i++)
            {
                Node* toDelete;
                int childIndex = s[i] - 'a';
                if (!curr->children[childIndex])
                    return;
                if (curr->children[childIndex]->count == 1)
                    toDelete = curr;
                curr->children[childIndex]->count--;
                curr = curr->children[childIndex];
                if (toDelete)
                    delete toDelete;
            }

        }
    }

    void findPrefixHelper( Node* curr, string path, vector<string>& answer)
    {
        if (!curr)
            return;
        if (curr->isWord)
            answer.push_back(path);
        for (int i = 0; i < 26; i++)
        {
            if (curr->children[i])
            {
                char c = 'a' + i;
                printTrie(curr->children[i], path+c);
            }
        }
    }


    vector<string> findPrefix(string target)
    {
        vector<string> answer;
        
        Node * curr = root;
        for (int i = 0; i < target.size(); i++)
        {
            int childIndex = target[i] - 'a';
            if (!curr->children[childIndex])
            {
                return answer;
            }
            else
                curr = curr->children[childIndex];
        }

        findPrefixHelper(curr, target, answer);  
        return answer;
    }


    void findRegexHelper(Node* curr, string target, string path, vector<string>& answer)
    {
        if (!curr )
            return;
        if ( target.size() == 0 )
        {
            if (curr->isWord)
                answer.push_back(path);
            return;
        }    

        char c = target[0];
        string nextTarget = target;
        nextTarget.erase(0,1);
        if ('a' <= c && c <= 'z')
        {
            int childIndex = c - 'a';
            if (curr->children[childIndex])
                findRegexHelper(curr->children[childIndex], nextTarget, path+c, answer);
        }
        else if (c == '?')
        {
            for (int i = 0; i < 26; i++)
            {
                if (curr->children[i])
                {
                    char c = 'a' + i;
                    findRegexHelper(curr->children[i], nextTarget, path+c, answer);
                }
            }
        }
        else if (c == '*')
        {
            // * represent 0 char
            findRegexHelper(curr, nextTarget, path, answer);

            for (int i = 0; i < 26; i++)
            {
                if (curr->children[i])
                {
                    char c = 'a' + i;

                    // * represent only 1 char, delete * in next subsearch
                    //findRegexHelper(curr->children[i], nextTarget, path+c, answer);

                    // * represent more than 1 char, keep * in next subsearch
                    findRegexHelper(curr->children[i], target, path+c, answer);
                }
            }
        }

    }
    vector<string> findRegex(string target)
    {
        vector<string> answer;
        findRegexHelper(root, target, "", answer);
        return answer;
    }

};


int main()
{
    Trie t;
    t.insertWord("at");
    t.insertWord("app");
    t.insertWord("apple");
    t.insertWord("cpa");
    t.insertWord("capa");
    t.insertWord("cbpda");
    t.insertWord("cpwa");
    t.insertWord("crpba");
    t.insertWord("cathy");
    t.insertWord("dog");
    //cout << t.findWord("ab");
    //cout << t.findWord("a");
    //cout << t.findWord("abc");
    //t.print();
    vector<string> answer = t.findRegex("c*p*a");
    cout << "==========" << endl;
    for (auto i : answer)
        cout << i << endl;
    return 0;
}
