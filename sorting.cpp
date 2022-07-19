#include "bits/stdc++.h"
#define ll long long
#define f(i,n) for(ll i=0;i<n;i++)
#define finm(n,m) for(ll i=0;i<n;i++) for(ll j=0;j<m;j++)
#define do(i,a,b) for(ll i=a;i<b;i++)
#define vi vector <int>
#define all(c) (c).begin(),(c).end()
#define pb push_back
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout<<#x<<"->"<<x<<endl;
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl

/*

Find a value in a *SORTED* sequence.
Still struggle with index

[lo, hi] --> 
[mid, hi]
[mid+1, hi]
[lo, mid]
[lo, mid-1]


*/

void print(vi v){
    for(auto in : v){
        cout<<in<<" ";
    }
    cout<<endl;
}

void merge(int lo, int mid , int hi, vector<int> &a){
    int L1 = lo;
    int R1 = mid;
    int L2 = mid+1;
    int R2 = hi;
    vector<int> v;
    while(L1<=R1 && L2<=R2){
        if(a[L1] <= a[L2]){
            // cout<<a[L1]<<" - "<<a[L2]<<endl;
            v.push_back(a[L1]);
            L1++;
        }
        else{
            v.push_back(a[L2]);
            L2++;
        }
    }
    while(L1<=R1){
        v.push_back(a[L1]);
        L1++;
    }
    while(L2<=R2){
        v.push_back(a[L2]);
        L2++;
    }
    for(int i = lo; i<=hi; i++){
        a[i] = v[i - lo];
    }
}

void merge_sort(int lo, int hi, vector<int> &a){

    if(lo<hi){

        int mid = lo + (hi - lo)/2;
        merge_sort(lo, mid, a);
        merge_sort(mid+1, hi, a);
        merge(lo, mid, hi, a);

    }

}


void topsort(){

}


void run(){

    vector<int> a = {6,7,8,3,2,1,2,4,5,9,10};
    print(a);
    cout<<"----"<<endl;
    merge_sort(0, a.size() - 1, a);
    print(a);

}

int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    
    for(int i=1;i<=t;i++){
        //        cout<<"Case #"<<i<<": ";
        
        run();
        
    }
      
}
