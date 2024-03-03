#include <bits/stdc++.h>
using namespace std;

// utility to get path
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string dirDict = "RLDU";

char mpp[1001][1001];

// child coordinates ---> {parent coord , which movement}
map<pair<int, int>, pair<pair<int, int>, char>> parent;

pair<int, int> dest, src;

bool bfs(int i, int j, vector<vector<bool>> &vis, int n, int m)
{

    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = 1;

    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();
        int dirCnt = -1;
        // checking all directions
        for (auto [di, dj] : dir)
        {
            int x = di + i, y = dj + j;
            dirCnt++;

            // for out of bound cases
            if (!(x >= 0 and x < n and y >= 0 and y < m))
                continue;

            // dest found
            if (mpp[x][y] == 'B')
            {
                dest = {x, y};                              // populating dest
                parent[{x, y}] = {{i, j}, dirDict[dirCnt]}; // adding in map
                return true;
            }
            else if (mpp[x][y] == '.' and vis[x][y] == false)
            {

                q.push({x, y});
                parent[{x, y}] = {{i, j}, dirDict[dirCnt]};
                vis[x][y] = 1;
            }
        }
    }

    return false;
}

int main()
{
    // taking input
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> mpp[i][j];
            if (mpp[i][j] == 'A')
                src = {i, j};
        }

    // adding src to defined via # in map

    parent[src] = {src, '#'};

    // if bfs can find dest then this case
    if (bfs(src.first, src.second, vis, n, m))
    {

        int i = dest.first, j = dest.second;
        string ans = "";

        // backtracking
        while (1)
        {
            auto [pi, pj] = parent[{i, j}].first; // getting parent coordinates
            char path = parent[{i, j}].second;    // getting which moves was taken

            if (path == '#') // found src
                break;

            ans = path + ans;

            i = pi;
            j = pj;
        }

        cout << "YES" << endl
             << ans.size() << endl
             << ans << endl;
    }
    else // couldnt find the way
        cout << "NO" << endl;

    return 0;
}