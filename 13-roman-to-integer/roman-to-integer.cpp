class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> table = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            if (i + 1 < s.length() && s[i] == 'I' && s[i + 1] == 'V') {
                ans += 4;
                i++;
            }
            else if (i + 1 < s.length() && s[i] == 'I' && s[i + 1] == 'X') {
                ans += 9;
                i++;
            }
            else if (i + 1 < s.length() && s[i] == 'X' && s[i + 1] == 'L') {
                ans += 40;
                i++;
            }
            else if (i + 1 < s.length() && s[i] == 'X' && s[i + 1] == 'C') {
                ans += 90;
                i++;
            }
            else if (i + 1 < s.length() && s[i] == 'C' && s[i + 1] == 'D') {
                ans += 400;
                i++;
            }
            else if (i + 1 < s.length() && s[i] == 'C' && s[i + 1] == 'M') {
                ans += 900;
                i++;
            }
            else {
                ans += table[s[i]];
            }
        }

        return ans;
    }
};