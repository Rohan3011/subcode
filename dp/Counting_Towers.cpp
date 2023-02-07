#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull ;
typedef long double ld ;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

#define fo(i,n) for (int i = 0; i < n; i++)
#define FO(i,a,n) for(int i= a ; i<n ; i++ )
#define all(x) x.begin(), x.end()
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define IMX INT_MAX
#define IMN INT_MIN
const unsigned int M = 1000000007;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif

/*----------------------------------------------------------------------------------------------------------------------------*/

// Editorial : https://codeforces.com/blog/entry/70018?#comment-820275
ll dp[1000005][2] ;
void solve() {
	ll n ;
	cin >> n ;
	dp[1][0] = dp[1][1] = 1 ;
	for (int i = 2; i <= n ; i++) {
		dp[i][0] = (4 * dp[i - 1][0] + dp[i - 1][1]) % M ;
		dp[i][1] =  (dp[i - 1][0] + 2 * dp[i - 1][1]) % M ;
	}
	cout << (dp[n][0] + dp[n][1]) % M  << "\n" ;
}



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen ("error.txt", "w", stderr);
#endif


	int t;
	cin >> t;
	while (t--) {
		solve();
	}

#ifndef ONLINE_JUDGE
	cerr << "Runtime : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

	return 0;
}