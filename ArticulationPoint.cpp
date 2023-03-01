#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> edge[10];
int t = 0;
vector<int> d(20, 0);
vector<int> low(20, 0);
vector<int> visited(20, 0);
vector<int> parent(20, 0);
vector<int> point;
int child = 0;

void findArticulationPoint(vector<int> a[],int u)
{
    t += 1;
    low[u] = t, d[u] = t;
    visited[u] = 1;
    child += 1;
    int i;
    int v;
    for (i = 0; i < a[u].size();i++)
    {
        v = a[u][i];
        if(v== parent[u])
        {

            continue;
        }
        if(visited[v])
        {
            low[u] = min(low[u], d[v]);

        }
        else{
            parent[v] = u;
            findArticulationPoint(a, v);
            low[u] = min(low[u], low[v]);
            if(d[u]<=low[v] && parent[u]!=0)
            {
                point.push_back(u);
            }
            child += 1;
        }
        if(child>1 && parent[u]==0)
        {
            cout << "root= " << u << endl;
            point.push_back(u);

        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int n, e,x,y;
cin >> n >> e;
int i;
for (i = 0; i < e;i++)
{
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
}

findArticulationPoint(edge, 1);
for (auto it:point)
{
        cout << it << " ";
}
}