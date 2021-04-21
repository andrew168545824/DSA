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

bool cmp(pi a, pi b){
	if(abs(a.fi)!=abs(b.fi))
		return abs(a.fi)<abs(b.fi);
	return a.se<b.se;
}

int brute(int a[],int n){
	int ans,sum=1e9;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(abs(a[i]+a[j])<sum){
				sum=abs(a[i]+a[j]);
				ans=a[i]+a[j];
			}
		}
	}
	return ans;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<pi> v(n);
		FOR(i,0,n){
			cin>>v[i].fi;
			v[i].se=i;
		}
		sort(all(v),cmp);
		int minpos,res,sum=1e9;
		for(int i=1;i<n;i++){
			if(abs(v[i].fi+v[i-1].fi)<sum){
				sum=abs(v[i].fi+v[i-1].fi);
				res=v[i].fi+v[i-1].fi;
				minpos=min(v[i].se,v[i-1].se);
			}
			else if(abs(v[i].fi+v[i-1].fi)==sum){
				if(minpos>min(v[i].se,v[i-1].se)){
					res=v[i].fi+v[i-1].fi;
					minpos=min(v[i].se,v[i-1].se);
				}
			}
		}
		cout<<res<<"\n";
	}
}
