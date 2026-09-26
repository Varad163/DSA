class Solution {
public:

    int solve(string &s,int &i){
        long long ans = 0;
        int sign=1;

        while(i<s.size()){

            if(s[i]==' '){
                i++;
            }
            else if(isdigit(s[i])){

                long long num=0;

                while(i < s.size() && isdigit(s[i])) {
                    num=num*10+(s[i]-'0');
                    i++;
                }

                ans+=sign*num;
            }
            else if(s[i]=='+'){
                sign=1;
                i++;
            

            }
            else if(s[i] == '-') {
                sign = -1;
                i++;
            }

            else if(s[i] == '(') {
                i++;

                int num = solve(s, i);

                ans += sign * num;
            }

                else if(s[i] == ')') {
                i++;
                return ans;
            }
        }
        return ans;
    }
    int calculate(string s) {
        int i=0;
        return solve(s,i);
    }
};