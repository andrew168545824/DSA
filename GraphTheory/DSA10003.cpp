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

int n,m;
int parent[1001],sz[1001];

int find(int x){
	if(x==parent[x])
		return x;
	return parent[x]=find(parent[x]);
}

int Union(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return 0;
	if(sz[x]<sz[y]) swap(x,y);
	sz[x]+=sz[y];
	parent[y]=x;
	return 1;
}

void solve(){
	cin>>n>>m;
	int coms=n;
	FOR(i,1,n+1){
		parent[i]=i;
		sz[i]=1;
	}
	bool ok=false;
	FOR(i,0,m){
		int x,y;cin>>x>>y;
		if(!Union(x,y)) ok=true;
	}
	cout<<(ok ? "YES\n" : "NO\n");
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		solve();
	}
}