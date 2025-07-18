vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {

       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V,1e9);
	 vector<int> vis(V,0);
        dist[s]=0;
        pq.push({0,s});
        
        while(!pq.empty())
        {
            int dis=pq.top().first;
            int node=pq.top().second;
            
            pq.pop();

              if(vis[node]==1) continue;
            
            vis[node]=1;
	
            for(auto it: adj[node])
            {
                int wt=it[1];
                int adjnode=it[0];
                
                
                if(dis+wt<dist[adjnode])
                {
                    dist[adjnode]=dis+wt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
    }
};
