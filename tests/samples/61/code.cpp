#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std ;

typedef pair<int,int> PII;

vector<PII> a;

int cow[10][10];//每一行的数字；
int col[10][10];//每一列的数字；
int qrt[10][10];//每一块的数字；

int g[10][10];

int len ;

int findd(int i , int j)
{

            if(i <= 3 && j <= 3)
            {
                return 1;
            }

            if( i <= 3 && j > 3 && j <= 6)
            {
                return 2;
            }

            if( i <= 3 && j > 6 && j <= 9)
            {
                return 3;
            }

            if( i > 3 && i <= 6 && j <= 3)
            {
                return 4;
            }

            if( i > 3 && i <= 6 && j > 3 && j <= 6)
            {
                return 5;
            }

            if( i > 3 && i <= 6 && j > 6 && j<= 9)
            {
                return 6;
            }

            if( i > 6 && j <= 3)
            {
                return 7 ;
            }

            if(i > 6 && j > 3 && j <= 6 )
            {

                return 8 ;
            }

            if( i > 6 && j > 6 && j <= 9)
            {
                return 9 ;
            }
    return 0 ;
}

bool f = 0 ;

void dfs(int s)
{
    if(s == len)
    {
        f=  1;
        return ;
    }
    for(int i = 1 ; i<= 9 ; i++)
    {
        if(col[a[s].first][i] == 0 &&cow[a[s].second][i] == 0&&qrt[findd(a[s].first,a[s].second)][i] == 0)
        {
            g[a[s].first][a[s].second] = i;
            col[a[s].first][i] = cow[a[s].second][i] = qrt[findd(a[s].first,a[s].second)][i] = 1;
            dfs(s+1);
            if(f == 1)return ;
            g[a[s].first][a[s].second] = 0;
            col[a[s].first][i] = cow[a[s].second][i] = qrt[findd(a[s].first,a[s].second)][i] = 0;
        }
    }

    return ;
}


int main()
{
    for(int i = 1  ; i <= 9 ; i++)
    {
        for(int j = 1 ; j <= 9 ; j++)
        {
            char  v ;
            cin >> v;
            if(v != '0')
            {
                g[i][j] = (v - '0');
                cow[j][v-'0'] = 1;
                col[i][v-'0'] = 1;
            }
            else a.push_back({i,j});
        }
    }

    len = a.size();

    for(int i = 1 ;  i<= 9 ; i++)
    {
        for(int j = 1 ;  j <= 9 ; j++)
        {
            if(g[i][j] == 0)continue;
            if(i <= 3 && j <= 3)
            {
                qrt[1][g[i][j]] = 1;
            }

            if( i <= 3 && j > 3 && j <= 6)
            {
                qrt[2][g[i][j]] = 1;
            }

            if( i <= 3 && j > 6 && j <= 9)
            {
                qrt[3][g[i][j]] = 1;
            }

            if( i > 3 && i <= 6 && j <= 3)
            {
                qrt[4][g[i][j]] = 1;
            }

            if( i > 3 && i <= 6 && j > 3 && j <= 6)
            {
                qrt[5][g[i][j]] = 1;
            }

            if( i > 3 && i <= 6 && j > 6 && j<= 9)
            {
                qrt[6][g[i][j]] = 1;
            }

            if( i > 6 && j <= 3)
            {
                qrt[7][g[i][j]] = 1;
            }

            if(i > 6 && j > 3 && j <= 6 )
            {

                qrt[8][g[i][j]] = 1;
            }

            if( i > 6 && j > 6 && j <= 9)
            {
                qrt[9][g[i][j]] = 1;
            }
        }
    }
    dfs(0);
    for(int i = 1 ;  i<= 9 ; i++)
    {
        for(int j = 1  ; j <= 9 ; j++)
        {
            cout << g[i][j]  <<' ';
        }
        cout <<endl ;
    }

  return 0 ;

}


