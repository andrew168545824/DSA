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

int find(int a[],int l, int m,int r){
	int sum1= -1e9, sum2=-1e9,sum=0;
	for(int i=m;i>=l;i--){
		sum+=a[i];
		sum1 = max(sum, sum1);
	}
	sum = 0;
	for(int i=m+1;i<=r;i++){
		sum+=a[i];
		sum2 = max(sum, sum2);
	}
	return sum1+sum2;
}

int maxsub(int a[],int l, int r){
	if(l==r)
		return a[l];
	int m = (l+r)/2;
	int trai = maxsub(a, l, m);
	int phai = maxsub(a, m+1, r);
	int cross = find(a, l, m, r);
	return max(max(trai, phai),cross);
}


int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n];
		FOR(i,0,n) cin>>a[i];
		cout<<maxsub(a,0,n-1)<<endl;
	}
}
