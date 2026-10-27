class Solution {
public:
    vector<string> createGrid(int m, int n) {
        char dot = '.';
        char hash = '#';
        vector<string> ans;
        while(m--){
            string s = ".";
            int tmp=n-1;
            while(tmp){
                tmp--;
                if(m) s+=hash;
                else s+=dot;
            }
            ans.push_back(s);
        }
        return ans;
    }
};