#include <iostream>
#include <vector>
using namespace std;

int solve_robbery(int capacity, vector<pair<int, int>>& bags) {
    // Create a DP table with dimensions (capacity + 1) x (number of bags + 1)
    vector<vector<int>> dp(capacity + 1, vector<int>(bags.size() + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= bags.size(); i++) {
        int weight = bags[i-1].first;
        int value = bags[i-1].second;

        for (int w = 0; w <= capacity; w++) {
            // Don't take the current bag
            dp[w][i] = dp[w][i-1];

            // Take the current bag if possible
            if (w >= weight) {
                dp[w][i] = max(dp[w][i], dp[w-weight][i-1] + value);
            }
        }
    }

    // Return maximum value possible
    return dp[capacity][bags.size()];
}

int main() {
    int N;
    cin >> N;  // Number of test cases

    // Process each test case
    for (int t = 0; t < N; t++) {
        int K, M;
        cin >> K >> M;  // Capacity and number of bags

        // Read bag information
        vector<pair<int, int>> bags;
        for (int i = 0; i < M; i++) {
            int weight, value;
            cin >> weight >> value;
            bags.push_back({weight, value});
        }

        // Solve and print result
        int result = solve_robbery(K, bags);
        cout << "Hey stupid robber, you can get " << result << "." << endl;
    }

    return 0;
}