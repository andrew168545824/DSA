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
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		int a[n],b[m];
		set<int> s1,s2;
		vi giao;
		FOR(i,0,n){
			cin>>a[i];
			s1.insert(a[i]);
			s2.insert(a[i]);
		}
		FOR(i,0,m){
			cin>>b[i];
			if(present(s1,b[i])){
				giao.pb(b[i]);
			}
			s2.insert(b[i]);
		}
		for(int x: s2) cout<<x<<" ";
		cout<<"\n";
		for(int x: giao){
			cout<<x<<" ";
		}
		cout<<"\n";
	}

}

