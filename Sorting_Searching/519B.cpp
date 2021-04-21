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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;cin>>n;
	int a[n],b[n-1],c[n-2];
	map<int,int> m,m3;
	FOR(i,0,n){
		cin>>a[i];
		m[a[i]]++;
	}
	map<int,int> m2;
	FOR(i,0,n-1){
		cin>>b[i];
		m2[b[i]]++;
	}
	FOR(i,0,n){
		if(m[a[i]]!=m2[a[i]]){
			cout<<a[i]<<"\n";break;
		}
	}
	FOR(i,0,n-2){
		cin>>c[i];
		m3[c[i]]++;
	}
	FOR(i,0,n-1){
		if(m2[b[i]]!=m3[b[i]]){
			cout<<b[i]<<"\n";break;
		}
	}
}
