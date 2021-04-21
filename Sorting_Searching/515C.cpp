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

int main(){
	//FileIO();
	int n;cin>>n;
	string s;cin>>s;
	string res="";
	for(int i=0;i<n;i++){
		int r=s[i];
		if(r=='2' || r=='3' || r=='5' || r=='7')
			res+=r;
		else if(r=='4'){
			res+="223";
		}
		else if(r=='6'){
			res+="35";
		}
		else if(r=='8'){
			res+="2227";
		}
		else if(r=='9')
			res+="3327";
	}
	sort(all(res),greater<char>());
	cout<<res;
}