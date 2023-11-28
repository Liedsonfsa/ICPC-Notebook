// O(maxn * maxv) time complexity

const int inf = 1e9;
const int maxn = 105;
const int maxv = 1005;

ll coins[maxn];
ll memo[maxn][maxv];
int n;

ll solve(int i, int v){
	if(v == 0) return 0;
	if(i == n) return inf;
	
	if(memo[i][v] != -1) return memo[i][v];
	ll r = inf;
	if(coins[i] <= v) r = min(r, 1+solve(i, v-coins[i]));
	
	r = min(r, solve(i+1, v));
	memo[i][v] = r;
	
	return r;
}

int main() { _
	int v;
	cin >> n;
	cin >> v;

	for(int i = 0; i < n; i++) cin >> coins[i];
	
	for(int i = 0; i < maxn; i++) for(int j = 0; j < maxv; j++) memo[i][j] = -1;
	
   	cout << solve(0, v) << '\n';

    return 0;
}
