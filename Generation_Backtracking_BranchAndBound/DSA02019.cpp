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

int n,m,ans;
vector<vi> adj(100);
bool mark[100][100];

void inp(){
	cin>>n>>m;
	ans=0;
	FOR(i,0,n) adj[i].clear();
	FOR(i,0,m){
		int x,y;cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
}

void dfs(int u,int cnt){
	for(int x:adj[u]){
		if(!mark[u][x] && !mark[x][u]){
			mark[u][x]=mark[x][u]=true;
			dfs(x,cnt+1);
			mark[u][x]=mark[x][u]=false;
		}
	}
	ans=max(ans,cnt);
}


int main(){
	//FileIO();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;cin>>t;
	while(t--){
		inp();
		for(int i=0;i<n;i++){
			ms(mark,false);
			dfs(i,0);
		}
		cout<<ans<<"\n";
	}
}
