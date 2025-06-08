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

        int len =  dp[a.size()][ b.size()];
        string ans = "";
        for(int i =0;i< len ;i++)
        {
            ans+='$';
        }

        int index = len - 1;

        int i = a.size(), j = b.size();
        while(i>0 && j>0)
        {
            if(a[i-1]==b[j-1])
            {
                ans[index]=a[i-1];
                index--;
                i--;j--;
            }
            else if (dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }

        }
        cout<< ans;

    }
};