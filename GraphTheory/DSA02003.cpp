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

int a[100][100],n,ok;
char c[1000];
void inp(){
	cin>>n;
	FOR(i,1,n+1){
		FOR(j,1,n+1) 
			cin>>a[i][j];
	}
}

void ql(int i,int j,int k){
	if(i==n && j==n){
		for(int i=1;i<k;i++){
			cout<<c[i];
		}
		cout<<" ";
		ok=1;
		return;
	}
	if(i+1<=n && a[i+1][j]==1){
		c[k]='D';
		a[i+1][j]=0;
		ql(i+1,j,k+1);
		a[i+1][j]=1;
	}
	if(j+1<=n && a[i][j+1]==1){
		c[k]='R';
		a[i][j+1]=0;
		ql(i,j+1,k+1);
		a[i][j+1]=1;
	}
}
int main(){
	int t;cin>>t;
	while(t--){
		inp();
		ok=0;
		if(a[1][1] && a[n][n]){
			ql(1,1,1);
		}
		if(ok) cout<<"\n";
		else cout<<"-1\n";
	}
}
