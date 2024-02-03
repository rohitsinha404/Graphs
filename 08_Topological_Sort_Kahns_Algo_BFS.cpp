
#include <bits/stdc++.h>
using namespace std;

// The simple logic is: if the indegree of any node is 0,
//       --:> this means there's no more dependency on another vertex, so it can be printed in the toposort.
// Maintain an indegree vector of all vertices and update it whenever any dependency is removed.

vector<int> topoSort(int v, vector<int> adj[])
{
    vector<int> inDegree(v, 0);

    for (int i = 0; i < v; i++)
        for (auto it : adj[i])
            inDegree[it]++;

    queue<int> q;

    for (int i = 0; i < v; i++)
        if (inDegree[i] == 0)
            q.push(i);

    vector<int> ans;

    while (!q.empty())
    {

        int curr = q.front();
        ans.push_back(curr);
        q.pop();

        for (auto &it : adj[curr])
        {
            inDegree[it]--;

            if (inDegree[it] == 0)
                q.push(it);
        }
    }

    return ans;
}

int main()
{
    return 0;
}