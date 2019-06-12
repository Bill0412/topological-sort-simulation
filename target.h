//
// Created by Fenghe Xu on 2019-06-12.
//

#ifndef HASHING_TARGET_H
#define HASHING_TARGET_H
#include<stdio.h>
#include<set>

using namespace std;

#define MAX 3000

int A[MAX][MAX];

int target(int n, int* a)
{
    int count;
    int i;
    int b[100000]; // b is a bucket
    void BuildGraph(int Hash[],int n);  //create a directed graph
    void TopSort(int Hash[],int Index[],int n, int count);//topological sort


    // scanf("%d",&n);
    count=n;
    for(i=0;i<n;i++)
    {
        // scanf("%d",&a[i]);
        if(a[i]<0)
            count--;  //calculate significant figures
        else
            b[a[i]]=i;  //to store array subscripts
    }
    BuildGraph(a,n);
    TopSort(a,b,n,count);

    return 0;
}

//Create a directed graph
void BuildGraph(int Hash[],int n)
{
    int i,j,s;

    for(i=0;i<n;i++)
    {
        if(Hash[i]>=0)
        {
            s=Hash[i]%n;
            if(Hash[s]!=Hash[i]) //if there are duplicates
                for(j=s;j!=i;j=(j+1)%n)
                    A[j][i]=1;  //Everything from j to i goes into the hash table before i
            //Edge with direction<j,i>;
        }
    }
}

//topological sort
void TopSort(int Hash[], int Index[], int n, int count)
{
    int i,j;
    int sum,index;
    int degree[MAX];
    set<int> p;

    //initialize
    for(i=0;i<MAX;i++)
        degree[i]=0;
    //calculate the entry degree of each node (indegree)
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(A[i][j]!=0)
                degree[j]++;
    //place vertices greater than 0 with degree 0 into the set and sort them automatically
    for(i=0;i<n;i++)
        if(degree[i]==0 && Hash[i]>0)
            p.insert(Hash[i]);

    while(!p.empty())
    {
        index=Index[*p.begin()]; //get the index of the smallest element
        p.erase(p.begin());  //delete the minimum
        printf("%d",Hash[index]);
        sum++;
        if(sum!=count)
            printf(" ");
        for(j=0;j<n;j++)
        {
            if(A[index][j]!=0)
            {
                degree[j]--;
                if(degree[j]==0)  //if the entry degree of j is 0 after delete index
                    p.insert(Hash[j]);  //insert j and sort them
            }
        }
    }

}


#endif //HASHING_TARGET_H
