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

int n,s,x[100],ok,k,res;
int a[100];

void next(){
	int i=k;
	while(i>=1 && a[i]==n-k+i){
		--i;
	}
	if(i==0){
		ok=false;return;
	}
	a[i]++;
	FOR(j,i+1,n+1){
		a[j]=a[i]+j-i;
	}
}


bool check(){
	ll sum=0;
	FOR(i,1,k+1){
		sum+=x[a[i]];
	}
	return sum==s;
}

void solve(){
	for(int i=1;i<=n;i++){
		k=i;
		FOR(j,1,k+1) a[j]=j;
		ok=true;
		while(ok){
			if(check()){
				cout<<i<<"\n";
				res=1;
				return;
			}
			next();
		}
	}
}

int main(){
	//FileIO();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;cin>>t;
	while(t--){
		cin>>n>>s;
		FOR(i,1,n+1) cin>>x[i];
		sort(x+1,x+n+1,greater<int>());
		res=0;
		solve();
		if(res==0){
			cout<<"-1\n";
		}
	}
}
