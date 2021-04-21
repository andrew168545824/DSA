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

int n,m,s,t;
vector<vi> adj;
vi parent;
bool used[1001];

void inp(){
	cin>>n>>m>>s>>t;
	adj.resize(n+1);
	parent.assign(n+1,-1);
	FOR(i,0,m){
		int x,y;cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	ms(used,false);
}

void DFS(int u){
	used[u]=true;
	for(int v: adj[u]){
		if(!used[v]){
			parent[v]=u;
			DFS(v);
		}
	}
}

void path(){
	DFS(s);
	vi path;
	if(!used[t]){
		cout<<"-1\n";
	}
	else{
		while(t!=s){
			path.pb(t);
			t=parent[t];
		}
		path.pb(s);
		reverse(all(path));
		for(int x: path)
			cout<<x<<" ";
		cout<<"\n";
	}
}
int main(){
	FileIO();
	int t;cin>>t;
	while(t--){
		inp();
		path();
		adj.clear();
	}
}
