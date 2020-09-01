#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
multiset <int> s;

int solution(vector<int> a,int k) {
    int ans = 1e9;
    for(int i = 0;i < k-1;i++) {
       s.insert(a[i]);
    }
    
    for(int i = k-1;i < a.size();i++) {
       s.insert(a[i]);
       auto it = s.end(); 
       --it;
       ans = min(ans,*it);
       s.erase(s.find(a[i-(k-1)]));
    }
    return ans;
}
