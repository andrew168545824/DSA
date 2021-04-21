#include <bits/stdc++.h>
using namespace std;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define present(t, x) (t.find(x) != t.end())
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;

const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+1;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}


void FileIO(){
	freopen("input.txt","r", stdin);
	freopen("output.txt","w",stdout);
}

void tc(){
	int n;cin>>n;
	int a[n];
	FOR(i,0,n) cin>>a[i];
	int l=-1,r=n;
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			l=i;break;
		}
	}
	for(int i=n-1;i>0;i--){
		if(a[i]<a[i-1]){
			r=i;break;
		}
	}
	int nho=*min_element(a+l,a+r+1);
	int lon=*max_element(a+l,a+r+1);
	for(int i=0;i<=l;i++){
		if(a[i]>nho){
			l=i;break;
		}
	}
	for(int i=n-1;i>=r;i--){
		if(a[i]<lon){
			r=i;break;
		}
	}
	cout<<l+1<<" "<<r+1<<"\n";
}
int main(){
	//FileIO();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		tc();
	}

}
