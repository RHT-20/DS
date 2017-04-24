#include<bits/stdc++.h>
using namespace std;

struct node
{
    int v;
    node *next;
};

struct Queue
{
    node *head=NULL;

    void Insert(int x)
    {
        node *temp = (node *)malloc(sizeof(node));
        node *p = head;
        temp->v = x;
        temp->next = NULL;
        if(head==NULL)
        {
            head = temp;
            return;
        }
        while(head->next!=NULL)
        {
            head = head->next;
        }
        head->next = temp;
        head = p;
    }

    int poop()
    {
        int x;
        if(head==NULL)
        {
            return -1;
        }
        if(head->next==NULL)
        {
            x = head->v;
            head = NULL;
            return x;
        }
        x = head->v;
        head = head->next;
        return x;
    }

    void print()
    {
        if(head==NULL)
        {
            printf("Empty list\n");
            return;
        }
        node *p=head;
        while(head!=NULL)
        {
            printf("%d ",head->v);
            head = head->next;
        }
        head = p;
        puts("");
    }
};

int main()
{
    Queue s;
    int i,x;
    while(scanf("%d",&i)==1)
    {
        if(i==1)
        {
            printf("Insert:\n");
            scanf("%d",&x);
            s.Insert(x);
        }
        else if(i==2)
        {
            printf("Print:\n");
            s.print();
        }
        else if(i==3)
        {
            x = s.poop();
            if(x==-1)   printf("Empty\n");
            else    printf("Pop: %d\n",x);
        }
        else    break;
    }
    return 0;
}
