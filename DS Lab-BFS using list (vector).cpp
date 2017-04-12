#include<bits/stdc++.h>
using namespace std;

#define MX 1000
vector<int>ve[MX];
int a[MX][MX],vis[MX],level[MX],n,m;
queue<int>q;

void bfs(int s)
{
    q.push(s);
    level[s] = 0;
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        vis[s] = 1;
        for(int i=0; i<ve[s].size(); i++)
        {
            if(vis[ve[s][i]]==0)
            {
                q.push(ve[s][i]);
                level[ve[s][i]] = level[s]+1;
                vis[ve[s][i]] = 1;
            }
        }
    }
}

int main()
{
    int i,u,v;
    scanf("%d %d",&n,&m);
    for(i=0; i<m; i++)
    {
        scanf("%d %d",&u,&v);
        a[u][v] = 1;
        a[v][u] = 1;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    puts("1 - Check edge between u and v using adjacency matrix");
    puts("2 - Check edge between u and v using adjacency list");
    puts("3 - Check path between u and v");
    puts("4 - Shortest path");
    while(1)
    {
        scanf("%d",&i);
        if(i==1)
        {
            scanf("%d %d",&u,&v);
            if(a[u][v]) printf("Yes\n");
            else    printf("No\n");
        }
        else if(i==2)
        {
            scanf("%d %d",&u,&v);
            int f = 0;
            for(i=0; i<ve[u].size(); i++)
            {
                if(ve[u][i]==v)
                {
                    printf("Yes\n");
                    f = 1;
                    break;
                }
            }
            if(f==0)    printf("No\n");
        }
        else if(i==3)
        {
            scanf("%d %d",&u,&v);
            memset(level,0,sizeof(level));
            memset(vis,0,sizeof(vis));
            bfs(u);
            if(vis[v])  printf("Yes\n");
            else    printf("No\n");
        }
        else if(i==4)
        {
            scanf("%d %d",&u,&v);
            memset(level,0,sizeof(level));
            memset(vis,0,sizeof(vis));
            bfs(u);
            if(vis[v])  printf("Shortest path of v from u = %d\n",level[v]);
            else    printf("No Shortest path\n");
        }
        else    break;
    }
    return 0;
}

/*
10 13
1 2
1 3
1 4
2 6
3 7
3 8
4 7
5 8
5 10
6 10
7 9
9 10
7 8
*/

