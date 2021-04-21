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

vector<vector<string>> a;

void init(){
	vector<string> v;
	v.pb("0");v.pb("1");
	a.pb(v);
	for(int i=2;i<=10;i++){
		vector<string> b(a[i-2]);
		reverse(all(b));
		vector<string> x;
		for(int j=0;j<a[i-2].size();++j){
			x.pb("0"+a[i-2][j]);
		}
		for(int j=0;j<b.size();++j){
			x.pb("1"+b[j]);
		}
		a.pb(x);
	}
}

int main(){
	init();
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(string x: a[n-1]){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
}
