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
int dis[1001][1001];
vector<vi> adj(1001);
//d[i][j] : shortest distance from i to j

bool used[101];


void inp(){
	cin>>n>>m;
	FOR(i,0,m){
		int x,y;cin>>x>>y;
		adj[x].pb(y);
	}
}


void bfs(int u){
	used[u]=true;
	dis[u][u]=0;
	int timer=0;
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int v=q.front();q.pop();
		for(int x :adj[v]){
			if(!used[x]){
				used[x]=true;
				dis[u][x]=dis[u][v]+1;
				q.push(x);
			}
		}
	}
}

void init(){
	int sum=0,cnt=0;
	FOR(i,1,n+1){
		ms(used,false);
		bfs(i);
	}
	FOR(i,1,n+1){
		FOR(j,1,n+1){
			//cout<<dis[i][j]<<" ";
			if(dis[i][j]){
				++cnt;
				sum+=dis[i][j];
			}
		}
		//cout<<"\n";
	}
	cout<<fixed<<setprecision(2)<<(double)sum/cnt<<"\n";
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;cin>>t;
	while(t--){
		inp();
		ms(dis,0);
		init();
		FOR(i,1,n+1) adj[i].clear();
	}
}
