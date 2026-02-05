#include <string>
#include <unordered_map>
using namespace std;
string isValid(string s) {
    //Count the characters freq
    unordered_map<char, int> freq;
    for (char c : s) ++freq[c];
    
    //Count frequency of frequencies
    unordered_map<int, int> freqFreq;
    for (auto it = freq.begin(); it != freq.end(); ++it) ++freqFreq[it->second];
    
    //Every character occurs the same amount of times in the string
    if (freqFreq.size() == 1) return "YES";
    //Too many different frequencies for our operation to validate string
    else if (freqFreq.size() >= 3) return "NO";
        
    if (freqFreq.find(1) != freqFreq.end() && freqFreq[1] == 1) return "YES";
    int biggerFreqFreq = 0;
    for (auto it = freqFreq.begin(); it != freqFreq.end(); ++it) {
        biggerFreqFreq = max(biggerFreqFreq, it->first);
    }
    if (freqFreq[biggerFreqFreq] == 1 && freqFreq.find(biggerFreqFreq-1) != freqFreq.end()) return "YES";
    return "NO";
}