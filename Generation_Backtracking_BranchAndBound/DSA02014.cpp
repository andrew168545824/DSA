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

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
char c[100][100];
int n,m,k;
vector<string> res;
set<string> dict;
bool used[100][100];

void dfs(int i, int j, string s){
	if(present(dict,s)){
		res.pb(s);
	}
	for(int it = 0 ; it < 8; it++){
		int i1=i+dx[it];
		int j1=j+dy[it];
		if(i1>=1 && i1<=n && j1>=1 && j1<=m && !used[i1][j1]){
			used[i1][j1]=true;
			dfs(i1, j1, s+c[i1][j1]);
			used[i1][j1]=false;
		}
	}
}


void solve(){
	res.clear();
	dict.clear();
	cin>>k>>n>>m;
	FOR(i,0,k){
		string s;cin>>s;
		dict.insert(s);
	}
	FOR(i,1,n+1){
		FOR(j,1,m+1){
			cin>>c[i][j];
		}
	}
	FOR(i,1,n+1){
		FOR(j,1,m+1){
			ms(used,false);
			used[i][j]=true;
			string s="";
			dfs(i, j,s+c[i][j]);
		}
	}
	if(sz(res)==0){
		cout<<"-1\n";
	}
	else{
		for(string x:res){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
}


int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
}
