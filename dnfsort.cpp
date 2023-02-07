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


void dnf(int arr[],int n){
  int l=0,m=0,h=n-1;

while(m<h){
  if(arr[m]==0){
    swap(arr[m],arr[l]);
    l++;
  }
  if(arr[m]==1){
    m++;
  }
    if(arr[m]==2){
    swap(arr[m],arr[h]);
    h--;  }

}
fo(i,n){cout<<arr[i]<<" ";}

}

void solve(){
 int i,j,sum=0,ans=0,cnt=0;
 int n;
 cin>>n;
 int  arr[n];
 fo(i,n){
  cin>>arr[i];
 }
 dnf(arr,n);


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