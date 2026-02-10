int getMinimumCost(int k, vector<int> c) {
    int res = 0;
    sort(c.begin(), c.end(), greater<int>());
    for (int i = 0; i < c.size(); ++i) res += (1 + ((i)/k)) * c[i];
    return res;
}