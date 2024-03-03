#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int v, vector<vector<int>> &edges, int s)
{
    vector<int> dist(v, INT_MAX);
    dist[s] = 0;

    // belman ---> relax all edges in same order v-1 times
    for (int i = 1; i <= v - 1; i++)

        for (auto it : edges)
        {
            int u = it[0], v = it[1], wt = it[2];
            // relaxing the edge
            if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) // can be relaxed or not ??
                dist[v] = dist[u] + wt;
        }

    // realxing one more time to check for neagtive cycle
    for (auto it : edges)
    {
        int u = it[0], v = it[1], wt = it[2];

        if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) // this edge can be realxed once more , therefore , it contains -ve cycle
            return {-1};
    }

    return dist; // no -ve cycle
}

// ============== TC =========
// O(EV)

int main()
{
    return 0;
}