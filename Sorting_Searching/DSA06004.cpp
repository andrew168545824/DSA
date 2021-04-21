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
	FileIO();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		int a[n],b[m];
		FOR(i,0,n) cin>>a[i];
		FOR(i,0,m) cin>>b[i];
		vi hop,giao;
		int i=0,j=0;
		while(i<n && j<m){
			if(a[i]==b[j]){
				giao.pb(a[i]);
				hop.pb(a[i]);
				++i;++j;
			}
			else if(a[i]<b[j]){
				hop.pb(a[i]);++i;
			}
			else{
				hop.pb(b[j]);++j;
			}
		}
		while(i<n){
			hop.pb(a[i++]);
		}
		while(j<m){
			hop.pb(b[j++]);
		}
		for(int x: hop){
			cout<<x<<" " ;
		}
		cout<<"\n";
		for(int x:giao){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
}
