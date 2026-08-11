class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int>table;

        for(char c:moves){
            table[c]++;
        }

        if(table['U']==table['D'] && table['L']==table['R']){
            return true;
        }else{
            return false;
        }

    }
};