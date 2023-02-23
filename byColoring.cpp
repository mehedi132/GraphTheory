#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> edge[100];
 int p[20],c[20];
 void constructGraph(int n, int e)
 {
     // vector<int> edge[100];

     for (int i = 0; i < e; i++)
     {
         int x, y;
         cin >> x >> y;
         edge[x].push_back(y);
         edge[y].push_back(x);
     }
}


void printPath(int s,int d)
{
int a;
a = d;
while(a>=s)
{
    cout << a;
    if(a>s)
    {
        cout << "<-";
    }
    a = p[a];
}
}


int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int node,edge1;
cin>>node>> edge1;
queue<int> q;
int level[20];
for (int i = 1; i < 20;i++)
{
    level[i] = 999;
    p[i] = 0;
    c[i] = 0;
}
constructGraph(node, edge1);
q.push(1);
int u,v;
u = 1;
level[u] = 0;
c[u] = 1;
int z = 0;
while(!q.empty())
{    
    u = q.front();
    q.pop();
    for (int i = 0; i < edge[u].size();i++)
    {
        v = edge[u][i];
       if(level[v]==999)
        {
            level[v] = level[u] + 1;
            p[v] = u;
            q.push(v);

            if(c[v]==0)
            {
                if(c[u]==1)
                {
                     c[v] = 2;
                }
                else
                {
                    c[v] = 1;
                }
               
            }
            if(c[u]==c[v])
            {
                cout << u << " " << v<<endl;
                cout <<"u="<<c[u]<<" v="<<c[v] <<"not"<<endl;
                z++;
                break;
            }
           
        }
            
        
    }
}
if(z==0)
{
 cout << "by color"<<endl;
}
   
 for (int i = 1; i < 20;i++)
 {
     cout<<c[i] <<" ";
 }
// cout << level[10];
// cout << endl;


// int b;
// // b = 9;
// // while(b>=1)
// // {
// //     cout << b << "<-";
// //     b = p[b];
// // }
// cout << endl;
// printPath(2, 9);

// int n = 1;


}
