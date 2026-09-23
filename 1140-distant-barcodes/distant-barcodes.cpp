class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
     unordered_map<int,int> mp;

     for(int x:barcodes)
        mp[x]++;

        priority_queue<pair<int,int>>pq;

        for(auto x:mp){
            pq.push({x.second,x.first});

        }   

        vector<int> ans;

        while(!pq.empty()){
            auto [cnt,num]=pq.top();

            pq.pop();

            if(ans.empty() || ans.back()!=num){
                ans.push_back(num);
                cnt--;

                if(cnt>0)
                    pq.push({cnt,num});
                

            }else{
                auto[cnt2,num2]=pq.top();
                pq.pop();

                ans.push_back(num2);
                cnt2--;

                if(cnt>0)
                pq.push({cnt,num});

                if(cnt2>0)
                pq.push({cnt2,num2});
            }


        }
        return ans;
    }
};