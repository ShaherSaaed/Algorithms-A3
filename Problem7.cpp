#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        int freq[26] = {0};
        for (char &ch: tasks) {
            freq[ch - 'A']++;
        }

        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        int time = 0;
        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> store;
            int taskCount = 0;
            while (cycle-- && !pq.empty()) {
                if (pq.top() > 1) {
                    store.push_back(pq.top() - 1);
                }
                pq.pop();
                taskCount++;
            }
            for (int &x: store) {
                pq.push(x);
            }
            time += (pq.empty() ? taskCount : n + 1);
        }
    }
};

int main() {
    int t;
    cin >> t;
    vector<char> tasks(t);
    int freq[26] = {0};
    for (int i = 0; i < t; i++) {
        cin >> tasks[i];
        freq[tasks[i] - 'A']++;
    }
    int n;
    cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            pq.push(freq[i]);
        }
    }

    int time = 0;
    while (!pq.empty()) {
        int cycle = n + 1;
        vector<int> store;
        int taskCount = 0;
        while (cycle-- && !pq.empty()) {
            if (pq.top() > 1) {
                store.push_back(pq.top() - 1);
            }
            pq.pop();
            taskCount++;
        }
        for (int &x: store) {
            pq.push(x);
        }
        time += (pq.empty() ? taskCount : n + 1);
    }

    cout << time << endl;
    return 0;
}