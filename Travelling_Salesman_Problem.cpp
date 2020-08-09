#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back
#define P pair<int, int>

const int N = 100005, M=22;

int n=4;
int dist[10][10]={{0,20,42,25},{20,0,30,34},{42,30,0,10},{25,34,10,0}};
int dp[16][10];
int VISITED_ALL = (1<<n)-1;

int tsp(int mask,int pos){

	if(mask==VISITED_ALL){
		return dist[pos][0];
	}
	if(dp[mask][pos]!=-1){
		return dp[mask][pos];
	}
	int ans =INT_MAX;
	for(int i=0;i<4;i++){ //i here is city 
		if(!(mask&1<<i)){
			ans = min(ans,tsp(mask+(1<<i),i)+dist[pos][i]); 
		}
	}
	return dp[mask][pos]=ans;
}

void solve(){
	int i,j,k,n,m,ans=0,cnt=0,sum=0;
	memset(dp,-1,sizeof(dp));
	cout<<tsp(1,0);
	
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