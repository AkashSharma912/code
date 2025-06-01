recursion

class Solution {
public:

    int f(int ind , int target ,vector<int>& a )
    {
        if(target == 0)
        return true;

        if(ind==0)
        return a[0]==target;

        int not_take = f(ind-1,target,a);
        int take = false;
        if(a[ind]<=target)
        {
            take =f(ind-1,target-a[ind],a);

        }
        return take || not_take;
    }

    int subarraySum(vector<int>& nums, int k) {
        
        return f(nums.size()-1,k,nums);
    }
};

x----------------------------------------------x---------------------------------------x

Memoization:


    int f(int ind, int target, vector<int>& a, vector<vector<int>>& dp) {
        if (target == 0)
            return true;

        if (dp[ind][target] != -1)
            return dp[ind][target];

        if (ind == 0)
            return a[0] == target;

        int not_take = f(ind - 1, target, a);
        int take = false;
        if (a[ind] <= target) {
            take = f(ind - 1, target - a[ind], a);
        }
        return dp[ind][target] = take || not_take;
    }


X-----------------------------------------------X--------------------------------------X

tabulation


    int subarraySum(vector<int>& nums, int k) {
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;

        for (int ind = 1; ind < num.size(); ind++) {
            for (int target = 1; target < nums.size(); target++) {

                int not_take = idp[ind - 1][target];
                int take = false;
                if (a[ind] <= target) {
                    take = dp[ind - 1][ target - a[ind]];
                }
                 dp[ind][target] = take || not_take;

            }
        }

        return dp[n-1][k];
    }


x--------------------------------x------------------------------------------------x






