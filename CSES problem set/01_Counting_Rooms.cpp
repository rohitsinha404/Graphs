#include <bits/stdc++.h>
using namespace std;
void solve();
int main()
{
    // problem link : https://cses.fi/problemset/task/1192
    solve();
    return 0;
}
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int i, int j, vector<string> &mpp, vector<vector<bool>> &visited, int n, int m)
{
    visited[i][j] = true;
    for (auto [di, dj] : dir)
    {
        int x = i + di, y = j + dj;
        /*
             checking if x and y are in bound
             is it a wall
             if it is still left to be marked
         */
        if ((x >= 0 and x < n and y >= 0 and y < m) and (mpp[x][y] == '.') and (visited[x][y] == false))
            dfs(x, y, mpp, visited, n, m);
    }
}

void bfs(int i, int j, vector<string> &mpp, vector<vector<bool>> &visited, int n, int m)
{

    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;

    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        for (auto [di, dj] : dir)
        {
            int x = i + di, y = j + dj;
            if ((x >= 0 and x < n and y >= 0 and y < m) and (mpp[x][y] == '.') and (visited[x][y] == false))
            {
                visited[x][y] = true;
                q.push({x, y});
            }
        }
    }
}
void solve()
{

    // taking input
    int n, m;
    cin >> n >> m;

    vector<string> mpp(n);

    for (int i = 0; i < n; i++)
        cin >> mpp[i];

    // intializing helping var
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int roomCount = 0;

    // calling dfs for each and every univisted room

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mpp[i][j] == '.' and visited[i][j] == false)
            {

                // dfs(i, j, mpp, visited, n, m);  using DFS
                bfs(i, j, mpp, visited, n, m); // using BFS

                roomCount++;
            }

    cout << roomCount << endl;
}