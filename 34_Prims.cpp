#include <bits/stdc++.h>
using namespace std;

int prims_wt(int v, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // pushing the very first node

    vector<bool> inMST(v, false); // to make sure any node is not added twice

    int sum = 0;

    while (!pq.empty())
    {

        // getting the minimum wt edge
        auto curr = pq.top();
        int wt = curr.first, node = curr.second;
        pq.pop();

        // if its already in MST , then skip
        if (inMST[node])
            continue;

        // else add it in the MST
        inMST[node] = 1;
        sum += wt;

        for (auto it : adj[node])
        {

            int w = it[1], adjNode = it[0];

            // if the vertex is not in MST , edge can have a potenial to have min wt
            // therefore pushing it in the queue as an future option
            if (inMST[adjNode] == false)
                pq.push({w, adjNode});
        }
    }

    return sum;
}

int main()
{
    return 0;
}