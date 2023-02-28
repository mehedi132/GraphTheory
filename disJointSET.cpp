#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int parent[15];

void makeset(int u)
{
    parent[u] = u;
}

int findRepresentative(int a)
{
    if(parent[a]==a)
    {
        return a;
    }
    else{
        
        //return findRepresentative(parent[a]);
        parent[a] = findRepresentative(parent[a]);
        return parent[a];
    }
}

void makefriend(int a,int b)
{
    int u, v;
    u = findRepresentative(a);
    v = findRepresentative(b);
    if(u!=v)
    {

        parent[u] = v;
    }
}



int main()
{
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int a[] = {1, 2, 3, 4, 5, 6};
int i;
for (i = 0; i < 6;i++)
{
        makeset(a[i]);
}
makefriend(1, 5);
makefriend(1, 2);
makefriend(3, 4);
makefriend(2, 4);
makefriend(4, 5);


for (i = 1; i < 6;i++)
{
        cout<<parent[i]<<" ";
}

}