#include <vector>
using namespace std;
class Bank {
public:
    vector<long long> bankAccounts;
    Bank(vector<long long>& balance) {
        bankAccounts = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 < 0 || account1 > bankAccounts.size() || 
        account2 < 0 || account2 > bankAccounts.size() || bankAccounts[account1-1] < money) return false;
        bankAccounts[account1-1] -= money;
        bankAccounts[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account < 0 || account > bankAccounts.size()) return false;
        bankAccounts[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account < 0 || account > bankAccounts.size() || bankAccounts[account-1] < money) return false;
        bankAccounts[account-1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */