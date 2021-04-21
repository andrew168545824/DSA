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

vi v,x(100);
ll res;
int n;

bool checkPerfectcube(ll x){
	int a=cbrt(x)+0.5;
	return 1ll*a*a*a==x;
}

void ql(int i){
	for(int j=0;j<=1;j++){
		x[i]=j;
		if(i==n-1){
			ll ans=0;
			for(int k=0;k<n;k++){
				if(x[k]){
					ans=ans*10+v[k];
				}
			}
			if(ans>res && checkPerfectcube(ans) && ans!=0){
				res=ans;
			}
		}
		else ql(i+1);
	}
}


void solve(){
	ll s;cin>>s;
	while(s){
		v.pb(s%10);s/=10;
	}
	n=v.size();
	reverse(all(v));
	res=-1;
	ql(0);
	cout<<res<<"\n";
	v.clear();
}

int main(){
	//FileIO();
	int t;cin>>t;
	while(t--){
		solve();
	}
}
