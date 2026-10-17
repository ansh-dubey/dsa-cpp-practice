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

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans += max(0, a[i-1] - a[i]);
    }

    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        solve();
    }
}