class Solution {
public:
    int numPrimeArrangements(int n) {
        const long long MOD = 1e9 + 7;
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) if(isPrime[i]) for(int j = i * i; j <= n; j += i) isPrime[j] = false;
        int primes = 0;
        for (int i = 2; i <= n; i++) if(isPrime[i]) primes++;
        long long ans = 1;
        for (int i = 1; i <= primes; i++) ans = (ans * i) % MOD;
        for (int i = 1; i <= n - primes; i++) ans = (ans * i) % MOD;
        return ans;
    }
};