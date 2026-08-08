struct stSegmentTree {
#define L node*2+1
#define R node*2+2
#define mid l+((r-l)>>1)
private:
	int sz,skip=oo,iv=0;//update the skip value according to the operation u need to use
	vi seg,lazy;
 
	int merge(int ln,int rn) {//update the merege according to the merge of nodes operation (query u want)
		ret min(ln,rn);
	}
 
	void propagate(int l,int r,int node) {
		if (!lazy[node]) {
			ret;
		}
 
		if (l!=r) {
			lazy[L]+=lazy[node];//update the operation according to the update insturction u want add, set, sub etc.(here is add a value.) (update U want)
			lazy[R]+=lazy[node];
		}
 
		seg[node]+=lazy[node];
		lazy[node]=0;
 
	}
 
 
	void update(int l,int r,int node,int lu,int ru,int val) {
		propagate(l,r,node);
		if (l==r) {
			if (l>=lu&&r<=ru) {
				lazy[node]+=val;// update the update operation according to the problem
				propagate(l,r,node);
 
			}
			ret;
		}
 
		if (l>ru||r<lu) {
			ret;
		}
 
		if (l>=lu&&r<=ru) {
			lazy[node]+=val;
			propagate(l,r,node);
			ret;
		}
 
		update(l,mid,L,lu,ru,val);
		update(mid+1,r,R,lu,ru,val);
		seg[node]=merge(seg[L],seg[R]);
 
	}
 
 
	int query(int l,int r,int node,int lq,int rq) {
		propagate(l,r,node);
 
		if (l==r) {
			if (l>=lq&&r<=rq) return seg[node];
			ret skip;
		}
 
 
		if (l>rq||r<lq) {
			ret skip;
		}
 
		if (l>=lq&&r<=rq) {
			ret seg[node];
		}
 
		ret merge(query(l,mid,L,lq,rq),query(mid+1,r,R,lq,rq));
 
	}
public:
 
	stSegmentTree(int n) {//pass the  size of the vector u want to build the lazy seg on it.
		sz=1;
		while (sz<n) sz<<=1;
 
		seg=vi(sz<<1,iv);
		lazy=vi(sz<<1,0);
 
	}
 
	void update(int lu,int ru,int val) {//use it to initial the vector also.
		update(0,sz-1,0,lu,ru,val);
	}
 
	int query(int l,int r) {
		return query(0,sz-1,0,l,r);
	}
 
 
#undef L
#undef R
#undef mid
};
 
