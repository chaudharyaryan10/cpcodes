#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // pbds A, *A.find_by_order(x), A.order_of_key(x),lb,upb

#define ll long long 
#define ull unsigned long long 
#define ld long double
const int mod = 1e9 + 7;

// tarjan's algo 

int timer;
vector<vector<int>> adj;
vector<vector<int>> bridges;
vector<int> tin;
vector<int> low;
vector<bool> visited;

void dfs(int i , int par){
   visited[i] = true;
   tin[i] = low[i] = timer;

   timer++;
   for(auto j : adj[i]){
      if(j!=par){
        if(!visited[j]){
           dfs(j,i);
           low[i] = min(low[j],low[i]);

           if(low[j]>tin[i]){
            bridges.push_back({i,j});
           }
        }
        else{
          low[i] = min(low[j],low[i]);
        }
      }
   }
}
void solve()
{
  int n,m;
  cin>>n>>m;
  
  adj.assign(n+1,vector<int>());
  tin.assign(n+1,0);
  low.assign(n+1,0);
  visited.assign(n+1,false);
  timer = 1;
  
  for(int i = 0;i<m;i++){
    int u,v;
    cin>>u>>v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  dfs(1,-1);
  
  for(auto it : bridges){
    cout<<it[0]<<" "<<it[1];
    cout<<endl;
  }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    // cin >> t;
   while(t--){
    solve();
    // cout<<endl;
   }
    return 0;
}
