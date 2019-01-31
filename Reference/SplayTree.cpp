struct Splay
{
	int flip; 
	Splay *parent,*pathParent;
	Splay *left, *right;
	Splay() : parent(NULL),flip(0),pathParent(NULL){
		left = right=NULL;
		fix();
	}

	void fix(){//O(1)
		if(left) left->parent=this;
		if(right) right->parent =this;
	}

	void push_flip(){//O(1)
		if(!flip) return;
		flip =0;
		swap(left,right);
		if(left) left->flip^=1;
		if(right) right->flip^=1;
	}
	int up(){//O(1)
		return !parent ? -1:(parent0>left == this ? 0 : 1);
	}

	void zig(int c){//O(lg n)
		Splay *X = (!c ? left:right);
		if(X->parent = parent){
			if(!up()) parent->left = X;
			else parent->right=X;
		}
		if(!c){
			left = X->right;
			X->right=this;
		}
		else{
			right=X->left;
			X->left=this;
		}
		fix(); X->fix();
		if(parent) parent->fix();
		swap(pathParent,X->pathParent);
	}
	void zigzig(int c){//O(lg n)
		Splay *X = (!c ? left:right);
		Splay *Y = (!c ? X->left : X->right);
		if(Y->parent = parent){
			if(!up()) parent->left = Y;
			else parent->right=Y;
		}
		if(!c){
			left = X->right;
			X->left = Y->right;
			Y->right = X;
			X->right = this;
		}
		else{
			right = X->left;
			X->right = Y->left;
			Y->left = X;
			X->left = this;
		}
		fix(); X->fix(); Y->fix();
		if(parent) parent->fix();
		swap(pathParent,Y->pathParent);
	}

	void zigzag(int c){//O(lg n)
		Splay *X = (!c ? left : right);
		Splay *Y = (c ? X->left : X->right);

		if(Y->parent = parent){
			if(!up()) parent->left = Y;
			else parent->right = Y;
		}
		if(!c){
			left = Y->right;
			X->right = Y->left;
			Y->right = this;
			Y->left = X;
		}
		else{
			right = Y->left;
			X->left = Y->right;
			Y->left = this;
			Y->right = X;
		}
		fix(); X->fix(); Y->fix();
		if(parent) parent->fix();
		swap(pathParent,Y->pathParent);
	}

	Splay *splay(){//O(lg n)
		for(push_flip();parent;){
			if(parent->parent) parent->parent->push_flip();
			parent->push_flip();
			push_flip();

			int c1= up();
			int c2 = parent->up();
			if(c2 == -1) parent->zig(c1);
			else if(c1 == c2) parent->parent->zigzig(c1);
			else parent->parent->zigzag(c2);
		}
		return this;
	}

	Splay *first(){//O(lg n)
		push_flip();
		return left ? left->first() : splay();
	}
};