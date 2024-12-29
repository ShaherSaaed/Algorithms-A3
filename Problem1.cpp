#include <iostream>
#include <vector>
using namespace std;

int findMinDiff(vector<int>& coins) {
    int totalSum = 0;
    for (int coin : coins) {
        totalSum += coin;
    }

    vector<vector<bool>> dp(coins.size() + 1, vector<bool>(totalSum + 1, false));

    for (int i = 0; i <= coins.size(); i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= coins.size(); i++) {
        for (int j = 1; j <= totalSum; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= coins[i-1]) {
                dp[i][j] = dp[i][j] || dp[i-1][j-coins[i-1]];
            }
        }
    }

    int minDiff = totalSum;
    for (int j = 0; j <= totalSum/2; j++) {
        if (dp[coins.size()][j]) {
            minDiff = min(minDiff, totalSum - 2*j);
        }
    }
    return minDiff;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int m;
        cin >> m;

        vector<int> coins(m);
        for (int i = 0; i < m; i++) {
            cin >> coins[i];
        }

        cout << findMinDiff(coins) << endl;
    }

    return 0;
}
