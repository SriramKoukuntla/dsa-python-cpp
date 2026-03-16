#include <vector>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        int res = 0;
        for (int i = 0; i < isPrime.size(); ++i) {
            if (isPrime[i]) {
                ++res;
                int j = i + i;
                while (j < isPrime.size()) {isPrime[j] = false; j += i;}
            }
        }
        return res;
    }
};
//if n <= 2 return 0
//Every number except 0, 1 are primes
//iterate throught each value, if it's a prime, increase res, and then for every values that's less than n, market them as not a prime if they are a factor of the curr prime
