#include <bits/stdc++.h>
using namespace std;

int util(vector<int>& weights, vector<int>& value, int index, int limit){
    if(index < 0) return 0;
    if(limit < 0) return 0;
    int val =  util(weights, value, index - 1, limit);
    if(limit - weights[index] >= 0){
        val = max(val, util(weights, value, index - 1, limit - weights[index]) + value[index]);
    }
    return val;
    
}

int main(){
    freopen("input1_greedy.txt", "r", stdin);
    freopen("output_greedy.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--)
        {    int n;
            cin >> n;
            vector<int> weights(n), value(n);
            for(int i = 0; i < n; i++) cin >> weights[i];
            for(int i = 0; i < n; i++) cin >> value[i];
            vector<pair<int, int>> p(n);
            for(int i = 0; i < n; i++){
                p[i] = {weights[i], value[i]};
            }
            int limit;
            cin >> limit;
            cout << util(weights, value, n - 1, limit) << endl;
            }
        
        
}