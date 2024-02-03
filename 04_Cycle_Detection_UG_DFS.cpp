#include <bits/stdc++.h>
using namespace std;

// do DFS traversal of graph, and if  u end up on any node which is already visited then it signifies that there's a cycle in graph

// just make sure ,DFS dont go back , using parent var

bool DetectCycle(int src, int parent, vector<int> adj[], vector<bool> &visited)
{
    visited[src] = true;

    for (auto &v : adj[src])
    {
        if (parent == v) // making sure its not going back
            continue;
        if (visited[v]) // BOOM !!  here is our cycle 🤩🤩
            return true;
        if (DetectCycle(v, src, adj, visited))
            return true;
    }

    return false;
}

int main()
{

    return 0;
}