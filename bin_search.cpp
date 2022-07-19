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

int pbin(vector<int> array, int x){
    int k = 0;
    int n = array.size();
    for (int b = n/2; b >= 1; b /= 2) {
        while (k+b < n && array[k+b] <= x) k += b;
    }

    if (array[k] == x) {
        cout<<"Found at: "<<k<<" -- "<<array[k]<<endl;
    }
    return k;
}


/*-------------------------------------------------*/


int _lower_bound(vector<int> v, int val, int lo, int hi){
    while(lo<hi){
        int mid = lo + (hi - lo)/2;

        if(v[mid] < val){
            lo = mid + 1;
        }
        else{
            hi = mid; 
        }

    }

    if(lo < v.size() && v[lo] < val){cout<<"none"<<endl;lo++;}
    return lo;

}



/*-------------------------------------------------*/

int _lowerBound(vector<int> v, int X, int low, int high){
    int mid;
    while (low < high) {
        mid = low + (high - low) / 2;

        if (X <= v[mid]) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
   
    // if X is greater than arr[n-1]
    if(low < v.size() && v[low] < X) {
       cout<<"none"<<endl;
       low++;
    }

    return low;
}


/*-------------------------------------------------*/


int _upper_bound(vector<int> v, int val, int lo, int hi){
    while(lo<hi){
        int mid = lo + (hi - lo)/2;

        if(v[mid] > val){
            hi = mid;
        }
        else{
            lo = mid + 1; 
        }

    }

    if(lo < v.size() && v[lo] <= val){cout<<"none"<<endl;lo++;}

    return lo;

}


/*-------------------------------------------------*/
int _upperBound(vector<int> v, int val, int lo, int hi){
    while(lo<hi){
        int mid = lo + (hi - lo)/2;

        if(v[mid] <= val){
            lo = mid + 1;
        }
        else{
            hi = mid; 
        }

    }

    if(lo < v.size() && v[lo] <= val){cout<<"none"<<endl;lo++;}

    return lo;

}


/*-------------------------------------------------*/


int bin_search(vector<int> v, int val, int lo, int hi){

    if(lo <= hi ){

        int mid = lo + (hi-lo)/2;
        if( v[mid] == val ){
            return mid;
        }
        if( v[mid] <= val ){
            return bin_search(v, val, mid + 1, hi);
        }
        else{
            return bin_search(v, val, lo, mid - 1);
        }

    }

    return -1;

}


/*-------------------------------------------------*/


int binSearch(vector<int> v, int val, int lo, int hi){

    while(lo <= hi){
        int mid = lo  + (hi - lo)/2;
        if(v[mid] == val){
            cout<<mid+1<<"--->"<<v[mid]<<endl;
            return mid;
        }
        if(v[mid] > val){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }

    }

    cout<<"error"<<endl;
    return -1;

}


/*------Last occurance of value equal to val.------*/


int binsearch(vector<int> a, int lo, int hi, int val)
{
    while(lo<hi)
    {
        int mid=(lo+hi+1)>>1;
        if( a[mid - 1] == val)
            lo=mid;
        else
            hi=mid-1;
    }
    return lo;
}

/*-------------------------------------------------*/


// int 2D_binSearch(vector<int> v, int val, int lo, int hi){  
//     while(lo <= hi){
//         int mid = lo  + (hi - lo)/2;
//         if(v[mid] == val){
//             cout<<mid+1<<"--->"<<v[mid]<<endl;
//             return mid;
//         }
//         if(v[mid] > val){
//             hi = mid - 1;
//         }
//         else{
//             lo = mid + 1;
//         }
//     }
//     cout<<"error"<<endl;
//     return -1;
// }



void run(){

    vector<int> v = {1,2,3,4,5,6,7,7,7,7,8,9,10};
    int val = 6;

    int a = binSearch(v, val, 0 , v.size() - 1);
    cout<<a<<"-"<<endl;
    if( a == -1 ){
        cout<<"ERROR"<<endl;
    }

    int t = pbin(v, val);
    cout<<"-->"<<t<<endl;


    // cout<<*binsearch(v.begin(), v.end(), val);
    // else{
    //     cout<<a+1<<"-->"<<v[a]<<endl;
    // }

    // sort(all(v));
    // int t = binsearch(0, v.size() - 1, val, v);


    // cout<<t+1<<"-->"<<v[t]<<endl;

    // val = 10;
    // cout<<"---lower----"<<endl;
    // cout<<lower_bound(all(v), val) - v.begin()<<endl;
    // cout<<_lower_bound(v, val, 0, v.size() - 1 )<<endl;
    // cout<<_lowerBound(v, val, 0, v.size() - 1 )<<endl;

    // cout<<"---upper----"<<endl;
    // cout<<upper_bound(all(v), val) - v.begin()<<endl;
    // cout<<_upper_bound(v, val, 0, v.size() - 1 )<<endl;
    // cout<<_upperBound(v, val, 0, v.size() - 1 )<<endl;


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
