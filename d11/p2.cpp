#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()

//--------CODE--------//

const ll INF = 1e18;
const int MOD = 1e9 + 7;

ll solve(int depth, map<ll,ll> nums){
    if (depth == 0) {
        ll sum = 0;
        for (auto &x: nums) sum += x.second;
        return sum;
    }
    map<ll, ll> new_nums;
    for (auto &x: nums) {
        if (x.first == 0) {
            new_nums[1] += x.second;
        } else if (to_string(x.first).size() % 2 == 0) {
            string snum = to_string(x.first);
            ll left = stoll(snum.substr(0, snum.size()/2));
            ll right = stoll(snum.substr(snum.size()/2));
            new_nums[left] += x.second;
            new_nums[right] += x.second;
        } else {
            new_nums[x.first * 2024] += x.second;
        }
    }
    return solve(depth - 1, new_nums);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<ll, ll> nums;
    ll x;
    while (cin >> x)
        nums[x]++;

    ll count = solve(75, nums);

    cout << count << endl;
}
