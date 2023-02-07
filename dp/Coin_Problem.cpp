#include <bits/stdc++.h>
#include <cmath>
using namespace std;

/**
 * Question: Form the target sum using minimun possible coins
 * Hint: Greedy may not work.
 */

#define INF 1e9

int minCoins(vector<int> coins, int targetSum) {
	int dp[targetSum + 1] , first[targetSum + 1];
	dp[0] = 0 ;
	for (int x = 1; x <= targetSum; x++) {
		dp[x] = INF;
		for (auto &c : coins) {
			if (x - c >= 0 && dp[x] > dp[x - c] + 1) {
				dp[x] = dp[x - c] + 1;
				first[x] = c ;
			}
		}
	}
	int sum = targetSum ;
	while (sum) {
		cout << first[sum] << " " ;
		sum -= first[sum] ;
	}
	puts("");
	return dp[targetSum];
}


int ways(vector<int> coins , int targetSum) {
	int dp[targetSum + 1];
	dp[0] = 1;
	for (int x = 1 ; x <= targetSum ; x++) {
		dp[x] = 0 ;
		for (auto &c : coins) {
			if (x - c >= 0)
				dp[x] += dp[x - c] ;
		}
	}

	return  dp[targetSum];
}

int main() {
	int n, targetSum;
	cin >> n >> targetSum;
	vector<int> coins(n);
	for (auto &c : coins)
		cin >> c;

	/**
	 * In dp, main idea is to find over-lapping subproblem.
	 * i.e. smaller version of problems can be used to solve
	 * the bigger ones.
	 * in this example:
	 * coinsRequired[x] = min( coinRequried[x - coins[0...n]] + 1)
	 *
	 *
	 */

	// cout << minCoins(coins, targetSum) << "\n";
	cout << ways(coins, targetSum) << "\n";
}