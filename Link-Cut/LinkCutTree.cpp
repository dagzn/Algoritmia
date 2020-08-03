#define forn(i,a,n) for(int i=a; i < n; i++)

struct Splay
{
	int flip; 
	Splay *parent,*pathParent;
	Splay * c[2];//c[0] = left, c[1]= right
	Splay() : parent(NULL),flip(0),pathParent(NULL){
		c[0] = c[1] =NULL;
		fix();
	}

	void fix(){//O(1)
		forn(i,0,2) if(c[i]) c[i]->parent = this;
	}

	void push_flip(){//O(1)
		if(!flip) return;
		flip =0;
		swap(c[0],c[1]);
		forn(i,0,2) if(c[i]) c[i]->flip^=1;
	}

	int up(){//O(1)
		return !parent ? -1:(parent->c[0] == this ? 0 : 1);
	}
	
	void rotate(){
		Splay *B = parent;
		int tag = up(),t2 = B->up();
		if(B->parent)
			B->parent->c[t2] = this;
		parent = B->parent;
		if(c[tag^1]) c[tag^1]->parent = B;
		B->c[tag] = c[tag^1];
		c[tag^1] = B;
		B->parent = this;
		fix();
		B->fix();
		swap(pathParent,B->pathParent);
	}

	Splay *splay(){//O(lg n)
		for(push_flip();parent;){
			if(parent->parent) parent->parent->push_flip();
			parent->push_flip();
			push_flip();
			int t1= up(), t2 = parent->up();
			if(t2 != -1)
				if(t1 == t2) parent->rotate();//zig-zig
				else rotate();//zig-zag
			rotate();
		}
		return this;
	}

	Splay *first(){//O(lg n)
		push_flip();
		return c[0] ? c[0]->first() : splay();
	}
};

struct LinkCut
{
	vector<Splay> node;
	LinkCut(int N): node(N){}
	
	void link(int u,int v){
		make_root(v);
		node[v].pathParent = &node[u];
	}

	void cut(int u, int v){
		make_root(u);
		node[v].splay();
		if(node[v].pathParent) node[v].pathParent= NULL;
		else{
			node[v].c[0]->parent=NULL;
			node[v].c[0] = NULL;
			node[v].fix();
		}
	}

	bool connected(int u,int v){
		Splay *nu = access(u)->first();
		Splay *nv = access(v)->first();
		return nu == nv;
	}

	void make_root(int u){
		access(u);
		node[u].splay();
		if(node[u].c[0]){
			node[u].c[0]->parent=NULL;
			node[u].c[0]->flip^=1;
			node[u].c[0]->pathParent = &node[u];
			node[u].c[0]=NULL;
			node[u].fix();
		}
	}

	Splay *access(int u){
		Splay *x, *pp;
		for(x = node[u].splay(); x->pathParent; x =pp){
			pp = x->pathParent->splay();
			x->pathParent = NULL;
			if(pp->c[1]){
				pp->c[1]->parent = NULL;
				pp->c[1]->pathParent = pp;
			}
			pp->c[1] = x;
			pp->fix();
		}
		return x;
	}
};
