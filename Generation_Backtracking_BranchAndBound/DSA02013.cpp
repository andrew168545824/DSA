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

int n,p,s,x[100],ans,m;
vector<int> prime;
vector<vi> res;

bool nt(int n){
	for(int i=2;i<=sqrt(n);i++) 
		if(n%i==0) return false;
	return n>1;
}

void init(){
	cin>>n>>p>>s;
	prime.clear();
	res.clear();
	for(int i=p+1;i<=s;i++){
		if(nt(i)) prime.pb(i);
	}
	m=sz(prime);
	ans=0;
}

void ql(int sum,int pos,int cnt){
	if(sum==s && cnt==n){
		++ans;
		vi tmp(x,x+cnt);
		res.pb(tmp);
		return;
	}
	for(int j=pos;j<m;j++){
		if(sum+prime[j]<=s){
			x[cnt]=prime[j];
			ql(sum+prime[j],j+1,cnt+1);
		}
	}
}

int main(){
	FileIO();
	int t;cin>>t;
	while(t--){
		init();
		ql(0,0,0);
		cout<<ans<<"\n";
		for(int i=0;i<res.size();i++){
			for(int x: res[i])
				cout<<x<<" ";
			cout<<"\n";
		}
	}
}
