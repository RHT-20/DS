#include<bits/stdc++.h>
using namespace std;

int c = 0;

struct node
{
    int v;
    node *next,*prev;
};

struct dubbly_linked_list
{
    node *head=NULL,*tail=NULL;

    bool empty_list()
    {
        return (c==0);
    }

    void insert_first(int x)
    {
        c++;
        node *p = (node *)malloc(sizeof(node));
        p->v = x;
        p->next = NULL;
        p->prev = NULL;
        if(head==NULL)
        {
            head = p;
            tail = p;
            return;
        }
        p->next = head;
        head->prev = p;
        head = p;
    }

    void insert_last(int x)
    {
        c++;
        node *p = (node *)malloc(sizeof(node));
        p->v = x;
        p->next = NULL;
        p->prev = NULL;
        if(tail==NULL)
        {
            tail = p;
            head = p;
            return;
        }
        p->prev = tail;
        tail->next = p;
        tail = p;
    }

    void insert_before(int x,int y)
    {
        if(head->v==x)
        {
            insert_first(y);
            return;
        }
        c++;
        node *p = (node *)malloc(sizeof(node));
        node *q,*r = head;
        p->v = y;
        p->next = NULL;
        p->prev = NULL;
        while(head->v!=x)
        {
            q = head;
            head = head->next;
        }
        p->prev = q;
        q->next = p;
        head->prev = p;
        p->next = head;
        head = r;
    }

    void insert_after(int x,int y)
    {
        c++;
        node *p = (node *)malloc(sizeof(node));
        node *q,*r = head;
        p->v = y;
        p->next = NULL;
        p->prev = NULL;
        while(head->v!=x)
        {
            head = head->next;
        }
        if(head->next==NULL)
        {
            insert_last(y);
            head = r;
            return;
        }
        q = head->next;
        p->prev = head;
        head->next = p;
        q->prev = p;
        p->next = q;
        head = r;
        ++c;
    }

    void print_first()
    {
        if(empty_list())
        {
            printf("Empty list\n");
            return;
        }
        node *p = head;
        while(head!=NULL)
        {
            printf("%d ",head->v);
            head = head->next;
        }
        head = p;
        puts("");
    }

    void print_rev()
    {
        if(empty_list())
        {
            printf("Empty list\n");
            return;
        }
        node *p = tail;
        while(tail!=NULL)
        {
            printf("%d ",tail->v);
            tail = tail->prev;
        }
        tail = p;
        puts("");
    }

    void delete_first()
    {
        if(empty_list())
        {
            printf("Sorry\n");
            return;
        }
        c--;
        head = head->next;
        head->prev = NULL;
    }

    void delete_last()
    {
        if(empty_list())
        {
            printf("Sorry\n");
            return;
        }
        c--;
        tail = tail->prev;
        tail->next = NULL;
    }

    void delete_any(int x)
    {
        if(empty_list())
        {
            printf("Sorry\n");
            return;
        }
        else if(head->v==x)
        {
            delete_first();
            return;
        }
        c--;
        if(head->v==x)
        {
            delete_first();
            return;
        }
        node *p = head,*q,*r;
        while(head->v!=x)
        {
            q = head;
            head = head->next;
        }
        if(head->next==NULL)
        {
            delete_last();
            head = p;
            return;
        }
        r = head->next;
        r->prev = q;
        q->next = r;
        head = p;
    }

    void search_first(int x)
    {
        if(empty_list())
        {
            printf("Sorry\n");
            return;
        }
        node *p = head;
        int i=1,f=0;
        while(1)
        {
            if(head->v==x)
            {
                f = 1;
                break;
            }
            i++;
            head = head->next;
        }
        head = p;
        if(f==1)    printf("Position %d from head\n",i);
        else    printf("Not found\n");
    }

    void search_last(int x)
    {
        if(empty_list())
        {
            printf("Sorry\n");
            return;
        }
        node *p = tail;
        int i=1,f=0;
        while(1)
        {
            if(tail->v==x)
            {
                f = 1;
                break;
            }
            i++;
            tail = tail->prev;
        }
        tail = p;
        if(f==1)    printf("Position %d from tail\n",i);
        else    printf("Not found\n");
    }

    node *srch(int x)
    {
        int f = 0;
        while(1)
        {
            if(head==NULL)  break;
            else if(head->v==x)
            {
                f = 1;
                return head;
            }
            else    head = head->next;
        }
        if(f==0)    return NULL;
    }

    void insert_key(node *p,int x)
    {
        node *s = head;
        node *temp1 = (node *)malloc(sizeof(node));
        temp1->v = x;
        temp1->next = temp1->prev = NULL;
        node *temp2 = (node *)malloc(sizeof(node));
        temp2->v = x;
        temp2->next = temp2->prev = NULL;
        if(head==p)
        {
            temp1->next = head;
            head->prev = temp1;
            node *q=NULL;
            if(head->next!=NULL)    q = head->next;
            head->next = temp2;
            temp2->prev = head;
            if(q!=NULL)
            {
                temp2->next = q;
                q->prev = temp2;
            }
            else if(q==NULL)
            {
                tail->next = temp2;
                temp2->prev = tail;
                tail = temp2;
            }
            head = temp1;
            return;
        }
        while(1)
        {
            if(head->next==p)
            {
                node *q = head->next;
                head->next = temp1;
                temp1->prev = head;
                temp1->next = q;
                q->prev = temp1;
                head = s;
                break;
            }
            else    head = head->next;
        }
        s = tail;
        if(tail==p)
        {
            tail->next = temp2;
            temp2->prev = tail;
            tail = temp2;
            return;
        }
        while(1)
        {
            if(tail->prev==p)
            {
                node *q = tail->prev;
                tail->prev = temp2;
                temp2->next = tail;
                temp2->prev = q;
                q->next = temp2;
                tail = s;
                break;
            }
            else    tail = tail->prev;
        }
    }
};

int main()
{
    dubbly_linked_list DLL;
    int x,y,i;
    printf("\tMenu:\n1 for Insert first\n2 for Insert last\n3 for Insert before\n4 for Insert after\n5 for Delete first\n");
    printf("6 for Delete last\n7 for Delete any\n8 for Print first\n9 for Print reverse\n10 for Search forward\n11 for Search backward\n12 for search key\nElse exit\n");
    while((scanf("%d",&i))==1)
    {
        if(i==1)
        {
            printf("Insert first:\n");
            scanf("%d",&x);
            DLL.insert_first(x);
        }
        else if(i==2)
        {
            printf("Insert last:\n");
            scanf("%d",&x);
            DLL.insert_last(x);
        }
        else if(i==3)
        {
            printf("Insert before:\n");
            scanf("%d %d",&x,&y);
            DLL.insert_before(x,y);
        }
        else if(i==4)
        {
            printf("Insert after:\n");
            scanf("%d %d",&x,&y);
            DLL.insert_after(x,y);
        }
        else if(i==5)
        {
            printf("Delete first:\n");
            DLL.delete_first();
        }
        else if(i==6)
        {
            printf("Delete last:\n");
            DLL.delete_last();
        }
        else if(i==7)
        {
            printf("Delete any:\n");
            scanf("%d",&x);
            DLL.delete_any(x);
        }
        else if(i==8)
        {
            printf("Print first:\n");
            DLL.print_first();
        }
        else if(i==9)
        {
            printf("Print reverse:\n");
            DLL.print_rev();
        }
        else if(i==10)
        {
            printf("Search forward:\n");
            scanf("%d",&x);
            DLL.search_first(x);
        }
        else if(i==11)
        {
            printf("Search backward:\n");
            scanf("%d",&x);
            DLL.search_last(x);
        }
        else if(i==12)
        {
            printf("Search key:\n");
            scanf("%d",&x);
            node *p = DLL.head;
            node *q = DLL.srch(x);
            DLL.head = p;
            if(q==NULL) printf("Not found\n");
            else
            {
                printf("Address = %p and value = %d\n",q,q->v);
                scanf("%d",&x);
                DLL.insert_key(q,x);
            }
        }
        else
        {
            printf("No operation to perform\n");
            break;
        }
    }
    return 0;
}
