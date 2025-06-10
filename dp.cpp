#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <numeric>
#include <assert.h>
template<typename T>
bool umin(T &a,T b){if(b<a){a=b;return true;}return false;}

using namespace std;

typedef long long ll;
const ll INF = 1e17;//Avoid int overflow

void backtrack(int n, vector<vector<ll> >&edge, vector<vector<ll> >&dp, int mask, int i, int type){
	if(mask == 1 || mask == 0)return;
	int prev = -1;
	for(int j = 0; j < n; j++){
		if(i != j && (mask >> j & 1)){
			/* Try to reach from "j" */
			ll w = edge[j][i];
			if(type)w = edge[i][j];
			if(dp[mask][i] == dp[mask ^ (1 << i)][j] + w)
				prev = j;
		}
	}
	assert(~prev);
	if(!type)backtrack(n, edge, dp, mask ^ (1 << i), prev, type);
	cout << ' ' << i + 1;
	if(type)backtrack(n, edge, dp, mask ^ (1 << i), prev, type);
}

int main(){
	int n;
	cin >> n;
	vector<vector<ll> > edge(n, vector<ll> (n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			cin >> edge[i][j];
			if(edge[i][j] == -1)
				edge[i][j] = INF;
		}

	vector<vector<ll> > dp(1 << n, vector<ll>(n, INF));//From 0
	vector<vector<ll> > dp2(1 << n, vector<ll>(n, INF));//To 0
	dp[1][0] = 0;
	dp2[1][0] = 0;
	int MAX_MASK = (1 << n) - 1;
	for(int mask = 2/*Skip 1*/; mask <= MAX_MASK; mask++){
		if(mask & 1){
			for(int i = 0; i < n; i++){
				if(mask >> i & 1){
					/* Reach state "mask", ending in a vertex "i" */
					for(int j = 0; j < n; j++){
						if(i != j && (mask >> j & 1)){
							/* Try to reach from "j" */
							umin(dp[mask][i], dp[mask ^ (1 << i)][j] + edge[j][i]);
							umin(dp2[mask][i], dp2[mask ^ (1 << i)][j] + edge[i][j]);
						}
					}
				}
			}
		}
	}
	ll ans = INF;
	int ans_mask;
	int ans_fr;
	int ans_sc;
	for(int mask = 1; mask <= MAX_MASK; mask++){
		if(mask & 1){
			int mask2 = MAX_MASK ^ mask ^ 1;
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					if((mask >> i & 1) && (mask2 >> j & 1)){
						if(umin(ans, dp[mask][i] + dp2[mask2][j] + edge[i][j])){
							ans_mask = mask;
							ans_fr = i;
							ans_sc = j;
						}
					}
		}
	}
	cout << ans << '\n';
	//Backtracking
	cout << 1;
	backtrack(n, edge, dp, ans_mask, ans_fr, 0);
	backtrack(n, edge, dp2, MAX_MASK ^ ans_mask ^ 1, ans_sc, 1);
	cout << '\n';
}