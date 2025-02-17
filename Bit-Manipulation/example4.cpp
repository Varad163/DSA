#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[2] = {nullptr, nullptr};
};

class Trie
{
public:
    TrieNode *root;
    Trie() { root = new TrieNode(); }

    void insert(int num)
    {
        TrieNode *node = root;
        for (int i = 31; i >= 0; --i)
        {
            int bit = (num >> i) & 1;
            if (!node->children[bit])
                node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
    }

    int getMaxXOR(int num)
    {
        TrieNode *node = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; --i)
        {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;
            if (node->children[opposite])
            {
                maxXOR |= (1 << i);
                node = node->children[opposite];
            }
            else
            {
                node = node->children[bit];
            }
        }
        return maxXOR;
    }
};

int findMaximumXOR(vector<int> &nums)
{
    Trie trie;
    for (int num : nums)
        trie.insert(num);

    int maxXOR = 0;
    for (int num : nums)
    {
        maxXOR = max(maxXOR, trie.getMaxXOR(num));
    }
    return maxXOR;
}

int main()
{
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << "Maximum XOR: " << findMaximumXOR(nums) << endl;
    return 0;
}
