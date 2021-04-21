#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod= 1000000007;

int tk(int a[], int n,int x){
	int l = 0, r = n-1;
	while(l<=r){
		int mid = l + (r-l)/2;
		if(a[mid] == x) return mid+1;
		else if(a[mid] < x){
			l = mid +1;
		}
		else r = mid-1;
	}
	return -1;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		int a[n];
		for(int i = 0 ; i < n; i++) cin>> a[i];
		int h = tk(a,n,k);
		if(h != -1) cout << h << endl;
		else cout << "NO" << endl; 
	}
}