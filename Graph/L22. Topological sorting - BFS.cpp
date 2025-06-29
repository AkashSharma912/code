




vector<int> topoSort(int n , vector<int> adj)
{
    int inDegree[n] ={0};
    for(int i =0;i<n;i++)
    {
        for(auto it : adj[i])
        {
            inDegree[it]++;
        }
        
    }
    queue<int> q;
    
    for(int i =0;i<n;i++)
    {
        if(inDegree[i]==0)
        q.push(i);
    }
    
    vector<int> topo ;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        top.push_back(node);
        
        
        for(auto it : adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            q.push(it);
        }
    }
    
    return topo;
}


t.c - O(v+e)


