#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>,
        rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int main(){
    ordered_set X; // 1, 2, 4, 8, 16
    for(int i = 1; i <= 16; i *= 2)
        X.insert(i);
    cout << *X.find_by_order(1) << endl; // Returns kth element
    cout << *X.find_by_order(2) << endl; // 4
    cout << (X.end()==X.find(6)) << endl; // Search
    X.erase(8);// Delete
    cout<<X.order_of_key(3)<<endl;// 2 Returns lower_bound
}
/*
typedef tree<int,int,less<int>,
    rb_tree_tag,tree_order_statistics_node_update> map_t;
int main(){
  map_t s;
  s.insert(make_pair(12, 1012));
  cout << s.find_by_order(1)->second << '\n';
  return 0;
}
*/