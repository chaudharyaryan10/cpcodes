// for finding strongly connected components in a directed grpah
// algo : 
// we need to find components based on which is finishing last to first
// reverse the edges
// start dfs from a component which is finishing last and so on

#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define ull unsigned long long 
#define ld long double
const int mod = 1e9 + 7;

void dfs(int i , vector<vector<int>> &adj , vector<bool> &vis, stack<int> &st){
   vis[i] = true;
    
   for(int j : adj[i]){
     if(!vis[j]){
        dfs(j,adj,vis,st);
     }
   }
   st.push(i);
}
void dfs2(int i ,vector<vector<int>> &adj2 , vector<bool> &vis2,vector<int> &v){
    vis2[i] = true;

    for(int j :adj2[i]){
        if(!vis2[j]){
            dfs2(j,adj2,vis2,v);
        }
    }
   v.push_back(i);
}
void solve()
{
  int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }
   
    stack<int> st;

    vector<bool> vis(n+1,false);
    for(int i =1;i<=n;i++){
       if(!vis[i]){
        dfs(i,adj,vis,st);
       }
    }

   vector<vector<int>> adj2(n+1);
   for (int i = 1; i <=n ; i++)
   {
     for(int j : adj[i]){
         adj2[j].push_back(i);
     }
   }
   
   vector<bool> vis2(n+1,false);
   vector<vector<int>> ans;
   

   while(!st.empty()){
      int u = st.top();
      st.pop();
      vector<int> v;
       if(!vis2[u]){
        dfs2(u,adj2,vis2,v);
        ans.push_back(v);
       }
   }

   for(auto it : ans){
    for(int i : it){
        cout<<i<<" ";
    }
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
    cout<<endl;
   }
    return 0;
}
