#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int a[],int n)
{
    int i,j,t;
    for(i=n-1; i>0; i--)
    {
        for(j=0; j<i; j++)
        {
            if(a[i]<a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    puts("");
}


void selection_sort(int a[],int n)
{
    int i,j,m,t;
    for(i=0; i<n-1; i++)
    {
        m = i;
        for(j=i+1; j<n; j++)
        {
            if(a[j]<a[m])   m = j;
        }
        t = a[m];
        a[m] = a[i];
        a[i] = t;
    }
    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    puts("");
}

void insertion_sort(int a[],int n)
{
    int i,j,t;
    for(i=1; i<n; i++)
    {
        for(j=i; j>=1; j--)
        {
            if(a[j]<a[j-1])
            {
                t = a[j];
                a[j] = a[j-1];
                a[j-1] = t;
            }
            else    break;
        }
    }
    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    puts("");
}

void merge_sort(int a[],int b[],int lo,int hi)
{
    if(lo>=hi)  return;
    int md;
    md = (lo+hi)/2;
    merge_sort(a,b,lo,md);
    merge_sort(a,b,md+1,hi);
    int i,j,k;
    for(i=lo,j=md+1,k=lo; k<=hi; k++)
    {
        if(i==md+1) b[k] = a[j++];
        else if(j==hi+1)  b[k] = a[i++];
        else if(a[i]>=a[j]) b[k] = a[j++];
        else    b[k] = a[i++];
    }
    for(i=lo; i<=hi; i++)
    {
        a[i] = b[i];
    }
}

void counting_sort(int a[],int c[],int b[],int n,int mx)
{
    int i;
    for(i=0; i<n; i++)
    {
        c[a[i]]++;
    }
    for(i=1; i<=mx; i++)
    {
        c[i] = c[i]+c[i-1];
    }
    for(i=n-1; i>=0; i--)
    {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
    for(i=1; i<=n; i++)
    {
        printf("%d ",b[i]);
    }
    puts("");
}

void quick_sort(int a[],int left,int right)
{
    int pivot = (left+right)/2;
    int i=left,j=right;
    while(i<=j)
    {
        while(a[i]<a[pivot])    i++;
        while(a[j]>a[pivot])    j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(left<j)  quick_sort(a,left,j);
    if(right>i) quick_sort(a,i,right);
}

void radix_sort(int a[],int n,int l)
{
    int i,j,k,x;
    queue <int> q[10];
    printf("%d\n",l);
    for(i=1; i<=l; i++)
    {
        for(j=0; j<n; j++)
        {
            x = a[j];
            for(k=1; k<i; k++)
            {
                x = x/10;
            }
            x = x%10;
            q[x].push(a[j]);
        }
        k = 0;
        for(j=0; j<=9; j++)
        {
            while(q[j].size())
            {
                a[k++] = q[j].front();
                q[j].pop();
            }
        }
    }
    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    puts("");
}

int main()
{
    int n,i,j,l=0,l1;
    while(1)
    {
        scanf("%d",&n);
        int a[n],mx=-1000000;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            mx = max(a[i],mx);
            l1 = log10(a[i])+1;
            l = max(l1,l);
        }
        scanf("%d",&j);
        if(j==1)    bubble_sort(a,n);
        else if(j==2)   selection_sort(a,n);
        else if(j==3)   insertion_sort(a,n);
        else if(j==4)
        {
            int b[n];
            merge_sort(a,b,0,n-1);
            for(i=0; i<n; i++)
            {
                printf("%d ",a[i]);
            }
            puts("");
        }
        else if(j==5)
        {
            int c[mx+5],b[n+5];
            memset(c,0,sizeof(c));
            memset(b,0,sizeof(b));
            counting_sort(a,c,b,n,mx);
        }
        else if(j==6)   quick_sort(a,0,n);
        else if(j==7)   radix_sort(a,n,l);
    }
    return 0;
}
