#include <bits/stdc++.h>
#include <regex>

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

    string program;

    regex pattern(R"(don't\(\)|do\(\)|mul\(([0-9]{1,3}),([0-9]{1,3})\))");
    smatch match;
    ll ms = 0;
    bool add = true;

    while (cin >> program)
    {
        auto search = program.cbegin();
        while (regex_search(search, program.cend(), match, pattern)) {
            if (match[0].str() == "do()")
                add = true;
            else if (match[0].str() == "don't()")
                add = false;
        
            else if (add) {
                ms += stoi(match[1].str()) * stoi(match[2].str());
            }
            search = match.suffix().first;
        }
    }
    cout << ms << endl;
    return 0;
}
