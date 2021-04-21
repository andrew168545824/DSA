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

void chuanHoa(string &a, string &b){
	int n1= a.length(), n2=b.length();
	if(n1<n2){
		for(int i=n1;i<n2;i++)
			a='0'+a;
	}
	else{
		for(int i=n2;i<n1;i++){
			b ='0'+b;
		}
	}
}

string add(string a, string b){
	chuanHoa(a,b);
	string res;
	int carry=0;
	for(int i=a.length()-1;i>=0;i--){
		int tmp = a[i]-'0'+b[i]-'0'+carry;
		res = (char)(tmp%2+'0')+res;
		carry = tmp/2;
	}
	if(carry)
		res ='1'+res;
	return res;
}

int mulbit(string a,string b){
	return (a[0]-'0')*(b[0]-'0');
}

ll mul(string a, string b){
	chuanHoa(a,b);
	int n = a.length();
	if(n==0) return 0;
	if(n==1)
		return mulbit(a,b);
	int fi = n/2;
	int la = n-fi;
	string xl = a.substr(0,fi);
	string xr = a.substr(fi,la);
	string yl = b.substr(0,fi);
	string yr = b.substr(fi,la);

	ll tmp1 = mul(xl,yl);
	ll tmp2 = mul(xr,yr);
	ll tmp3 = mul(add(xl, xr),add(yl,yr));
	return tmp1*(ll)pow(2,la*2) +(tmp3-tmp1-tmp2)*(ll)pow(2,la) +tmp2;
}
int main(){
	//FileIO();
	int t;cin>>t;
	while(t--){
		string a,b;cin>>a>>b;
		cout<<mul(a,b)<<endl;
	}
}
