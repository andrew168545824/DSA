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

int main(){
	//FileIO();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;cin>>n;
	int a[n];
	ll prefix[n+1]={0};
	FOR(i,0,n){
		cin>>a[i];
		prefix[i+1]=prefix[i]+a[i];
	}
	sort(a,a+n);
	ll prefix2[n+1]={0};
	FOR(i,0,n){
		prefix2[i+1]=prefix2[i]+a[i];
	}
	int m;cin>>m;
	while(m--){
		int x,l,r;cin>>x>>l>>r;
		if(x==1){
			cout<<prefix[r]-prefix[l-1]<<"\n";
		}
		else{
			cout<<prefix2[r]-prefix2[l-1]<<"\n";
		}
	}
}
