int alternatingCharacters(string s) {
    int res = 0;
    char lastChar = s[0];
    for (int i = 1; i < s.size(); ++i) {
        char currChar = s[i];
        if (currChar == lastChar) ++res;
        else lastChar = currChar;
    }
    return res;
}