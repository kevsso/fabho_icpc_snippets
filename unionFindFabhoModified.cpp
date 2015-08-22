#include <iostream>
#include <cstdio>

#define ELEMENTS        1000

using namespace std;

int parent[ELEMENTS];//points to its parent or its representative of its set
int rank[ELEMENTS];
int numDisjointSets;

//for faster implementation and less function calls we don't call make set
//n times we only call make sets 1 time.

void make_sets(int number_of_elements)
{
    numDisjointSets = number_of_elements;
    int i;
    for(i = 0; i < number_of_elements; i++)
    {
        parent[i] = i;
        rank[i] = 1;
    }
}

int find_set(int element)
{
    if(element != parent[element])
        parent[element] = find_set(parent[element]);
    return parent[element];
}

bool isSameSet(int i, int j)
{
    return find_set(i) == find_set(j);
}

void set_union(int x, int y)//where x and y are elements of different sets
{
    int rx, ry; //roots or representatives of x and y sets
    rx = find_set(x);
    ry = find_set(y);
    if(rx == ry) // it means the elements already are in the same set
        return;

    numDisjointSets--;
    if(rank[rx] > rank[ry])
    {
        rank[rx] += rank[ry];
        parent[ry] = rx;
    }
    else
    {
        rank[ry] += rank[rx];
        parent[rx] = ry;
    }

    //rank[ry] += rank[rx];
    //parent[rx] = ry;

}

int getNumSets()
{
    return numDisjointSets;
}

int sizeOfSet(int i)
{
    return rank[find_set(i)];
}

int main()
{
    int number_of_elements;
    int s1, s2;
    int unions;
    int finds;
    int i,j;
    int sizes;
    scanf("%d", &number_of_elements);
    make_sets(number_of_elements);
    //perform any of the required set operations.
    cout<<"initial sets"<<endl;
    for(i = 0; i < number_of_elements; i++)
        cout<<parent[i]<<" ";
    cout<<endl;
    cout<<"initial ranks"<<endl;
    for(i = 0; i < number_of_elements; i++)
        cout<<rank[i]<<" ";
    cout<<endl;
    //some operations
    //unions
    scanf("%d", &unions);
    for(i = 0; i < unions; i++)
    {
        scanf("%d %d", &s1, &s2);
        set_union(s1,s2);
        cout<<"sets: ";
        for(j = 0; j < number_of_elements; j++)
            cout<<parent[j]<<" ";
        cout<<endl;
        cout<<"ranks: ";
        for(j = 0; j < number_of_elements; j++)
            cout<<rank[j]<<" ";
        cout<<endl;
    }
    //finds
    scanf("%d", &finds);
    for(i = 0; i < finds; i++)
    {
        scanf("%d", &s1);
        cout<<s1<<" belongs to the set: "<<find_set(s1)<<endl;
        for(j = 0; j < number_of_elements; j++)
            cout<<parent[j]<<" ";
        cout<<endl;
        for(j = 0; j < number_of_elements; j++)
            cout<<rank[j]<<" ";
        cout<<endl;
    }

    int setSize;
    cout<<"Finding size\n";
    cin>>sizes;

    for(i = 0; i < sizes; i++)
    {
        scanf("%d", &setSize);
        cout<<setSize<<" size is: "<<sizeOfSet(setSize)<<endl;
    }

    return 0;
}
