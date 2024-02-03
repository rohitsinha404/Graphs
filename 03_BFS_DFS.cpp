#include <bits/stdc++.h>
using namespace std;

// =================================DFS===================================
// TC --> o (v+e)  , sc --> o(v)
vector<int> res;
void DFS(int u, vector<int> adj[], vector<bool> &visited)
{

    if (visited[u] == true)
        return;
    visited[u] = true;

    // do the job here  , let say  , here we have to return a vector having DFS of the graph
    res.push_back(u);

    for (auto it : adj[u])
        if (!visited[it])
            DFS(it, adj, visited);
}

vector<int> DFSOfGraph(int v, vector<int> adj[])
{
    vector<bool> visited(v + 1, false);
    DFS(0, adj, visited);
    return res;
}

// =================================BFS===================================
// TC --> o (v+e)  , sc --> o(1)
void BFS(int u, vector<int> adj[], vector<bool> &visited, vector<int> &res)
{
    queue<int> q;
    q.push(u);
    res.push_back(u);
    visited[u] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto it : adj[curr])

            if (!visited[it])
            {
                visited[it] = true;
                res.push_back(it);
                q.push(it);
            }
    }
}
vector<int> bfsOfGraph(int v, vector<int> adj[])
{
    vector<bool> visited(v + 1, 0);
    vector<int> res;
    BFS(0, adj, visited, res);
    return res;
}
int main()
{
    return 0;
}
