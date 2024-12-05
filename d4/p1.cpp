#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()

//--------CODE--------//

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void print_wsearch(vector<string> wsearch) {
    for (auto line: wsearch)
         cout << line << endl;
}


int match(vector<string> wsearch, string pattern, int i, int j, int dir_x, int dir_y) {
    int k = 0;
    int count = 0;
    while (j < wsearch.size() && j >= 0 && i >= 0 && i < wsearch[j].size()) {
        if (wsearch[j][i] != pattern[k]) {
            k = 0;
            if (wsearch[j][i] == pattern[0])
                k = 1;
        }
        else {
            k++;
            if (k == pattern.size()) {
                count++;
                k = 0;
            }
        }
        i += dir_x;
        j += dir_y;
    }
    return count;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> wsearch;

    string line;

    while (cin >> line)
        wsearch.push_back(line);

    int count = 0;
   // match lines
    for (int i = 0; i < wsearch.size(); i++) {
        count += match(wsearch, "XMAS", 0, i, 1, 0);
        count += match(wsearch, "SAMX", 0, i, 1, 0);
    }
    
    // match vertically
    for (int i = 0; i < wsearch[0].size(); i++) {
        count += match(wsearch, "XMAS", i, 0, 0, 1);
        count += match(wsearch, "SAMX", i, 0, 0, 1);
    }
    
    // match diag
    for (int i = 0; i < wsearch[0].size(); i++) {
        count += match(wsearch, "XMAS", i, 0, 1, 1);
        count += match(wsearch, "SAMX", i, 0, 1, 1);
    }
    for (int i = 1; i < wsearch.size(); i++) {
        count += match(wsearch, "XMAS", 0, i, 1, 1);
        count += match(wsearch, "SAMX", 0, i, 1, 1);
    }
    
    // match other diag
    for (int i = 0; i < wsearch[0].size(); i++) {
        count += match(wsearch, "XMAS", i, 0, -1, 1);
        count += match(wsearch, "SAMX", i, 0, -1, 1);
    }
    for (int i = 1; i < wsearch.size(); i++) {
        count += match(wsearch, "XMAS", wsearch[i].size() - 1, i, -1, 1);
        count += match(wsearch, "SAMX", wsearch[i].size() - 1, i, -1, 1);
    }

    cout << count << endl;

    return 0;
}
