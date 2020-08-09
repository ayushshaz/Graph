#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back
#define P pair<int, int>

const int N = 100005, M=22;

struct sparse_table{ 
   vector<vector<int>> mat;
   int n,m;
   vector<int> p2; //log2() function will give TLE

   void init(int _n,int _m){
   		n=_n,m=_m;
   		mat.resize(n);
   		for(int i=0;i<n;i++) mat[i].resize(m);
   		for(int i=2;i<=n;i++) p2[i] = p2[i/2]+1; //will have the (int)log value
   }

	void build(int a[]){
		for(int i=0;i<n;i++) mat[i][0]=a[i];
		for( int j=1;j<m;j++){
			for(int i=0; i+(1<<j)<=n;i++){ 
				mat[i][j] = min(mat[i][j-1],mat[i+(1<<(j-1))][j-1]);
			}
		}
	}

	int query(int l,int r){
		int pw = p2[r-l];
		return min(mat[l][pw],mat[r-(1<<pw)+1][pw]);
	}

};

void solve(){
	int i,j,k,n,m,ans=0,cnt=0,sum=0;
	int a[]={2,3,4,12,23,2,6,7,3,4,5,8,9,12,21,23,9};
    sparse_table p;
    p.init(23,10);
    p.build(a);
    p.query(1,10);
	
}

void init(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif	
}
	
int32_t main(){
	init();
	int t;cin>>t;while(t--){
		solve();
	}
	return 0;
}