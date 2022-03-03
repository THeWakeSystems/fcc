#include <bits/stdc++.h>
using namespace std;

char g[6][6];
char bc[6][6];

int dx[5] = { -1 , 0 , 1 , 0 , 0 };
int dy[5] = { 0 , 1 , 0 , -1 , 0 };

void turn( int x , int y )
{
	int a = 0;
	int b = 0;
	int i = 0;
	
	for( i = 0 ; i < 5 ; i++ )
	{
		a = x + dx[i];
		b = y + dy[i];
		
		if( a < 0 || a >= 5 || b < 0 || b >= 5 )
		{
			continue;
		}
		
		g[a][b] ^= 1;
	}
}
int main()
{
	int t = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int ans = 0;
	int step = 0;
	bool b = 0;
	
	cin >> t;
	
	while( t-- )
	{
		for( i = 0 ; i < 5 ; i++ )
		{
			cin >> g[i];
		}
		
		ans = 10;
		
		for( k = 0 ; k < 32 ; k++ )
		{
			memcpy( bc , g , sizeof g );
			step = 0;
			
			for( i = 0 ; i < 5 ; i++ )
			{
				if( k >> i & 1 )
				{
					step++;
					turn( 0 , i );
				}
			}
			
			for( i = 0 ; i < 4 ; i++ )
			{
				for( j = 0 ; j < 5 ; j++ )
				{
					if( g[i][j] == '0' )
					{
						step++;
						turn( i + 1 , j );
					}
				}
			}
			
			b = 0;
			
			for( i = 0 ; i < 5 ; i++ )
			{
				if( g[4][i] == '0' )
				{
					b = 1;
					break;
				}
			}
			
			if( !b )
			{
				ans = min( ans , step );
			}
			
			memcpy( g , bc , sizeof g );
		}
		
		if( ans > 6 )
		{
			ans = -1;
		}
		
		cout << ans << endl;
	}
	
	return 0;
}