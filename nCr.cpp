#include <iostream>
using namespace std;
#define int long long
const int num = 1000000;
const int mod = 1000000007;
int fact[num];

void preCompute(){
	fact[0] = 1;
	for(int i=1;i<num;i++){
		fact[i] = fact[i-1]*i;
	}
}

int modPow(int base, int x, int mod){
	int ans = 1;
	while(x>0){
		if(x%2==0){
			base = (base*base)%mod;
			x = x>>1;
		}else{
			ans = (ans*base)%mod;
			x = x-1;
		}
	}
	return ans;		
}

int nCr(int n, int r){
	int num = 1, den = 1;
	num = fact[n];
	den = (fact[r]*fact[n-r])%mod;
	num = (num*modPow(den,mod-2,mod))%mod;
	return num;
}

signed main(){
	preCompute();
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		cout<<nCr(n-1, k-1)<<endl;
	}
	return 0;
}
