class Solution {
public:
    int f(int ind, int target, vector<int>& a, vector<vector<int>>& dp) {
        if (target == 0) return 1;
        if (ind == 0) return a[0] == target ? 1 : 0;
        if (dp[ind][target] != -1) return dp[ind][target];
        
        int not_take = f(ind - 1, target, a, dp);
        int take = 0;
        if (a[ind] <= target)
            take = f(ind - 1, target - a[ind], a, dp);
        
        return dp[ind][target] = take + not_take;
    }

    int subarraySum(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size(), vector<int>(k + 1, -1));
        return f(nums.size() - 1, k, nums, dp);
    }
};




Tabulation




class Solution {
public:
    int f(int ind, int target, vector<int>& a, vector<vector<int>>& dp) {
        if (target == 0) return 1;
        if (ind == 0) return a[0] == target ? 1 : 0;
        if (dp[ind][target] != -1) return dp[ind][target];
        
        int not_take = f(ind - 1, target, a, dp);
        int take = 0;
        if (a[ind] <= target)
            take = f(ind - 1, target - a[ind], a, dp);
        
        return dp[ind][target] = take + not_take;
    }

    int subarraySum(vector<int>& a, int k) {
        vector<vector<int>> dp(a.size(), vector<int>(k + 1, 0));
        
        for( int i =0;i<a.size();i++)
        {
            dp[i][0]=1;
        }

        if(a[0]<= k)
        {
            dp[0][a[0]]= 1;

        }



        for( int i =1 ; i<a.size();i++){
            for( int sum =0;sum<=k;sum++)
            {
                int not_take = dp[i - 1][sum];
                int take = 0;
                if (a[i] <= sum)
                  take = dp[i - 1][ sum - a[i]];

                dp[i][sum]= not_take + take;
        
            }
        }

        return dp[a.size()-1][k];
    }
};

