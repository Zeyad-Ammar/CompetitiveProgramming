struct stSegmentTree {
private:
#define lNode node*2+1
#define rNode node*2+2
#define mid l+((r-l)>>1)
#define value first
#define count second
int sz,skip = 0;
	struct stNode {
		int sum,pre,suf,mx;
		stNode(){}
		stNode(int _sum,int _pre,int _suf,int _mx):sum(_sum),pre(_pre),suf(_suf),mx(_mx) {}
	};
 
	vector<stNode> seg;
 
stNode merge(stNode lv,stNode rv) {
	stNode res;
	res.sum=(lv.sum+rv.sum);
	res.pre=max(lv.pre,lv.sum+rv.pre);
	res.suf=max(rv.suf,rv.sum+lv.suf);
	res.mx=max({lv.suf+rv.pre,lv.mx,rv.mx});
	return res;
}
 
 
 
	void build(int l,int r,int node,vi &v) {
 
if (l==r) {
	if (l<sz(v)) {
 
		seg[node] = stNode(v[l],v[l],v[l],v[l]);
 
 
	}
 
	return;
}
        build(l,mid,lNode,v);
		build(mid+1,r,rNode,v);
		seg[node]=merge(seg[lNode],seg[rNode]);
 
 
	}
 
void update(int l,int r, int node, int idx,int val) {
 
if (l==r) {
 
	seg[node]=stNode(val,val,val,val);
 
	return;
}
 
	if (idx>mid) {
		update(mid+1,r,rNode,idx,val);
	}else {
		update(l,mid,lNode,idx,val);
	}
 
	seg[node]=merge(seg[lNode],seg[rNode]);
 
 
}
 
 
 
public:
 
	stSegmentTree(vi &v) {//pass the vector u want to build the segtree on it.
		sz=1;
		while (sz<sz(v)) {
			sz*=2;
		}
		seg=vector<stNode>(2*sz,stNode(skip,skip,skip,skip));
 
		build(0,sz-1,0,v);
 
	}
 
 
	void update(int idx,int val) {
		update(0,sz-1,0,idx,val);
	}
 
 
	int query() {
		return seg[0].mx;
	}
 
#undef lNode
#undef rNode
#undef mid
};
