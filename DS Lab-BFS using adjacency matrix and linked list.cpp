#include<bits/stdc++.h>
using namespace std;

#define MX 1000
int a[MX][MX],vis[MX],level[MX],n,m;
queue<int>q;

struct node
{
    int v;
    node *next;
    node()
    {
        next = NULL;
    }
};

struct adjacency_list
{
    node *head=NULL;
    void insert_v(node *temp,int x)
    {
        node *p = new node();
        p->v = x;
        p->next = NULL;
        if(temp==NULL)
        {
            head = p;
            return;
        }
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }

    void search_e(node *temp,int x)
    {
        if(temp==NULL)
        {
            printf("No edge\n");
            return;
        }
        else if(temp->v==x)
        {
            printf("Yes\n");
            return;
        }
        else    search_e(temp->next,x);
    }
    void print(node *temp)
    {
        if(temp==NULL)  return;
        printf("%d ",temp->v);
        print(temp->next);
    }
};
adjacency_list al[MX];

void bfs(int s)
{
    q.push(s);
    level[s] = 0;
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        vis[s] = 1;
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0 && a[s][i])
            {
                q.push(i);
                level[i] = level[s]+1;
                vis[i] = 1;
            }
        }
    }
}

void bfs_al(int s)
{
    int i;
    q.push(s);
    level[s] = 0;
    node *temp;
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        temp = al[s].head;
        vis[s] = 1;
        while(temp!=NULL)
        {
            i = temp->v;
            if(vis[i]==0)
            {
                q.push(i);
                level[i] = level[s]+1;
                vis[i] = 1;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int i,u,v;
    scanf("%d %d",&n,&m);
    node *temp;
    for(i=0; i<m; i++)
    {
        scanf("%d %d",&u,&v);
        a[u][v] = 1;
        a[v][u] = 1;
        temp = al[u].head;
        al[u].insert_v(temp,v);
        temp = al[v].head;
        al[v].insert_v(temp,u);
    }
    puts("");
    for(i=1; i<n; i++)
    {
        printf("%d: ",i);
        temp = al[i].head;
        al[i].print(temp);
        puts("");
    }
    puts("");
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
            temp = al[u].head;
            al[u].search_e(temp,v);
        }
        else if(i==3)
        {
            scanf("%d %d",&u,&v);
            memset(level,0,sizeof(level));
            memset(vis,0,sizeof(vis));
            bfs_al(u);
            if(vis[v])  printf("Yes\n");
            else    printf("No\n");
        }
        else if(i==4)
        {
            scanf("%d %d",&u,&v);
            memset(level,0,sizeof(level));
            memset(vis,0,sizeof(vis));
            bfs_al(u);
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
