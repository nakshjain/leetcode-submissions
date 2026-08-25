class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen;
        for(int i: nums) if(i%k==0) seen.insert(i);
        int multiple = 1;
        while(multiple<nums.size()+1 && seen.count(multiple*k)){
            multiple++;
        }
        return k*multiple;
    }
};