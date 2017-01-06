#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> d;
vector<int>::iterator it,iu,il;

int main()
{
    int i,n,q,t;
    cin >> n >> q;
    for(i=0;i<n;i++)
    {
        cin >> t;
        d.push_back(t);
    }
    sort(d.begin(),d.end());
    for(i=0;i<q;i++)
    {
        cin >> t;
     //   iu=upper_bound(d.begin(),d.end(),t+1);
        il=lower_bound(d.begin(),d.end(),t);
     //   if(d[(iu-d.begin())-1]!=t||iu-d.begin()==0) cout << iu-d.begin() << endl;
        cout << il-d.begin() << endl;
    }
    //for(it=d.begin();it!=d.end();++it) cout << *it << ' ' << endl;
    return 0;
}
