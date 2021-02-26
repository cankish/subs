//Squeezing

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
#define f(i,n) for(ll i=0;i<n;i++)
#define finm(n,m) for(ll i=0;i<n;i++) for(ll j=0;j<m;j++)
#define do(i,a,b) for(ll i=a;i<b;i++)
#define vi vector <int>
#define vii vector<vector<int>>
#define vll vector<long long>
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mod 1000000007
using namespace std;
#define peek(l,r) cout<<"--"<<l<<" "<<r<<"--"<<endl;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define deb(x) cout<<#x<<"->"<<x<<endl;
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl;
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl;
const int N=500023;
//bool vis[N];
vector <int> adj[N];
int count=0;

const int maxn=500;
int  grid[maxn][maxn];
int  vis[maxn][maxn];
string s;

int val(int l,int h,int c){
    int v=0;
    
    for(int i=l;i<=h;i++){
        
        v += !( (s[i] - 97) == c );
        
    }
    
    return v;
}
int pown(int a,int n){
    if(n==0)return 1;
    if(n==1)return a;
    
    int t = pown(a,n/2);
    return t*t*pown(a,n%2);
    
}

bool is_prime(int n){
    int ok=1;
    for(int i=2;i*i<=n;i++){
        
        if(n%i==0){
            ok=0;break;
        }
        
    }
    
    return ok;
}
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

bool is_powertwo(int x){
    
    return (x&&!(x&(x-1)));
}
int nc2(int n){
    if(!n)return n;
    return (n)*(n-1)/2;
}


//bool check(string s,int i){
//    string t="";
//    for(int j=0;j<7;j++){
//
//        if(p[j]!=s[i+j] && s[i+j]!='?'){
//            return false;
//        }
//        else{
//
//
//
//        }
//
//
//    }
//    return t;
//}
void solve(){
   
    int n,k;
    cin>>n>>k;
    
    vi a(n+1);
    a.pb(0);
    
    f(i,n)cin>>a[i+1];
    
    vi p;
    map<int,int> mp;
    vi mn,mx;
    
    for(int i=1;i<=n/2;i++){
        
        p.pb(a[i]+a[n-i+1]);
        mp[a[i]+a[n-i+1]]++;
        
        mn.pb(min(a[i],a[n-i+1]));
        mx.pb(max(a[i],a[n-i+1]));
        
    }
    int res=INT_MAX;
    
    sort(all(mn));
    sort(all(mx));
    
    for(int x = 2;x<=2*k;x++){
        
        int ans = 0;
        
        int z0 = mn.end() - upper_bound(all(mn),x-1);
        int z1 = lower_bound(all(mx), x-k) - mx.begin();
        
        ans+=z0;
        ans+=z1;
        ans+=n/2;
        ans-=mp[x];
        res=min(res,ans);
    }

    d1(res);
    
}


int32_t main()
{
    IOS;
    int t=1;
    cin>>t;
    
    for(int i=1;i<=t;i++){
        //        cout<<"Case #"<<i<<": ";
        
        solve();
        
        
    }
    
    
}



