class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left=0, right=s.size()-1, leftFound=false, rightFound=false;
        while(left<right){
            if(leftFound && rightFound){
                char tmp = s[left];
                s[left]=s[right];
                s[right]=tmp;
                leftFound=false;
                rightFound=false;
                left++;
                right--;
                continue;
            }
            if(!leftFound){
                if(vowels.count(s[left])){
                    leftFound=true;
                } else left++;
            }
            if(!rightFound){
                if(vowels.count(s[right])){
                    rightFound=true;
                } else right--;
            }
        }
        return s;
    }
};