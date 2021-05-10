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

int main(){
	//FileIO();
	int n;cin>>n;
	int a[n];
	FOR(i,0,n) cin>>a[i];
	sort(a,a+n);
	ll x1 = 1ll*a[0]*a[1]*a[n-1];
	ll x2 = 1ll*a[n-3]*a[n-2]*a[n-1];
	ll x3 = 1ll*a[0]*a[1];
	ll x4 = 1ll*a[n-2]*a[n-1];
	cout<<max(max(x1,x2), max(x3,x4))<<endl;
}
