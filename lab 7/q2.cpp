#include<bits/stdc++.h>
using namespace std;

struct comparator {
    bool operator ()(const pair<int, pair<int, char>>& p1, const pair<int, pair<int, char>>& p2) {
        return p1.first > p2.first;
    }
};

int maxprofit(map<int, vector<pair<int, char>>>& m) {

    //minheap of pair of profit and pair of deadline and name of job
    priority_queue<pair<int, pair<int, char>>, vector<pair<int, pair<int, char>>>, comparator >pq;
    //minheap of jobs according to their profits
    int ans = 0;
    for (auto x : m) {
        int curr = x.first;//curr is the maximum size of pq for this iteration
        //it should be noted that in the previous iteration size of pq is acording to that iteration
        //so our constraint will remain valid
        int size = (int)(x.second).size();//size of vector

        for (int i = 0;i < size;i++) {
            if ((int)pq.size() < curr) {//if size of heap is less than maximum size for this iteration, simply add the job
                pq.push({ x.second[i].first,{x.first,x.second[i].second} });
                ans += x.second[i].first;//updating ans(maximum profit)
            }
            else if (pq.top().first < x.second[i].first) {//if size of heap is equal to maximum size and the current job gives more profit
                ans -= pq.top().first;//pop the minimum profit job in the heap and update the ans(max profit)
                pq.pop();

                pq.push({ x.second[i].first,{x.first,x.second[i].second} });//insert the current job and update the ans(maximum profit)
                ans += x.second[i].first;
            }
        }
    }
    multimap<int, char>dl;//for printing the sequence of job we make a multimap of deadline and name of job and contain all the elements of heap
    while (!pq.empty()) {
        dl.insert(pq.top().second);
        pq.pop();
    }
    for (auto q : dl) {
        cout << q.second << ' ';//outputing sequence
    }
    cout << endl;

    return ans;//returning maximum profit

}

int main() {
     freopen("input2.txt", "r", stdin);
     freopen("output2.txt", "w", stdout);
    int t;cin >> t;//number of test cases
    while (t--) {
        int n;
        cin >> n;//number of jobs
        map<int, vector<pair<int, char>>>m;
        for (int i = 0;i < n;i++) {
            char c;//name of job
            int d, p;//deadline and profit
            cin >> c >> d >> p;
            m[d].push_back({ p,c });//inserting into map
        }
        cout << maxprofit(m) << endl << endl;
    }
    return 0;
}