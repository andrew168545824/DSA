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

void merge(int a[],int l,int m,int r){
	int n1=m-l+1;
	int n2=r-m;
	int x[n1],y[n2],j=0;
	FOR(i,l,m+1){
		x[j++]=a[i];
	}
	j=0;
	FOR(i,m+1,r+1){
		y[j++]=a[i];
	}
	int i=0;j=0;
	while(i<n1 && j<n2){
		if(x[i]<=y[j]){
			a[l++]=x[i];++i;
		}
		else{
			a[l++]=y[j++];
		}
	}
	while(i<n1){
		a[l++]=x[i++];
	}
	while(j<n2){
		a[l++]=y[j++];
	}
}

void mergerSort(int a[],int l,int r){
	if(l>=r) return ;
	int m=(l+r)/2;
	mergerSort(a,l,m);
	mergerSort(a,m+1,r);
	merge(a,l,m,r);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n];
		FOR(i,0,n) cin>>a[i];
		mergerSort(a,0,n-1);
		for(int x: a) cout<<x<<" ";
		cout<<"\n";
	}
}