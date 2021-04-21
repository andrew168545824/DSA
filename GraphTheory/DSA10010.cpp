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
vector<pi> adj[100001];

void inp(){
	cin>>n>>m;
	FOR(i,0,m){
		int x,y,w;cin>>x>>y>>w;
		adj[x].pb(mp(y,w));
		adj[y].pb(mp(x,w));
	}
}

void dijsktra(){
	vector<ll> d(n+1,1e18);
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq;
	d[1]=0;
	pq.push({0,1});
	vector<ll> path(n+1,0);
	path[1]=1;
	while(!pq.empty()){
		pair<ll,int> front=pq.top();
		pq.pop();
		ll len=front.fi;
		int v=front.se;
		//cout<<len<<" "<<v<<"\n";
		if(v==n){
			cout<<d[n]<<" "<<path[n]<<endl;
			return;
		}
		//if(len>d[v]) continue;
		for(auto it : adj[v]){
			if(d[it.fi]>d[v]+it.se){
				d[it.fi]=d[v]+it.se;
				pq.push({d[it.fi],it.fi});
				path[it.fi]=path[v];
			}
			else if(d[it.fi]==d[v]+it.se){
				path[it.fi]+=path[v];
			}
		}
	}
}

int main(){
	//FileIO();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;t=1;
	while(t--){
		inp();
		dijsktra();
		FOR(i,1,n+1) adj[i].clear();
	}
}