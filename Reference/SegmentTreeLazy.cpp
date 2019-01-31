template<typename T>
class SegmentTree
{
public:
	vector<T> ST,lazy;
	int n;
	T base_value;
	SegmentTree(int n,vector<T> & a){
		this->n = n;
		base_value = -INF;//0: sum,gcd 1:multiplication INF:min -INF:max 
		int h = ceil(log2(n));
		ST.resize((1 << (h+1)),base_value);
		lazy.resize((1 << (h+1)),0);
		build(0,n-1,1,a);
	}
	T F(T a,T b){
		//return a+b;
		return max(a,b);
		//return min(a,b);
		//return __gcd(a,b);
	}
	void build(int ini,int fin,int pos,vector<T> &a){
		if(ini == fin){
			ST[pos] = a[ini];	
			return;
		}
		int mitad = (ini+fin)/2;
		build(ini,mitad,pos*2,a);
		build(mitad+1,fin,pos*2+1,a);
		ST[pos] =  F(ST[pos*2],ST[pos*2+1]);
	}

	void propagate(int start, int end, int pos, T val){
		//ST[pos]+=(val*(end-start+1));//Sum
		ST[pos]+=val;//Min,max
		if(start!=end){
			lazy[pos*2]+=val;
			lazy[pos*2+1]+=val;
		}
	}
	void UpdateLazy(int left,int right,int pos,int start,int end,T val){
		if(lazy[pos] != 0){
			propagate(start,end,pos,lazy[pos]);
			lazy[pos]=0;
		}
		if(end < left || right < start)
			return;
	    if(start >= left && end <= right){
	    	propagate(start,end,pos,val);
	        return;
	    }
		int mitad = (start+end)/2;
		UpdateLazy(left,right,pos*2,start,mitad,val);
		UpdateLazy(left,right,pos*2+1,mitad+1,end,val);
		ST[pos] = F(ST[pos*2],ST[pos*2+1]);	
	}

	T Query(int start,int end,int pos,int left,int right){
		if(lazy[pos] != 0){
			propagate(start,end,pos,lazy[pos]);
			lazy[pos]=0;
		}
		if(end < left || right < start) 
			return base_value;//0 para suma, -INF para max e INF para min
		if(start >= left && end <= right)
			return ST[pos];
	
		int mitad = (start+end)/2;
		T izq = Query(start,mitad,pos*2,left,right);
		T der = Query(mitad+1,end,pos*2+1,left,right);
		return F(izq,der);
	}

	void singleElementUpdate(int left,int right,int pos,int start,int end, T value){
		if(lazy[pos] != 0){
			propagate(start,end,pos,lazy[pos]);
			lazy[pos]=0;
		}
		if(end < left || right < start)
			return;
		if(start >= left && end <= right){
			ST[pos]=value;
			return;
		}
		int mitad = (start+end)/2;
		singleElementUpdate(left,right,pos*2,start,mitad,value);
		singleElementUpdate(left,right,pos*2+1,mitad+1,end,value);
		ST[pos]=F(ST[pos*2],ST[pos*2+1]);
	}
};