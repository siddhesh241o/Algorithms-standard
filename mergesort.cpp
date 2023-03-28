#include <bits/stdc++.h>
typedef long long ll;
#define nline "\n"
#define vi vector<ll>
#define pii pair<ll,ll>
#define vpii vector<pii>
#define ff first
#define ss second
#define pb push_back
#define input(var, type) type var; cin >> var
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define sortv(a) sort(all(a))
#define rsortv(a) sort(rall(a))
#define yes cout<<"YES\n"
#define yess cout<<"Yes\n"
#define no cout<<"NO\n"
#define noo cout<<"No\n"
int MOD = 1e9 + 7;
using namespace std;

void merge(vector<int> &p,int low,int mid,int high){
   vector<int> q;
   int l = low,r = mid+1;
   while(l <= mid && r <= high){
      if(p[l] > p[r]){
         q.pb(p[r]);
         r++;
      }else{
         q.pb(p[l]);
         l++;
      }
   }
   while(l <= mid){
      q.pb(p[l]);
      l++;
   }
   while(r <= high){
      q.pb(p[r]);
      r++;
   }
   for(int i = low;i <= high;i++){
      p[i] = q[i-low];
   }
}

void mergesort(vector<int> &p,int low,int high){
   if(low == high) return;
   int mid = (low+high)/2;
   mergesort(p,low,mid);
   mergesort(p,mid+1,high);
   merge(p,low,mid,high);
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int n;cin >> n;
   vector<int> p(n);
   for(int i = 0;i < n;i++){
      cin >> p[i];
   }
   mergesort(p,0,n-1);
   for(int i = 0;i < n;i++){
      cout << p[i] << " ";
   }
}
