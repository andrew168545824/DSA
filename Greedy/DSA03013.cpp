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

bool cmp(pair<int,char> a, pair<int,char> b){
	return a.fi>b.fi;
}

bool check(string s,int d){
	int n=s.length();
	int a[256]={0};
	FOR(i,0,n){
		a[s[i]]++;
	}
	vi v;
	FOR(i,0,256){
		if(a[i]){
			v.pb(a[i]);
		}
	}
	sort(all(v),greater<int>());
	for(int i=0;i<sz(v);i++){
		int fre=v[i];
		for(int k=0;k<fre;k++){
			if(i+k*d>=n) return false;
		}
	}
	return true;
}

int main(){
	//FileIO();
	int t;cin>>t;
	while(t--){
		int d;
		string s;cin>>d>>s;
		if(check(s,d)) cout<<"1\n";
		else cout<<"-1\n";
	}
}
