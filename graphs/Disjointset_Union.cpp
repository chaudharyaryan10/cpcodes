template<typename T>
class DSU{
    vector<T>size,parent;
public:
    DSU(T n){
        size.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    T findparent(T node){
        if(node == parent[node])
            return node;
        return parent[node] = findparent(parent[node]);
    }
    void Union(T u,T v){
        T ulp_u = findparent(u);
        T ulp_v = findparent(v);
        if(ulp_u == ulp_v)return;
        if(size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else if(size[ulp_v] < size[ulp_u]){
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
