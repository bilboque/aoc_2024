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
    vector<int> vec1, vec2;
    
    int a, b;
    while (cin >> a >> b)
    {
        vec1.push_back(a);
        vec2.push_back(b);
    }
    sort(all(vec1));
    sort(all(vec2));
    
    int sum = 0;
    for (int i = 0; i < vec1.size(); i++)
        sum += abs(vec1[i] - vec2[i]);

    cout << sum << endl;
    return 0;
}
