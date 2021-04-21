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


int find(ll a[],ll x, int l, int r){
	int res=-1;
	while(l<=r){
		int m = (l+r)/2;
		if(a[m]<=x){
			res = m+1;
			l = m+1;
		}
		else
			r = m-1;
	}
	return res;
}

int main(){
	//FileIO();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		ll x;
		int n;cin>>n>>x;
		ll a[n];
		FOR(i,0,n) cin>>a[i];
		//cout<<find(a,x,0,n-1)<<"\n";
		auto it = upper_bound(a,a+n,x);
		if(it==a)
			cout<<"-1\n";
		else cout<<it-a<<"\n";

	}
}
