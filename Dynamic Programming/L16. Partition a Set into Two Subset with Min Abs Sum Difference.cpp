class Solution {
public:
    int minimumDifference(vector<int>& arr) {
        int totSum= 0;

        for(int i =0;i<arr.size();i++)
        {
            totSum +=arr[i];
        }


        int k = totSum;

        vector<vector<bool>> dp(arr.size(),vector<bool>(k+1,0));
        for(int i =0;i<arr.size();i++)
        {
            dp[i][0]=true;
        }

        if(arr[0]<=k)
        dp[0][arr[0]]=true;

        for(int ind= 1;ind<arr.size();ind++)
        {
            for(int target=1;target<=k;target++)
            {
                bool notTake = dp[ind-1][target];
                bool take    = false;
                if(arr[ind]<=target)
                take=dp[ind-1][target-arr[ind]];
                dp[ind][target]=take | notTake;
            }
            
        }

        int mini = 1e7;

        for(int s1 =0;s1<=totSum/2 ;s1++)
        {
            if(dp[arr.size()-1][s1]==true)
            {
                mini = min(mini, abs((totSum-s1) -s1 ));
            }
        }

    return mini; 

    }
};