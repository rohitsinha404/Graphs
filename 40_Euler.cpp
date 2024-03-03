#include <bits/stdc++.h>
using namespace std;

// simple dfs
void dfs(int u, vector<int> adj[], vector<bool> &visited)
{
    visited[u] = true;

    for (auto it : adj[u])
        if (!visited[it])
            dfs(it, adj, visited);
}

// to checking if there are multiple components or diffrent comp have 0 deg
bool isConnected(int v, vector<int> adj[])
{

    // find the first non zero degree node
    int nonZero = -1;

    for (int i = 0; i < v; i++)
        if (adj[i].size() > 0)
        {
            nonZero = i;
            break;
        }

    vector<bool> visited(v, false);

    dfs(nonZero, adj, visited);

    for (int i = 0; i < v; i++)
        if (!visited[i] and adj[i].size() > 0)
            return false;

    return true;
}

int isEulerCircuit(int v, vector<int> adj[])
{

    if (!isConnected(v, adj))
        return 0;

    int oddDegree = 0;

    for (int i = 0; i < v; i++)
        if (adj[i].size() % 2 == 1)
            oddDegree++;

    if (oddDegree > 2)
        return 0;

    else if (oddDegree == 2)
        return 1;

    else // oddDegree == 2 , Circuit
        return 2;
}

int main()
{
    return 0;
}