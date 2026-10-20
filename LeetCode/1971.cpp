
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfsRec(vector<vector<int>>& adj, int i, int d,
                vector<bool>& visited) {
        visited[i] = true;

        if (i == d) {
            return true;
        }

        for (int node : adj[i]) {
            if (!visited[node]) {
                if (dfsRec(adj, node, d, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {
        vector<vector<int>> adj(n);

        // Build adjacency list
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        return dfsRec(adj, source, destination, visited);
    }
};

int main() {
    Solution sol;

    int n = 6;

    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {3, 5},
        {5, 4},
        {4, 3}
    };

    int source = 0;
    int destination = 5;

    bool ans = sol.validPath(n, edges, source, destination);

    cout << (ans ? "Path exists" : "Path does not exist") << '\n';

    return 0;
}
