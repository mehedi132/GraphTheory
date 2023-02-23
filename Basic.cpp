#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int node,edge1;
cin>>node>> edge1;

vector<int> edge[100];
vector<int> cost[100];
for (int i = 0; i < edge1;i++)
{
    int x, y;
    cin >> x >> y ;
    edge[x].push_back(y);
   // edge[y].push_back(x);
    //cost[x].push_back(1);
   // cost[y].push_back(1);
}
//int s = cost[5].size();

for (int j = 1; j <= node;j++)
{
    cout << " outdegree Node " << j << "=";
    for (int i = 0; i < edge[j].size(); i++)
    {
        cout << edge[j][i] << " ";
    }
    cout << endl;
}
cout << endl;

for (int j = 1; j <= node;j++)
{
    cout << "INdegree Node " << j << "=";
    for (int k = 1; k <= node;k++)
       {
             for (int i = 0; i < edge[k].size(); i++)
                { if(edge[k][i]==j)
                   cout << k << " ";
                }  

       }
cout << endl;
    
}


    

// int a[10][10];

// for (int i = 0; i < edge;i++)
// {
// int x, y, c;
// cin >> x >> y >> c;
// a[x][y] = c;
// a[y][x] = c;
// }
// if(a[1][3])
// {
// cout << "has edge";
// }
// else{
//     cout << "no edge";
// }
//cout<<a[2][3];
    
}

