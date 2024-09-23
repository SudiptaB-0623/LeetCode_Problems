class Bank 
{
    vector<long long> accounts;
public:
    Bank(vector<long long>& balance) 
    {
        this->accounts = balance;
    }
    
    bool transfer(int account1, int account2, long long money) 
    {
        if(account1>accounts.size() || account2>accounts.size())
            return false;
        
        if(accounts[account1-1] >= money)
        {
            accounts[account1-1] = accounts[account1-1] - money;
            accounts[account2-1] = accounts[account2-1] + money;
            
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) 
    {
        if(account>accounts.size())
            return false;
        
        accounts[account-1] = accounts[account-1] + money;
        return true;
    }
    
    bool withdraw(int account, long long money) 
    {
        if(account>accounts.size())
            return false;
        if(accounts[account-1] >= money)
        {
            accounts[account-1] = accounts[account-1] - money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */