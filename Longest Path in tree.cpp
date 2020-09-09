#include <iostream>
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
/*
	 A
	/ \
	B   D
	/	/\
	C   E
	Proof:
	Root the tree at any node start dfs let it from A 	
	Now the node which is farthest from A let it be C
	Contradiction - let C not be one of end points of the diameter 
	let it be B. Then we can say that it gives wrong answer as it 
	can be extended to C to give longest one.

	Method:
	Start dfs from A 
	Find C ----->start dfs from C 
	dis of farthest from C =diameter

*/
int maxd,maxnode;
int vis[100001];
vector<int> adj[100001];
void dfs(int u,int d)
{
	vis[u]=1;
	if(maxd<d)
	{
		maxd=d;
		maxnode=u;
	}
	for(int v:adj[u])
	{
		if(!vis[v])
			dfs(v,d+1);
	}
}
int main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	#endif
	int n,x,y;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(vis,0,sizeof(vis));
	maxd=-1;
	dfs(1,0);

	memset(vis,0,sizeof(vis));
	maxd=-1;
	dfs(maxnode,0);
	cout<<maxd<<"\n";
	return 0;
}
