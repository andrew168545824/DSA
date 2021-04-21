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

int bs(int a[],int l,int r,int x){
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]==x)
			return m;
		else if(a[m]<x)
			l=m+1;
		else r=m-1;
	}
	return -1;
}

int find(int a[],int l,int r){
	if(l==r)
		return l;
	else if(l>r)
		return -1;
	int m=(l+r)/2;
	if(m<r && a[m]>a[m+1]){
		return m;
	}
	if(m>l && a[m]<a[m-1])
		return m-1;
	if(a[m]>=a[l])
		return find(a,m+1,r);
	return find(a,l,m-1);
}

int main(){
	//FileIO();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		int n,x;cin>>n>>x;
		int a[n];
		FOR(i,0,n) cin>>a[i];
		int chot=find(a,0,n-1);
		if(chot==-1){
			cout<<bs(a,0,n-1,x)+1<<"\n";
		}
		else if(a[chot]==x){
			cout<<chot+1<<"\n";
		}
		else if(a[0]<=x){
			cout<<bs(a,0,chot-1,x)+1<<"\n";
		}
		else cout<<bs(a,chot+1,n-1,x)+1<<"\n";
	}
}
