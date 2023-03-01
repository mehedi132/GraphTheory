#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> edge[10];
vector<int> rev_edge[10];
vector<int> componennt[10];
vector<int> c(20, 0);
vector<int> visited(20, 0);
stack<int> s,q;
int n, e,x,y;
int i,j,v,mark=0;

void DFS(vector<int> a[], int u)
{
    c[u] = 1;
    for (i = 0; i < a[u].size();i++)
    {
        v = a[u][i];
        if(c[v]==0)
        {
            DFS(a, v);
        }

    }

    c[u] = 2;
    s.push(u);
     q.push(u);
}
void DFS2(vector<int> a[], int u, int mark) 
{
    componennt[mark].push_back(u);
    visited[u] = 1;
    for (i = 0; i < a[u].size();i++)
    {
        v = a[u][i];
        if(visited[v]==0) //prb
        {
            DFS2(a, v, mark);
        }
    }
}

void findSCC(vector<int> a[])
{
    // for (i = 1; i <=n;i++)
    //   { for (j = 0; j < a[i].size();j++)
    //     {
    //         v = a[i][j];
    //         if(c[v]==0) // answer given 
    //                     //Component 1: 4 3 2 1 
    //                     //Component 2: 5 7 6 
    //         {
    //             DFS(a, v);
    //         }
    //     }
       
    //    }


    DFS(a, 1);  //correct anns is Component 1: 1 3 2 
                //Component 2: 4 
                 //Component 3: 5 7 6 



//     cout << "Stack= ";
//     while(!q.empty())
// {
//         cout << q.top() << " "; 
//         q.pop();
// }
// cout << endl;


int t;
while (!s.empty())
{
        t = s.top();
        s.pop();
        if(visited[t]==0)
        {
             mark += 1;
             DFS2(rev_edge, t, mark);
        }
       }

       for (i = 1; i <= mark;i++)
       {
        cout << "Component " << i  << ": ";
        for (auto it : componennt[i])
        {

             cout << it << " ";
         }
         cout << endl;
       }
}

int main()
{
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
//int n, e,x,y;
cin >> n >> e;
int i;
for (i = 0; i < e;i++)
{
        cin >> x >> y;
        edge[x].push_back(y);
        rev_edge[y].push_back(x);

}
// int u = 1;
// c[u] = 1;
//     for (i = 0; i < edge[u].size();i++)
//     {
//         v = edge[u][i];
//         if(c[v]==0)
//         {
//             DFS(edge, v);
//         }

//     }

//     c[u] = 2;
//     s.push(u);

findSCC(edge);



}


