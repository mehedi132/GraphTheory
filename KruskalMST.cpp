#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct  node {
   int s, d;
};


class minpriorityQueue
{

public:
   bool operator()(const pair<node,int> &a,const pair<node,int> &b)
   {
       return a.second > b.second;
   }
    
};


int findReprensetive(int u, int p[])
{
if(p[u]==u)
  {
       return u;
  }
  else{
       return findReprensetive(p[u],p);
  }
}

void makef(int u,int v, int p[])
{

  p[u] = v;
}



int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif



int n, e;
cin >> n >> e;
int parent[n];

//vector<pair<int, int>> edge[15];
priority_queue<pair< node , int>,vector<pair< node , int>>,minpriorityQueue> q;

int i,x,y,z,s,d,c,r1,r2,res=0;

for (i = 0; i < e;i++)
{
       node n1;
       cin >> x >> y >> z;
       n1.s = x;
       n1.d = y;
       q.push(make_pair(n1, z));
     //  edge[x].push_back(make_pair(y, z));
       parent[x] = x;

      // edge[y].push_back(make_pair(x, z));
       parent[y] = y;
}

while(!q.empty())
{
       s = q.top().first.s;
       d=q.top().first.d;
       c = q.top().second;
       //cout << "s= " << s << " d= " << d << " c= " << c << endl;
       q.pop();
       r1 = findReprensetive(s, parent);
       r2 = findReprensetive(d, parent);
       if(r1!=r2)
       {
           makef(r1, r2, parent);
          // cout << " before res= " << res << " c= " << c << endl;
           res += c;
       }
}

cout <<"MST: "<< res;
}