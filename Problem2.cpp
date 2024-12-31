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
ll fastPow(ll x ,ll n, ll m){
    ll res = 1;
    while (n > 0){
        if (n % 2 == 1){
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



void solve()
{
    string s;cin >> s;

    for (auto c : s)
        if (c == 'w' || c == 'm')
            return void(cout << 0 << e);


    vector<ll> dp(s.size()+1, 0);


    dp[0] = 1; // empty string
    dp[1] = 1; // single char

    // create DP Table
    for (ll i = 2 ; i <= s.size() ; i++) {
        dp[i] = dp[i-1]; // value from above
        if (s[i-1] == s[i-2] and s[i-2] == 'u')
            dp[i] += dp[i-2];

        if (s[i-1] == s[i-2] and s[i-2] == 'n')
            dp[i] += dp[i-2];
    }

    cout << dp.back() << endl;
}

signed main()
{
    FastIO

    ll tt = 1; //cin >> tt;
    while (tt-->0)
        solve();

    Checkmate
}