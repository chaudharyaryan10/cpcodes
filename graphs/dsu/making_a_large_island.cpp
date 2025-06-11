class Solution {
public:
      bool isvalid(int i,int j,int n){
        if(i>=0 && j>=0 && i<n && j<n){
            return true;
        }
        return false;
      }
      int findUPar(int i,vector<int> &parent){
        if(parent[i]==i){
            return i;
        }
        return parent[i] = findUPar(parent[i],parent);
    }
     void unionBySize(int u, int v,vector<int> &parent, vector<int>& size) {
        int ulp_u = findUPar(u,parent);
        int ulp_v = findUPar(v,parent);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> parent(n*n);
        vector<int> size(n*n,1);

        for(int i=0;i<n*n;i++){
          parent[i] =i;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    continue;
                } 
             int dx[] = {-1,0,1,0};
             int dy[] = {0,-1,0,1};
             for(int ind = 0;ind<4;ind++){
                int ni = i+dx[ind];
                int nj = j+ dy[ind];

                if(isvalid(ni,nj,n) && grid[ni][nj]==1){
                    int cellval = i*n + j;
                    int ncellval = ni*n + nj;
                      unionBySize(cellval,ncellval,parent,size);
                }
             }
            }
        }
    int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                set<int> ans;
                if(grid[i][j]==1){
                    continue;
                } 
             int dx[] = {-1,0,1,0};
             int dy[] = {0,-1,0,1};
             for(int ind = 0;ind<4;ind++){
                int ni = i+dx[ind];
                int nj = j+ dy[ind];

                if(isvalid(ni,nj,n) && grid[ni][nj]==1){
                     int ncellval = ni*n + nj;
                      ans.insert(findUPar(ncellval,parent));
                }
             }

             int c=1;

             for(auto it : ans){
                c+=size[it];
             }
             res = max(res,c);
            }
        }

        for(int i=0;i<n*n ;i++){
          res = max(res,size[findUPar(i,parent)]);
        }


return res;
    }
};
