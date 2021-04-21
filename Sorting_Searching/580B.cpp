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

bool cmp(pi a,pi b){
	if(a.fi!=b.fi)
		return a.fi<b.fi;
	return a.se>b.se;
}

int main(){
	//FileIO();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,d;
	cin>>n>>d;
	vector<pi> a(n);
	for(auto &it : a){
		cin>>it.fi>>it.se;
	}
	sort(all(a),cmp);
	ll prefix[n];
	for(int i=0;i<n;i++){
		i==0 ? prefix[i]=a[i].se : prefix[i]=prefix[i-1]+a[i].se;
	}
	ll ans=-1e18;
	for(int i=0;i<n;i++){
		int l=i+1,r=n-1;
		int pos=i;
		while(l<=r){
			int m=(l+r)/2;
			if(a[i].fi+d>a[m].fi){
				pos=m;
				l=m+1;
			}
			else
				r=m-1;
		}
		if(i==0) ans=max(ans,prefix[pos]);
		else ans=max(ans,prefix[pos]-prefix[i-1]);
	}
	cout<<ans<<"\n";
}
