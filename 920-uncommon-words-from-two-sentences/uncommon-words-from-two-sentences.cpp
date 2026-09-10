class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>mp;
        vector<string> ans;

        stringstream ss1(s1);
        string word;


        while(ss1>>word)
        mp[word]++;

        stringstream ss2(s2);
        
        while(ss2>>word){
            mp[word]++;

        }

        for(auto x:mp){
            if(x.second==1)
                ans.push_back(x.first);
        }
        return ans;
    }
};