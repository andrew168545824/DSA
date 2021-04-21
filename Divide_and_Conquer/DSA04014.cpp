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

int n;
vector<ll> a;

void inp(){
	cin>>n;
	a.resize(n);
	FOR(i,0,n) cin>>a[i];
}

ll merge(int l, int m, int r){
	ll tmp[r+1];
	ll i=l,j=m,k=l,cnt=0;
	while(i<=m-1 && j<=r){
		if(a[i]<=a[j]){
			tmp[k++]=a[i++];
		}
		else{
			tmp[k++]=a[j++];
			cnt += m-i;
		}
	}
	while(i<=m-1) tmp[k++]=a[i++];
	while(j<=r) tmp[k++]=a[j++];
	for(int j=l;j<=r;j++){
		a[j]=tmp[j];
	}
	return cnt;
}



ll mergeSort(int l, int r){
	ll cnt = 0;
	if(l<r){
		int m = (l+r)/2;
		cnt += mergeSort(l,m);
		cnt += mergeSort(m+1,r);
		cnt += merge(l,m+1,r);
	}
	return cnt;
}


int main(){
	//FileIO();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		inp();
		cout<<mergeSort(0,n-1)<<endl;
	}
}
