#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(E log v)

vector<int> Dijkstras_PQ(int v, vector<vector<int>> adj[], int s)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> res;

    res[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto &it : adj[node])
        {
            int adjNode = it[0];
            int wt = it[1];

            if (d + wt < res[adjNode])
            {
                res[adjNode] = d + wt;
                pq.push({d + wt, adjNode});
                int a = pq.size();
            }
        }
    }

    return res;
}

// better than PQ  , cause few iterations are avoided using erase !!
vector<int> dijkstra_SET(int v, vector<vector<int>> adj[], int s)
{
    set<pair<int, int>> st;

    st.insert({0, s});

    vector<int> res(v, INT_MAX);
    res[s] = 0;

    while (st.size() != 0)
    {

        auto curr = *st.begin();
        int d = curr.first, node = curr.second;
        st.erase(curr);

        for (auto it : adj[node])
        {

            int wt = it[1], adjNode = it[0];

            if (d + wt < res[adjNode])
            {
                res[adjNode] = d + wt;

                if (res[adjNode] != INT_MAX)
                    st.erase({res[adjNode], adjNode});

                st.insert({d + wt, adjNode});
            }
        }
    }

    return res;
}

// to find shortest path between s and dest
// printing the shortest path here
vector<int> shortestPathUsingDij(int v, int s, int dest, vector<vector<int>> adj[])
{
    set<pair<int, int>> st;
    st.insert({0, s});

    vector<int> res(v, INT_MAX);
    res[s] = 0;

    // for path
    vector<int> parent(v + 1);
    for (int i = 0; i <= v; i++)
        parent[i] = i;

    while (st.size() != 0)
    {

        auto curr = *st.begin();
        int d = curr.first, node = curr.second;
        st.erase(curr);

        for (auto it : adj[node])
        {

            int wt = it[1], adjNode = it[0];

            if (d + wt < res[adjNode])
            {
                res[adjNode] = d + wt;

                if (res[adjNode] != INT_MAX)
                    st.erase({res[adjNode], adjNode});

                st.insert({d + wt, adjNode});

                parent[adjNode] = node; // for path
            }
        }
    }

    vector<int> path;

    int node = dest; // the destination node
    if (res[node] == INT_MAX)
        return {-1}; // no path

    while (parent[node] != node)
    {
        path.push_back(node);
        node = parent[node];
    }

    path.push_back(s);
    reverse(path.begin(), path.end());

    return path;
}

int main()
{

    cout << 1 << endl;

    return 0;
}