#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back
#define P pair<int, int>


const int N = 100005, M=22;

vector<int> gr[N];
int tin[N],tout[N],timer;

// INPUT
// 1
// 9
// 1 2
// 2 4
// 2 5
// 2 6
// 1 3
// 3 7
// 7 8
// 7 9

void euler_tour_1(int curr,int par){
	// cout<<curr<<" "; //print when entering 
	for(auto x: gr[curr]){
		if(x!=par){
			euler_tour_1(x,curr);
			// cout<<curr<<" ";	//print when leaving if its branch exist
		}
	}
}
void euler_tour_2(int curr,int par){
	// cout<<curr<<" "; //print when entering 
	tin[curr]=timer++;
	for(auto x: gr[curr]){
		if(x!=par){
			euler_tour_2(x,curr);
		}
	}
	tout[curr]=timer++;
	// cout<<curr<<" ";	//print when leaving doesnt matter if it has branch or not 
}
void euler_tour_3(int curr,int par){
	// cout<<curr<<" "; //print when entering 
	tin[curr] = ++timer; //timer here will start from 0
	for(auto x: gr[curr]){
		if(x!=par){
			euler_tour_3(x,curr);
		}
	}
	tout[curr] = timer;
}

bool is_ancestor(int x,int y){
	return tin[x]<=tin[y] && tout[x]>=tout[y];
}

void solve(){
	int i,j,k,n,m,ans=0,cnt=0,sum=0;
	cin>>n;
	for(i=0;i<n-1;i++){
		int x,y;cin>>x>>y;
		gr[x].pb(y);
		gr[y].pb(x);
	}
	//timer=1;
	// euler_tour_1(1,0);
	// euler_tour_2(1,0);
	timer=0;
	euler_tour_3(1,0);
	for (i = 1; i <= n; ++i)
	{
		cout<<" "<<tin[i]<<" "<<tout[i]<<endl;
	}

	if(is_ancestor(1,7)){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	
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