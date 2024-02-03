#include <bits/stdc++.h>
using namespace std;

bool BFS(int u, vector<int> adj[], vector<bool> &visited)
{

    queue<pair<int, int>> q; //  { curr node ,  its parent }
    q.push({u, -1});
    visited[u] = true;

    while (!q.empty())
    {

        auto temp = q.front();
        int curr = temp.first, parent = temp.second;
        q.pop();

        for (auto v : adj[curr])
        {
            if (v == parent)
                continue;
            if (visited[v])
                return true;
            visited[v] = true;
            q.push({v, curr});
        }
    }
    return false;
}

bool isCycle(int v, vector<int> adj[])
{
    vector<bool> visited(v, false);

    for (int i = 0; i < v; i++) // for all taking all components into consideration
    {
        if (!visited[i])
            if (BFS(i, adj, visited))
                return true;
    }

    return false;
}
int main()
{

    return 0;
}