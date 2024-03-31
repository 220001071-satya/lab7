# include <bits/stdc++.h>
using namespace std;

bool myComp(pair<int, int> a, pair<int, int> b){
    return 1.0 * a.second / a.first > 1.0 * b.second / b.first;
}
int main(){
    freopen("input1_greedy.txt", "r", stdin);
    freopen("output_greedy.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
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
        sort(p.begin(), p.end(), myComp);
        int ans = 0;
        int curr_weight = 0;
        for(int i = 0; i < n; i++){
            if(curr_weight + p[i].first <= limit){
                ans += p[i].second;
                curr_weight += p[i].first;
            }
        }
        cout << ans << endl;
    }
}