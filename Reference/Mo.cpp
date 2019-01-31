struct query
{
    int L, R,id;
};
typedef query* queer;

class Mo
{
public:
    int n,m,block;

    Mo(int n,int m){
        this->n=n;
        this->m=m;
        block = (int)(sqrt(n));
    }

    bool compare(queer x, queer y){
        if (x->L/block != y->L/block)
            return x->L/block < y->L/block;
        return x->R < y->R;
    }

    void queryResults(vector<int> &a, vector<queer> &q){   
        vector<int> resultados(m);   
        sort(q.begin(), q.end(), compare);

        int total = 0;
        int l = q[0]->L;
        int r = q[0]->R;
        int num;
        //Only for first query
        for (int i = l; i <= r; ++i){
            num = a[i];
            //Your code goes here
        }
        resultados[q[0]->id] = total; 
        int currL = l, currR = r;
        for (int i=1; i<m; i++){
            int L = q[i]->L, R = q[i]->R;
            //Add from left side
            while (currL > L){
                num = a[currL-1];
                //Your code goes here
                currL--;
            }
            //Add from right side
            while (currR < R){
                num = a[currR+1];  
                //Your code goes here
                currR++;
            }
            //Delete from left side
            while (currL < L){
                num = a[currL];
                //Your code goes here
                currL++;
            }    
            //Delete from right side
            while (currR > R){
                num = a[currR];
                //Your code goes here
                currR--;
            }
            resultados[q[i]->id]=total; 
        }
        for (int i = 0; i < resultados.size(); ++i){
            cout << resultados[i] << "\n";
        }
    }  
};