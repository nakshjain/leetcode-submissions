class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> cMp;
        unordered_map<string, char> sMp;
        int cur=0;
        for(char c: pattern){
            if(cur>=s.size()) return false;
            int start=cur;
            while(cur<s.size() && s[cur]!=' '){
                cur++;
            }
            string tmp = s.substr(start, cur-start);
            if(cMp.count(c) && cMp[c]!=tmp) return false;
            if(sMp.count(tmp) && sMp[tmp]!=c) return false;
            cMp[c]=tmp;
            sMp[tmp]=c;
            cur++;
        }
        return cur>=s.size();
    }
};