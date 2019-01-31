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
			node[v].left->parent=NULL;
			node[v].left = NULL;
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
		if(node[u].left){
			node[u].left->parent=NULL;
			node[u].left->flip^=1;
			node[u].left->pathParent = &node[u];
			node[u].left=NULL;
			node[u].fix();
		}
	}

	Splay *access(int u){
		Splay *x, *pp;
		for(x = node[u].splay(); x->pathParent; x =pp){
			pp = x->pathParent->splay();
			x->pathParent = NULL;
			if(pp->right){
				pp->right->parent = NULL;
				pp->right->pathParent = pp;
			}
			pp->right = xl
			pp->fix();
		}
		return x;
	}
};