#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<algorithm>

using namespace std;

struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };

map<double,int> m;
 
bool compare(Point a, Point b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
 
int maxPoints(vector<Point> &points) {
    
    sort(points.begin(),points.end(),compare);
    
	for(vector<Point>::iteator it=m.begin();it!=m.end;it++)
	{
		for(vector<Point>::iteator it1=it+1;it1!=m.end;it1++)
		{
			int val=m.y
			
		}		
	}
}
    
int main()
{
	
}
