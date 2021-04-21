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

double euclidianDist(pi a, pi b){
	return sqrt(pow(a.fi-b.fi,2) + pow(a.se-b.se,2));
}

bool cmp1(pi a, pi b){
	return a.fi<b.fi;
}

bool cmp2(pi a, pi b){
	return a.se<b.se;
}

double bf(pi a[], int n){
	double min_dist = 1e18;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			min_dist = min(min_dist, euclidianDist(a[i],a[j]));
		}
	}
	return min_dist;
}

double combine(vii a, int n, double lower){
	sort(all(a),cmp2);
	double res = lower;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n && a[j].se -a[i].se<res;j++){
			res = min(res, euclidianDist(a[i],a[j]));
		}
	}
	return res;
}

double solve(pi a[],int n){
	if(n<=3)
		return bf(a,n);
	int m = n/2;
	pi mid = a[n/2];
	double left = solve(a,m);
	double right = solve(a+m,n-m);
	double lower = min(left, right);
	vii bet;
	for(int i=0;i<n;i++){
		if(abs(a[i].fi - mid.fi)<lower){
			bet.pb(a[i]);
		}
	}
	return min(lower, combine(bet, bet.size(), lower));
}

int main(){
	//FileIO();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		pi a[n];
		FOR(i,0,n){
			cin>>a[i].fi>>a[i].se;
		}
		sort(a,a+n,cmp1);
		cout<<fixed<<setprecision(6)<<solve(a,n)<<endl;
	}
}
