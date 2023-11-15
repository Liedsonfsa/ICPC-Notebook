
const int maxn = 2 * 1e5;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

vector<vi> g(maxn);
vector<bool> visited(maxn, false);
void dfs(int u){
	if(!visited[u]){
		visited[u] = true;
		for(auto x : g[u]){
			visited[x] = true;
		}
	}
}

int main() { _
	int n, m; cin >> n >> m;

	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b), g[b].pb(a);
	}
	
	// memset(visited, false, sizeof(visited));

	int ans = 0;
  // find number of components connected 
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
	 		dfs(i);
			ans++;
		}
	}
    

	cout << ans << '\n';

  return 0;
}
