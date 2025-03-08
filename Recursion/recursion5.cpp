#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<string, vector<string>> memo;

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return dfs(s, wordSet);
    }

    vector<string> dfs(string s, unordered_set<string> &wordSet)
    {
        if (memo.find(s) != memo.end())
            return memo[s];
        if (s.empty())
            return {""};

        vector<string> res;
        for (int i = 1; i <= s.size(); i++)
        {
            string prefix = s.substr(0, i);
            if (wordSet.count(prefix))
            {
                vector<string> rest = dfs(s.substr(i), wordSet);
                for (string sentence : rest)
                {
                    res.push_back(prefix + (sentence.empty() ? "" : " " + sentence));
                }
            }
        }
        return memo[s] = res;
    }
};
