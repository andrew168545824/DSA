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

void mul(ll a[2][2], ll b[2][2]){
	ll c[2][2];
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			c[i][j]=0;
			for(int k=0;k<2;k++){
				c[i][j] +=(a[i][k]*b[k][j])%MOD;
				c[i][j]%=MOD;
			}
		}
	}
	a[0][0]=c[0][0];
	a[1][0]=c[1][0];
	a[0][1]=c[0][1];
	a[1][1]=c[1][1];
}
#Binary exponentiation using recursion
void power(ll f[2][2],int n){
	if(n==0||n==1)
		return;
	ll tmp[2][2] = {{1,1},{1,0}};
	power(f, n/2);
	mul(f,f);
	if(n%2) mul(f,tmp);
}

#Binary exponentiation using while loop
void power2(ll a[2][2], int n){
	ll res[2][2]={{1,0}, {0, 1}};
	while(n){
		if(n%2==1){
			nhan(res,a);
		}
		nhan(a,a);
		n/=2;
	}
	cout<<res[0][1]<<endl;
}

int main(){
	//FileIO();
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		ll f[2][2]={{1,1},{1,0}};
		power(f,n);
		cout<<f[0][1]<<endl;
		//power2(a,n);
	}
}
