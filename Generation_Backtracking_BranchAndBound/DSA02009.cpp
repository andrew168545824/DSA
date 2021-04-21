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

int n,k,a[100],sum,ok;
bool used[100];

void ql(int cntSub,int acc){
	//cout<<cntSub<<" "<<acc<<endl;
	if(cntSub==k){
		ok=1;return;
	}
	if(ok) return;
	FOR(i,1,n+1){
		if(!used[i]){
			// FOR(i,1,n+1) cout<<used[i]<<" ";
			// cout<<"\n";
			used[i]=true;
			if(acc==sum){
				ql(cntSub+1,0);
			}
			else if(acc<sum){
				ql(cntSub,acc+a[i]);
			}
		}
		used[i]=false;
	}
}


void inp(){
	cin>>n>>k;
	sum=ok=0;
	ms(used,false);
	FOR(i,1,n+1){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum%k!=0){
		cout<<"0\n";
		return;
	}
	sum/=k;
	ql(0,0);
	cout<<(ok ? "1\n" : "0\n");
}


int main(){
	//FileIO();
	int t;cin>>t;
	while(t--){
		inp();
	}
}
