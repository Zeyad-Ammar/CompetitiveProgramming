struct FenwickTree{//do the operations prefix sum solve (operations that have inverse operation to can go forward and backward like sum&sub mul&div xor&xor.
//but w/ updates and it's use less memory than segtree cuz it's o(n) memory
    vector<ll>bit;int sz;
    FenwickTree(int n)
    {
        sz=n+1;
        bit=vector<ll>(sz);
    }
    void update(int idx,ll val)//if u need to set to a specific value make val= set - exist val
    {
        while(idx<sz)
        {
            bit[idx]+=val;//update the operation here from + to op in case another one
            idx+=idx&-idx;
        }
    }
    ll query(int idx)
    {
        ll ret=0;
        while(idx>0)
        {
            ret+=bit[idx];//update the operation here from + to another one
            idx-=idx&-idx;
        }
        return ret;
    }
    ll prefix(int l,int r)
    {
        return query(r)-query(l-1);
    }
};
