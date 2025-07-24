#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char dir[4] = {'R', 'L', 'D', 'U'};

signed main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m, '?'));
    vector<pair<int, int>> monster, exits;
    pair<int, int> A;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 'A')
                A = {i, j};

            if ((i == 0 || i == n - 1) && (g[i][j] == '.'))
            {
                exits.push_back({i, j});
            }
            if ((j == 0 || j == m - 1) && (g[i][j] == '.'))
            {
                exits.push_back({i, j});
            }
            if (g[i][j] == 'M')
            {
                monster.push_back({i, j});
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<int, int>> q;
    for (auto c : monster)
    {
        dist[c.f][c.s] = 0;
        q.push(c);
    }

    // multisource bfs from monsters to all the edges
    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        if (vis[i][j])
            continue;
        vis[i][j] = 1;

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#')
            {
                if (dist[x][y] > dist[i][j] + 1)
                {
                    dist[x][y] = dist[i][j] + 1;
                    q.push({x, y});
                }
            }
        }
    }

    // bfs from A to all the exits
    vector<vector<int>> distA(n, vector<int>(m, 1e9));
    vector<vector<int>> visA(n, vector<int>(m, 0));

    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> move(n, vector<char>(m));

    queue<pair<int, int>> qA;
    qA.push(A);
    distA[A.first][A.second] = 0;

    while (!qA.empty())
    {
        auto [nx, ny] = qA.front();
        qA.pop();

        if (visA[nx][ny])
            continue;
        visA[nx][ny] = 1;

        for (int k = 0; k < 4; k++)
        {
            int x = nx + dx[k];
            int y = ny + dy[k];

            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#')
            {
                if (distA[x][y] > distA[nx][ny] + 1)
                {
                    distA[x][y] = distA[nx][ny] + 1;
                    parent[x][y] = {nx, ny};
                    move[x][y] = dir[k];
                    qA.push({x, y});
                }
            }
        }
    }

    // check if the distance of any exit is lesser for A compared to the neareset monster

    bool found = false;
    pair<int, int> end;

    for (auto v : exits)
    {
        if (distA[v.f][v.s] < dist[v.f][v.s])
        {
            found = true;
            end = v;
            break;
        }

        //   cout << "A : " << distA[v.f][v.s] << " , M : " << dist[v.f][v.s] << endl;
    }

    if (found)
    {
        // print the path
        cout << "YES" << endl;
        string path = "";

        pair<int, int> cur = end;

        while (cur != A)
        {
            path += move[cur.f][cur.s];
            cur = parent[cur.f][cur.s];
        }

        reverse(path.begin(), path.end());

        cout << path.length() << endl;
        cout << path << endl;
    }
    else
    {
        // if no edge . and no monster i.e only A then yes
        // if no edge . and there are monsters  then no
        if ((exits.size() == 0) && (monster.size() == 0))
        {
            cout << "YES" << endl;
            cout << 0 << endl;
        }
        else
        {
            cout << "NO" << endl ; 
        }
    }
}