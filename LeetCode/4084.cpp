// Leetcode 4084

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        if (m==1 && n==1) {
            return {0,0};
        }
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;

        int lastVisitedi = 0, lastVisitedj = 0;
        int i=0, j=0;
        if (grid[i][j] == 'R') {
            j++;
        } else if(grid[i][j] == 'D') {
            i++;
        } else if(grid[i][j] == 'L') {
            j--;
        } else if(grid[i][j] == 'U') {
            i--;
        }

        while (i < m && j < n && j >= 0 && i >= 0) {
            if (visited[i][j]) {
                return {lastVisitedi, lastVisitedj};
            }
            visited[i][j] = true;
            lastVisitedi = i;
            lastVisitedj = j;
            if (grid[i][j] == 'R') {
                j++;
            } else if(grid[i][j] == 'D') {
                i++;
            } else if(grid[i][j] == 'L') {
                j--;
            } else if(grid[i][j] == 'U') {
                i--;
            }
        }

        return {lastVisitedi, lastVisitedj};
    }
};

int main() {
    Solution sol;

    vector<vector<char>> grid = {
        {'U'}
    };

    vector<int> ans = sol.lastVisitedCell(grid);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << '\n';

    return 0;
}
