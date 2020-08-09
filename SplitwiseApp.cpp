#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back
#define f(n) for(int i=0;i<n;i++)

const int N = 100005, M=22;

void solve(){
	int i,j,k,n,m,ans=0,cnt=0,sum=0;
	
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
    int numberOfTrans;cin>>numberOfTrans;
    unordered_map<string,int> trans;
    string debit,credit; int money;
    while(numberOfTrans--){
        cin>>debit>>credit>>money;
        trans[credit]+=money;
        trans[debit]-=money;
    }
    multiset<pair<int,string>> net;
    for(auto x: trans){
        net.insert(make_pair(x.second,x.first));
    }
    while(!net.empty()){
        pair<int,string> start=*net.begin();
        pair<int,string> last=*prev(net.end());
        int absolute=min(-(start.first),last.first);
        net.erase(start);
        net.erase(last);
        start.first=start.first+absolute;
        last.first=last.first-absolute;
        cout<<start.second<<" have to pay "<<last.second<<" amount "<<absolute<<endl;
        if(start.first!=0){
            net.insert(start);
        }
        if(last.first!=0){
            net.insert(last);
        }
    }
	return 0;
}