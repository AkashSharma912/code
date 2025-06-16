

void dfs(int node , int vis[], vector<int> & adj,stack<int> &st )
{
    vis[node]=1;
    for(auto it : adj[node])
    {
        if(!vis[it])
        {
        dfs(it , vis,adj,st);
    }
    st.push(node);
}


vector<int> topoSort(int n , vector<int> adj)
{
    int vis[n]={0};
    std::stack<int> st ;
    
    for(int i =0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,adj,st);
        }
    }
    
    vector<int> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans ;
    
    
}




T.C. - o(V + E)
S.C. - o(N) + O(N)