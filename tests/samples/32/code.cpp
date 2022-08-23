#include <bits/stdc++.h>
#include <sys/time.h> 
using namespace std;
 
const double INF = 1e20;
 
struct Point{
    double x, y;
    Point (double a = 0, double b = 0) : x(a), y(b) {}
};
 
int n, st;
double v;
Point p[8005], S, T;
double dist[8005];
bool vis[8005];
 
double getdist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
 
double cross(Point o, Point a, Point b) {
    double x1 = a.x - o.x, y1 = a.y - o.y;
    double x2 = b.x - o.x, y2 = b.y - o.y;
    return x1 * y2 - x2 * y1;
}
 
bool check(int up, int low, Point a, Point b) {
    return !(up && cross(a, p[up], b) > 0 || low && cross(a, p[low], b) < 0);
}
 
void spfa() {
    for (int i = st; i <= n; i++)
        dist[i] = INF;
    dist[st] = 0;
    vis[st] = 1;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int up = 0, low = 0;
        for (int i = cur + 1; i <= n; i++) {
            if (check(up, low, p[cur], p[i])) {
                if (dist[cur] + getdist(p[cur], p[i]) < dist[i]) {
                    dist[i] = dist[cur] + getdist(p[cur], p[i]);
                    if (!vis[i]) q.push(i);
                }
            }
            if (((i - 1) % 4 + 1) & 1 && (!up || cross(p[cur], p[up], p[i]) <= 0)) up = i;
            else if (!(((i - 1) % 4 + 1) & 1) && (!low || cross(p[cur], p[low], p[i]) >= 0)) low = i;
            if (up && low && cross(p[cur], p[up], p[low]) > 0) break;
        }
        vis[cur] = 0;
    }
}
 
int main() {
//	freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf %lf %lf %lf", &p[i * 4 - 2].x, &p[i * 4 - 2].y, &p[i * 4 - 1].x, &p[i * 4 - 1].y);
        p[i * 4 - 3] = Point(p[i * 4 - 2].x, p[i * 4 - 1].y);
        p[i * 4] = Point(p[i * 4 - 1].x ,p[i * 4 - 2].y);
    }
    n <<= 2;
    scanf("%lf %lf %lf %lf", &S.x, &S.y, &T.x, &T.y);
    scanf("%lf", &v);
    struct timeval start;
    struct timeval end;
    float time_use=0;
    gettimeofday( &start, NULL );
    if (S.x > T.x) swap(S, T);
    for (; n; n--)
        if (p[n].x <= T.x) break;
    p[++n] = T;
    for (st = 1; st <= n; st++)
        if (p[st].x >= S.x) break;
    p[--st] = S;
    spfa();
    gettimeofday( &end, NULL );
    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    
    printf("%.10lf\n", dist[n] / v);
    printf("time_use is %f\n",time_use);
    return 0;
}
