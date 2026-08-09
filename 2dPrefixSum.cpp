void _2d_prefix()// Converts global vector v into its 2D prefix sum.
{
    for(int i=1;i<=n;i++)
    {
        for(int o=1;o<=m;o++)
        {
            v[i][o]+=v[i][o-1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int o=1;o<=m;o++)
        {
            v[i][o]+=v[i-1][o];
        }
    }
}
int query(int l1,int r1,int l2,int r2)//return the prefix sum of the rectangle of (l1,r1) to (l2,r2)
{
    int x=v[l2][r2]-v[l1-1][r2];
    int y=v[l2][r1-1]-v[l1-1][r1-1];
    return x-y;
}
