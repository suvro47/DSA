#include<bits/stdc++.h>
using namespace std;

int vis[10005][10005];
char G[10005][10005];

int n,m;

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

void dfs(int x,int y)
{
    vis[x][y]=1;

    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx>=0 && ny>=0 && nx<n && ny<n && G[nx][ny]=='.' && !vis[nx][ny])
            dfs(nx,ny);
    }
}

int main()
{
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>G[i][j];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(G[i][j]=='.' && !vis[i][j]){
                dfs(i,j);
            }
        }
    }

    return 0;

}
