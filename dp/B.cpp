#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define IMX INT_MAX
#define IMN INT_MIN
const unsigned int M = 1000000007;
#define fo(i, n) for (int i = 0; i < n; i++)
#define FO(i, a, n) for (int i = a; i < n; i++)
#define all(x) x.begin(), x.end()
ll binpow(ll a, ll b);
ll modmul(ll a, ll b, ll m);
//******************************** Template End ******************************//
#define int ll

void solve() {
  int n, q, x;
  cin >> n >> q;
  vector<int> arr(n), pre(n);
  for (auto &u : arr)
    cin >> u;
  sort(all(arr), greater<>());
  pre[0] = arr[0];
  for (int i = 1; i < n; i++)
    pre[i] = pre[i - 1] + arr[i];

  while (q--) {
    cin >> x;

    int low = 1, high = n, ans = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (pre[mid-1] >= x) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    cout << ans << endl;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifndef ONLINE_JUDGE
  freopen("error.txt", "w", stderr);
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

//******************************** Utility Functions *************************//

ll binpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = res * a % M;
    a = a * a % M;
    b >>= 1;
  }
  return res;
}

ll modmul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m; }