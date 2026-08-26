class Solution {
private:
    vector<vector<int>> dp;
    int dfs(int target, vector<int>& coins, int curr){
        if(target==0){
            return 1;
        }
        if(dp[target][curr]!=-1) return dp[target][curr];
        int ways = 0;
        for(int i=curr;i<coins.size();i++){
            if(coins[i]<=target) 
                ways+=dfs(target-coins[i], coins, i);
        }
        return dp[target][curr]=ways;
    }

public:
    int change(int amount, vector<int>& coins) {
        dp = vector<vector<int>>(amount+1, vector<int>(coins.size(), -1));
        return dfs(amount, coins, 0);
    }
};