#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define repx(i,x,n) for(int i=x; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9
 
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }



int isInside(double ax, double ay, double bx, double by, double cx, double cy, double tx, double ty)
{
	double abXat, bcXbt, caXct;

	abXat = (bx-ax)*(ty-ay) - (by-ay)*(tx-ax);
	bcXbt = (cx-bx)*(ty-by) - (cy-by)*(tx-bx);
	caXct = (ax-cx)*(ty-cy) - (ay-cy)*(tx-cx);
 
	if(( abXat > 0.0 && bcXbt > 0.0 && caXct > 0.0) || ( abXat < 0.0 && bcXbt < 0.0 && caXct < 0.0))
	{
		return 1;
	}
	else if(abXat*bcXbt*caXct == 0.0)
	{
		return 0;
	}

	return 0;

}

int isConcave(double px[], double py[])
{
	int i;
	for(i=0; i<4; i++)
	{
		if(isInside(px[i%4], py[i%4], px[(i+1)%4], py[(i+1)%4], px[(i+2)%4], py[(i+2)%4], px[(i+3)%4], py[(i+3)%4]))
		{
			return 1;
		}
	}

	return 0;
}

int main()
{

	double px[4], py[4];
	int i;
	for(i=0; i<4; i++)
	{
		scanf("%lf", &px[i]);
		scanf("%lf", &py[i]);
	}

	if(isConcave(px,py))
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
	}
}