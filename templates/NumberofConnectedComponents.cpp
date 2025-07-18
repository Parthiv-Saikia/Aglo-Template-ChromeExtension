void dfs(vector<int>adj[],int n,int prev,vector<int>&vis,int node)
    {
        vis[node]=prev+1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(adj,n,prev,vis,it);
            }
        }
    }

int main()
{
	for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                vis[i]=prev+1;
                dfs(adj,n,prev,vis,i);
                prev++;
            }
        }
}