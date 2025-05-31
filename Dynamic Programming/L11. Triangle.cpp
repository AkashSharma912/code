X-------------------------------X-------------------------------------X-

RECURSION

class Solution {
public:

    int f(int i , int j , vector<vector<int>>& a,int n)
    {
        if(i==n-1)
        {
            return a[i][j];
        }
        int down = a[i][j] + f(i+1,j,a,n);
        int diag = a[i][j] + f(i+1,j+1,a,n);

        return min(down,diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        return f(0,0,triangle,n);
    }
};



T.C. - 2^N

S.C - O(N*N)



X--------------------------------------X----------------------------------------------X

MEMOIZATION :

class Solution {
public:

    int f(int i , int j , vector<vector<int>>& a,int n,vector<vector<int>>&dp)
    {
        if(i==n-1)
        {
            return a[i][j];
        }
        if(dp[i][j]!=-1)
         return dp[i][j];
        int down = a[i][j] + f(i+1,j,a,n,dp);
        int diag = a[i][j] + f(i+1,j+1,a,n,dp);

        return dp[i][j]=min(down,diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return f(0,0,triangle,n,dp);
    }
};


X-------------------------------------X---------------------------------------X

TABULATION


class Solution {
public:

    int f(int i , int j , vector<vector<int>>& a,int n,vector<vector<int>>&dp)
    {
        if(i==n-1)
        {
            return a[i][j];
        }
        if(dp[i][j]!=-1)
         return dp[i][j];
        int down = a[i][j] + f(i+1,j,a,n,dp);
        int diag = a[i][j] + f(i+1,j+1,a,n,dp);

        return dp[i][j]=min(down,diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int j=0;j<n;j++)
        {
            dp[n-1][j]=triangle[n-1][j];
        }

        for(int i = n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int d = triangle[i][j] + dp[i+1][j];
                int dia = triangle[i][j] + dp[i+1][j+1];

                dp[i][j]=min(d,dia);

            }
        }


        return dp[0][0];
     
    }
};

T.C. - O(N^2)
S.C. - O(N^2)



