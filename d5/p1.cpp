#include <bits/stdc++.h>
#include <iostream>
#include <istream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()

//--------CODE--------//

const ll INF = 1e18;
const int MOD = 1e9 + 7;

bool is_tsorted(vector<int> & nums, vector<unordered_set<int>> & graph) {
    bool sorted = true;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++)
            if (graph[nums[i]].count(nums[j])) {
                sorted = false;
                break;
            }
        if (!sorted)
            break;
    }
    return sorted;
}


int main() {

    vector<unordered_set<int>> graph(100);

    int x, y;
    char _;
    string line;

    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        ss >> x >> _ >> y;
        graph[y].insert(x);
    }

    int sum = 0;
    while (getline(cin, line)) {
        istringstream sline(line);
        vector<int> nums;
        int x;

        while (sline >> x) {
            nums.push_back(x);
            if (sline.peek() == ',')
                sline.ignore();
        }

        if (is_tsorted(nums, graph)) {
            sum += nums[(nums.size() + 1) / 2 - 1];
        }
    }
    cout << sum << endl;

    return 0;
}
