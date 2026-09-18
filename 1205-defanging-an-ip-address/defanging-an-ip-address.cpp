class Solution {
public:
    string defangIPaddr(string address) {
        string ans="";
        for( auto ch:address){
            if(ch=='.'){
                ans+="[.]";
                
            }else{
                ans=ans+ch;
            }
        }
        return ans;
    }
};