#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char value;
    // array of pointers
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char val)
    {
        this->value = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insertValue(TrieNode *root, string str)
{
    cout << "recieved string :" << str << " for insertion" << endl;

    if (str.length() == 0)
    {
        // so terminal mark kardo.
        root->isTerminal = true;
        return;
    }

    char ch = str[0];
    int index = ch - 'a';
    TrieNode *child;

    if (root->children[index] != NULL)
    {
        // it means present
        child = root->children[index];
    }
    else
    {
        // it means absent
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // ak hum kar diye baki recursion karenge , so yha starting index hogya so next index that is 1 se leakar last tk lere.
    insertValue(root, str.substr(1));
}

bool searchingStr(TrieNode *root, string str)
{
    if (str.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = str[0];
    int index = ch - 'a';
    TrieNode *child;

    if (root->children[index] != NULL)
    {
        // present or found hai.
        child = root->children[index];
    }
    else
    {
        // not found
        return false;
    }
    // baki recursion samhaal lega bhai

    return searchingStr(child, str.substr(1));
}

void deleteString(TrieNode *root, string str)
{
    if (str.length() == 0)
    {
        root->isTerminal = false;
        return;
    }

    // ak case solve karunga baki , recursion samhaal lega bhai.

    char ch = str[0];
    int index = ch - 'a';
    TrieNode *child;

    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // mila hi nahi so return karo
        return;
    }
    // recursion call kardo bhai.
    deleteString(child, str.substr(1));
}

void storeString(TrieNode *root, vector<string> &ans, string &input, string &prefix)
{
    // base case
    if (root->isTerminal == true)
    {
        ans.push_back(prefix + input);

        // return isliye nahi kiya kyuki aisa bhi ho skta hai , jis terminal mai hum khade hai uske niche bhi aur string ho skta h.
    }

    // check karna hai uske niche koi string present hai ya nahi.

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        int index = ch - 'a';
        TrieNode *next = root->children[index];
        if (next != NULL)
        {
            // means present
            input.push_back(ch);
            // baki recursion dekhega
            storeString(root, ans, input, prefix);
            // backtrack
            input.pop_back();
        }
    }
}

void findPrefixString(TrieNode *root, string input, vector<string> &ans, string &prefix)
{
    if (input.length() == 0)
    {
        // so humlog ko input string ke last character tk traverse karna hoga.
        TrieNode *lastChar = root;
        storeString(lastChar, ans, input, prefix);
        return;
    }
    char ch = input[0];
    int index = ch - 'a';
    TrieNode *child;

    if (root->children[index] != NULL)
    {
        // it means child is present
        child = root->children[index];
    }
    else
    {
        return;
    }

    // recursive call
    // so yaha humne child ko nayaa root banaya hai.
    findPrefixString(child, input.substr(1), ans, prefix);
}

vector<vector<string>> getSuggestions(TrieNode *root, string input)
{
    vector<vector<string >> output;
    TrieNode *prev = root;
    string inputHelper = "";

    for (int i = 0; i < input.length(); i++)
    {
        char lastChar = input[i];
        int index = lastChar - 'a';
        TrieNode *curr = prev->children[index];

        if (curr == NULL)
        {
            // means present hi nahi hai character aaage.
            break;
        }
        else
        {
            vector<string> nicheKaAns;
            inputHelper.push_back(lastChar);
            string dummy = "";
            storeString(curr, nicheKaAns, inputHelper, dummy);
            output.push_back(nicheKaAns);
            // important
            prev = curr;
        }
    }

    return output;
}

int main()
{
    // creation of root node
    TrieNode *root = new TrieNode('-');

    insertValue(root, "cater");
    insertValue(root, "care");
    insertValue(root, "com");
    insertValue(root, "lover");
    insertValue(root, "loved");
    insertValue(root, "load");
    insertValue(root, "lov");
    insertValue(root, "bat");
    insertValue(root, "cat");
    insertValue(root, "car");

    // string input = "C";
    // string prefix = input;
    // vector<string> ans;

    // // calling the find function
    // findPrefixString(root, input, ans, prefix);

    // for (auto i : ans)
    // {
    //     cout << i << " ";
    // }

    // getSuggestion question type 2

    vector<vector<string>> ans = getSuggestions(root, "loa");

    for (int i = 0; i < ans.size(); i++)
    {
        cout << i << " ";

        for (auto str : ans[i])
        {
            cout << str << ", ";
        }
        cout << endl;
    }
}