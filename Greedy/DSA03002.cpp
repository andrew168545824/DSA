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
void tc(){
	string a,b;cin>>a>>b;
	string x=a,y=b;
	for(int i=0;i<a.length();i++){
		if(a[i]=='6') a[i]='5';
		if(x[i]=='5') x[i]='6';
	}
	for(int i=0;i<b.length();i++){
		if(b[i]=='6') b[i]='5';
		if(y[i]=='5') y[i]='6';
	}
	cout<<stol(a)+stol(b)<<" "<<stol(x)+stol(y)<<"\n";

}

int main(){
	int t;t=1;
	while(t--){
		tc();
	}
}

