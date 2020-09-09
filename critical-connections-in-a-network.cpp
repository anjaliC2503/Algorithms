/*
Brute force approach - take an edge exclude that edge, do dfs find number of connected components 
if it changes it implies this edge is critical/bridge. 
Time complexity- O(E*(V+E)) E:edges V:vertices

Optimised approach- calculate in and low values of all nodes
in - in time of node
low - lowest ancestor that can be reached from this node
if low[child] >in[node] => only this edge connects the subtree with child as root to the ancestors
hence critical else there must be a back edge

*/
class Solution {
public:
    vector<int> in,low;
    vector<vector<int>>res;
    int timer;
    void dfs(int u,int p,vector<int> adj[],int vis[])
    {
        vis[u]=1;
        in[u]=low[u]=timer++;
        for(int v:adj[u])
        {
            if(v==p)continue;
            if(vis[v])
            {
                //back edge
                low[u]=min(low[u],in[v]);
            }
            else
            {
                dfs(v,u,adj,vis);
                low[u]=min(low[u],low[v]);
                if(low[v]>in[u])
                    res.push_back({u,v});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n];
        int vis[n];
        memset(vis,0,sizeof(vis));
        in=vector<int>(n);
        low=vector<int>(n);
        int edges=connections.size();
        for(int i=0;i<edges;i++)
        {
            int x=connections[i][0],y=connections[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(0,-1,adj,vis);
        return res;
    }
};