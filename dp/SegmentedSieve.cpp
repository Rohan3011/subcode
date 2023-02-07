#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<int, string> pis;
typedef vector<pair<int, string>> vpis;
typedef vector<pair<int, int>>  vpi;

#define fo(i,n) for (int i = 0; i < n; i++)
#define FO(i,a,n) for(int i= a ; i<n ; i++ )
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define IMX INT_MAX
#define IMN INT_MIN
const unsigned int M = 1000000007;

#ifndef ONLINE_JUDGE
#define deb(x) cerr<< #x << "="<< x<<endl
#define deb2(x,y) cerr<< #x << "="<< x<<","<< #y << "="<< y<<endl
#else
#define deb(x)
#define deb2(x,y)
#endif
const int N = 100001 ;
bool sieve[N + 1] ;
void CreateSieve() {
	for (int i = 0 ; i <= N ; i++) {
		sieve[i] = true ;
	}

	for (int i = 2 ; i * i <= N ; i++) {
		if (sieve[i]) {
			for (int j = i * i ; j <= N ; j += i)
				sieve[j] = false ;
		}
	}
}

vi GenratePrimes(int n) {
	vi primes ;
	for (int i = 2 ; i <= n ; i++) {
		if (sieve[i])
			primes.pb(i) ;
	}
	return primes ;
}


void solve() {
	ll l , r ;
	cin >> l >> r ;
	CreateSieve() ;
	vi primes = GenratePrimes(sqrt(r)) ;
	for (auto u : primes) {
		cerr << u << " ";
	}	cerr << "\n" ;
	int n = r - l + 1 ;
	int segment[n] ;
	for (int i = 0; i < n ; i++)
		segment[i] = true ;

	for (auto prime : primes) {
		ll FirstMultiple = (l / prime) * prime ;
		if (FirstMultiple < l )
			FirstMultiple += prime ;
		for (ll j = max(FirstMultiple , (ll) prime * prime) ; j <= r ; j += prime) {
			segment[j - l] = false ;
		}
	}

	for (int i = l ; i <= r ; i++) {
		if (segment[i - l]) {
			if (i != 1)
				cout << i << "\n" ;
		}
	}

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