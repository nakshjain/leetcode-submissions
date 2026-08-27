class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> seen = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<char> vowels;
        vector<int> indexes;
        for(int i=0;i<s.size();i++){
            if(seen.count(s[i])){
                vowels.push_back(s[i]);
                indexes.push_back(i);
            }
        }
        int n = vowels.size();
        for(int i=0;i<n;i++){
            s[indexes[i]]=vowels[n-i-1];
        }
        return s;
    }
};