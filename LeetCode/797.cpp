// Leetcode 797
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& graph, int i, int target,
             vector<vector<int>>& res, vector<int>& temp) {

        temp.push_back(i);

        if (i == target) {
            res.push_back(temp);
        } else {
            for (int node : graph[i]) {
                dfs(graph, node, target, res, temp);
            }
        }

        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        int src = 0;
        int target = n - 1;

        vector<vector<int>> res;
        vector<int> temp;

        dfs(graph, src, target, res, temp);

        return res;
    }
};

int main() {
    Solution sol;

    // Example input: graph adjacency list
    vector<vector<int>> graph = {
        {1, 2},
        {3},
        {3},
        {}
    };

    vector<vector<int>> ans = sol.allPathsSourceTarget(graph);

    cout << "All paths from source to target:\n";

    for (const auto& path : ans) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];

            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << '\n';
    }

    return 0;
}
