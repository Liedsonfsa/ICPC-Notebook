const int MOD = 1e9+7;
const int MAXN = 1e6+10;
 
ll fact[MAXN], inv[MAXN];
 
ll inverse(ll x){
	ll r = 1;
	ll exp = MOD-2;
	while(exp > 0){
		if(exp&1) r = (r*x)%MOD;
		x = (x*x) % MOD;
		exp >>= 1;
	}
 
	return r;
}
 
void init(){
	fact[0] = inv[0] = 1;
	for(int i = 1; i <= MAXN; i++){
		fact[i] = i * fact[i-1] % MOD;
		inv[i] = inverse(fact[i]);
	}
}
 
int main() { _
	init();
	int n; cin >> n;
	while(n--){
		ll a, b; cin >> a >> b;
		cout << fact[a] * inv[b] % MOD * inv[a-b] % MOD << '\n';
 
	}	
 
    return 0;
}
