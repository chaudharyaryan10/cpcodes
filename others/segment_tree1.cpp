// point update
template<typename T>
class SGTree{
    vector<T>seg;
    vector<T>lazy;
public:
    //SGTree<int/long long>st(n);
    SGTree(T n){
        seg.resize(4*n+1);
    }
    // sg1.build(0,0,n-1,arr);
    void build(T ind,T low,T high,vector<T>arr)
    {
        if(low==high)
        {
            seg[ind] = arr[low];
            return;
        }
        T mid = low + (high-low)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
    // sg1.query(0,0,n-1,l,r)
    T query(T ind,T low,T high,T l,T r)
    {
        if(r<low || high<l)return 0;
        if(low>=l && high <=r)return seg[ind];
        T mid = low+(high-low)/2;
        T left = query(2*ind+1,low,mid,l,r);
        T right = query(2*ind+2,mid+1,high,l,r);
        return left+right;
    }
    // sg1.update(0,0,n-1,i,val);
    void update(T ind,T low,T high,T i,T val)
    {
        if(low == high)
        {
            seg[ind] = val;
            return;
        }
        T mid = low + (high-low)/2;
        if(i<=mid)update(2*ind+1,low,mid,i,val);
        else update(2*ind+2,mid+1,high,i,val);
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
};
