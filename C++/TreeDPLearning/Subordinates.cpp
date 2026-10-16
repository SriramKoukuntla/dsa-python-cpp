//Problem: https://cses.fi/ckvo8q5wh/task/1674
#include <bits/stdc++.h>
using namespace std;
int helper(unordered_map<int, int>& res, unordered_map<int, vector<int>>& directSubordinates, int index) {
	int tempRes = directSubordinates[index].size();
	for (int subordinate : directSubordinates[index]) {
		res[subordinate] = helper(res, directSubordinates, subordinate);
		tempRes += res[subordinate];
	}
	res[index] = tempRes;
	return tempRes;
}


int main() {
	int n; cin >> n;
	unordered_map<int, vector<int>> directSubordinates;
	for (int i = 2; i <= n; ++i) {
		int superior; cin >> superior;
		directSubordinates[superior].push_back(i);
	}
	unordered_map<int, int> res;
	
	
	helper(res, directSubordinates, 1);
	
	for (int i = 1; i <= n; ++i) cout << res[i] << " ";
	
	return 0;
}