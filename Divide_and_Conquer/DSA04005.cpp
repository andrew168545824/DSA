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

ll fibo[100];
void init(){
	fibo[0]=0;
	fibo[1]=1;
	for(int i=2;i<=93;i++){
		fibo[i]=fibo[i-1]+fibo[i-2];
	}
}

char xaufibo(int n, ll i){
	if(n==1) return 'A';
	if(n==2) return 'B';
	if(i<=fibo[n-2])
		return xaufibo(n-2, i);
	return xaufibo(n-1,i-fibo[n-2]);
}

int main(){
	//FileIO();
	int t;cin>>t;
	init();
	while(t--){
		int n;
		ll k;cin>>n>>k;
		cout<<xaufibo(n,k)<<endl;
	}
}
