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

bool prime[1000001];

void sieve(){
	ms(prime,true);
	prime[0]=prime[1]=false;
	for(int i=2;i<=1000;i++){
		if(prime[i]){
			for(int j=i*i;j<=1e6;j+=i){
				prime[j]=false;
			}
		}
	}
}
int main(){
	//FileIO();
	sieve();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		bool ok=false;
		for(int i=1;i<=n;i++){
			if(prime[i] && prime[n-i]){
				cout<<i<<" "<<n-i<<"\n";
				ok=true;
				break;
			}
		}
		if(!ok) cout<<"-1\n";
	}
}
