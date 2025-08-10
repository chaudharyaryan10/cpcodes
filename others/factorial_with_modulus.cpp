#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5; // change based on constraints

vector<ll> fact(MAX), invFact(MAX);

// Fast modular exponentiation
ll modPow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// Precompute factorials and inverse factorials
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    // Fermat's Little Theorem: a^(p-1) ≡ 1 (mod p) ⇒ a^(p-2) ≡ a^(-1)
    invFact[MAX - 1] = modPow(fact[MAX - 1], MOD - 2, MOD);
    for (int i = MAX - 2; i >= 0; i--)
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

// Compute nCr % MOD
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return ((fact[n] * invFact[r]) % MOD * invFact[n - r]) % MOD;
}

int main() {
    precompute();

    cout << nCr(5, 2) << "\n"; // Example: 5C2 = 10
    cout << nCr(1000000, 500000) << "\n"; // Large test

    return 0;
}
