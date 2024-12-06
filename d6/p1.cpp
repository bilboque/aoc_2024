#include <array>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()

//--------CODE--------//

const ll INF = 1e18;
const int MOD = 1e9 + 7;

#define IS_UP(dir) (dir[0] == 0 && dir[1] == -1)
#define IS_DOWN(dir) (dir[0] == 0 && dir[1] == 1)
#define IS_LEFT(dir) (dir[0] == -1 && dir[1] == 0)
#define IS_RIGHT(dir) (dir[0] == 1 && dir[1] == 0)

void update_pos(array<int, 2> &pos, array<int, 2> &dir){
    pos[0] += dir[0];
    pos[1] += dir[1];
}

void turn_90(array<int, 2> &dir){
    if (IS_UP(dir)) {
        dir[0] = 1; dir[1] = 0;
    }
    else if (IS_RIGHT(dir)) {
        dir[0] = 0; dir[1] = 1;
    }
    else if (IS_DOWN(dir)) {
        dir[0] = -1;dir[1] = 0;
    }
    else if (IS_LEFT(dir)) {
        dir[0] = 0;dir[1] = -1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> map;
    string line;
    while (cin >> line) {
        map.push_back(line);
    }
    
    array<int, 2> dir{0, -1};
    array<int, 2> pos;
    bool found = false;
    for (int y = 0; y < map.size() && !found; y++)
        for (int x = 0; x < map[y].size(); x++)
            if (map[y][x] == '^'){
                pos[0] = x; pos[1] = y;
                found = true;
                break;
            }

    if (!found) {
        cout << "WHAT" << endl;
        return 0;
    }

    for (auto line: map)
         //cout << line << endl;

    bool done = false;
    set<array<int, 2>> reached;
    reached.insert(pos);
    array<int, 2> scan = pos;
    while (true) {
        if (pos[1] + dir[1] < 0 ||
            pos[1] + dir[1] >= map.size() ||
            pos[0] + dir[0] < 0 ||
            pos[0] + dir[0] >= map[pos[0]].size())
            break;
        if (map[pos[1] + dir[1]][pos[0] + dir[0]] == '#') {
            turn_90(dir);
            //cout << "turn" << endl;
            //cout << dir[0] << " " << dir[1] << endl;
            continue;
        }
        update_pos(pos, dir);
        //cout << pos[0] << " " << pos[1] << endl;
        reached.insert(pos);
    }
    cout << reached.size() << endl;
}
