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

int main()
{
    // creation of root node
    TrieNode *root = new TrieNode('-');

    insertValue(root, "CATER");
    insertValue(root, "CARE");
    insertValue(root, "COM");
    insertValue(root, "CATER");
    insertValue(root, "LOVER");
    insertValue(root, "LOVED");
    insertValue(root, "LOAD");
    insertValue(root, "LOV");
    insertValue(root, "BAT");
    insertValue(root, "CAT");
    insertValue(root, "CAR");

    cout<<"Insertion Completed"<<endl;

    deleteString(root , "COM");

    bool searchAns  = searchingStr(root, "COM");

    cout << endl
         << "insertion done!!!!" << endl;

    if(searchAns)
    {
        cout<<"the string is found"<<endl;
    }
    else
    {
        cout<<"the string is not found"<<endl;
    }
}