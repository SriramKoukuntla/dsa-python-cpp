class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> levelOfTrust(n, 0); 
        vector<bool> givenAnyTrust(n, false);
        for (vector<int>& t : trust) {
            givenAnyTrust[t[0]-1] = true;
            levelOfTrust[t[1]-1]++;
        }
        for (int i = 0; i < n; ++i) if (!givenAnyTrust[i] && levelOfTrust[i] == n-1) return i+1;
        return -1;
    }
};