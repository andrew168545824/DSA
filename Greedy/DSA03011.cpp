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

const ll MOD = (ll) 1e9+7;
const int INF = (int) 1e9+1;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}


void FileIO(){
	freopen("input.txt","r", stdin);
	freopen("output.txt","w",stdout);
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		FOR(i,0,n){
			ull x;cin>>x;
			pq.push(x);
		}
		ll kq=0;
		while(sz(pq)>1){
			ll top1=pq.top();
			pq.pop();
			ll top2=pq.top();
			pq.pop();
			ll tmp=top1+top2;
			kq=(ans+tmp)%MOD;
			pq.push(tmp%MOD);
		}
		cout<<kq<<"\n";
	}
}
