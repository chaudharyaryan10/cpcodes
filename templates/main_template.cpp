#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // pbds A, *A.find_by_order(x), A.order_of_key(x),lb,upb

#define ll long long int
#define ld long double
const int mod = 1e9 + 7;

template<typename T>
istream& operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v) istream >> it;
    return istream;
}
template<typename T1, typename T2>
istream& operator>>(istream &istream, vector<pair<T1, T2>> &v) {
    for (auto &it : v) istream >> it.first >> it.second;
    return istream;
}
template<typename T>
ostream& operator<<(ostream &ostream, const vector<T> &v) {
    for (const auto &it : v) ostream << it << " ";
    return ostream;
}
template<typename T1, typename T2>
ostream& operator<<(ostream &ostream, const vector<pair<T1, T2>> &v) {
    for (const auto &it : v) ostream << it.first << " " << it.second << "\n";
    return ostream;
}

void solve(){
{

    
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
   while(t--){
    solve();
    cout<<endl;
   }
    return 0;
}
