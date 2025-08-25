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

bool cycle;

void dfs(int i , vector<vector<int>> &adj, vector<int> &visited, stack<int> &st){
    if (cycle) return; 
    visited[i] = 1;

    for(int j : adj[i]){
        if(visited[j]==0){
          dfs(j,adj,visited,st);
        }
        else{
        if(visited[j]==1){
          cycle = true;
          return;
        }
      }
     }

     visited[i] = 2;
     st.push(i);
    }
    
void solve()
{
    int n,m;
    cin>>n>>m;
    cycle = false;

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }
    
    stack<int> st;
    vector<int> visited(n+1,0);

    for(int i = 1;i<=n;i++){
        if(visited[i]==0)
        dfs(i,adj,visited,st);

        if(cycle){
            break;
        }
    }
    if(cycle){
        cout<<"No topo sort as cycle is present ";
        return;
    }

    while(!st.empty()){
        int top = st.top();
        st.pop();

        cout<<top<<" ";
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
