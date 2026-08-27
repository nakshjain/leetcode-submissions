class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0, removed=0;
        string ans="";
        for(char c: s){
            if(c=='('){
                if(removed==0){
                    removed++;
                    continue;
                }
                ans+=c;
                count++;
            } else {
                if(count){
                    ans+=c;
                    count--;
                } else {
                    removed--;
                    continue;
                }
            }
        }
        return ans;
    }
};