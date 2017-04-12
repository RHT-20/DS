#include<bits/stdc++.h>
using namespace std;

#define MX 1000

struct data
{
    string name;
    int roll,marks,srank;
};

struct node
{
    data d;
    node *left,*right;
    node()
    {
        left = NULL;
        right = NULL;
    }
};

struct BST
{
    node *head = NULL;
    void insert_a(data da)
    {
        if(head==NULL)
        {
            node *temp = new node();
            temp->d = da;
            temp->left = temp->right = NULL;
            head = temp;
            return;
        }
        insert_b(head,da);
    }

    void insert_b(node *temp,data da)
    {
        if(temp->d.name>=da.name)
        {
            if(temp->left==NULL)
            {
                node *p = new node();
                p->d = da;
                p->left = p->right = NULL;
                temp->left = p;
                return;
            }
            else    insert_b(temp->left,da);
        }
        else
        {
            if(temp->right==NULL)
            {
                node *p = new node();
                p->d = da;
                p->left = p->right = NULL;
                temp->right = p;
                return;
            }
            else    insert_b(temp->right,da);
        }
    }

    void inorder_print(node *temp,int i)
    {
        if(temp==NULL)  return;
        inorder_print(temp->left,i++);
        cout << temp->d.name << "  " << temp->d.roll << "  " << temp->d.marks << endl;
        inorder_print(temp->right,i++);
    }
};

struct heap
{
    int nod = 1,top = 1;
    data maxheap[MX],sorted_heap[MX];
    void insert_h(data da)
    {
        maxheap[nod] = da;
        compare_hi(nod);
        nod++;
    }

    void compare_hi(int i)
    {
        while(i/2)
        {
            if(maxheap[i].marks>maxheap[i/2].marks) swap(maxheap[i],maxheap[i/2]);
            i = i/2;
        }
    }

    void heap_sort_h()
    {
        int x = nod;
        for(int i=1; i<x; i++)
        {
            sorted_heap[top] = maxheap[1];
            if(i==1)    sorted_heap[top].srank = 1;
            else if(sorted_heap[top].marks==sorted_heap[top-1].marks)   sorted_heap[top].srank = sorted_heap[top-1].srank;
            else    sorted_heap[top].srank = sorted_heap[top-1].srank+1;
            delete_h();
        }
        nod = 1;
    }

    void delete_h()
    {
        maxheap[1] = maxheap[nod-1];
        top++;
        nod--;
        compare_hd(1);
    }

    void compare_hd(int i)
    {
        if((2*i)<nod && (2*i+1)>=nod)
        {
            if(maxheap[i].marks>maxheap[2*i].marks)   return;
            else
            {
                swap(maxheap[i],maxheap[2*i]);
                compare_hd(2*i);
            }
        }
        else if((2*i)<nod && (2*i+1)<nod)
        {
            if(maxheap[2*i].marks>maxheap[2*i+1].marks)
            {
                if(maxheap[i].marks>maxheap[2*i].marks)   return;
                else
                {
                    swap(maxheap[i],maxheap[2*i]);
                    compare_hd(2*i);
                }
            }
            else
            {
                if(maxheap[i].marks>maxheap[2*i+1].marks)   return;
                else
                {
                    swap(maxheap[i],maxheap[2*i+1]);
                    compare_hd(2*i+1);
                }
            }
        }
        else    return;
    }

    void print_h()
    {
        for(int i=1; i<top; i++)
        {
            cout << sorted_heap[i].name << "  " << sorted_heap[i].roll << "  " << sorted_heap[i].marks << "  " << sorted_heap[i].srank << endl;
        }
    }
};

int main()
{
    BST b;
    heap h;
    data da;
    int i;
    puts("\t\t\t\t\t  ********** Menu **********");
    puts("");
    puts("\t\t\t\t\t1 - Input student information");
    puts("\t\t\t\t\t2 - Print in-order result");
    puts("\t\t\t\t\t3 - Print result with rank-list");
    puts("\t\t\t\t\t4 - Exit");
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&i)==1)
    {
        printf("%d\n",i);
        if(i==1)
        {
            puts("Student information:");
            cin >> da.name >> da.roll >> da.marks;
            b.insert_a(da);
            h.insert_h(da);
        }
        else if(i==2)
        {
            puts("");
            puts("In-order result:");
            puts("Name   Roll   Marks");
            puts("");
            b.inorder_print(b.head,0);
        }
        else if(i==3)
        {
            puts("");
            puts("Result with rank-list:");
            h.heap_sort_h();
            puts("Name   Roll   Marks   Rank");
            puts("");
            h.print_h();
            for(int j=1; j<h.top; j++)
            {
                h.insert_h(h.sorted_heap[j]);
            }
            h.nod = h.top;
            h.top = 1;
        }
        else if(i==4)   break;
    }
    return 0;
}

/*
1
b 1 20
1
c 2 30
1
a 3 35
1
d 4 39
2
3
4
*/
