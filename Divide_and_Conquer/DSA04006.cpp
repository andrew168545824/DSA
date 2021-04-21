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

ll count(int n, ll l, ll r){
	//cout<<n<<" "<<l<<" "<<r<<endl;
	if(l>r)
		return 0;
	if(l==r && n<=1)
		return n;
	int hat = (int)log2(n) +1;
	//cout<<"hat "<<hat<<endl;
	ll mid = pow(2, hat-1);
	if(l==mid){
		return n%2 + count(n/2, 1, r-mid);
	}
	else if(r==mid)
		return n%2 + count(n/2, l, mid-1);
	else if(l>mid)
		return count(n/2, l-mid, r-mid);
	else if(r<mid)
		return count(n/2, l, r);
	else return n%2+ count(n/2,l, mid-1) + count(n/2, 1, r-mid);
}

//1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1

vector<ll> power;

void init(ll n){
	int tmp = log2(n);
	for(int i=0;i<=tmp;i++){
		power.pb((ll)(pow(2,i)));
	}
}


int find(ll pos, ll n, int idx){
	if(pos%2==1)
		return 1;
	if(pos<power[idx])
		return find(pos, n/2, idx-1);
	else if(pos==power[idx])
		return n%2;
	return find(power[idx]-pos+power[idx], n/2, idx-1);
}

int main(){
	//FileIO();
	int t;cin>>t;
	while(t--){
		ll n,l,r;cin>>n>>l>>r;
		init(n);
		int ans =0 ;
		for(ll i = l;i<=r;i++){
			ans += find(i, n, sz(power)-1);
		}
		cout<<ans<<"\n";
		power.clear();
	}
}
