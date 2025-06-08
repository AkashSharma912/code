Recursion:
x-----------------------x-------------------------------x


class Solution {
public:

    int f(int i, int j , string &a, string &b)
    {
        if(i<0 || j<0)
        {
            return 0;
        }

        if(a[i]==b[j])
        return 1 + f(i-1,j-1,a,b);

        return max(f(i-1,j,a,b),f(i,j-1,a,b));
        

    }


    int longestCommonSubsequence(string a, string b) 
    
    {
        
            return f (a.size()-1,b.size()-1 ,a,b);
    }
};




Memoization:
x-------------------------x--------------------------------------x

class Solution {
public:

    int f(int i, int j , string &a, string &b ,   vector<vector<int>> &dp)
    {
        if(i<0 || j<0)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if(a[i]==b[j])
        return dp[i][j]=1 + f(i-1,j-1,a,b,dp);

        return dp[i][j]=max(f(i-1,j,a,b,dp),f(i,j-1,a,b,dp));
        

    }


    int longestCommonSubsequence(string a, string b) 
    
    {
        vector<vector<int>> dp(a.size(),vector<int>(b.size(),-1));
            return f (a.size()-1,b.size()-1 ,a,b,dp);
    }
};




Tabulation:
x--------------------------x------------------------------------x

class Solution {
public:


    int longestCommonSubsequence(string a, string b)

    {
        vector<vector<int>> dp(a.size()+1, vector<int>(b.size() + 1, 0));

        for (int i = 0; i <= a.size(); i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= b.size(); i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <=a.size() ; i++) {
            for (int j = 1; j <= b.size() ; j++) {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                dp[i][j] = max(dp[i - 1][j], dp[i][ j - 1]);
            }
        }

        return dp[a.size()][ b.size()];
    }
};


