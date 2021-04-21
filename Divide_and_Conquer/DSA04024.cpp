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

typedef vector<vector<ll>> vll;

void mul(vll &a, vll b,int n){
	ll c[n][n];
	FOR(i,0,n){
		FOR(j,0,n){
			c[i][j]={0};
			FOR(k,0,n){
				c[i][j] += a[i][k]*b[k][j]%MOD;
				c[i][j]%=MOD;
			}
		}
	}
	FOR(i,0,n){
		FOR(j,0,n) a[i][j] = c[i][j];
	}
}

void power(vll a,int n, int k){
	vll res(n);
	FOR(i,0,n){
		FOR(j,0,n){
			if(i==j) res[i].pb(1);
			else res[i].pb(0);
		}
	}
	while(k){
		if(k&1){
			mul(res, a, n);
		}
		mul(a,a,n);
		k/=2;
	}
	ll sum = 0;
	FOR(i,0,n){
		sum += res[n-1][i];
	}
	cout<<sum%MOD<<endl;
}


int main(){
	//FileIO();
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		vll a(n);
		FOR(i,0,n){
			FOR(j,0,n){
				int x;cin>>x;
				a[i].pb(x);
			}
		}
		power(a,n,k);
	}
}