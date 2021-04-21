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

bool cmp(pair<int,pi> a, pair<int,pi> b){
	return a.se.se>b.se.se;
}

void solve(){
	int n;cin>>n;
	vector<pair<int,pi>> v(n);
	FOR(i,0,n){
		cin>>v[i].fi>>v[i].se.fi>>v[i].se.se;
	}
	sort(all(v),cmp);
	bool used[n];
	ms(used,false);
	int res[n]={0};
	for(int i=0;i<n;i++){
		for(int j=min(n,v[i].se.fi)-1;j>=0;j--){
			if(!used[j]){
				used[j]=true;
				res[j]=i;break;
			}
		}
	}
	int cnt=0,ans=0;
	FOR(i,0,n){
		if(used[i]){
			ans+=v[res[i]].se.se;
			++cnt;
		}
	}
	cout<<cnt<<" "<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		solve();
	}
}
