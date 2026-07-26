class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(ans, nums, tmp, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& ans, const vector<int>& nums, vector<int>& tmp, int index){
        ans.push_back(tmp);
        if(index==nums.size()){
            return;
        }
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]) continue;
            tmp.push_back(nums[i]);
            dfs(ans, nums, tmp, i+1);
            tmp.pop_back();
        }
    }
};