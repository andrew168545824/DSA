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

string a,b;
int k;

bool cmp(string a, string b){
	int n1 = a.length(), n2 = b.length();
	if(n1>n2)
		return true;
	else if(n1==n2)
		return a>b;
	else return false;
}


void solve(){
	if(cmp(b, a)){
		swap(a,b);
	}
	reverse(all(a));
	reverse(all(b));
	int c = 0;
	string res="";
	for(int i=0;i<b.length();i++){
		int tmp = a[i]+b[i]-2*'0'+c;
		res += (char)(tmp%k+'0');
		c = tmp/k;
	}
	for(int i=b.length();i<a.length();i++){
		int tmp = a[i]+c-'0';
		res += (char)(tmp%k+'0');
		c = tmp/k;
	}
	if(c)
		res+=(char)(c+'0');
	reverse(all(res));
	cout<<res<<"\n";
}
int main(){
	//FileIO();
	int t;cin>>t;
	while(t--){
		cin>>k>>a>>b;
		solve();
	}
}
