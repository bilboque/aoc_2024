#include <bits/stdc++.h>
#include <filesystem>
#include <vector>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()

//--------CODE--------//

const ll INF = 1e18;
const int MOD = 1e9 + 7;

int follow_trail(const vector<string> &topomap, int i, int j, int h) {
    if (i < 0 || i >= topomap[0].size() || j < 0 || j >= topomap.size())
        return 0;

    if (h != (topomap[j][i] - '0')) return 0;
    if (h == 9 && (topomap[j][i] - '0') == 9) return 1;

    return follow_trail(topomap, i - 1, j, h + 1)
         + follow_trail(topomap, i + 1, j, h + 1)
         + follow_trail(topomap, i, j - 1, h + 1)
         + follow_trail(topomap, i, j + 1, h + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string line;
    vector<string> topomap;

    while (cin >> line) topomap.push_back(line);
    // for (auto x: topomap) cout << x << endl;

    ll sum = 0;
    for (int j = 0; j < topomap.size(); j++)
        for (int i = 0; i < topomap[0].size(); i++)
            if ((topomap[j][i] - '0') == 0) {
                sum += follow_trail(topomap, i, j, 0);
            }
    cout << sum << endl;
}
