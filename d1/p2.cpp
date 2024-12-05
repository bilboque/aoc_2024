#include <bits/stdc++.h>
#include <map>
#include <unordered_map>

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
    vector<int> vec1;
    unordered_map<int, int> map2;
    
    int a, b;
    while (cin >> a >> b)
    {
        vec1.push_back(a);
        map2[b]++;
    }

    int sim = 0;
    for (int i = 0; i < vec1.size(); i++)
        sim += vec1[i] * map2[vec1[i]];

    cout << sim << endl;
    return 0;
}
