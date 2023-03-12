#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> visited(10, 0);
queue<pair<int, int>> q;
bool findCycle(int s, vector<int> a[], vector<int> visited)
{
    visited[s] = 1;
    int p,u;
    q.push({s, -1});
    while(!q.empty())
    {

        u = q.front().first;
        p = q.front().second;
        q.pop();

        for (auto ad : a[u])
        {
            if(visited[ad]==0)
        {
            visited[ad] == 1;
            q.push({ad,u});
        }
        else
        {
            if(p!=ad)
            {
                return true;
            }
        }

        }
    }
    return false;
}


int main()
{
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int n, e,x,y,i;

vector<int> graph[15];
cin >> n >> e;
for (i = 0; i < n;i++)
{
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
}
int z = 1;
bool r;
r = findCycle(z, graph, visited);
cout << r;
}