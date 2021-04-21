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

int n,a[100000];



int main(){
	//FileIO();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		cin>>n;
		FOR(i,0,n) cin>>a[i];
		sort(a,a+n,greater<int>());
		int idx = n/2-1;
		vi b(a,a+idx+1);
		vi c(a+idx+1,a+n);
		int ans =0;
		int i =0,j=0;
		while(i<sz(b) && j<sz(c)){
			if(b[i]>=2*c[j]){
				++i;++j;
				++ans;
			}
			else{
				++j;++ans;
			}
		}
		ans += sz(b)-i + sz(c)-j;
		cout<<ans<<"\n";
	}
}
