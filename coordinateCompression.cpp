struct coordinateCopmression{
private:
    vector<ll>init;
    void compress(vector<ll>&v)
    {
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
    }
public:
    coordinateCopmression(vector<ll>&v)//pass the vector u want to build the coordinate compression vector on it.
    {
        init=v;
        compress(init);
    }
    int index(ll val)//give u the compression or idx of the value after compress.
    {
        return lower_bound(init.begin(),init.end(),val)-init.begin();
    }
    ll initVal(int idx)//give u the real value of the compressed value
    {
        return init[idx];
    }
};
