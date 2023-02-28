#include<bits/stdc++.h>
#include<iostream>
using namespace std;



int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int n, e,x,y,u,v;
cin >> n >> e;
vector<int> edge[15];
vector<int> sorted;
vector<int> indegree(n+1,0);
int i;
queue<int> q;
for (i = 0; i < e;i++)
{
    cin >> x >> y;
    edge[x].push_back(y);
    indegree[y] += 1;
}

for(auto it:indegree)
{
    //cout << it << " ";
}
//cout << endl;

for (i = 1; i < indegree.size();i++)
{
    if(indegree[i]==0)
    {
        q.push(i);
    }
}
while(!q.empty())
{
    u = q.front();

    //cout << "u= " << u << endl;
    sorted.push_back(u);
    q.pop();
    for (i = 0; i < edge[u].size();i++)
    {
        v = edge[u][i];
        indegree[v] -= 1;
        if(indegree[v]==0)
        {
        
            q.push(v);
        }
    }

}
for (auto it :sorted)
{
    cout << it << " ";
}


}