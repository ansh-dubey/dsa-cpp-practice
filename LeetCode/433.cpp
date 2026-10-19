
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene,
                    vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(), bank.end());
        unordered_set<string> visited;
        queue<string> q;

        q.push(startGene);
        visited.insert(startGene);

        int level = 0;

        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                string s = q.front();
                q.pop();

                if (s == endGene) {
                    return level;
                }

                for (char c : string("ACGT")) {
                    for (int i = 0; i < s.length(); i++) {
                        string next = s;
                        next[i] = c;

                        if (visited.find(next) == visited.end() &&
                            bankset.find(next) != bankset.end()) {
                            visited.insert(next);
                            q.push(next);
                            }
                    }
                }
            }

            level++;
        }

        return -1;
    }
};

int main() {
    Solution sol;

    string startGene = "AACCGGTT";
    string endGene = "AAACGGTA";

    vector<string> bank = {
        "AACCGGTA",
        "AACCGCTA",
        "AAACGGTA"
    };

    int ans = sol.minMutation(startGene, endGene, bank);

    cout << "Minimum mutations: " << ans << '\n';

    return 0;
}
