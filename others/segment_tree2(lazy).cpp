// range update 
template<typename T>
class SGTree{
    vector<T>seg;
    vector<T>lazy;
public:
    //SGTree<int/long long>st(n);
    SGTree(T n){
        seg.resize(4*n+1);
        lazy.resize(4*n+1);
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
    T range_query(T ind,T low,T high,T l,T r)
    {
        // update the previous remaining updates
        // and propagate downwards
        if(lazy[ind]!=0){
            seg[ind]+=(high-low+1)*lazy[ind];
            if(low!=high){
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind] = 0;
        }
        if(r<low || high<l)return 0; // no-overlap
        if(low>=l && high <=r)return seg[ind]; // complete-overlap
        T mid = low+(high-low)/2; // partial-overlap
        T left = query(2*ind+1,low,mid,l,r);
        T right = query(2*ind+2,mid+1,high,l,r);
        return left+right;
    }

    void range_update(T ind,T low,T high, T l, T r, T val)
    {
        // update the previous remaining updates
        // and propagate downwards
        if(lazy[ind]!=0){
            seg[ind]+=(high-low+1)*lazy[ind];
            if(low!=high){
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind] = 0;
        }
        //no overlap
        if(high<l || r<low){
            return;
        }
        // complete overlap
        if(low>=l && high <=r)
        {
            seg[ind] += (high-low+1)*val;
            if(low!=high){
                lazy[2*ind+1] +=val;
                lazy[2*ind+2] +=val;
            }
            return;
        }
        //partial overlap
        T mid=low+(high-low)/2;
        range_update(2*ind+1,low,mid,l,r,val);
        range_update(2*ind+1,mid+1,high,l,r,val);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
};
