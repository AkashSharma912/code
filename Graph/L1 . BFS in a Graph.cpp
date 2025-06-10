
#include <stdio.h>

class Solution{
    public:
    
    vector<int> bfsOfGraph(int v , vector<int> adj[])
    {
        int vis[n] = {0};
        vis{0}=1;
        queue<int> q;
        q.push(0);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push(node);
            
            for(auto it : adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        
        }
        return bfs;
}




S.c - O(3N)
T.C - o(N) + O(2E) --> DEGREE of the graph


