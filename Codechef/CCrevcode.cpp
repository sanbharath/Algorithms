//BY:BHARATH S
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double dbl;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<long long> vl;
typedef vector< pair<int, int> > vii;
#define mp make_pair
#define pb push_back
#define fr(i,j,k) for(ll i = j; i < k; i++)
#define FR(i,j,k) for(ll i = j; i >= 0; i--)
#define MOD 1000000007
#define all(v) v.begin(), v.end()
#define xx first
#define yy second
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
#include<bits/stdc++.h>
using namespace std;
long long t;
int n;
vector<string> v;
void fun(string a)
{   
    static int k=2;
    if(k==22)
    {
        return;
    }
    else
    {   string t="";
        for(int i=0;i<a.size();i++)
        {   
            long long cnt=1;
            while(a[i]==a[i+1])
            {
                cnt++;
                i++;
            }
            t=t+to_string(cnt);
            t=t+a[i];
        }
        string aa=t;
        v.push_back(t);
        k++;
        fun(aa);
    }
}
int main()
{   
    string a="19";
    v.push_back(a);
    fun(a);
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<v[n-1]<<endl;
    }
}