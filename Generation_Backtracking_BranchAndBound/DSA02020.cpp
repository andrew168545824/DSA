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

ll prime[10]={2,3,5,7,11,13,17,19,23,29};
int n;

ll ql(ll cnt, ll num, ll pos){
	//cout<<cnt<<" "<<num<<" "<<pos<<"\n";
	if(cnt==n) return num;
	ll ans=1e18+1;
	for(int i=1;;i++){
		num*=prime[pos];
		if(ans<num || cnt*(i+1)>n) break;
		ans=min(ans, ql(cnt*(i+1),num,pos+1));
	}
	return ans;
}

int main(){
	//FileIO();
	int t;cin>>t;
	while(t--){
		cin>>n;
		cout<<ql(1,1,0)<<"\n";
	}
}
