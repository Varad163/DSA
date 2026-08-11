class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> table;

        for(string word:words){
            table[word]++;

        }

        vector<string> v;

        for(auto it:table){
            v.push_back(it.first);

        }

        sort(v.begin(),v.end(),[&](string a,string b){
            if(table[a]!=table[b]){
                return table[a]>table[b];
            }
            return a<b;
        });

        vector<string> ans;

        for(int i=0;i<k;i++){
            ans.push_back(v[i]);
        }

        return ans;



    }
};