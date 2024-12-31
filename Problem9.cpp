#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr) return false;

        if (rank[xr] < rank[yr]) {
            parent[xr] = yr;
        } else if (rank[xr] > rank[yr]) {
            parent[yr] = xr;
        } else {
            parent[yr] = xr;
            rank[xr]++;
        }
        return true;
    }
};

bool canBeConnected(int n, long long maxGold, long long maxSilver, const vector<tuple<int, int, long long, long long>>& edges) {
    DSU dsu(n);
    for (const auto& edge : edges) {
        int u, v;
        long long gi, si;
        tie(u, v, gi, si) = edge;
        if (gi <= maxGold && si <= maxSilver) {
            dsu.unite(u, v);
        }
    }

    int representative = dsu.find(1);
    for (int i = 2; i <= n; ++i) {
        if (dsu.find(i) != representative) return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    long long g, s;
    cin >> g >> s;

    vector<tuple<int, int, long long, long long>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long gi, si;
        cin >> u >> v >> gi >> si;
        edges[i] = {u, v, gi, si};
    }

    // binary search
    long long left = 0, right = 1e18, result = -1;
    while (left <= right) {
        long long mid = (left + right) / 2;

        bool found = false;
        for (long long maxGold = 0; maxGold * g <= mid; maxGold++) {
            long long maxSilver = (mid - maxGold * g) / s;
            if (canBeConnected(n, maxGold, maxSilver, edges)) {
                found = true;
                break;
            }
        }

        if (found) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}