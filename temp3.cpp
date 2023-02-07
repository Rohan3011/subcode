#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef set<int> si;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<int,string> pis;
typedef vector<pair<int,string>> vpis;
typedef vector<pair<int,int>>  vpi;
 
#define fo(i,n) for (ll i = 0; i < n; i++)
#define fo2(i,a,n) for (ll i = a; i < n; i++)
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define endl  "\n"
#define deb(x) cout<< #x << "="<< x<<endl
#define deb2(x,y) cout<< #x << "="<< x<<","<< #y << "="<< y<<endl
 
 
void solve(){
    ll a,b,c,d,m,n;
    cin>>a>>b>>c>>d;
     m=max(a,b);
     n=max(c,d);
     b=min(a,b);
     d=min(c,d);

     if(m>=d  and n>=b){
       cout << "YES\n";
     }
     else{
      cout << "NO\n";
     }
     
        // cout<<(( ) ? : "NO\n");
  return;
 
 
}