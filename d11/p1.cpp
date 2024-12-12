#include <bits/stdc++.h>
#include <list>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()

//--------CODE--------//

const ll INF = 1e18;
const int MOD = 1e9 + 7;

int solve(ll x, int itt) {
    if (itt == 0) 
        return 1;
    if (x == 0) // rule 1
        return solve(1, itt - 1);
    string xs = to_string(x);
    if (xs.size() % 2 == 0) // rule 2
    {
        string left = xs.substr(0, xs.size() / 2);
        string right = xs.substr(xs.size() / 2);

        return solve(stoll(left), itt - 1)
             + solve(stoll(right), itt - 1);
    }
    return solve(x * 2024, itt - 1);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    list<ll> nums;
    ll x;
    while (cin >> x)
        nums.push_back(x);
    
    ll count = 0;
    for (auto &x: nums)
        count += solve(x, 25);

    cout << count << endl;
}
