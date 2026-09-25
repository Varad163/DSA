class Solution {
public:


    set<string> solve(string &s, int &i){

        set<string> ans;
        set<string> cur;
        cur.insert("");

        while(i<s.size() && s[i]!='}'){
            if(s[i]==','){
                for(auto x:cur)
                    ans.insert(x);

                cur.clear();
                cur.insert("");
                i++;

            }else{
                set<string> temp;

                if(s[i]=='{'){
                    i++;
                    temp=solve(s,i);
                    i++;
                }
                else{
                    temp.insert(string(1,s[i]));
                    i++;
                }
                set<string> next;

                for(auto a:cur){
                    for(auto b:temp){
                        next.insert(a+b);
                    }
                }
                cur=next;
            }
        }
        for(auto x:cur)
            ans.insert(x);
        
        return ans;
    }
    vector<string> braceExpansionII(string expression) {
        int i=0;

        set<string> st=solve(expression,i);
        return vector<string>(st.begin(),st.end());
    }
};