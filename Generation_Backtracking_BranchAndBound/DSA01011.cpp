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

bool ok=false;

void next(string &s){
	int i=s.length()-2;
	while(i>=0 && s[i]>=s[i+1]){
		--i;
	}
	if(i==-1){
		ok=true;//biggest
	}
	else{
		int j=s.length();
		while(s[i]>=s[j]){
			--j;
		}
		swap(s[i],s[j]);
		sort(s.begin()+i+1,s.end());
	}
}
int main(){
	int t;cin>>t;
	while(t--){
		int tc;string s;
		cin>>tc>>s;
		ok=false;
		next(s);
		if(ok){
			cout<<tc<<" BIGGEST\n";
		}
		else cout<<tc<<" "<<s<<endl;
	}
}
