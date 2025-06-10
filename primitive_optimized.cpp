#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <numeric>

using namespace std;

typedef long long ll;
int n;
vector<int>idx, path;
vector<vector<ll> > edge;
vector<int>best;
ll ans = LLONG_MAX;

ll cur_cost = 0;

void go(int depth){
	if(depth == n){
		ll cost = cur_cost + edge[path[n - 1]][path[0]];
		if(cost < ans){
			ans = cost;
			best = path;
		}
		return;
	}
	int head = 0;
	while(idx[head] >= 0){
		int cur = idx[head];
		idx[head] = idx[cur];

		ll weight = 0;
		weight = edge[path[depth - 1]][cur - 1];
		path[depth] = cur - 1;

		cur_cost += weight;
		go(depth + 1);
		cur_cost -= weight;

		idx[head] = cur;

		head = cur;
	}
}

int main(){
	cin >> n;
	edge.assign(n, vector<ll>(n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> edge[i][j];

	idx.resize(n + 1);
	iota(idx.begin(), idx.end(), 1);
	idx[n] = -1;
	idx[0] = 2;
	path.resize(n);
	go(1);

	cout << ans << '\n';
	for(int i = 0; i < n; i++)
		cout << best[i] + 1 << " \n"[i == n - 1];
}