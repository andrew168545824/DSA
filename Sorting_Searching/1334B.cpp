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

void tc(){
	int n,k;cin>>n>>k;
	int a[n];
	ll sum=0,cnt=0,res=0;
	FOR(i,0,n){
		cin>>a[i];
		if(a[i]==k) ++res;
		else{
			++cnt;
			sum+=a[i];
		}
	}
	sort(a,a+n);
	if(cnt !=0 && sum/cnt>=k){
		cout<<n<<"\n";
	}
	else{
		for(int i=0;i<n && a[i]<k;++i){
			sum-=a[i];
			--cnt;
			if(cnt==0) break;
			if(sum/cnt>=k){
				res+=cnt;
				break;
			}
		}
		cout<<res<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;cin>>t;
	while(t--){
		tc();
	}
}
