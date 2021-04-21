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

int n,m,a[100][100];
int cnt=0;
void inp(){
	cin>>n>>m;
	FOR(i,1,n+1){
		FOR(j,1,m+1) cin>>a[i][j];
	}
	cnt=0;
}

void ql(int i,int j){
	if(i==n && j==m){
		++cnt;return;
	}
	if(i+1<=n){
		ql(i+1,j);
	}
	if(j+1<=m){
		ql(i,j+1);
	}
}

int main(){
	int t;cin>>t;
	while(t--){
		inp();
		ql(1,1);
		cout<<cnt<<"\n";
	}
}
