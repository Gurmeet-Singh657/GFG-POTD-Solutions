#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    bool ContainsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    void set(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void Insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->ContainsKey(word[i]))
            {
                node->set(word[i], new Node());
            }
            node = node->get(word[i]);
        }
    }
    bool Search(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->ContainsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }
};
int prefixSuffixString(vector<string> &s1, vector<string> s2)
{
    Trie trie;
    for (auto it : s1)
    {
        trie.Insert(it);
        reverse(it.begin(), it.end());
        trie.Insert(it);
    }
    int count = 0;
    for (auto it : s2)
    {
        string rev = it;
        reverse(rev.begin(), rev.end());
        if (trie.Search(it) || trie.Search(rev))
        {
            count++;
        }
    }
    return count;
}