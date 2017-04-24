#include<bits/stdc++.h>
using namespace std;

struct node
{
    int v;
    node *left,*right;
};

struct tree
{
    node *head=NULL;

    node *insert(node *temp,int x)
    {
        if(temp==NULL)
        {
            node *p = (node *)malloc(sizeof(node));
            p->v = x;
            p->left = p->right = NULL;
            temp = p;
            return temp;
        }
        else if(temp->v>x)  temp->left = insert(temp->left,x);
        else    temp->right = insert(temp->right,x);
    }

    void preorder(node *temp)
    {
        if(temp!=NULL)
        {
            printf("%d ",temp->v);
            preorder(temp->left);
            preorder(temp->right);
        }
        else    return;
    }

    void inorder(node *temp)
    {
        if(temp!=NULL)
        {
            inorder(temp->left);
            printf("%d ",temp->v);
            inorder(temp->right);
        }
        else    return;
    }

    void postorder(node *temp)
    {
        if(temp!=NULL)
        {
            postorder(temp->left);
            postorder(temp->right);
            printf("%d ",temp->v);
        }
        else    return;
    }

    int srch(node *temp,int x)
    {
        if(temp==NULL)  return -1;
        if(temp->v==x)  return 1;
        if(temp->v>x)   srch(temp->left,x);
        else    srch(temp->right,x);
    }

    node *find_min(node *p)
    {
        if(p->left==NULL)   return p;
        else    return find_min(p->left);
    }

    node *dlt(node *temp,int x)
    {
        if(temp==NULL)  return temp;
        if(temp->v>x)   temp->left = dlt(temp->left,x);
        else if(temp->v<x)  temp->right = dlt(temp->right,x);
        else
        {
            if(temp->left==NULL && temp->right==NULL)   temp = NULL;
            else if(temp->left==NULL)   temp = temp->right;
            else if(temp->right==NULL)  temp = temp->left;
            else
            {
                node *p = find_min(temp->right);
                temp->v = p->v;
                temp->right = dlt(temp->right,p->v);
            }
        }
        return temp;
    }
};

int main()
{
    tree T;
    int i,x;
    printf("1 for insert\n2 for preorder\n3 for inorder\n4 for postorder\n5 for search\n6 for delete\n");
    while(scanf("%d",&i)==1)
    {
        if(i==1)
        {
            scanf("%d",&x);
            node *temp = T.head;
            T.head = T.insert(temp,x);
        }
        else if(i==2)
        {
            node *temp = T.head;
            T.preorder(temp);
            puts("");
        }
        else if(i==3)
        {
            node *temp = T.head;
            T.inorder(temp);
            puts("");
        }
        else if(i==4)
        {
            node *temp = T.head;
            T.postorder(temp);
            puts("");
        }
        else if(i==5)
        {
            scanf("%d",&x);
            node *temp = T.head;
            x = T.srch(temp,x);
            if(x==-1)   printf("Not found\n");
            else    printf("Found\n");
        }
        else if(i==6)
        {
            scanf("%d",&x);
            node *temp = T.head;
            T.head = T.dlt(temp,x);
        }
    }
    return 0;
}
