#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findLIS(const vector<int>& A) {
    int n = A.size();
    // dp[i] represents the length of the longest increasing subsequence 
    // that ends with element A[i]
    vector<int> dp(n, 1);

    // For each position, look at all previous positions
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // If current element is greater than previous element,
            // we can extend that subsequence
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the maximum length from all possible ending positions
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int N;
    cin >> N;  // Length of the list

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];  // Read the numbers
    }

    cout << findLIS(A) << endl;

    return 0;
}