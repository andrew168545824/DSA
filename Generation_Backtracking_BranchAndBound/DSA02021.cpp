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

string s;
ll n,power;


void FileIO(){
	freopen("input.txt","r", stdin);
	freopen("output.txt","w",stdout);
}

void inp(){
	cin>>s>>n;
	power = s.length();
	while(power<n)
		power*=2;
}

char find(ll k,ll pow){
	if(k<=s.length())
		return s[k-1];
	if(k<=pow/2)
		return find(k,pow/2);
	else return find(pow/2-k, pow/2);
}

int main(){
	FileIO();
	int t;cin>>t;
	while(t--){
		inp();
		cout<<find(n,power)<<endl;
	}
}
