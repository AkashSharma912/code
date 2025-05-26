#include <bits/stdc++.h>
using namespace std;


// Memoization

int f(int day , int last , vector<vector<int>> & points, vector<vector<int>> & dp)
{
    if(day==0)
    {
        int maxi=0;
        for(int task =0;task<3;task++)
        {
            if(task!=last)
            {
                maxi= max(maxi , points[day][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1)
    return dp[day][last];
    
    int maxi=0;
    
    for(int task =0;task<3;task++)
    {
        if(task!=last)
        {
            int point = points[day][task] + f(day-1,task,points,dp);
            maxi= max(point, maxi);
        }
    }
    return dp[day][last]=maxi;
    
    
}
int main()
{
    
     vector<vector<int>> dp(3, vector<int>(4,-1));
    
    vector<vector<int>> points = {
        {32,45,2},
        {21,32,4},
        {98,44,89}
    };
    
    cout<< f(3-1,3,points,dp);
    
    
}


Tabulation:(bottom-up)


    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        vector<vector<int>> points = {
            {32, 45, 2},
            {21, 32, 4},
            {98, 44, 89}
        };
    
        vector<vector<int>> dp(3, vector<int>(4, 0));
    
        // Base case for day 0
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max({points[0][0], points[0][1], points[0][2]});
    
        for (int day = 1; day < 3; day++) {
            for (int last = 0; last < 4; last++) {
                dp[day][last] = 0;
                for (int task = 0; task < 3; task++) {
                    if (task != last) {
                        int point = points[day][task] + dp[day-1][task];
                        dp[day][last] = max(dp[day][last], point);
                    }
                }
            }
        }
    
        cout << dp[2][3] << endl;
    
        return 0;
    }


t.c - O(n x 4 x 3)
s.c - O(nX4)

x----------------------------------------------------x

Space optimization

    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        vector<vector<int>> points = {
            {32, 45, 2},
            {21, 32, 4},
            {98, 44, 89}
        };
    
        vector<int> prev(4, 0);
    
        // Base case for day 0
        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max({points[0][0], points[0][1], points[0][2]});
    
        for (int day = 1; day < 3; day++) {
            vector<int> temp(4,0);
            for (int last = 0; last < 4; last++) {
                temp[last] = 0;
                for (int task = 0; task < 3; task++) {
                    if (task != last) {
                        temp[last] = max(temp[last], points[day][task] + prev[task]);
                    }
                }
            }
            
            prev = temp;
        }
    
        cout << prev[3] << endl;
    
        return 0;
    }



T.c. -> o(n * 4*3)
s.c  -> 0(4)

