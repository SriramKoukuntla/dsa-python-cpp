#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t; 
    for (int p = 0; p < t; ++p) {
        int n; cin >> n;
        int t; cin >> t; 
        vector<int> buttons;
        for (int i = 0; i < n; ++i) {
            int temp; cin >> temp;
            buttons.push_back(temp);
        }

        unordered_map<int, int> visited;
        visited[0] = 0; 
        queue<tuple<int, int>> q; 
        q.push({0, 0});

        while (!q.empty()) {
            auto [s, bp]= q.front();
            q.pop();
            for (int button : buttons) {
                int nextS = s + button;
                if (nextS < 0) nextS = 0;
                if (nextS > 3600) nextS = 3600;
                if (visited.find(nextS) == visited.end()) {
                    q.push({nextS, bp+1});
                    visited[nextS] = bp+1;
                }
            }
        }
        for (int z = t; z <= 3600; ++z) {
            if (visited.find(z) != visited.end()) {
                int extraTime = z-t;
                cout << visited[z] << " " << extraTime << endl;
                break;
            }
        }
    }
    return 0;
}