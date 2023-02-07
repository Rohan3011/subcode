#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull ;
typedef long double ld ;
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
#define fo(i,n) for (int i = 0; i < n; i++)
#define FO(i,a,n) for(int i= a ; i<n ; i++ )
#define all(x) x.begin(), x.end()
ll binpow(ll a , ll b) ;
ll modmul(ll a , ll b , ll m);


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


//******************************** Template End ******************************//
#define int ll

int min_changes(map<int, int> &mp , int mex , int k , vector<int> &extra) {
    if (mex >= k)
        return mp[k] ;
    auto last = mp.upper_bound(k);
    int req = k - mex ;
    int req_sum = k * (k + 1) / 2 - mex * (mex + 1) / 2 ;
    int curr =  upper_bound(all(extra) , k) - extra.begin();
    if (curr < req)
        return -1 ;
    return req_sum - curr_sum ;
}


void solve() {
    int n ;
    cin >> n ;
    vector<int> arr(n) ;
    for (auto &u : arr)
        cin >> u ;
    map<int, int>mp ;
    for (int i =  0 ; i < n ; i++) {
        mp[arr[i]]++;
    }
    int mex = 0 ;
    for (auto &[x , y] : mp) {
        if (x == mex)
            mex++;
        else
            break;
    }
    vector<int> extra ;
    for (auto &[x , y] : mp) {
        for (int i = 1; i < y ; i++)
            extra.pb(x);
    }
    deb(extra);
    deb(mex);
    for (int i = 0 ; i <= n ; i++) {
        cout << min_changes(mp , mex , i) << ' ';
    }
    cout << '\n';
}



signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen ("error.txt", "w", stderr);
#endif
    int t ;
    cin >> t ;
    while (t--) {
        solve();
    }

#ifndef ONLINE_JUDGE
    cerr << "Runtime : " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

    return 0;
}

//******************************** Utility Functions *************************//

ll binpow(ll a , ll b) {
    ll res = 1 ;
    while (b) {
        if (b & 1) res = res * a % M ;
        a = a * a % M ;
        b >>= 1 ;
    }
    return res ;
}

ll modmul(ll a , ll b , ll m) {
    return ((a % m) * (b % m )) % m ;
}