class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minNum = INT_MAX, minOdd=INT_MAX;
        for(int i:nums1){
            minNum=min(minNum, i);
            if(i%2!=0) minOdd = min(minOdd, i);
        }
        if(minNum%2!=0 || minOdd==INT_MAX) return true;
        return false;
    }
};