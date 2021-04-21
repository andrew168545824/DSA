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

int n,a[100][100];

void inp(){
	cin>>n;
	FOR(i,1,n+1){
		cin>>a[n][i];
	}
}

void ql(int hang){
	if(hang==0) return;
	for(int i=1;i<=hang;i++){
		a[hang][i]+=a[hang+1][i]+a[hang+1][i+1];
	}
	ql(hang-1);
}

int main(){
	//FileIO();
	int t;cin>>t;
	while(t--){
		inp();
		ql(n);
		for(int i=1;i<=n;i++){
			cout<<"[";
			for(int j=1;j<=i;j++){
				cout<<a[i][j];
				if(j!=i) cout<<" ";
			}
			cout<<"] ";
		}
		ms(a,0);
		cout<<"\n";
	}
}
