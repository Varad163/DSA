#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(string &s, string current, int index, vector<string> &result)
{
    if (index == s.length())
    {
        result.push_back(current);
        return;
    }

    // Exclude the current character
    generateSubsets(s, current, index + 1, result);

    // Include the current character.//--00
    generateSubsets(s, current + s[index], index + 1, result);
}

int main()
{
    string s = "abc";
    vector<string> subsets;

    generateSubsets(s, "", 0, subsets);

    // Print all subsets
    for (const string &subset : subsets)
    {
        cout << "\"" << subset << "\" ";
    }

    return 0;
}
