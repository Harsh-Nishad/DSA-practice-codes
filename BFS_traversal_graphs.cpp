#include <bits/stdc++.h>
using namespace std;
int main()
{
    int node, edges;
    cout << "Enter the number of nodes and edge\n";
    cin >> node >> edges;
    vector<int> adj[node];
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cout << "Enter the nodes connected through edges :";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cout << endl;
    }

    vector<int> bfs;
    vector<int> visted(node + 1, 0);

    for (int i = 0; i <= node; i++)
    {
        if (visted[i] == 0)
        {
            queue<int> q;
            visted[i] == 1;
            q.push(i); //
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto it : adj[node])
                {
                    if (visted[it] == 0)
                    {
                        q.push(it);
                        visted[it] == 1;
                    }
                }
            }
        }
    }

    for (auto it = bfs.begin(); it != bfs.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}