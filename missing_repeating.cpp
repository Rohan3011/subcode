#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int,int> pi;
typedef pair<int,string> pis;
typedef vector<pair<int,string>> vpis;
typedef vector<pair<int,int>>  vpi;

#define fo(i,n) for (int i = 0; i < n; i++)
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define size() sz
#define deb(x) cout<< #x << "="<< x<<endl
#define deb2(x,y) cout<< #x << "="<< x<<","<< #y << "="<< y<<endl
#define INF 0x3f3f3f3f
#define endl "\n"




void solve(){
 int i=0,j,sum=0,cnt=0;
 int k=1;
 int n;
 cin>>n;
 int ans=n*(n+1)/2;
 int arr[n+1];
 for(int i=1;i<=n;i++){
cin>>arr[i];
 }
 int temp[n+1]={0};
 for(int i=0;i<n;i++){
 	if(temp[arr[i]]==0){
 		temp[arr[i]]=1;
 	}
 	if(temp[arr[i]]==1){
 		ans=arr[i];
 	}
 }

for(int i=1;i<=n;i++){
 	if(temp[i]==0){
 		cout<<"missing no= "<<i<<" repeating no= "<<ans<<endl;
 	}
 }


}






int main()
{
    ios::sync_with_stdio(0);cin.tie(0);

    string s;
    //int t;
    //cin>>t;
    //while(t--){
    // 
    //}
    solve();
    return 0;
}