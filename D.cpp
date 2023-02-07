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

#define fo(i,n) for (int i = 0; i < n; i++)
#define fo2(i,a,n) for(int i= a ; i<n ; i++ )
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define deb(x) cout<< #x << "="<< x<<endl
#define deb2(x,y) cout<< #x << "="<< x<<","<< #y << "="<< y<<endl
#define INF 0x3f3f3f3f
#define endl "\n"
#define M  1000003

map<char,int> mp ;

void solve(){

    mp.insert({'>' ,1000});
    mp.insert({'<' ,1001});
    mp.insert({'+' ,1010});
    mp.insert({'-' ,1011});
    mp.insert({'.' ,1100});
    mp.insert({',' ,1101});
    mp.insert({'[' ,1110});
    mp.insert({']' ,1111});

     // ll n =1 ;
    string s,n;
    cin >> s;
    for(auto u : s){
        int x = mp[u];
        // cout << x <<" ";

        n= n+ to_string(x);
        
    }
    cout << stoll(n);
 
}




int main()
{
    ios::sync_with_stdio(0);cin.tie(0);


    //int t;
    //cin>>t;
    //while(t--){
    //}
    solve();
    return 0;
}