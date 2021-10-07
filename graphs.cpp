//inplementing undirected graph using matrix
//space complexcity is n^2
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter the number of vertex and nodes\n";
    cin >> n >> m;

    //n =vertex m=edges
    int u, v;
    int mat[n + 1][m + 1];
    for (int i = 0; i < m; i++)
    {
        cout << "Enter the nodes connected through edges :";
        cin >> u >> v;
        mat[u][v] = 1;
        mat[v][u] = 1;
        cout << endl;
    }

    ///////////implementation of the undirected graphs using STL  with less space complexicity
    //space complexcity is (n+edges*2)

    int n, m;
    //n=edges;
    //m=edges;
    cout << "Enter the number of vertex and nodes\n";
    cin >> n >> m;
    vector<int> mat[m];
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cout << "Enter the nodes connected through edges :";
        cin >> u >> v;
        mat[u].push_back(v);
        mat[v].push_back(u);
        cout << endl;
    }

    //////// undirected graphs with weights/////////
    //space complexcity is (n+edges*2+2*edges)
    int n, m;
    //n=edges;
    //m=edges;
    cout << "Enter the number of vertex and nodes\n";
    cin >> n >> m;
    vector<pair<int, int>> mat[m];
    int u, v, weight;
    for (int i = 0; i < m; i++)
    {
        cout << "Enter the nodes connected through edges and the weight respectively :";
        cin >> u >> v >> weight;
        mat[u].push_back({v, weight});
        mat[v].push_back({u, weight});
        cout << endl;
    }

    return 0;
}