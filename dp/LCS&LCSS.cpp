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

bool issubstring(string s1 , string s2) {
	int n = s1.size() ; // original string ;
	int m = s2.size() ;

	for (int i = 0 ; i < n - m ; i++) {
		int j ;
		for ( j = 0 ; j < m ; j++) {
			if (s1[i + j] != s2[j]) {
				break ;
			}
		}
		if (j == m) {
			deb2(i, j) ;
			return true ;
		}
	}
	return false ;
}



int LCsubstr(string s1 , string s2) {
	int m = s1.size() ;
	int n = s2.size() ;

	int dp[m + 1][n + 1] ;
	int ans = 0 ;

	// initialzing
	for (int k = 0 ; k <= m; k++) // row
		dp[k][0] = 0 ;
	for (int k = 0 ; k <= n ; k++) // column
		dp[0][k] = 0 ;

	for (int i = 1 ; i <= m; i++) {
		for (int j = 1; j <= n ; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1 ;
				ans = max(ans , dp[i][j]) ;
			}
			else
				dp[i][j] = 0;
		}
	}



	return ans ;
}
int LCsubseq(string s1 , string s2) {
	int m = s1.size() ;
	int n = s2.size() ;

	int dp[m + 1][n + 1] ;
	int ans = 0 ;

	// initialzing
	for (int k = 0 ; k <= m; k++) // row
		dp[k][0] = 0 ;
	for (int k = 0 ; k <= n ; k++) // column
		dp[0][k] = 0 ;

	for (int i = 1 ; i <= m; i++) {
		for (int j = 1; j <= n ; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1 ;
				ans = max(ans , dp[i][j]) ;
			}
			else
				dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
		}
	}

	// for (int i = 0 ; i <= m ; i++) {
	// 	for (int j = 0 ; j <= n ; j++)
	// 		cout << dp[i][j] << " " ;
	// 	cout << endl;
	// }

	return dp[m][n] ;
}

void solve() {
	string s1 , s2 ;
	cin >> s1 >> s2 ;
	// deb2(s1 , s2);
	// cout << (issubstring(s1 , s2) ? "YES\n"  : "NO\n")  ;
	cout << LCsubstr(s1, s2) ;
}



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen ("error.txt", "w", stderr);
#endif


	solve() ;

#ifndef ONLINE_JUDGE
	cerr << "Runtime : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

	return 0;
}