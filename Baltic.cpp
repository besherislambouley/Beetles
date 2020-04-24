/*
 * for every k from 1 to n , try to drink k water drops with the minmum number of moves 
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ld pai=acos(-1);
int n , m ;
int a[100009] ;
int dp[309][309][2] ;
int dis ( int a , int b ) {
	return abs ( a - b ) ;
}
int bt ( int l , int r , int here , int goal ) {
	if ( !goal ) return 0 ;
	int &ret = dp[l][r][here] ;
	if ( ret != -1 ) return ret ;
	ret = 1e9 ;
	int pos = ( !here ? a[l] : a[r] ) ;
	if ( l > 0 ) ret = min ( ret , bt ( l-1 , r , 0 , goal-1 ) + dis ( pos , a[l-1] ) * goal ) ;
	if ( r <n-1) ret = min ( ret , bt ( l , r+1 , 1 , goal-1 ) + dis ( pos , a[r+1] ) * goal ) ; 
	return ret ;
}
int main () {
	cin >> n >> m ;
	for ( int i = 0 ; i < n ; i ++ ) cin >> a[i] ; 
	a[n++] = 0 ;
	sort ( a , a+n );
	int here ;
	for ( int i = 0 ; i < n ; i ++ ) {
		if ( !a[i] ) here = i ;
	}
	int ans = 0 ;
	for ( int i = 1 ; i < n ; i ++ ) {
		mem ( dp , -1 ) ;
		ans = max ( ans , m * i - bt ( here , here , 0 , i ) ) ;
	}
	cout << ans << endl ;
}
