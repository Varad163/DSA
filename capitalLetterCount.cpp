#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int n = word.size();
        int capitalCount = 0;

        // Count the number of uppercase letters///././././
        for (char ch : word)
        {
            if (isupper(ch))
            {
                capitalCount++;
            }
        }

        // Check valid cases
        if (capitalCount == n)
        {
            // All letters are capitals
            return true;
        }
        else if (capitalCount == 0)
        {
            // All letters are not capitals
            return true;
        }
        else if (capitalCount == 1 && isupper(word[0]))
        {
            // Only the first letter is capital
            return true;
        }

        return false; // Invalid usage of capitals
    }
};