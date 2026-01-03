#include<bits/stdc++.h>
using namespace std;

vector<int>G[100005];
int vis[100005],lev[100005];

void dfs(int u)
{
    vis[u] = 1;

    for(int v:G[u]){
        if(!vis[v]){
            lev[v] = lev[u]+1;
            dfs(v);
        }
    }
}

int main()
{
    int n,e,u,v;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(vis[i]==0) dfs(i);
    }

    return 0;
}
