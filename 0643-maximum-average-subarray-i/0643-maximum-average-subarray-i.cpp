class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int tmp=k;
        long long sum = 0;
        while(tmp--){
            sum+=nums[tmp];
        }
        long long ans=sum;
        for(int i=k;i<nums.size();i++){
            sum-=nums[i-k];
            sum+=nums[i];
            ans=max(ans, sum);
        }
        return (double)ans/k;
    }
};