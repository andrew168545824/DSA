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

int n,m,k;
int a[1000001],b[1000001];

void inp(){
	cin>>n>>m>>k;
	FOR(i,0,n) cin>>a[i];
	FOR(i,0,m) cin>>b[i];
}


int find(int l1, int r1, int l2, int r2,int k){
	if(l1>r1) return b[k-1];
	if(l2>r2) return a[k-1];
	int m1 = (l1+r1)/2;
	int m2 = (l2+r2)/2;
	if(m1+m2==k)
		return max(a[m1],b[m2]);
	if(m1+m2<k){
		if(a[m1]<b[m2]){
			return find(m1+1, r1, l2, r2,k-)
		}
	}
}
int Union(){
	int i=0,j=0,cnt = 0;
	while(i<n && j<m){
		if(a[i]<=b[j]){
			++i;
			++cnt;
			if(cnt==k)
				return a[i-1];
		}
		else{
			++j;++cnt;
			if(cnt==k) return b[j-1];
		}
	}
	while(i<n){
		++i;++cnt;
		if(cnt==k) return a[i-1];
	}
	while(j<m){
		++j;++cnt;
		if(cnt==k) return b[j-1];
	}
}

int main(){
	//FileIO();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		inp();
		cout<<Union()<<endl;
	}
}