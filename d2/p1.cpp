#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

//--------CODE--------//

const ll INF = 1e18;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string line;
    int count = 0;
    while (getline(cin, line)) {
        vector<int> report;
        istringstream report_stream(line);
        int a;

        while (report_stream >> a)
            report.push_back(a);
        
        bool asc = report[0] < report[1];
        bool safe = true;

        for (int i = 0; i< report.size() - 1; i++) {
            if (asc && report[i] > report[i+1] || !asc && report[i] < report[i+1]) {
                safe = false;
                break;
            }
            int diff = abs(report[i] - report[i+1]);
            if (diff < 1 || diff > 3) {
                safe = false;
                break;
            }
        }
        if (safe)
            count++;
    }
    cout << count << endl;
    return 0;
}
