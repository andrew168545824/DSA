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

int n,m,u;
vi adj[1001];
vector<pi> tree;
bool used[1001];

void inp(){
	cin>>n>>m>>u;
	FOR(i,0,m){
		int x,y;cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	ms(used,false);
}

void dfs(int u){
	used[u]=true;
	for(int v: adj[u]){
		if(!used[v]){
			tree.pb({u,v});
			dfs(v);
		}
	}
}

void solve(){
	dfs(u);
	for(int i=1;i<=n;i++){
		if(!used[i]){
			cout<<"-1\n";return;
		}
	}
	for(auto it : tree){
		cout<<it.fi<<" "<<it.se<<"\n";
	}
}

int main(){
	//FileIO();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		inp();
		solve();
		FOR(i,1,n+1) adj[i].clear();
		tree.clear();
	}
}
