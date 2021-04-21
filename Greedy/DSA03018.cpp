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

void solve(){
	int n;cin>>n;
	int ans=-1;
	for(int i=n/7;i>=0;--i){
		int j=n-7*i;
		if(j%4==0){
			FOR(k,0,j/4){
				cout<<"4";
			}
			FOR(k,0,i){
				cout<<"7";
			}
			cout<<"\n";
			return;
		}
	}
	cout<<"-1\n";
}
int main(){
	//FileIO();
	int t;cin>>t;
	while(t--){
		solve();
	}
}
