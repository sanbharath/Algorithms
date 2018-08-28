#include<bits/stdc++.h>
using namespace std;
long long p;
int s;
int main() {
 
	cin>>p>>s;
	vector< pair<long long,long long> > res;
	for(long long i=0;i<p;i++)
	{      vector<pair<long long,long long>> vp;
	    long long counts=0; 
	    long long x[s+1]={};
	    long long y[s+1]={};
	    for(long long j=0;j<s;j++)
	    {
	        cin>>x[j];
	    }
	    for(long long k=0;k<s;k++)
	    {
	        cin>>y[k];
	    }
	    long long a[s+1]={};
	    for(long long c=0;c<s;c++)
	        vp.push_back(make_pair(x[c],y[c]));
	    sort(vp.begin(),vp.end());
	    long long l=0;
	    for(vector<pair<long long,long long>>::const_iterator it = vp.begin() ; it!= vp.end(); it++)
	    {
	        a[l++]=it->second;
	        //cout<<it->first<<"   "<<it->second<<endl;
	    }
	    for(long long m=0;m<s-1;m++)
	    {
	        if(a[m]>a[m+1])
	        {
	            counts++;
	        }
	    }
	    //cout<<counts<<endl;
	    res.push_back(make_pair(counts,i));
	}
	sort(res.begin(),res.end());
	for(vector<pair<long long,long long>>::const_iterator it = res.begin() ; it!= res.end(); it++)
	{
	     cout<<(it->second)+1<<endl;
	}
	return 0;
}
