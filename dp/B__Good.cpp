#include <bits/stdc++.h>
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
int n , q , x , k = 1,  small , big , swapSmall , swapBig , right_ , left_ , ans;
void solve() {
    int n , q ;
    scanf("%d%d" , &n, &q);
    map<int, int> index , sortedIndex ;
    int arr[n + 1];
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d" , &arr[i]);
        index[arr[i]] = i ;
    }
    for (auto [x , y] : index) {
        sortedIndex[x] = k ;
        k++;
    }
    while (q--) {
        scanf("%d" , &x) ;
        k = index[x] ;
        int idx = sortedIndex[x] ;
        deb(k , idx);
        left_ = idx - 1 , right_ = n - idx ;
        small = big = swapBig = swapSmall = 0 ;
        int low = 0 , high = n ;
        while (high > low) {
            int mid = low + (high - low) / 2 ;
            if (mid == k)
                break ;
            else if (k < mid) {
                high = mid - 1;
                if (arr[k] < arr[mid]) big++;
                else swapBig++; //swap arr[mid] with value bigger than arr[k]
            }
            else {
                low = mid + 1;
                if (arr[k] > arr[mid]) small++;
                else swapSmall++; //swap arr[mid] with value smaller than arr[k]
            }
        }
        if (left_ < small || right_ < big)
            ans = -1;
        else
            ans = min(swapSmall , swapBig) + abs(swapBig - swapSmall);
        printf("%d\n", ans);
    }
}



signed main()
{
    // ios::sync_with_stdio(0); cin.tie(0);

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