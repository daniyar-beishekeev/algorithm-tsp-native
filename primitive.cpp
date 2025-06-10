#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <numeric>

using namespace std;

template<typename T>
bool nextPermutation(vector<T>&vec){
	int n = vec.size();
	int i = n - 2;
	while(i >= 0 && vec[i] >= vec[i + 1])
		i--;
	if(i >= 0){
		int j = n - 1;
		while(vec[j] <= vec[i])
			j--;
		swap(vec[i], vec[j]);
	}
	//reverse()
	for(int l = i + 1, r = n - 1; l < r; l++, r--)
		swap(vec[l], vec[r]);
	return i >= 0;
}

typedef long long ll;
int main(){
	int n;
	cin >> n;
	vector<vector<ll> > edge(n, vector<ll> (n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> edge[i][j];

	ll ans = LLONG_MAX;

	vector<int> order(n), best(n);
	iota(order.begin(), order.end(), 0);
	
	do{
		ll cost = 0ll;
		for(int i = 0; i < n; i++)
			cost += edge[order[i]][order[(i + 1) % n]];
		if(cost < ans){
			ans = cost;
			best = order;
		}
	}while(nextPermutation(order));

	cout << ans << '\n';
	for(int i = 0; i < n; i++)
		cout << best[i] + 1 << " \n"[i == n - 1];
}