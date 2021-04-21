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

int first1(int a[],int l,int r,int x){
	int pos=-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]==x){
			pos=m;
			r=m-1;
		}
		else if(a[m]>x){
			r=m-1;
		}
		else l=m+1;
	}
	return pos;
}

int last(int a[],int l,int r,int x){
	int pos=-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]==x){
			pos=m;
			l=m+1;
		}
		else if(a[m]>x){
			r=m-1;
		}
		else l=m+1;
	}
	return pos;
}


int main(){
	//FileIO();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		int n,x;cin>>n>>x;
		int a[n];
		int cnt=0;
		FOR(i,0,n){
			cin>>a[i];
			cnt+=a[i]==x;
		}
		if(cnt==0) cout<<"-1\n";
		else cout<<cnt<<"\n";
	}
}
