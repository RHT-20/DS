#include<bits/stdc++.h>
using namespace std;

#define MX 10000
vector<int>v[MX],top;
int level[MX],path[MX],cycle,visited[MX];
queue<int>q;

void bfs(int s)
{
    q.push(s);
    level[s] = 0;
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        visited[s] = 1;
        for(int i=0; i<v[s].size(); i++)
        {
            if(visited[v[s][i]]==0)
            {
                level[v[s][i]] = level[s]+1;
                q.push(v[s][i]);
                visited[v[s][i]] = 1;
                path[v[s][i]] = s;
            }
        }
    }
}

void dfs(int s)
{
    visited[s] = 2;
    for(int i=0; i<v[s].size(); i++)
    {
        if(visited[v[s][i]]==0) dfs(v[s][i]);
        if(visited[v[s][i]]==2) cycle = 1;
    }
    visited[s] = 1;
    top.insert(top.begin(),s);
}

void shortest_path(int s)
{
    if(path[s]==-1)
    {
        printf("%d ",s);
        return;
    }
    shortest_path(path[s]);
    printf("%d ",s);
}

void clr()
{
    top.clear();
    for(int i=0; i<MX; i++) v[i].clear();
    memset(level,0,sizeof(level));
    memset(visited,0,sizeof(visited));
    memset(path,-1,sizeof(path));
}

int main()
{
    int n,e,i,x,y,k;
    printf("1 - Input the graph\n2 - Length of shortest path from source to destination\n3 - Shortest path\n4 - Topological order\n5 - Check the given graph is a tree or not\n6 - Exit\n");
    while(1)
    {
        scanf("%d",&k);
        if(k==1)
        {
            clr();
            printf("Number of nodes and edges:\n");
            scanf("%d %d",&n,&e);
            for(i=0; i<e; i++)
            {
                scanf("%d %d",&x,&y);
                v[x].push_back(y);
            }
        }
        else if(k==2)
        {
            printf("Input source and destination:\n");
            scanf("%d %d",&x,&y);
            memset(level,0,sizeof(level));
            memset(visited,0,sizeof(visited));
            memset(path,-1,sizeof(path));
            bfs(x);
            if(visited[y])  printf("Length of the shortest path of %d = %d\n",y,level[y]);
            else    printf("No direct edge\n");
        }
        else if(k==3)
        {
            printf("Input source and destination:\n");
            scanf("%d %d",&x,&y);
            memset(level,0,sizeof(level));
            memset(visited,0,sizeof(visited));
            memset(path,-1,sizeof(path));
            bfs(x);
            if(visited[y])
            {
                printf("Shortest path of %d form %d -> ",y,x);
                shortest_path(y);
            }
            else    printf("No direct path");
            puts("");
        }
        else if(k==4)
        {
            memset(visited,0,sizeof(visited));
            cycle = 0;
            top.clear();
            for(i=1; i<=n; i++)
            {
                if(visited[i]==0)   dfs(i);
            }
            if(cycle==1)  printf("No Topological order\n");
            else
            {
                printf("Topological order:");
                for(i=0; i<top.size(); i++) printf(" %d",top[i]);
                puts("");
            }
        }
        else if(k==5)
        {
            clr();
            printf("Number of nodes and edges:\n");
            scanf("%d %d",&n,&e);
            for(i=0; i<e; i++)
            {
                scanf("%d %d",&x,&y);
                v[x].push_back(y);
            }
            int f;
            for(i=1; i<=n; i++)
            {
                memset(visited,0,sizeof(visited));
                cycle = 0;
                f = 0;
                top.clear();
                dfs(i);
                if(cycle==1)
                {
                    f = 1;
                    break;
                }
                else
                {
                    for(int j=1; j<=n; j++)
                    {
                        if(visited[j]==0)
                        {
                            f = 1;
                            break;
                        }
                    }
                }
                if(f==0)
                {
                    printf("The graph is a thee.\n");
                    break;
                }
            }
            if(f==1)    printf("The graph is not a tree.\n");
        }
        else if(k==6)   break;
    }
    return 0;
}
