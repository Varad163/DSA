class Solution {
public:
        vector<int> ans;
        vector<int> path;
        vector<int> used;

    void solve(vector<int>& digits){
        
        
        if(path.size()==3){
            int num=path[0]*100+path[1]*10+path[2];
            ans.push_back(num);
            return;
        }

        for(int i=0;i<digits.size();i++){

            if(used[i]) continue;

            if(i>0 && digits[i]==digits[i-1] && !used[i-1])
                continue;
            
            if(path.size()==0 && digits[i]==0)
                continue;

            if(path.size()==2 && digits[i]%2!=0)
                continue;
            
            used[i]=1;
            path.push_back(digits[i]);
            solve(digits);
            path.pop_back();
            used[i]=0;
        }

    }


    vector<int> findEvenNumbers(vector<int>& digits) {

        sort(digits.begin(),digits.end());
        used.assign(digits.size(),0);

        solve(digits);

        sort(ans.begin(),ans.end());

        return ans;
        
    }
};