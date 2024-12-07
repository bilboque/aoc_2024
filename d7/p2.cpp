#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()

//--------CODE--------//

const ll INF = 1e18;
const int MOD = 1e9 + 7;

#define MUL 1
#define ADD 2
#define CAT 3

bool solve(ll goal, vector<ll> &arr, ll i, int op, ll curr) {
    if (op == ADD)
        curr += arr[i];
    else if (op == MUL)
        curr *= arr[i];
    else if (op == CAT)
        curr = stoll(to_string(curr) + to_string(arr[i]));

    if (i+1 == arr.size())
        return goal == curr;

    return solve(goal, arr, i + 1, ADD, curr) ||
           solve(goal, arr, i + 1, MUL, curr) ||
           solve(goal, arr, i + 1, CAT, curr);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string eq;
    ll sum = 0;
    while (getline(cin, eq)) {
        istringstream line(eq);

        ll goal;
        char _;
        ll num;
        line >> goal;
        line >> _;

        vector<ll> arr;

        while (line >> num) arr.push_back(num);

        if (solve(goal, arr, 0, ADD, 0)) {
            sum += goal;
        }
   }
    cout << sum << endl;
}
