#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back
#define f(n) for(int i=0;i<n;i++)

const int N = 100005, M=22;
unordered_map<string,list<pair<string,int>>> gr;

void dijkstra(string src){
	unordered_map<string,int> dist;
	for(auto x :gr){
		dist[x.first]=INT_MAX;
	}
	set<pair<int,string>> s;
	dist[src]=0;
	s.insert(make_pair(0,src));
	while(!s.empty()){
		auto p=*s.begin();
		string node=p.second;
		s.erase(s.begin());
		for(auto neighbour:gr[node]){
			if(dist[neighbour.first]==INT_MAX){
				if(dist[neighbour.first]>dist[node]+neighbour.second){
					string des=neighbour.first;
					auto f=s.find(make_pair(dist[des],des));					
					if(f!=s.end()){
						s.erase(f);
					}
					dist[des]=dist[node]+neighbour.second;
					s.insert(make_pair(dist[des],des));
				}
			}
		}
	}
	for(auto d: dist){
		cout<<d.first<<" "<<d.second<<endl;
	}
}

void solve(){
	int i,j,k,n,m,ans=0,cnt=0,sum=0;
	cin>>m;
	for(int i=0;i<m;i++){
		string x,y;cin>>x>>y;
		int w;cin>>w;
		gr[x].pb(make_pair(y,w));
		gr[y].pb(make_pair(x,w));
	}
	string src;
	cin>>src;
	dijkstra(src);
	// for(auto x:gr){
	// 	cout<<x.first<<" ";
	// 	for(auto y : x.second){
	// 		cout<<y.first<<" "<<y.second<<" ";
	// 	}
	// 	cout<<endl;
	// }
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