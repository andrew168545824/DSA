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

vector<vi> hv,ch;
int a[10],b[10],ok;
bool used[10];
void next(){
	int i=4;
	while(i>=1 && a[i]==3){
		i-=1;
	}
	if(i==0){
		ok=false;
	}
	else{
		a[i]+=1;
		FOR(j,i+1,5) a[j]=1;
	}
}

void init(){
	for(int i=1;i<=4;i++) a[i]=1;
	ok = 1;
	while(ok){
		vi x(a+1,a+5);
		ch.pb(x);
		next();
	}
}

void ql(int i){
	for(int j=1;j<=5;j++){
		if(!used[j]){
			b[i]=j;
			used[j]=true;
			if(i==5){
				vi x(b+1,b+6);
				hv.pb(x);
			}
			else ql(i+1);
			used[j]=false;
		}
	}
}


int main(){
	//FileIO();
	init();
	ql(1);
	int t;cin>>t;
	while(t--){
		int num[6];
		FOR(i,1,6){
			cin>>num[i];
		}
		bool ok = false;
		for(int i=0;i<hv.size();i++){
			//duyet tung hoan vi chu so
			for(int j=0;j<ch.size();j++){
				int sum = num[hv[i][0]];
				for(int k=0;k<4;k++){
					if(ch[j][k]==1)
						sum+=num[hv[i][k+1]];
					else if(ch[j][k]==2){
						sum*=num[hv[i][k+1]];
					}
					else sum-=num[hv[i][k+1]];
				}
				if(sum==23){
					ok=true;
					goto nhan;
				}
			}
		}
		nhan:
		cout<<(ok ? "YES\n" : "NO\n");
	}
}