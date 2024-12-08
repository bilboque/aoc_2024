#include <bits/stdc++.h>
#include <utility>

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
    vector<string> grid;

    while (cin >> line) grid.push_back(line);

    map<char, vector<pair<int,int>>> locations;

    for (int y = 0; y < grid.size(); y++)
        for ( int x = 0; x < grid[0].size(); x++)
            if (grid[y][x] != '.')
                locations[grid[y][x]].push_back(make_pair(x, y));

    vector<pair<int, int>> antinodes;
    for (auto &x: locations) {
        for (int i = 0; i < x.second.size(); i++)
            for (int j = i + 1; j < x.second.size(); j++) {
                int xdiff = x.second[i].first - x.second[j].first;
                int ydiff = x.second[i].second - x.second[j].second;

                int a = x.second[i].first;
                int b = x.second[i].second;
                antinodes.push_back(make_pair(a + xdiff, b + ydiff));
                
                a = x.second[j].first;
                b = x.second[j].second;
                antinodes.push_back(make_pair(a - xdiff, b - ydiff));
            }
    }
    
    int count = 0;
    for (auto x: antinodes) {
        if (x.first >= 0 && x.first < grid[0].size() &&
            x.second >= 0 && x.second < grid.size()) {
            if (grid[x.second][x.first] != '#') {
                count++;
                grid[x.second][x.first] = '#';
            }
        }
    }
    cout << count << endl;

    // for (auto &line: grid)
    //     cout << line << endl;
}
