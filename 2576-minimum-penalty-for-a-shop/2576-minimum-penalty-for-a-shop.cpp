typedef long long ll;
#define vvi vector<vector<int>>
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)
#define all(x)  x.begin(),x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll lcm( ll x, ll y) { return (x*y)/gcd(x,y);}

class Solution {
public:
    int bestClosingTime(string c) {
        c += 'Y';
        int n = c.length();
        int ans=n,mini=n;
        vi suf(n), pre(n);
        int y=0,no=0;
        repr(i,n-1,0){
            if(c[i]=='Y') y++;
            suf[i] = y;
        }
        rep(i,0,n){
            if(c[i] == 'N') no++;
            pre[i] = no;
            
        }
        rep(i,0,n){
            // cout << i << " -> " << ((i>1 ? pre[i-1] : 0)+suf[i]) << endl;
            if( ((i>1 ? pre[i-1] : 0)+suf[i]) == 0){
                return i;
            }
            if(((i>1 ? pre[i-1] : 0)+suf[i]) < mini){
                ans = i;
                mini = ((i>1 ? pre[i-1] : 0)+suf[i]);
            }
        }
        // if(ans==n-1 && c[n-1] == 'Y') ans++;
        return ans;
    }
};