struct stSegmentTree {//use in operations that don't have inverse operations always forward same operations of sparse tables max, min, gcd, lcm but w/ updates.
private:
#define lNode node*2+1
#define rNode node*2+2
#define mid l+((r-l)>>1)
int sz,skip = oo;//update the skip to the appropriate ignore value of ur operation U use
	vi seg;
 
int merge(int l,int r) {//update to the operation u want
	return min(l,r);
}
 
	void build(int l,int r,int node,vi &v) {
 
if (l==r) {
	if (l<sz(v)) {
		seg[node]=v[l];
 
	}
	return;
}
        build(l,mid,lNode,v);
		build(mid+1,r,rNode,v);
		seg[node]=merge(seg[lNode],seg[rNode]);
 
	}
 
void update(int l,int r, int node, int idx,int val) {
 
if (l==r) {
	seg[node]=val;
	return;
}
 
	if (idx>mid) {
		update(mid+1,r,rNode,idx,val);
	}else {
		update(l,mid,lNode,idx,val);
	}
	seg[node]=merge(seg[lNode],seg[rNode]);
}
 
int query(int l,int r, int node,int lq,int rq) {
	if (r<lq || l>rq) return skip;
	if (l>=lq && r<=rq) return seg[node];
	int left=query(l,mid,lNode,lq,rq);
	int right=query(mid+1,r,rNode,lq,rq);
	return merge(left,right);
}
 
public:
 
	stSegmentTree(vi &v) {//pass the vector u want to build the segment tree on it.
		sz=1;
		while (sz<sz(v)) {
			sz*=2;
		}
		seg=vi(2*sz,skip);
 
		build(0,sz-1,0,v);
 
	}
 
 
	void update(int idx,int val) {
		update(0,sz-1,0,idx,val);
	}
 
 
	int query(int l ,int r) {
		return query(0,sz-1,0,l,r);
	}
 
#undef lNode
#undef rNode
#undef mid
};
