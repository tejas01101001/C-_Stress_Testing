//https://codeforces.com/contest/1312/problem/C
//BROWNIE TK
 
#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define pb push_back
#define popb pop_back()
#define pf push_front
#define popf pop_front()
 
#define si size()
#define be begin()
#define en end()
#define all(v) v.be, v.en
 
#define le length()
#define mp make_pair
#define mt make_tuple
#define acc(v) accumulate(all(v), 0)
#define F first
#define S second
 
#define pll pair<lli, lli>
#define pii pair<int, int>
#define pil pair<int, lli>
 
#define forz(i, n) for (int i = 0; i < n; i++)
#define fore(i, m, n) for (int i = m; i <= n; i++)
#define rforz(i, n) for (int i = n - 1; i >= 0; i--)
#define rfore(i, m, n) for (int i = n; i >= m; i--)
 
#define deci(n) fixed << setprecision(n)
#define high(n) __builtin_popcount(n)
#define highll(n) __builtin_popcountll(n)
#define parity(n) __builtin_parity(n)
#define ctz(n) __builtin_ctz(n)
 
#define bset(a, p) ((a) | (1ll << (p)))
#define bchk(a, p) ((a) & (1ll << (p)))
#define bxor(a, p) ((a) ^ (1ll << (p)));
#define brem(a, p) (bchk(a, p) ? (bxor(a, p)) : (a))
/*SOME BITMASK KNOWLEDGE
1)x & (x - 1):sets the last one bit of x to zero
power of two exactly when x & (x − 1) = 0.
2)x & -x:sets all the one bits to zero, except last one bit
3)x | (x - 1):inverts all the bits after the last one bit*/
 
#define lb lower_bound
#define ub upper_bound
#define er equal_range
 
#define findnot find_first_not_of
 
#define maxe *max_element
#define mine *min_element
 
#define mod 1000000007
#define mod2 998244353
#define gcd __gcd
#define kira ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 
#define endl "\n"
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
 
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define osetlli tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements sbtriectly lesser than k
//2. find_by_order(k) : k-th element in the set
#define ofk order_of_key
#define fbo find_by_order
using namespace std;
 
/*STD funcions*/
lli power(lli x, lli y, lli p)
{
    lli res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
lli modi(lli a, lli m) { return power(a, m - 2, m); }
/*CODE BEGINS*/
const int N = 2e5 + 5;
vector<int> adj[N];
lli dis[N];
void dfs(int s, int e)
{
    for (auto u : adj[s])
    {
        if (u == e)
            continue;
        dis[u] = dis[s] + 1;
        dfs(u, s);
    }
}
pair<lli, lli> far(lli n)
{
    pair<lli, lli> p = {-1, -1};
    for (int i = 1; i <= n; i++)
    {
        if (p.F < dis[i])
        {
            p.F = dis[i];
            p.S = i;
        }
    }
    return p;
}
lli dist[N][2];
void bfs(lli s, lli index)
{
    queue<lli> q;
    vector<bool> vis(N, false);
    vis[s] = true;
    dist[s][index] = 0;
    q.push(s);
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        for (auto u : adj[s])
        {
            if (vis[u])
                continue;
            vis[u] = true;
            dist[u][index] = dist[s][index] + 1;
            q.push(u);
        }
    }
}
int main()
{
    kira;
    lli n, u, v;
    cin >> n;
    forz(i, n - 1)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, -1);
    pair<lli, lli> next = far(n);
    memset(dis, 0, sizeof(dis));
    dfs(next.S, -1);
    pll maxi={next.S,-1};
    next = far(n);
    maxi.S=next.S;
    bfs(maxi.F,0);
    bfs(maxi.S,1);
    for(int i=1;i<=n;i++)
    {
        cout<<max(dist[i][0],dist[i][1])<<" ";
    }
    return 0;
}