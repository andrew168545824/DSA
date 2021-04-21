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

int n,m,a[501][501];
int dx[8]={0,-1,-1,-1,0,1,1,1};
int dy[8]={-1,-1,0,1,1,1,0,-1};

void inp(){
	cin>>n>>m;
	FOR(i,1,n+1){
		FOR(j,1,m+1){
			cin>>a[i][j];
		}
	}
}

void dfs(int i,int j){
	a[i][j]=0;
	for(int k=0;k<8;k++){
		int i1=i+dx[k];
		int j1=j+dy[k];
		if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1]){
			dfs(i1,j1);
		}
	}
}

void countIsland(){
	int ans=0;
	for(int i=1;i<=n;i++){
		FOR(j,1,m+1){
			if(a[i][j]){
				++ans;
				dfs(i,j);
			}
		}
	}
	cout<<ans<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		inp();
		countIsland();
	}
}
