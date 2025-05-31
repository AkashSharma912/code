MEMOIZATION


class Solution {
public:

    int f(vector<vector<int>>&a ,int n, int i ,int j,vector<vector<int>>& dp)
    {
        if(i==n-1)
         return a[i][j];

         if(j<0 || j>n-1)
         return 1e9;

         if(dp[i][j]!=-1)
         return dp[i][j];

        int down       = a[i][j] + f(a,n,i+1,j,dp);
    int left_dia = (j - 1 >= 0) ? a[i][j] + f(a, n, i + 1, j - 1, dp) : 1e9;
    int right_dia = (j + 1 < n) ? a[i][j] + f(a, n, i + 1, j + 1, dp) : 1e9;

        return dp[i][j]=min(down,min(left_dia,right_dia));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<int>ans(n,0);int min_ans=INT_MAX;
        for(int j =0;j<n;j++)
        {
         ans[j]=f(matrix,n,0,j,dp);
         
         min_ans = min(ans[j],min_ans);
        }

        return min_ans;
        
    }
};




X------------------------------------------X------------------------------------------X



TABULATION



class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            dp[0][j] = a[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int down = a[i][j] + dp[i - 1][j];
                int left_dia = (j - 1 >= 0) ? a[i][j] + dp[i - 1][j - 1] : 1e9;
                int right_dia = (j + 1 < n) ? a[i][j] + dp[i - 1][j + 1] : 1e9;

                dp[i][j] = min(down, min(left_dia, right_dia));
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[n - 1][j]);
        }

        return ans;
    }
};






