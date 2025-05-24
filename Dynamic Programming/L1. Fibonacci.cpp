#include <bits/stdc++.h>
using namespace std;


int fib(int n , vector<int> &dp)
{
    if(n<=1)
    return n;
    
    if(dp[n]!=-1)
    return dp[n];
    
    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}

int main()
{
    int n ;
    cin>>n;
    std::vector<int> dp(n+1,-1);
    cout<<fib(n,dp);
    
}

// Tabulation

#include <bits/stdc++.h>

using namespace std;


int main() {

  int n=5;
  vector<int> dp(n+1,-1);
  
  dp[0]= 0;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}
Output: 5

Time Complexity: O(N)

Reason: We are running a simple iterative loop

Space Complexity: O(N)

Reason: We are using an external array of size ‘n+1’.

x---------------------------x--------------------------------x


Space Optimization :


#include <bits/stdc++.h>

using namespace std;


int main() {

  int n=5;
  
  int prev2 = 0;
  int prev = 1;
  
  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
  cout<<prev;
  return 0;
}

Output: 5

Time Complexity: O(N)

Reason: We are running a simple iterative loop

Space Complexity: O(1)

Reason: We are not using any extra space