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






int longestCommonPalindrome(string s)
{
   string t = s;
   reverse(s.begin(), s.end());
   
   return longestCommonSubsequence(s,t);
}