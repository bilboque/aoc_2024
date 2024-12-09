#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()

//--------CODE--------//

const ll INF = 1e18;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string line;
    cin >> line;

    bool is_file = true;
    int id_counter = 0;
    vector<int> disk;
    for (auto &x: line) {
        int n = x - '0';

        for (int i = 0; i<n; i++)
            disk.push_back(is_file ? id_counter / 2 : -1);

        is_file = !is_file;
        id_counter++;
    }

    int i = 0;
    int j = disk.size() - 1;
    ll sum = 0;
    while (i <= j) {
        if (disk[i] == -1) {
            while (disk[j] == -1) j--;
            if (i > j) break;
            sum += disk[j] * (i);
            j--;
        } else {
            sum += disk[i] * (i);
        }
        i++;
    }

    cout << sum << endl;
}
