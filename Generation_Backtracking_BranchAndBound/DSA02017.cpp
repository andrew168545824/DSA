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

int cot[100],xuoi[100],nguoc[100],a[100][100],n,ans=0,x[100];

void inp(){
	n=8;
	FOR(i,1,n+1){
		FOR(j,1,n+1) cin>>a[i][j];
	}
	ms(cot,1);
	ms(xuoi,1);
	ms(nguoc,1);ans=0;
}

void ql(int i){
	for(int j=1;j<=8;j++){
		if(cot[j] && xuoi[i+n-j] && nguoc[i+j-1]){
			x[i]=j;// con hau o hang i nam o cot j
			cot[j]=xuoi[i-j+n]=nguoc[i+j-1]=0;
			if(i==8){
				int sum=0;
				for(int k=1;k<=8;k++){
					sum+=a[k][x[k]];
				}
				ans=max(ans,sum);
			}
			else ql(i+1);
			cot[j]=xuoi[i-j+n]=nguoc[i+j-1]=1;
		}
	}
}


int main(){
	int t;cin>>t;
	while(t--){
		inp();
		ql(1);
		cout<<ans<<"\n";
	}
}
