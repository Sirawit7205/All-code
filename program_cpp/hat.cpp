#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct wtv {
    int w,v;

    wtv(int a, int b)
    {
        w=a;
        v=b;
    }

    bool operator < (const wtv &T) const
    {
        return w > T.w;
    }
};

int main()
{
    int i,n,m,ds,sd,w,v,d,x;
    cin >> n >> m;
    cin >> ds;
    if(ds==1)
    {
        cin >> sd;
        if(sd==1)
        {
            cin w >> v;
        }
        else if(sd==2)
        {
            cin w >> v >> d;
        }
        else
        {
            cin w >> v >> d >> x;
        }
    }
    else
    {

    }
}
