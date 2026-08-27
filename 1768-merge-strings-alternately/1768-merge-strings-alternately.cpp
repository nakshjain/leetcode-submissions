class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0, j=0;
        bool swap=true;
        string s="";
        while(i<word1.size() && j<word2.size()){
            if(swap){
                s+=word1[i];
                i++;
            } else {
                s+=word2[j];
                j++;
            }
            swap=!swap;
        }
        while(i<word1.size()){
            s+=word1[i];
            i++;
        }
        while(j<word2.size()){
            s+=word2[j];
            j++;
        }
        return s;
    }
};