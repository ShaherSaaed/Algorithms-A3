#include <bits/stdc++.h>

using namespace std;
const int N = 100000;
const int M = 200000;

int n, m;
int d[N + 5], bm;
long long b[M + 70];
pair<int, pair<int, int> > a[M + 5];
vector<pair<int, int> > v[N + 5];

int fin(int x) {
    if (d[x] == x) return x;
    return d[x] = fin(d[x]);
}

int dfs(int x, int fr) {
    int R = 1;
    for (int i = 0; i < v[x].size(); i++)
        if (v[x][i].first != fr) {
            int K = dfs(v[x][i].first, x);
            b[v[x][i].second] += 1ll * K * (n - K);
            R += K;
        }
    return R;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        cin >> a[i].second.first >> a[i].second.second >> a[i].first;
    sort(a, a + m);
    for (int i = 1; i <= n; i++) d[i] = i;
    for (int i = 0; i < m; i++)
        if (fin(a[i].second.first) != fin(a[i].second.second)) {
            d[fin(a[i].second.first)] = fin(a[i].second.second);
            v[a[i].second.first].push_back({a[i].second.second, a[i].first});
            v[a[i].second.second].push_back({a[i].second.first, a[i].first});
            bm = a[i].first;
        }
    dfs(1, 1);
    for (int i = 0; i < bm; i++)
        b[i + 1] += b[i] / 2,
                b[i] %= 2;
    while (b[bm] > 1) {
        b[bm + 1] = b[bm] / 2;
        b[bm] %= 2;
        bm++;
    }
    for (int i = bm; i >= 0; i--) putchar('0' + b[i]);
    putchar('\n');
    return 0;
}
