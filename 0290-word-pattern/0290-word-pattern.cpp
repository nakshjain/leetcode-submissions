class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToS;
        unordered_map<string, char> sToChar;
        int cur=0;
        for(char c: pattern){
            if(cur>=s.size()) return false;
            int size=1;
            while(cur+size<=s.size() && s[cur+size]!=' '){
                size++;
            }
            string tmp =s.substr(cur, size);
            if((charToS.count(c) && charToS[c]!=tmp) || (sToChar.count(tmp) && sToChar[tmp]!=c)) return false;
            charToS[c]=tmp;
            sToChar[tmp]=c;
            cur=cur+size+1;
        }
        return cur>=s.size();
    }
};