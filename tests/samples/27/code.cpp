//light oj 1130 - Intersection between Circle and Rectangle 
 
#pragma comment(linker, "/STACK:102400000,102400000")  
#include <stdio.h>  
#include <iostream>  
#include <algorithm>  
#include <sstream>  
#include <stdlib.h>  
#include <string.h>  
#include <limits.h>  
#include <string>  
#include <time.h>  
#include <math.h>  
#include <queue>  
#include <stack>  
#include <set>  
#include <map>  
using namespace std;  
#define INF 0x3f3f3f3f  
#define eps 1e-17  
#define pi acos(-1.0)  
typedef long long ll;  
int dcmp(double x){  
    if(fabs(x)<eps)return 0;  
    return x>0?1:-1;  
}  
struct Point{  
    double x,y;  
    Point(double _x=0,double _y=0){  
        x=_x;y=_y;  
    }  
};  
Point operator + (const Point &a,const Point &b){  
    return Point(a.x+b.x,a.y+b.y);  
}  
Point operator - (const Point &a,const Point &b){  
    return Point(a.x-b.x,a.y-b.y);  
}  
Point operator * (const Point &a,const double &p){  
    return Point(a.x*p,a.y*p);  
}  
Point operator / (const Point &a,const double &p){  
    return Point(a.x/p,a.y/p);  
}  
bool operator < (const Point &a,const Point &b){  
    return a.x<b.x||(dcmp(a.x-b.x)==0&&a.y<b.y);  
}  
bool operator == (const Point &a,const Point &b){  
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;  
}  
double Dot(Point  a,Point b){  
    return a.x*b.x+a.y*b.y;  
}  
double Length(Point a){  
    return sqrt(Dot(a,a));  
}  
double Angle(Point a,Point b){  
    return acos(Dot(a,b)/Length(a)/Length(b));  
}  
double angle(Point a){  
    return atan2(a.y,a.x);  
}  
double Cross(Point a,Point b){  
    return a.x*b.y-a.y*b.x;  
}  
Point vecunit(Point a){  
    return a/Length(a);  
}  
Point Normal(Point a){  
    return Point(-a.y,a.x)/Length(a);  
}  
Point Rotate(Point a,double rad){  
    return Point(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));  
}  
double Area2(Point a,Point b,Point c){  
    return Length(Cross(b-a,c-a));  
}  
bool OnSegment(Point p,Point a1,Point a2){    
    return dcmp(Cross(a1-p,a2-p))==0&&dcmp(Dot(a1-p,a2-p))<=0;    
}    
struct Line{  
    Point p,v;  
    double ang;  
    Line(){};  
    Line(Point p,Point v):p(p),v(v){  
        ang=atan2(v.y,v.x);  
    }  
    bool operator < (const Line &L) const {  
        return ang<L.ang;  
    }  
    Point point(double d){  
        return p+(v*d);  
    }  
};  
bool OnLeft(const Line &L,const Point &p){  
    return Cross(L.v,p-L.p)>=0;  
}  
Point GetLineIntersection(Point p,Point v,Point q,Point w){  
    Point u=p-q;  
    double t=Cross(w,u)/Cross(v,w);  
    return p+v*t;  
}  
Point GetLineIntersection(Line a,Line b){  
    return GetLineIntersection(a.p,a.v,b.p,b.v);  
}  
double PolyArea(vector<Point> p){  
    int n=p.size();  
    double ans=0;  
    for(int i=1;i<n-1;i++)  
        ans+=Cross(p[i]-p[0],p[i+1]-p[0]);  
    return fabs(ans)/2;  
}  
struct Circle      
{      
    Point c;      
    double r;      
    Circle(){}      
    Circle(Point c, double r):c(c), r(r){}      
    Point point(double a) //根据圆心角求点坐标      
    {      
        return Point(c.x+cos(a)*r, c.y+sin(a)*r);      
    }      
};     
    
bool InCircle(Point x,Circle c){    
    return dcmp(c.r-Length(c.c-x))>=0;    
}    
bool OnCircle(Point x,Circle c){    
    return dcmp(c.r-Length(c.c-x))==0;    
}    
int getSegCircleIntersection(Line L,Circle C,Point *sol){    
    Point nor=Normal(L.v);    
    Line p1=Line(C.c,nor);    
    Point ip=GetLineIntersection(p1,L);    
    double dis=Length(ip-C.c);    
    if(dcmp(dis-C.r)>0)return 0;    
    Point dxy=vecunit(L.v)*sqrt(C.r*C.r-dis*dis);    
    int ret=0;    
    sol[ret]=ip+dxy;    
    if(OnSegment(sol[ret],L.p,L.point(1)))ret++;    
    sol[ret]=ip-dxy;    
    if(OnSegment(sol[ret],L.p,L.point(1)))ret++;    
    return ret;    
}    
double SegCircleArea(Circle C,Point a,Point b){    
    double a1=angle(a-C.c);    
    double a2=angle(b-C.c);    
    double da=fabs(a1-a2);    
    if(da>pi)da=pi*2-da;    
    return dcmp(Cross(b-C.c,a-C.c))*da*C.r*C.r/2.0;    
}    
double PolyCircleArea(Circle C,Point *p,int n){    
    double ret=0;    
    Point sol[2];    
    p[n]=p[0];    
    for(int i=0;i<n;i++){    
        double t1,t2;    
        int cnt=getSegCircleIntersection(Line(p[i],p[i+1]-p[i]),C,sol);  //判断线段与圆有几个交点，  
    //  cout<<"cnt="<<cnt<<" "<<p[i].x<<" "<<p[i].y<<" "<<p[i+1].x<<" "<<p[i+1].y<<endl;  
    //  cout<<"C: "<<C.c.x<<" "<<C.c.y<<" "<<C.r<<endl;  
    //  cout<<"sol ";for(int j=0;j<cnt;j++)cout<<sol[j].x<<" "<<sol[j].y<<" ";cout<<endl;  
        if(cnt==0){  //0个交点，判断线段在多边形内部还是外部。  
            if(!InCircle(p[i],C)||!InCircle(p[i+1],C))ret+=SegCircleArea(C,p[i],p[i+1]); //外部直接计算圆弧面积   
            else ret+=Cross(p[i+1]-C.c,p[i]-C.c)/2;  //内部计算三角形面积。  
        }    
        if(cnt==1){    
            if(InCircle(p[i],C)&&(!InCircle(p[i+1],C)||OnCircle(p[i+1],C)))ret+=Cross(sol[0]-C.c,p[i]-C.c)/2,ret+=SegCircleArea(C,sol[0],p[i+1]);//,cout<<"jj-1"<<endl;  
            else ret+=SegCircleArea(C,p[i],sol[0]),ret+=Cross(p[i+1]-C.c,sol[0]-C.c)/2;//,cout<<"jj-2"<<endl;  
        }    
        if(cnt==2){  //两个交点  
            if((p[i]<p[i+1])^(sol[0]<sol[1]))swap(sol[0],sol[1]);    
            ret+=SegCircleArea(C,p[i],sol[0]);    
            ret+=Cross(sol[1]-C.c,sol[0]-C.c)/2;    
            ret+=SegCircleArea(C,sol[1],p[i+1]);    
        }  
     // cout<<ret<<endl;      
    }    
    return fabs(ret);    
}    
  
int main()    
{     
    Point p[5];
	int t, cas = 1;    
    double R;    
    double x1,y1,x2,y2,x3,y3;    
    bool flag=0;    
    cin >> t;
    while(cin>>x2>>y2>>x3>>y3>>R)    
    {    
        x1 = y1 = 0;
        Circle C=Circle(Point(x1,y1),R);    
        if(x2>x3)swap(x2,x3);  
        if(y2>y3)swap(y2,y3);  
        p[0]=Point(x2,y2);    
        p[2]=Point(x3,y3);    
        p[1]=Point(x3,y2);    
        p[3]=Point(x2,y3);    
        double ans=PolyCircleArea(C,p,4);  
        if(ans < -eps) ans = -ans;
        printf("%.10lf\n",cas++, ans);         
    }  
     return 0;    
}  