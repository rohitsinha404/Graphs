#include <bits/stdc++.h>
using namespace std;

bool DFS(int src, vector<int> adj[], vector<bool> &visited, vector<bool> &inRecursion)
{

    inRecursion[src] = true;
    visited[src] = true;

    for (auto it : adj[src])
    {

        if (visited[it] and inRecursion[it])
            return true;

        if (!visited[it])
            if (DFS(it, adj, visited, inRecursion))
                return true;
    }

    inRecursion[src] = false;

    return false;
}

bool isCyclic(int v, vector<int> adj[])
{
    vector<bool> visited(v + 1, false), inRecursion(v + 1, false);

    for (int i = 0; i < v; i++)
    {
        if (!visited[v])
            if (DFS(i, adj, visited, inRecursion))
                return true;
    }

    return false;
}

// approach --> pretty similar to that of directed graph  , but only change here is parent cant be visited again  , so instead we maintained a inrecursion / inpath vector  , that can maintain a record of whether the current node is already visited in the current traversal  , if yes then it signifies that its cyclic
int main()
{

    return 0;
}