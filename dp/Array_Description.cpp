#include <bits/stdc++.h>
using namespace std ;

int main() {
	int n , m ;
	cin >> n >> m ;
	int arr[n] ;
	for (auto &i : arr) cin >> i ;
	const int M = 1e9 + 7 ;
	int dp[n][m + 1] ;
	memset(dp , 0 , sizeof(dp)) ;
	if (arr[0] == 0)
		fill(dp[0] , dp[0] + m + 1 , 1) ;
	else dp[0][arr[0]] = 1 ;

	for (int i = 1 ; i < n ; i++) {
		if (arr[i]) {
			for (auto k : {arr[i] - 1 , arr[i] , arr[i] + 1}) {
				if (k >= 1 && k <= m)
					(dp[i][arr[i]] += dp[i - 1][k]) %= M ;
			}
		}
		else {
			for (int j = 1 ; j <= m ; j++) {
				for (auto k : {j - 1 , j , j + 1}) {
					if (k >= 1 && k <= m)
						(dp[i][j] += dp[i - 1][k]) %= M ;
				}
			}
		}
	}
	int ans = 0 ;
	for (int i = 1 ; i <= m ; i++)
		(ans += dp[n - 1][i]) %= M ;

	cout << ans << "\n" ;
}