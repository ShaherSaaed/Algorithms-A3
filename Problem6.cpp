#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int content = 0;
        int index = 0;
        while (s[index] < s.size() && s[content] < g.size()) {
            if (s[index] >= g[content]) {
                content++;
            }
        }
        return content;
    }
};

int main() {
    int n;
    cin >> n;
    vector<long long> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    int t;
    cin >> t;
    vector<long long> s(t);
    for (int i = 0; i < t; i++) {
        cin >> s[i];
    }
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int content = 0;
    int index = 0;
    while(index < s.size() && content < g.size()){
        if(s[index] >= g[content]){
            content++;
        }
        index++;
    }
    cout << content;
}