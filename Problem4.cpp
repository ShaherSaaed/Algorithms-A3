#include <bits/stdc++.h>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define Checkmate return 0;
#define ll long long
#define lll __int128
#define e '\n'
using namespace std;

void printInt128(lll n) {
    if (n == 0) {
        cout << "0";
        return;
    }
    if (n < 0) {
        cout << "-";
        n = -n;
    }

    string result;
    while (n > 0) {
        result = char('0' + (n % 10)) + result;
        n /= 10;
    }
    cout << result << e;
}

ll MOD = 1e9 + 7;

ll fastPow(ll x, ll n, ll m) {
    ll res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        n = n / 2;
    }
    return res;
}

ll sum(ll start, ll end) {
    return (end * (end + 1)) / 2 - (start * (start - 1)) / 2;
}


void solve() {
    int t, w;
    while (cin >> t >> w) { // after finishing the test cases enter '.' in the cin (input)
        int n;
        cin >> n;

        vector<int> depth(n), gold(n), timeCost(n);
        for (int i = 0; i < n; i++)
            cin >> depth[i] >> gold[i], timeCost[i] = 3 * w * depth[i];


        vector<int> dp(t + 1, 0);
        vector<vector<bool>> take(n, vector<bool>(t + 1, false));

        for (int i = 0; i < n; ++i)
            for (int j = t; j >= timeCost[i]; j--)
                if (dp[j - timeCost[i]] > dp[j] - gold[i])
                    dp[j] = dp[j - timeCost[i]] + gold[i], take[i][j] = true;


        int maxGold = dp[t];
        int remainingTime = t;
        vector<int> selectedTre;


        for (int i = n - 1; i >= 0; i--)
            if (take[i][remainingTime])
                selectedTre.push_back(i), remainingTime -= timeCost[i];


        cout << maxGold << e;
        cout << selectedTre.size() << e;
        for (int i = selectedTre.size() - 1; i >= 0; i--)
            cout << depth[selectedTre[i]] << ' ' << gold[selectedTre[i]] << e;

        cout << e;
    }
}


signed main() {
    FastIO

    ll tt = 1; //cin >> tt;
    while (tt-- > 0)
        solve();

    Checkmate
}