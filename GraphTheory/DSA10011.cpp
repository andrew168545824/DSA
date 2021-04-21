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
int n,m,ans=INF;
int a[501][501];
int d[501][501];
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

void inp(){
	cin>>n>>m;
	FOR(i,1,n+1){
		FOR(j,1,m+1){
			cin>>a[i][j];
			d[i][j]=INF;
		}
	}
}

void dijkstra(){
	d[1][1]=a[1][1];
	priority_queue<pair<int,pi>,vector<pair<int,pi>> ,greater<pair<int,pi>> > pq;
	pq.push(mp(a[1][1],mp(1,1)));
	while(!pq.empty()){
		pair<int,pi> front=pq.top();
		pq.pop();
		int len=front.fi;
		pi pos=front.se;
		if(len>d[pos.fi][pos.se]) continue;
		for(int k=0;k<4;k++){
			int i1=pos.fi+dx[k];
			int j1=pos.se+dy[k];
			if(i1>=1 && i1<=n && j1>=1 && j1<=m){
				if(d[i1][j1]>d[pos.fi][pos.se]+a[i1][j1]){
					d[i1][j1]=d[pos.fi][pos.se]+a[i1][j1];
					pq.push(mp(d[i1][j1],mp(i1,j1)));
				}
			}
		}
	}
	cout<<d[n][m]<<"\n";
}

int main(){
	//FileIO();
	int t;cin>>t;
	while(t--){
		inp();
		dijkstra();
		ans=INF;
	}
}
