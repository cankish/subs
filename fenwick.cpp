#include "bits/stdc++.h"
#define ll long long
#define f(i,n) for(ll i=0;i<n;i++)
#define finm(n,m) for(ll i=0;i<n;i++) for(ll j=0;j<m;j++)
#define do(i,a,b) for(ll i=a;i<b;i++)
#define vi vector <int>
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mod 1000000007
using namespace std;
#define peek(l,r) cout<<"--"<<l<<" "<<r<<"--"<<endl;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout<<#x<<"->"<<x<<endl;
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl;
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl;
const int N=500023;

vector <int> adj[N];

template <typename T>
class fenwick {
    // copied from tourist's submissions
    
 public:
  vector<T> fenw;
  int n;
 
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
 
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
 
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};


template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
  }
  void add(int i, T x){
    i++;
    while (i <= N){
      BIT[i] += x;
      i += i & -i;
    }
  }
  T sum(int i){
    T ans = 0;
    while (i > 0){
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
  T sum(int L, int R){
    return sum(R) - sum(L);
  }
};


struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
 
struct Fenwick{
 
    ll n;
    vector<ll> bit;
 
    ll op(ll a, ll b) {
        return a + b;
    }
 
    Fenwick(int _n) {
        n = _n + 2;
        bit.resize(n, 0);
    }
 
    void update(int c, ll v) {
        c++;
        while (c <= n) {
            bit[c] = op(bit[c], v);
            c += (c & (-c));
        }
    }
 
    ll query(int c) {
        ll res = 0;
        c++;
        while (c > 0) {
            res = op(bit[c], res);
            c -= (c & (-c));
        }
        return res;
    }
    
};



void solve(){

    int n;cin>>n;
    vi a(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }

    // FenwickTree BIT(n + 1);
    
    // int sum = 0;

    // for(int i=1;i<=n;i++){
    //     sum += BIT.sum(i, n);
    //     BIT.add(a[i], 1);
    // }

    // cout<<sum<<endl;

    binary_indexed_tree<int> BIT(n);

    long long ans = 0;
    for (int j = 0; j < n; j++){
      ans += BIT.sum(a[j], n);
      BIT.add(a[j], 1);
    }
    cout<<ans<<endl;

}

int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    cin>>t;
    
    for(int i=1;i<=t;i++){
        //        cout<<"Case #"<<i<<": ";
        
        solve();
        
        
    }
    
    
}
