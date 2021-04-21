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

int n;
vector<vector<pi>> adj(100);
int c[100][100];
void inp(){
	cin>>n;
	FOR(i,1,n+1){
		FOR(j,1,n+1){
			int x;cin>>x;
			c[i][j]=x;
			if(i<j){
				adj[i].pb({x,j});
				adj[j].pb({x,i});
			}
		}
	}
}

void mst(){
	int mst_cost=0;
	vi mst;
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.push({0,1});
	vector<bool> used(n+1,false);
	used[1]=true;
	while(!pq.empty()){
		pi front=pq.top();
		pq.pop();
		if(used[front.se]) continue;
		mst_cost+=front.fi;
		used[front.se]=true;
		mst.pb(front.fi);
		for(auto it :adj[front.se]){
			if(!used[it.se]){
				pq.push({it.fi,it.se});
			}
		}
	}
	mst_cost+=c[mst.back()][1];
	cout<<mst_cost<<"\n";
}
int main(){
	FileIO();
	inp();
	mst();
}
