class Solution 
{
public:
    long mod = 1e9 + 7;

    long power(long x, long n){
        if(n == 0) 
            return 1;
        long temp = power(x, n/2);

        if(n%2 == 0) 
            return (temp*temp)%mod;
        else return (x*temp*temp)%mod;
    }

    int countGoodNumbers(long long n) {
        long even = (n+1)/2;
        long odd = n/2;

        long first = power(5, even) % mod;
        long second = power(4, odd) % mod;

        return (int)((first * second) % mod);
    }

};