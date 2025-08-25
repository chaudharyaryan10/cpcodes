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
void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1,0);

    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);

        indegree[v]++;
    }

    queue<int> q;

    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        ans.push_back(u);

        for(int v : adj[u]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
  
    int sz = ans.size();
    if(sz<n){
      cout<<"no topo sort due to cycle present";
      return;
    }
    
    for(int i : ans){
        cout<<i<<" ";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    // cin >> t;
   while(t--){
    solve();
    cout<<endl;
   }
    return 0;
}
