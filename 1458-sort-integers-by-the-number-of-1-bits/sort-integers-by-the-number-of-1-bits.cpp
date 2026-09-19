class Solution {
public:
int countBits(int n){
            int cnt=0;

            while(n>0){
                if(n%2==1)
                    cnt++;
                n=n/2;
            }

            return cnt;
        }


    vector<int> sortByBits(vector<int>& arr) {

        sort(arr.begin(),arr.end(),[&](int a, int b){
            int counta=countBits(a);
            int countb=countBits(b);

            if(counta==countb)
                return a<b;
            
            
            return counta<countb;
            
            
            });

            return arr;
        

        
        
    }
};