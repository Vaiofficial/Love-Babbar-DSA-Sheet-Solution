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
    cout<<"recieved string :"<<str<<" for insertion"<<endl;

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

int main()
{
    // creation of root node
    TrieNode *root = new TrieNode('-');

    insertValue(root , "DONATION");

    return 0;
}