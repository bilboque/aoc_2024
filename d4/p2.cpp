#include <bits/stdc++.h>
#include <istream>

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


int match(char tl, char tr, char bl, char br) {
    for (int i = 0; i < 4; i++) {
        char temp = tl; // rotate this shit
        tl = bl;        // tl - tr
        bl = br;        // | 'A' |
        br = tr;        // bl - br
        tr = temp;      // easy
        if (tl == tr && tl == 'M' && bl == br && bl == 'S')
            return 1;
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> wsearch;

    string line;

    while (cin >> line)
        wsearch.push_back(line);

    int count = 0;

    // find an A
    for (int j = 1; j < wsearch.size() - 1; j++) {
        for (int i = 1; i < wsearch[j].size() - 1 ; i++) {
            if (wsearch[j][i] == 'A')
                count += match(wsearch[j + 1][i - 1], wsearch[j + 1][i + 1],
                               wsearch[j - 1][i - 1], wsearch[j - 1][i + 1]);
        }
    }

    cout << count << endl;

    return 0;
}
