#include<bits/stdc++.h>
using namespace std;

// ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template < typename T >
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;


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

struct range
{
	int l ,  r ,  idx ;
	bool operator < (const range &other) {
		if (other.l == l)
			return r > other.r ;
		return l < other.l ;
	}
};


void solve() {
	int n ;
	cin >> n ;
	vector<range> ranges(n) ;
	vector<int> contains(n , 0);
	vector<int> contained(n , 0) ;
	for (int i = 0 ; i < n ; i++) {
		int a , b ;
		cin >> a >> b ;
		ranges[i].l = a ;
		ranges[i].r = b;
		ranges[i].idx = i;
	}
	sort(all(ranges)) ;
	ordered_set <pair<int, int>> os ;
	for (int i = 0 ; i < n ; i++) {
		os.insert({ranges[i].r , -1 * i});
		contained[ranges[i].idx] = os.size() - os.order_of_key({ranges[i].r , -1 * i}) - 1 ;
	}
	os.clear();
	for (int i = n - 1 ; i >= 0 ; i--) {
		os.insert({ranges[i].r , -1 * i}) ;
		contains[ranges[i].idx] = os.order_of_key({ranges[i].r , -1 * i});
	}

	for (auto u : contains) cout << u << " ";
	cout << "\n" ;
	for (auto u : contained) cout << u << " ";
	cout << "\n" ;
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