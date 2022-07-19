#include "bits/stdc++.h"
#define LL long long
#define vi vector <int>
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define peek(l, r) cerr<<"--"<<l<<" "<<r<<"--"<<endl;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout<<#x<<"->"<<x<<endl;
#define d0(x) cout<<(x)<<" ";
#define d1(x) cout<<(x)<<endl;
#define endl "\n"
using namespace std;
int mod = 1e9 + 7;

void print(vector<int> v){
  for(auto in : v){
    cout<<in<<" ";
  }
  cout<<endl;
}

int gcd(int a, int b){
    if(a == 0)return b;
    else return gcd(b%a, a);
}

void read(vector<int> &a){
    int n = a.size();
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}

template<class T>
class SparseTable{
    public:
    vector<vector<T>> m;
    vector<int> LOG;

    T Union(T a,T b){
        return min(a,b);
    }

    // SparseTable(){

    // }

    void build(vector<T> a)
    {   
        assert(!a.empty());

        int n = (int)a.size();
        LOG = vector<int>(n + (int)1);
        LOG[1] = 0;
        for(int i=2; i<=n; i++){
            LOG[i] = LOG[i>>1] + 1;
        }

        m = vector<vector<T>> (n, vector<T>(LOG.back() + 1));

        for (int i = 0; i < n; ++i){
            m[i][0] = a[i];
        }

        for(int k = 1; k <= LOG[n]; k++){
            for(int i = 0; i + (1<<k) - 1 < n;i++){
                m[i][k] = Union(  m[i][k - 1]  ,   m[i + (1<<(k - 1))][k - 1]  );
            }
        }
    }

    T query(int L, int R){
        int len = R - L + 1;
        int K = LOG[len];
        return Union( m[L][K], m[R - (1<<K) + 1][K] ); 
    }

};


void solve(){
    int n;cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    
    SparseTable<int> s;
    s.build(a);

    int q;cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<s.query(l,r)<<endl;
    }
}

int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
}
