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

    string line;
    cin >> line;

    bool is_file = true;
    int id_counter = 0;
    vector<int> spaces;
    deque<pair<int, int>> files;

    // We count spaces and files
    for (auto &x: line) {
        int n = x - '0';

        if (is_file)
            files.push_back(make_pair(id_counter/2, n));
        else 
            spaces.push_back(n);

        is_file = !is_file;
        id_counter++;
    }

    vector<int> disk;
    stack<pair<int,int>> temp;
    
    for (auto &x: spaces) {
        if (files.empty()) break;

        // push the leftmost file on disk
        pair<int, int> file = files.front();
        for (int i = 0; i < file.second; i++)
            disk.push_back(file.first);
        files.pop_front();

        // push the biggests ids files on the empty spaces if possible
        int free_space = x;
        while (free_space > 0) {
            if (files.empty()) break;
            file = files.back();
            files.pop_back();
            if (file.second <= free_space && file.first != -1) {
                for (int i = 0; i < file.second; i++)
                    disk.push_back(file.first);
                free_space -= file.second;
                temp.push(make_pair(-1, file.second));
            }
            else
                temp.push(file);
        }

        // write remaining spaces
        for (int i = 0; i < free_space; i++) {
            disk.push_back(-1);
        }

        // rebuild what files we still need to process
        while (!temp.empty()) {
            files.push_back(temp.top());
            temp.pop();
        }
    }

    // for (auto &c: disk) cout << c << " ";
    // cout << endl;

    ll sum = 0;
    int i = 0;

    // compute checksum
    for (auto &x: disk) {
        if (x != -1)
            sum += i * x;
        i++;
    }
    cout << sum << endl;
}
