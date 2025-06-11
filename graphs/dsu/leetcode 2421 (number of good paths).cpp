class Solution {
public:
    int findUnion(int i,vector<int> & parent){
        if(parent[i]==i){
            return i;
        }
        return parent[i] = findUnion(parent[i],parent);
    }
    void DsuUnion(int i,int j ,vector<int> &parent, vector<int> &rank){
        int pi = findUnion(i,parent);
        int pj = findUnion(j,parent);
        
        if(pi == pj){
            return;
        }
        if(rank[pi]>rank[pj]){
            parent[pj] = pi;
        }
        else{
            if(rank[pi]<rank[pj]){
                parent[pi] =pj;
            }
            else{
                parent[pi] =pj;
                rank[pj]++;
            }
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
       int n = vals.size();
       int m = edges.size();

        vector<vector<int>> adj(n);

        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
             adj[u].push_back(v);
             adj[v].push_back(u);
        }

        vector<int> parent(n,0);
        for(int i=0;i<n;i++){
            parent[i] =i;
        }
        vector<int> rank(n,0);
        map<int,vector<int>> mp;
       
       for(int i=0;i<n;i++){
        mp[vals[i]].push_back(i);
       }
        int ans=n;
        vector<bool> active(n,false);
        unordered_map<int,int> mp2;
       for(auto it : mp){
        vector<int> v = it.second;
        int s = v.size();
          for(int j=0;j<s;j++){
            active[v[j]] = true;
          }
          for(int i=0;i<s;i++){
            for(int j : adj[v[i]]){
                if(active[j]){
                    DsuUnion(v[i],j,parent,rank);
                }
            }
            // active[v[i]] = true;
          }
         
         for(int i=0;i<s;i++){
            int pr = findUnion(v[i],parent);
            mp2[pr]++;
         }
         
         for(auto it : mp2){
           ans+=  (it.second)*(it.second-1)/2;
         }
         mp2.clear();
       }

       return ans;
    }
};
