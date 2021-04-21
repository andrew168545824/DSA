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

void solve(string s){
	vi pos;
	for(int i=0;i<s.length();i++){
		if(s[i]=='[') pos.pb(i);
	}
	int cnt=0,trace=0;
	ll ans=0;
	FOR(i,0,s.length()){
		if(s[i]=='[') ++cnt,++trace;
		else if(s[i]==']') --cnt;
		if(cnt<0){
			ans+=pos[trace]-i;
			swap(s[i],s[pos[trace]]);
			cnt=1;
			++trace;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	//FileIO();
	int t;cin>>t;
	while(t--){
		string s;cin>>s;
		solve(s);
	}
}