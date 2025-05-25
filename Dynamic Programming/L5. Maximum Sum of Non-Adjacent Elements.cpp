class Solution {
public:

#Memoization


    int fin( int n ,vector<int> & nums, vector<int> &dp)
    {
        if(n==0)
        return nums[n];

        if(n<0)
        return 0;

        if(dp[n]!=-1)
        return dp[n];

        int pick = nums[n] + fin(n-2,nums,dp) ;
        int not_pick = fin(n-1,nums,dp);

        return dp[n]= max(pick,not_pick);


    }




# Tabulation(top-down)
    
    int rob(vector<int>& a) {

        int n=a.size();
        vector<int> dp(n+1,-1);
    dp[0] = a[0];
    
    // Iterate through the elements of the array
    for (int i = 1; i < n; i++) {
        // Calculate the maximum value by either picking the current element
        // or not picking it (i.e., taking the maximum of dp[i-2] + arr[i] and dp[i-1])
        int pick = a[i];
        if (i > 1)
            pick += dp[i - 2];
        int nonPick = dp[i - 1];
        
        // Store the maximum value in the dp array
        dp[i] = max(pick, nonPick);
    }
    
    // The last element of the dp array will contain the maximum sum
    return dp[n - 1];



    }
// t.c - O(n)   s.c - O(n)

};

#Space Optimization


    int rob(vector<int>& a) 
{

    int prev = a[0],prev2=0,curi,pick,nonPick;
    
    for (int i = 1; i < a.size(); i++) {

        pick = a[i];
        if (i > 1)
            pick += prev2;
        nonPick = prev;
        
         curi = max(pick, nonPick);

        prev2=prev;
        prev=curi;
    }
    
    // The last element of the dp array will contain the maximum sum
    return prev;



    }