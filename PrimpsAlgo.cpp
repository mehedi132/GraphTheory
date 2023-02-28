#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class minpriorityQueue
{

public:
   bool operator()(const pair<int,int> &a,const pair<int,int> &b)
   {
       return a.second > b.second;
   }
    
};







int main()
{
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
int n, e;
cin >> n >> e;
vector<pair<int, int>> edge[15];
int i,x,y,z;
for (i = 0; i < e;i++)
{
    cin >> x >> y >> z;
    edge[x].push_back(make_pair(y, z));
    edge[y].push_back(make_pair(x, z));
}
vector<int> r;
vector<int> v(10,0);


priority_queue<pair<int, int>,vector<pair<int, int>>,minpriorityQueue> q;
int s = 1, res = 0, t;
v[s] = 1;
r.push_back(s);
for (i = 1; i <=n;i++)
{
    
    for (int j = 0; j < edge[s].size();j++)
    {
        if(v[edge[s][j].first]==0)
        {
        q.push(edge[s][j]);
        cout << s << " from we go ";
        cout << edge[s][j].first << " cost " << edge[s][j].second << endl;
        }
    }
    

    cout << endl;
        cout << endl;
    s = q.top().first;
     t = q.top().second;
    cout << "min cost node " << s << endl;
    q.pop();
    if(v[s]==1)
    //while(v[s]==1)
    {
        cout << "visited already= "<<s<<endl;
       // q.pop();
        s = q.top().first;
        t = q.top().second;
        cout <<"nxt node to visit "<< s<< endl;
         q.pop();
        
  
    }
    //else{
    v[s] = 1;
    
    int a = 0,b;
    for (auto it = r.begin(); it < r.end();it++)
{
         b = *it;
         
         if (*it == s)
         {
        a++;
         break;
         }
}
cout << endl;
if(a==0)
{
    r.push_back(s);
    res += t;

}
    

    //}
}

for (auto it = r.begin(); it < r.end();it++)
{
    cout << *it << " ";
}
cout << endl;


for (auto it = v.begin(); it < v.end();it++)
{
    cout << *it << " ";
}
cout << endl;
cout << "total cost= " << res;
}