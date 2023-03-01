#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int n, e,x,y,c,u,v;
cin >> n >> e;
vector<int> node;
vector<pair<int,int>> edge[10];
int path[n + 1];
int i,j,k=0;
for (i = 0; i < e;i++)
{
    cin >> x >> y >> c;
    node.push_back(x);
    edge[x].push_back(make_pair(y, c));
}

int s = 1;
vector<int> d(10, 999);
d[s] = 0;
for (i = 0; i < n - 1;i++)
{
    for (k = 0; k < n;k++)
    {
        for (j = 0; j < edge[node[k]].size(); j++)
        {
            u = node[k];
            v = edge[u][j].first;
            if(d[u]+edge[u][j].second< d[v])
            {
                d[v] = d[u] + edge[u][j].second;
                path[v]=u;
            }
        }
    }     
}

for (k = 0; k < n;k++)
    {
        for (j = 0; j < edge[node[k]].size(); j++)
        {
            u = node[k];
            v = edge[u][j].first;
            if(d[u]+edge[u][j].second< d[v])
            {
                cout << "Negetive cycle found";
                return 0;
            }
        }
    }
    cout << "path is from source" << endl;
    int so = 1, de = 6;
    while(so!=de)
    {
        cout << de << "<-";
        de = path[de];
    }
    cout << so;
}