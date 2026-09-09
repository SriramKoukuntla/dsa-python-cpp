class Solution {
public:
    int tribonacci(int n) {
        if (n < 2) return n;
        vector<int> tab(n+1, 0);
        tab[1] = 1;
        tab[2] = 1;
        for (int i = 3; i < n+1; ++i) tab[i] = tab[i-1] + tab[i-2] + tab[i-3];
        return tab.back();
    }
};