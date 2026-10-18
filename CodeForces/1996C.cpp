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
#include <array>
using namespace std;


void solve() {
    int n, q;
    cin >> n >> q;

    string a, b;
    cin >> a >> b;

    // Prefix frequency difference: count(a) - count(b)
    vector<array<int, 26>> pref(n + 1, array<int, 26>{});
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i];

        pref[i + 1][a[i] - 'a']++;
        pref[i + 1][b[i] - 'a']--;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        int ans = 0;

        for (int c = 0; c < 26; c++) {
            int diff = pref[r][c] - pref[l - 1][c];

            if (diff > 0) {
                ans += diff;
            }
        }

        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
