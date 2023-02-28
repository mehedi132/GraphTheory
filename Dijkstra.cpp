#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<pair<int, int>> egdeC[15];
vector<int> distance1(15, 9999);
vector<int> path(15, 0);

void constractGraph(int n,int edge)
{
    int x, y, z;
    for (int i = 0; i < edge;i++)
    {
        pair<int, int> p;
    cin >> x >> y >> z;
    p=make_pair(y, z);
    egdeC[x].push_back(p);
    }
   
}
void patho(int s, int d)
{
    int a;

    cout << d;
    a = path[d];
    while(a!=s)
    {
        
        if(a==0)
        {
            cout << "nno path";
            return;
        }
    cout << "<-" << a;
     a = path[a];

    }
    cout << "<-" << s;
}


int main()
{
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int node, edge1;
    cin >> node >> edge1;
    queue<int> q;
    constractGraph(node, edge1);
    int u,v,c;
    cin >> u;
    //distance[0] = 0;
    distance1[u] = 0;
    q.push(u);
    while(!q.empty())
    {
     u = q.front();
     q.pop();
     for (int i = 0; i < egdeC[u].size();i++)
     {
         v = egdeC[u][i].first;
         c = egdeC[u][i].second;
         if(distance1[u]+c<distance1[v])
         {
             distance1[v] = distance1[u] + c;
             path[v] = u;
             q.push(v);
         }
     }
    }

    patho(1, 5);
}