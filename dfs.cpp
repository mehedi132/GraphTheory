#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> edge[20];
int path[20];
vector<int> visited(20, 0);

void constractGraph(int n,int e)
{
    int x, y;
    for (int i = 0; i < e;i++)
    {
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
    a = path[a];
}
}
void dfs(int i)
{
visited[i] = 1;
int v;
cout << i << " ";
for (int j = 0; j < edge[i].size();j++)
{
    v = edge[i][j];
    if(visited[v]==0)
    {
        dfs(v);
    }
}

}



int main()
{
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int node, edge1;
    cin >> node >> edge1;
    constractGraph(node, edge1);
    dfs(1);
    // stack<int> s;
    // int u, v,z=0;
    // u = 1;
    // visited[u] = 1;
    // s.push(u);
    // while(!s.empty())
    // {
    //     for (int i = 0; i < edge[u].size();i++)
    //     {
    //         v = edge[u][i];
    //         path[v] = u;
    //         if(visited[u]==0)
    //           {
    //             visited[u] = 1;
    //             s.push(u);        
    //           }
    //       else{
    //          s.pop();
    //          if(!s.empty())
    //          {
    //            u = s.top();
    //          }
             
    //         }
    //    }         
    // }
    // cout << "h";
    // printPath(1, 9);
    //  cout << "h1";
}