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

int findi(vector<int> &p,int low,int high){
   int l = low,r =high,piv=p[low];
   while(l < r){
      while(p[l] <= piv && l <= high-1){
         l++;
      }
      while(p[r] > piv && r >= low +1){
         r--;
      }
      if(l < r){
         swap(p[l],p[r]);
      }
   }
   swap(p[low],p[r]);
   return r;
}

void qs(vector<int> &p,int low,int high){
   if(low < high){
      int ind = findi(p,low,high);
      qs(p,low,ind-1);
      qs(p,ind+1,high);
   }
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int n;cin >> n;
   vector<int> p(n);
   for(int i = 0;i < n;i++){
      cin >> p[i];
   }
   qs(p,0,n-1);
   for(int i = 0;i < n;i++){
      cout << p[i] << " ";
   }
}
