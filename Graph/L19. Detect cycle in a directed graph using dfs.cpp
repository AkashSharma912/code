class Solution {
public:

    bool dfsCheck(int node , int vis[] ,int pathVis[] ,vector<vector<int>>& grid)
    {
        vis[node]= 1;
        pathVis[node] = 1;


        for(auto it: grid[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,pathVis,grid)==true)
                  return true;
            }
            else if(pathVis[it])
            {
                return true;
            }
        }

        pathVis[node]=0;
        return false;




    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();

        int vis[n]={0};
        int pathVis[n] ={0};

        for(int i =0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dfsCheck(i,vis,pathVis,grid)==true)
                {
                    return true;
                }
            }
        }

        return false;
        
    }
};