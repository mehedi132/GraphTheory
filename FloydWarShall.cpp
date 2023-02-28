#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int main()
{
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int node, edge;  
    cin >> node >> edge;
    int matrix[node][node],path[node][node];
    int x, y, c;
    for (int i = 0; i < edge;i++)
    {
        cin >> x >> y >> c;
        matrix[x][y] = c;
    }
   

    int i, j, k;

for (i = 1; i <=node;i++)
    {
        for (j = 1; j <= node;j++)
        {
            path[i][j]=j;
        }

        cout << endl;
    }
cout << "stating path" << endl;
    for (i = 1; i <=node;i++)
    {
        for (j = 1; j <= node;j++)
        {
            cout << path[i][j] << " ";
        }

        cout << endl;
    }
    for (k = 1; k <= node;k++)
    {
        for (i = 1; i <= node;i++)
        {
            for (j = 1; j <= node;j++)
            {
                if(matrix[i][j]>matrix[i][k]+matrix[k][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    path[i][j] = path[i][k];
                }

            }
        }
    }
cout << "cost" << endl;
    for (i = 1; i <=node;i++)
    {
        for (j = 1; j <= node;j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
     cout << endl;
    cout << "path" << endl;
    for (i = 1; i <=node;i++)
    {
        for (j = 1; j <= node;j++)
        {
            cout << path[i][j] << " ";
        }

        cout << endl;
    }
        int s = 4;
    int d = 1;
    while(s!=d)
    {
        cout << s<<"->";
        s = path[s][d];
    }
    cout << s;
}