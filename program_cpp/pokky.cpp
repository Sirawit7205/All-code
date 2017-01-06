#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> place;
vector<int>::iterator  it,iu,il;

int main()
{
    int i,n,q,ta,tb;
    cin >> n >> q;
    for(i=0;i<n;i++)
    {
        cin >> ta;
        place.push_back(ta);
    }
    sort(place.begin(),place.end());
    for(i=0;i<q;i++)
    {
        cin >> ta >> tb;
        il=lower_bound(place.begin(),place.end(),ta);
        iu=upper_bound(place.begin(),place.end(),tb);
        cout << (((iu-place.begin())-1)-(il-place.begin()))+1 << endl;
    }
    return 0;
}
