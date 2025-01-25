#include<bits/stdc++.h>
using namespace std;

void bfs(int n,vector<pair<int,int>> adj[],int &startingNode){
    
    vector<bool> visited(n,false);
    queue<int> q;
    q.push(startingNode);
     visited[startingNode] = true;
    cout<<"\n"<<" BFS traversal of given graph is "<<"\n";
    while(!q.empty()){
        int x = q.front();
            cout<<x<<" ";
        q.pop();
        for(int i=0;i<adj[x].size();i++){
          int y = adj[x][i].first;
          if(!visited[y]){
            q.push(y);
            visited[y]= true;
          }
        }
    }
    
    cout<<endl;
    
}
int main(){
    int m,n;
    cout<<"enter the number of edges and vertices in the graph "<<endl;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
cout<<"Enter the edges of the graph "<<endl;
bool isdirected=false;
char D;
  cout<<"PRESS Y if graph is directed and anything else if not "<<endl;
  cin>>D;
  if(D=='Y'){
    isdirected = true;
  }

  // creating adjaceny list
       int u,v,w;
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

  bfs(n,adj,startingNode);
return 0;
}
