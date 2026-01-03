#include<bits/stdc++.h>
using namespace std;

vector<int>G[100005];
queue<int>Q;

int n,e,u,v,s,d,vis[100005],lev[100005],p[100005];

void BFS(int s)
{
    lev[s]=0;
    vis[s]=1;
    Q.push(s);

    while(!Q.empty()){

        u=Q.front();
        Q.pop();

        for(int v:G[u]){
            if(!vis[v]){
                lev[v]=lev[u]+1;
                vis[v]=1;
                p[v]=u;
                Q.push(v);
            }
        }
    }
}

void path(int d)
{
    if(d==s){
        return;
    }
    else{
        path(p[d]);
        cout<<p[d]<<' ';
    }
}

int main()
{
    cin>>n>>e;

    for(int i=1;i<=e;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    cin>>s>>d;

    BFS(s);
    path(d);
    cout<<d<<endl;
    return 0;
}


//5 4
//1 5
//1 3
//5 2
//5 4
//1
