class Solution {
public:
    string ans="";

    void solve(vector<int>& arr,vector<int>& temp,vector<bool>& used){
        if(temp.size()==4){
            int hour=temp[0]*10+temp[1];
            int minute=temp[2]*10+temp[3];

            if(hour<24 && minute<60){
                string time=(hour<10 ? "0" : "")+to_string(hour)+":"+
                            (minute<10 ? "0" : "")+to_string(minute);

                if(ans=="" || time>ans)
                    ans=time;
            }
            return;
        }

        for(int i=0;i<4;i++){
            if(!used[i]){
                used[i]=true;
                temp.push_back(arr[i]);

                solve(arr,temp,used);

                temp.pop_back();
                used[i]=false;
            }
        }
    }

    string largestTimeFromDigits(vector<int>& arr){
        vector<int> temp;
        vector<bool> used(4,false);

        solve(arr,temp,used);

        return ans;
    }
};