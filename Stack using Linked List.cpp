#include<bits/stdc++.h>
using namespace std;

struct node
{
    int v;
    node *next;
};

struct Stack
{
    node *head=NULL;

    void Insert(int x)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->v = x;
        temp->next = NULL;
        if(head==NULL)
        {
            head = temp;
            return;
        }
        temp->next = head;
        head = temp;
    }

    int poop()
    {
        if(head==NULL)
        {
            return -1;
        }
        node *p=head;
        head = head->next;
        return p->v;
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
    Stack s;
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
