
class Solution {
    int LOG;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth;
    vector<int> bit;
    vector<int> initial;
    int timer = 0;

    void add(int i, int val, int n) {
        for (; i <= n; i += i & -i)
            bit[i] ^= val;
    }

    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    void dfs(int u, int p, int n, string &s) {
        tin[u] = ++timer;
        up[0][u] = p;
        depth[u] = (u == p ? 0 : depth[p] + 1);

        initial[u] = (1 << (s[u] - 'a'));
        for (int j = 1; j < LOG; j++)
            up[j][u] = up[j - 1][up[j - 1][u]];

        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, n, s);
        }

        tout[u] = timer;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for (int j = 0; j < LOG; j++)
            if (diff & (1 << j))
                u = up[j][u];

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }
        return up[0][u];
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        adj.assign(n, {});
        up.assign(LOG, vector<int>(n));
        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        initial.resize(n);
        bit.assign(n + 2, 0);
        timer = 0;

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, 0, n, s);

        // Initial root-to-node XOR masks.
        vector<int> pref(n);
        for (int u = 0; u < n; u++) {
            pref[u] = initial[u];
            if (u != 0)
                pref[u] ^= pref[up[0][u]];
        }

        vector<bool> ans;

        for (string &q : queries) {
            string type;
            int u, v;
            char c;
            stringstream ss(q);
            ss >> type;

            if (type == "update") {
                ss >> u >> c;

                int newMask = 1 << (c - 'a');
                int delta = initial[u] ^ newMask;
                initial[u] = newMask;
                s[u] = c;

                // Change the root-path XOR for all descendants.
                add(tin[u], delta, n);
                add(tout[u] + 1, delta, n);
            } else {
                ss >> u >> v;

                int a = lca(u, v);

                int pu = pref[u] ^ sum(tin[u]);
                int pv = pref[v] ^ sum(tin[v]);

                int mask = pu ^ pv ^ initial[a];

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
