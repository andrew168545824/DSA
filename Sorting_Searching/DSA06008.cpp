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

int tmp[5]={0};

ll count(int b[],int m,int x){
	if(x==0) return 0;
	if(x==1) return tmp[0];
	auto it =upper_bound(b,b+m,x);
	int ans = (b+m)-it;
	ans+=tmp[0]+tmp[1];
	if(x==2) ans-=tmp[3]+tmp[4];
	if(x==3) ans+=tmp[2];
	return ans;
}

int main(){
	//FileIO();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		int a[n],b[m];
		FOR(i,0,n){
			cin>>a[i];
		}
		ms(tmp,0);
		FOR(i,0,m){
			cin>>b[i];
			if(b[i]<=4){
				tmp[b[i]]++;
			}
		}
		sort(b,b+m);
		ll ans=0;
		for(int i=0;i<n;i++){
			ans+=count(b,m,a[i]);
		}
		cout<<ans<<"\n";
	}
}
