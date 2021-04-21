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

int a[100],n,k,ok;

void next(){
	int i=k;
	while(i>=1 && a[i]==n-k+i){
		--i;
	}
	if(i==0){
		ok=true;//tat ca duoc nghi
		return;
	}
	a[i]++;
	FOR(j,i+1,k+1){
		a[j]=a[i]+j-i;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;cin>>t;
	while(t--){
		cin>>n>>k;
		ok=false;
		set<int> s;
		FOR(i,1,k+1){
			cin>>a[i];
			s.insert(a[i]);
		}
		next();
		if(ok){
			cout<<k<<"\n";
		}
		else{
			int ans=0;
			for(int i=1;i<=k;i++){
				if(!present(s,a[i])) ++ans;
			}
			cout<<ans<<"\n";
		}
	}
}
