#include <any>
#include <bits/stdc++.h>
#include <string>
#include <sys/ucontext.h>
#include <utility>
#include <vector>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()

//--------CODE--------//

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void dfs(vector<string> &garden, vector<bool> &explored,
        char region, int x, int y, vector<pair<int, int>> &area){
    if (x < 0 || y < 0 || x >= garden[0].size() || y >= garden.size())
        return;
    if (garden[y][x] == region && !explored[x + y * garden[0].size()]) {
        explored[x + y * garden[0].size()] = true;
        area.push_back(make_pair(x,y));
        dfs(garden, explored, region, x+1, y, area);
        dfs(garden, explored, region, x-1, y, area);
        dfs(garden, explored, region, x, y+1, area);
        dfs(garden, explored, region, x, y-1, area);
    }
}

int perimetre(vector<pair<int,int>> &area) {
    set<pair<int,int>> s(all(area));
    int peri = 0;
    for (auto &x: area) {
        int fences = 4;
        if(s.count(make_pair(x.first + 1, x.second))) fences--;
        if(s.count(make_pair(x.first - 1, x.second))) fences--;
        if(s.count(make_pair(x.first, x.second + 1))) fences--;
        if(s.count(make_pair(x.first, x.second - 1))) fences--;
        peri += fences;
    }
    return peri;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string line;
    vector<string> garden;
    while (getline(cin, line)) garden.push_back(line);

    vector<bool> explored(garden.size() * garden[0].size(), false);
    vector<vector<pair<int,int>>> areas;
    bool all_explored = false;
    for (int x = 0; x < garden[0].size(); x++) {
        for (int y = 0; y < garden.size(); y++) {
            if (!explored[x + y * garden[0].size()]) {
                vector<pair<int,int>> area;
                dfs(garden, explored, garden[y][x], 
                    x, y, area);
                areas.push_back(area);
            }
        }
    }

    ll cost = 0;
    for (auto &x: areas) {
        cost += perimetre(x) * x.size();
    }
    cout << cost << endl;
}
