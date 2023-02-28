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
// priority_queue<int,vector<int>,minpriorityQueue> a;
// a.push(1);
// a.push(5);
// a.push(3);

// while(!a.empty())
// {
//     cout << a.top() << " ";
//     a.pop();
// }

priority_queue < pair<int, int>,vector<pair<int, int>>,minpriorityQueue> a;
a.push(make_pair(10, 2));
a.push(make_pair(5, 100));
a.push(make_pair(30, 200));

while(!a.empty())
{
    cout << a.top().first << " "<<a.top().second<<endl;
    a.pop();
}

}