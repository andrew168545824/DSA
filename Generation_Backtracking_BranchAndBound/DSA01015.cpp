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

vector<ll> res;
int ok;
ll a[501]={0};

void next(string &s){
	int i=s.length()-1;
	while(i>=0 && s[i]=='9'){
		s[i]='0';--i;
	}
	if(i==0){
		ok=false;
	}
	s[i]='9';
}


void init(){
	for(int i=1;i<=14;i++){
		ok=true;
		string s=string(i,'0');
		next(s);
		while(ok){
			res.pb(stoll(s));
			next(s);
		}
	}
	for(int i=1;i<=500;i++){
		if(!a[i]){
			for(ll x: res){
				if(x%i==0){
					a[i]=x;break;
				}
			}
		}
	}
}

int main(){
	init();
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		cout<<a[n]<<"\n";
	}
}
