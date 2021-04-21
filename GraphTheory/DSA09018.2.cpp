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

int n,m,timer=0;
vi adj[1001];
vi num,low,ap;
bool used[1001];


void inp(){
	cin>>n>>m;
	FOR(i,0,m){
		int x,y;cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	num.resize(n+1);
	low.resize(n+1);
	ap.resize(n+1,0);
	ms(used,false);
}

void dfs(int u,int par){
	used[u]=true;
	low[u]=num[u]=++timer;
	int child=0;
	for(int v: adj[u]){
		if(v==par) continue;
		if(!used[v]){
			++child;
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(par==-1){
				if(child>1)
					ap[u]=1;
			}
			else if(low[v]>=num[u]){
				ap[u]=1;
			}
		}
		else{
			low[u]=min(low[u],num[v]);
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		inp();
		timer=0;
		dfs(1,-1);
		FOR(i,1,n+1){
			if(ap[i]) cout<<i<<" ";
		}
		low.clear();ap.clear();num.clear();
		FOR(i,1,n+1) adj[i].clear();
		cout<<"\n";
	}
}
