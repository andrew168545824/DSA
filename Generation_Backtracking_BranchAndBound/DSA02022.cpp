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

int n,c[100][100],cmin=1e9,fopt=1e9,res=0,a[100];

bool used[100];
void inp(){
	cin>>n;
	FOR(i,1,n+1){
		FOR(j,1,n+1){
			cin>>c[i][j];
			if(c[i][j]!=0)
				cmin=min(cmin,c[i][j]);
		}
	}
	ms(used,false);
}

void branchAndBound(int i){
	for(int j=2;j<=n;j++){
		if(!used[j]){
			used[j]=true;
			a[i]=j;
			res+=c[a[i-1]][a[i]];
			if(i==n){
				fopt=min(fopt, res+c[a[n]][1]);
			}
			else if(res+ cmin*(n-i+1) <fopt){
				branchAndBound(i+1);
			}
			used[j]=false;
			res-=c[a[i-1]][a[i]];
		}
	}
}


int main(){
	inp();
	a[1]=1;
	branchAndBound(2);
	cout<<fopt<<"\n";
}
