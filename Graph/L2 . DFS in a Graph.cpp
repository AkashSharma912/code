
#include <stdio.h>

class Solution{
    
    void dfs(int node, vector<int> adj[],int vis[], vector<int> &ls)
    {
        vis[node]=1;
        ls.push_back(node);
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis,ls);
            }
        }
    }
    
    public:
    
    vector<int> dfsOfGraph(int n , vector<int> adj[])
    {
        int vis[n] = {0};
        int start =0;
        vector<int> ls ;
        
        dfs(start, adj, vis , ls);
        return ls;
        
    }




S.c - O(n)
T.C. - SUM OF DEGREE(2E) 




