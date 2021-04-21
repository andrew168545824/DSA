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

void tc(){
	int n,d,cnt=0;;cin>>n>>d;
	int a[n];
	FOR(i,0,n) cin>>a[i],cnt+=a[i]<=d;
	sort(a,a+n);
	if(cnt==n){
		cout<<"YES\n";return;
	}
	if(n==1 && a[0]<=d){
		cout<<"YES\n";
		return ;
	}
	else if(n==1 && a[0]>d){
		cout<<"NO\n";
		return ;
	}
	if(a[0]+a[1]<=d) cout<<"YES\n";
	else cout<<"NO\n";
}

int main(){
	//FileIO();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;cin>>t;
	while(t--){
		tc();
	}
}
