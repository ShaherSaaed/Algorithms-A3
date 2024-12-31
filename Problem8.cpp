#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {


    if (source == destination) {
        return true;
    }

    vector<vector<int>> graph(n);
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                if (neighbor == destination) {
                    return true;
                }
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return false;
}

int main() {
    int n, e, source, destination;
    cin >> n >> e;

    vector<vector<int>> edges;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    cin >> source >> destination;

    // output
    if(validPath(n, edges, source, destination)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}
