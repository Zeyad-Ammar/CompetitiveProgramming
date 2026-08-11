struct dsu
{//used to merge 'connect' 2 nodes w/ each others. create the graph when the question we need
//to make groups of people, nodes, etc.
    int parent[N],group[N];
    dsu()
    {
        for(int i=0;i<N;i++)
        {
            parent[i]=i;
            group[i]=1;
        }
    }
    int AbsLeader(int i)
    {
        if(parent[i]==i)
        {
            return i;
        }
        return parent[i]= find(parent[i]);
    }
    bool samegroup(int x,int y)
    {
        return find(x)==find(y);
    }
    void merge(int x,int y)
    {
        int leader1=find(x);
        int leader2=find(y);
        if(leader1==leader2)
        {
            return;
        }
        if(group[leader1]>group[leader2])
        {
            parent[leader2]=leader1;
            group[leader1]+=group[leader2];
        }
        else
        {
            parent[leader1]=leader2;
            group[leader2]+=group[leader1];
        }
    }
    int getsize(int x)
    {
        return group[find(x)];
    }
};
