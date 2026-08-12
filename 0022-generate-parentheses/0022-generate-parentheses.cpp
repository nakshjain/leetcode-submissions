class Solution {
private:
    int open=0;
    int close=0;
    void dfs(vector<string>& ans, string& cur, int n){
        if(cur.size()==2*n){
            ans.push_back(cur);
            return;
        }
        if(open<n){
            cur.push_back('(');
            open++;
            dfs(ans, cur, n);
            cur.pop_back();
            open--;
        }
        if(close<open){
            cur.push_back(')');
            close++;
            dfs(ans, cur, n);
            cur.pop_back();
            close--;
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur="";
        dfs(ans, cur, n);
        return ans;
    }
};