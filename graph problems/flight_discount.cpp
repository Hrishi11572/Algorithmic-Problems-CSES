// dp like state space formulation
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
#define f first
#define s second

signed main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<lli, int>>> g;
    g.resize(n + 1);

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        lli e;
        cin >> u >> v >> e;
        g[u].push_back({v, e}); // Uni .. node, dist
    }

    vector<vector<lli>> dist(n + 1, vector<lli>(2, 1e18));
    vector<vector<int>> vis(n + 1, vector<int>(2, 0));
    dist[1][0] = 0;
    priority_queue<pair<lli, pair<int, int>>> q; // dist, node, flag
    q.push({0, {1, 0}});

    while (!q.empty())
    {
        auto n = q.top();
        q.pop();

        if (vis[n.s.f][n.s.s])
            continue;
        vis[n.s.f][n.s.s] = 1;

        for (auto v : g[n.s.f])
        {
            // all neighbours

            // case1 : coupon not used
            if (dist[v.f][n.s.s] > dist[n.s.f][n.s.s] + v.s)
            {
                dist[v.f][n.s.s] = dist[n.s.f][n.s.s] + v.s;
                q.push({-1 * dist[v.f][n.s.s], {v.f, n.s.s}});
            }

            // case2 : coupon used
            if (n.s.s == 0)
            {
                if (dist[v.f][1] > dist[n.s.f][0] + floor(v.s / 2))
                {
                    dist[v.f][1] = dist[n.s.f][0] + floor(v.s / 2);
                    q.push({-1 * dist[v.f][1], {v.f, 1}});
                }
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]) << endl;
}