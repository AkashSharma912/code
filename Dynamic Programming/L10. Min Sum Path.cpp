X-------------------------------X-------------------------------------X-

RECURSION
class Solution {
public: 
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        return f(n-1,m-1,grid);
    }
    int f(int i, int j , vector<vector<int>>& a)
    {
        if(i ==0 && j==0)
        return a[i][j];

        if(i<0 || j<0)
        return 1e9;

        int up = a[i][j] + f(i-1,j,a);
        int left= a[i][j] + f(i,j-1,a);

        return min(up,left);
    }
};



X=========================X================================================X===========

MEMOIZATION

class Solution {
public: 
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return f(n-1,m-1,grid,dp);
    }
    int f(int i, int j , vector<vector<int>>& a,vector<vector<int>> &dp)
    {
        if(i ==0 && j==0)
        return a[i][j];

        if(i<0 || j<0)
        return 1e9;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int up = a[i][j] + f(i-1,j,a,dp);
        int left= a[i][j] + f(i,j-1,a,dp);

        return dp[i][j]=min(up,left);
    }
};

x-------------------------x-------------------------------x

TABULATI0N

class Solution {
public: 
    int minPathSum(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i =0 ;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 & j==0)
                dp[i][j]=a[0][0];
                else 
                {
                    int up=a[i][j];
                    if(i>0)
                     up +=dp[i-1][j];
                    else
                    up+=1e9;
                    int left = a[i][j] ;
                   if(j>0) left+= dp[i][j-1];
                   else
                   left+=1e9;


                   dp[i][j] = min(up,left);

                }
            }
        }
        
        return dp[n-1][m-1];
    }
};

X-----------------------------------------------X-------------------------------------X-

// recursion
class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
         vector<int> prev(m,0);
         for(int i=0;i<=n-1;i++){
             vector<int>curr(m,0);
             for(int j=0;j<=m-1;j++){
                 if(i==0 and j==0)curr[0]=grid[0][0];
                else{
                 int up=grid[i][j];
                 int left=grid[i][j];
                 if(i>0)up+=prev[j];
                 else up+=1e9;
                 if(j>0) left+=curr[j-1];
                 else left+=1e9;
                 curr[j]=min(up,left);
                }
             }
             prev=curr;
         }
         return prev[m-1];
    }
};