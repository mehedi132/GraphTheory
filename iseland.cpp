#include<bits/stdc++.h>
#include<iostream>
using namespace std;



int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif



int e,i,j,u,v,V,w;
cin >> V >> e;
vector<vector<int>> adj[V];

vector<int> d(V, 999);
cout << d[2] << endl;
int p[V];
d[2] = 0;
p[2] = 2;

i = 0;
while(i++<e)
{
    cin >> u >> v >> w;
    vector<int> t1,t2;
    t1.push_back(v);
    t1.push_back(w);
    
    adj[u].push_back(t1);
    t2.push_back(u);
    t2.push_back(w);
    adj[v].push_back(t2);
    

}

int s = adj[0].size();
//cout << s << endl;
for (j = 2; j >=0;j--)
{
    cout << "from " << j << endl;
    for (auto it : adj[j])
    {
            u = j;
            v = it[0];
            w = it[1];
            cout << "from " << u<<" to "<<v << endl;
            cout << "previous dis " << d[v] << endl;
            if(d[u]+w<d[v])
            {
                d[v] = d[u] + w;
                cout << "new dis " << d[v] << endl;
                p[v] = u;
            }




        // for (auto itt : it)
        // {
            
        //     cout << itt << " ";
        // }
        // cout << endl;
    }

}
cout << "dis" << endl;
for (auto i : d)
{
    cout << i << " ";
        }
        cout << endl;
cout << "par" << endl;
        for (auto i :p)
        {            
            cout << i << " ";
        }
        cout << endl;

    
}
