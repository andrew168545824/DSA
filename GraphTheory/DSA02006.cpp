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
int n,s,a[100],x[100],ok;
bool used[100];

void inp(){
	cin>>n>>s;
	FOR(i,1,n+1) cin>>a[i];
	sort(a,a+n+1);
	ms(used,false);
	ok=0;
}

void ql(int i,int k,int sum){
	if(sum==s){
		cout<<"[";
		for(int j=1;j<k;j++){
			cout<<x[j];
			if(j!=k-1) cout<<" ";
		}
		cout<<"] ";
		ok=1;
		return;
	}
	for(int j=i;j<=n;j++){
		if(!used[j] && sum+a[j]<=s){
			used[j]=true;
			x[k]=a[j];
			ql(j,k+1,sum+a[j]);
			used[j]=false;
		}
	}
}

int main(){
	int t;cin>>t;
	while(t--){
		inp();
		ql(1,1,0);
		if(ok) cout<<"\n";
		else cout<<"-1\n";
	}
}
