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

int n,k,a[1005];

void inp(){
	cin>>n>>k;
	FOR(i,1,k+1) cin>>a[i];
}

void previous(){
	int i=k-1;
	while(i>=1 && a[i]==a[i+1]-1) --i;
	if(i==0 && a[1]==1){
		FOR(i,1,k+1){
			cout<<n-k+i<<" ";
		}
		cout<<"\n";
		return;
	}
	else{
		a[i+1]--;
		FOR(j,i+2,k+1){
			a[j]=n-k+j;
		}
	}
	FOR(i,1,k+1) cout<<a[i]<<" ";
	cout<<"\n";
}

int main(){
	int t;cin>>t;
	while(t--){
		inp();
		previous();
	}
}
