// Graph Repersentaion using adjacency list

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <utility>
#include <numeric>
#include <cmath>
#include <climits>
#include <cstring>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int m, n;
    cin >> n >> m;

    vector<int> adj[n+1];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}