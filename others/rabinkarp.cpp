long long get_hash(string s) {
    int n = size(s);
    long long h = 0;
    for (int i = 0; i < n; i++) h = (h * 31 + (s[i] - 'a' + 1)) % MOD;
    return h;
}

vector<int> rabin_karp(string s, string t) {
    int n = size(s), m = size(t);
    long long p = 1;
    for (int i = 0; i < m - 1; i++) p = (p * 31) % MOD;
    vector<int> pos;
    long long ht = get_hash(t);
    long long hs = get_hash(s.substr(0, m));
    if (hs == ht) pos.push_back(0);
    for (int l = 1, r = m; r < n; l++, r++) {
        int del = ((s[l - 1] - 'a' + 1) * p) % MOD;
        int add = s[r] - 'a' + 1;
        hs = ((hs - del + MOD) * 31 + add) % MOD;
        if (hs == ht) pos.push_back(l);
    }
    return pos;
}
