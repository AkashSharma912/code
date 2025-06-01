MEMOIZATION


Cherry Pickup II

class Solution {
public:

    int f(int i, int j1, int j2, int r, int c, vector<vector<int>>& a, vector<vector<vector<int>>>& dp) {
        // Base case: If we're at the last row
        if(i == r - 1) {
            if(j1 == j2)
                return a[i][j1];
            else
                return a[i][j1] + a[i][j2];
        }
        
        // Check the memoization table to avoid redundant calculations
        if(dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }

        int maxi = -1e8; // Use INT_MIN for clarity

        // Explore all possible moves for both the "robots" (j1, j2)
        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {
                // Calculate the next valid positions for j1 and j2
                int newJ1 = j1 + dj1;
                int newJ2 = j2 + dj2;

                // Make sure the new positions are within bounds
                if(newJ1 >= 0 && newJ1 < c && newJ2 >= 0 && newJ2 < c) {
                    int value = 0;

                    // If j1 == j2, we pick the same cell only once
                    if(j1 == j2) {
                        value = a[i][j1];
                    } else {
                        value = a[i][j1] + a[i][j2];
                    }

                    // Recursively calculate the next row and accumulate the result
                    value += f(i + 1, newJ1, newJ2, r, c, a, dp);

                    // Take the maximum value across all valid moves
                    maxi = max(maxi, value);
                }
            }
        }

        // Memoize the result before returning
        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        // Create a 3D DP table to store intermediate results
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

        // Start from the first row with j1 at 0 and j2 at the last column
        return f(0, 0, c - 1, r, c, grid, dp);
    }
};


X-----------------------------------------------X--------------------------------------X




