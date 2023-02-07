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


void solve() {
	int n , m ,  sum = 1;
	cin >> n >> m ;
	vi arr(n + 1) , pos(n + 1, 0) ;
	for (int i = 1 ; i <= n ; i++) {
		cin >> arr[i] ;
		pos[arr[i]] =  i ;
	}
	for (int i = 1 ; i < n ; i++)
		sum += (pos[i] > pos[i + 1]);
	while (m--) {
		int a , b ;
		cin >> a >> b ;
		set<pair<int, int>> st ;
		// Each swap will effect the adjecent elements
		if (arr[a] - 1 >= 1 )st.insert({arr[a] - 1 , arr[a]}) ;
		if (arr[a] + 1 <= n )st.insert({arr[a] , arr[a] + 1}) ;
		if (arr[b] - 1 >= 1)st.insert({arr[b] - 1 , arr[b]}) ;
		if (arr[b] + 1 <= n )st.insert({arr[b] , arr[b] + 1}) ;

		// Excluding the rounds which were due to indexes a and b
		// Because, we are swaping them
		for (auto u : st)
			sum -= (pos[u.F] > pos[u.S]) ;
		swap(arr[a] , arr[b]) ;
		pos[arr[a]] = a ;
		pos[arr[b]] = b ;

		// Including new rounds due to swap
		for (auto u : st)
			sum += (pos[u.F] > pos[u.S]) ;
		cout << sum << "\n" ;
	}



}



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen ("error.txt", "w", stderr);
#endif

	solve();

#ifndef ONLINE_JUDGE
	cerr << "Runtime : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

	return 0;
}