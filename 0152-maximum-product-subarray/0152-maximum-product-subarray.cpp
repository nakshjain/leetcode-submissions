class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<pair<int, int>> dp(nums.size());
        int maxProduct=nums[0], minProduct=nums[0];
        dp[0]={maxProduct, minProduct};
        for(int i=1;i<nums.size();i++){
            int oldMax = dp[i-1].first;
            int oldMin = dp[i-1].second;
            int curMax = max(nums[i], max(oldMax*nums[i], oldMin*nums[i]));
            int curMin = min(nums[i], min(oldMax*nums[i], oldMin*nums[i]));
            dp[i]={curMax, curMin};
            maxProduct = max(maxProduct, curMax);
        }
        return maxProduct;
    }
};