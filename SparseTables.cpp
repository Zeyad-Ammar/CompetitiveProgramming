struct SparseTable {

	vvi v;
	int n=1;
	int size=0;
	int ign=-oo;

	function<int(int,int)> merge;

	SparseTable(vi &vec,function<int(int,int)> mergeFunc,int ignValue) {

		merge=mergeFunc;
		ign=ignValue;
		size=sz(vec);
		n=__lg(size);
		v=vvi(n+1,vi(size));
		v[0]=vec;

		build();

	}



	void build() {


		for (int len=1;len<=n;len++) {
			int sl=len-1;

			for (int i=0;i<size-(1<<len)+1;i++) {
				int l=v[sl][i];
				int r=v[sl][i+(1<<sl)];

				v[len][i]=merge(l,r);
			}

		}
	}

	bool isOn(int num,int bit) {
		return (num>>bit)&1;
	}

	int query(int l,int r) {
		int len=r-l+1;
		int ans=ign;
		for (int b=0;l<=r;b++) {
			if (isOn(len,b)) {

				ans=merge(ans,v[b][l]);
				l+=(1<<b);
			}
		}

		return ans;
	}

	int queryOL(int l,int r) {
		int len=r-l+1;
		int pow=__lg(len);

		return merge(v[pow][l],v[pow][r-(1<<pow)+1]);
	}

};

