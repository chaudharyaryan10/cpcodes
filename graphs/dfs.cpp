#include<bits/stdc++.h>
using namespace std;

void dfs(int n,vector<pair<int,int>> adj[],int startingNode,vector<bool> &visited){
    visited[startingNode]=true;
    cout<<startingNode<<" ";
    for(int i=0;i<adj[startingNode].size();i++){
         int x = adj[startingNode][i].first;
        if(!visited[x]){
            dfs(n,adj,x,visited);
        }
    }
   
}
int main(){
    int m,n;
    cout<<"enter the number of edges and vertices in the graph "<<endl;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
cout<<"Enter the edges of the graph and weight "<<endl;
bool isdirected=false;
char D;
  cout<<"PRESS Y if graph is directed and anything else if not "<<endl;
  cin>>D;
  if(D=='Y'){
    isdirected = true;
  }

  // creating adjaceny list
       int u,v,w=0;
    for(int i=0;i<m;i++){
       cin>>u>>v;
       adj[u].push_back({v,w});
       if(!isdirected){
        adj[v].push_back({u,w});
       }
    }
  int startingNode;
  cout<<"enter the starting node"<<"\n";
  cin>>startingNode;
  
  vector<bool> visited(n,false);
  cout<<"DFS traversal of the given graph is "<<"\n";
  dfs(n,adj,startingNode,visited);
return 0;
}
