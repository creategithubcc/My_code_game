#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x;
	int y;
}zuobiao;
int n,m,k;
char op,t;
char mp[1002][1002];
void func2()
{
	if((mp[zuobiao.x][zuobiao.y]<='z'&&mp[zuobiao.x][zuobiao.y]>='a'&&mp[zuobiao.x][zuobiao.y]!='v')
		||(mp[zuobiao.x][zuobiao.y]<='Z'&&mp[zuobiao.x][zuobiao.y]>='A')
		||(mp[zuobiao.x][zuobiao.y]<='9'&&mp[zuobiao.x][zuobiao.y]>='0')
		||(mp[zuobiao.x][zuobiao.y]=='/')||(mp[zuobiao.x][zuobiao.y]=='\\'))
	{
		return;
	}
	if(zuobiao.x>=n&&t=='v')//发生鬼打墙 
	{
		zuobiao.x=1;
	}
	else if(zuobiao.y>=m&&t=='>')
	{
		zuobiao.y=1;
	}
	else if(zuobiao.x<=1&&t=='^')
	{
		zuobiao.x=n;
	}
	else if(zuobiao.y<=1&&t=='<')
	{
		zuobiao.y=m;
	}
}
void func3()
{
	if(zuobiao.x>=n&&t=='v')//发生鬼打墙 
	{
		mp[zuobiao.x][zuobiao.y]='.';
		zuobiao.x=1;
	}
	else if(zuobiao.y>=m&&t=='>')
	{
		mp[zuobiao.x][zuobiao.y]='.';
		zuobiao.y=1;
	}
	else if(zuobiao.x<=1&&t=='^')
	{
		mp[zuobiao.x][zuobiao.y]='.';
		zuobiao.x=n;
	}
	else if(zuobiao.y<=1&&t=='<')
	{
		mp[zuobiao.x][zuobiao.y]='.';
		zuobiao.y=m;
	}
}
void func()
{
	if((mp[zuobiao.x][zuobiao.y]<='z'&&mp[zuobiao.x][zuobiao.y]>='a'&&mp[zuobiao.x][zuobiao.y]!='v')
	||(mp[zuobiao.x][zuobiao.y]<='Z'&&mp[zuobiao.x][zuobiao.y]>='A')
	||(mp[zuobiao.x][zuobiao.y]<='9'&&mp[zuobiao.x][zuobiao.y]>='0'))
	{
		for(int ii=1;ii<=n;ii++)
		{
			for(int jj=1;jj<=m;jj++)
			{
				if(mp[ii][jj]==mp[zuobiao.x][zuobiao.y])
				{
					if(ii==zuobiao.x&&jj==zuobiao.y)
					{
						continue;
					}
					if(t=='^')
					{
						zuobiao.x=ii-1;
						zuobiao.y=jj;
						return;
					} 
					else if(t=='<')
					{
						zuobiao.y=jj-1;
						zuobiao.x=ii;
						return;
					}
					else if(t=='>')
					{
						zuobiao.y=jj+1;
						zuobiao.x=ii;
						return;
					}
					else if(t=='v')
					{
						zuobiao.x=ii+1;
						zuobiao.y=jj;
						return;
					}
				}
			}
		}
	}
	else if(mp[zuobiao.x][zuobiao.y]=='/')
	{
		if(t=='^')
		{
			zuobiao.y++;
			t='>';
		}
		else if(t=='>')
		{
			zuobiao.x--;
			t='^';	
		}
		else if(t=='<')
		{
			zuobiao.x++;
			t='v';
		}
		else if(t=='v')
		{
			zuobiao.y--;
			t='<';
		}
	}
	else if(mp[zuobiao.x][zuobiao.y]=='\\')
	{
		if(t=='^')
		{
			zuobiao.y--;
			t='<';
		}
		else if(t=='>')
		{
			zuobiao.x++;
			t='v';
		}
		else if(t=='<')
		{
			zuobiao.x--;
			t='^';
		}
		else if(t=='v')
		{
			zuobiao.y++;
			t='>';
		}
	}
}
void output()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<mp[i][j]<<" ";
		}cout<<endl;
	}
}
int main()
{ 
	while(cin>>n>>m>>k)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>mp[i][j];//构建地图完成 
				if(mp[i][j]=='^'||mp[i][j]=='<'||mp[i][j]=='>'||mp[i][j]=='v')
				{
					zuobiao.x=i;
					zuobiao.y=j;
				}
			}
		}
		for(int i=0;i<k;i++)//命令 
		{
			cin>>op;
			switch(op)
			{
				case 'q'://输出当前位置方向 
					cout<<zuobiao.x<<" "<<zuobiao.y<<" "<<mp[zuobiao.x][zuobiao.y]<<endl; 
					break;
				case 'r'://向右 
					if(mp[zuobiao.x][zuobiao.y]=='^')
					{
						mp[zuobiao.x][zuobiao.y]='>';
						cout<<zuobiao.x<<" "<<zuobiao.y<<" "<<mp[zuobiao.x][zuobiao.y]<<endl;
					} 
					else if(mp[zuobiao.x][zuobiao.y]=='>')
					{
						mp[zuobiao.x][zuobiao.y]='v';
						cout<<zuobiao.x<<" "<<zuobiao.y<<" "<<mp[zuobiao.x][zuobiao.y]<<endl;
					}
					else if(mp[zuobiao.x][zuobiao.y]=='v')
					{
						mp[zuobiao.x][zuobiao.y]='<';
						cout<<zuobiao.x<<" "<<zuobiao.y<<" "<<mp[zuobiao.x][zuobiao.y]<<endl;
					}
					else if(mp[zuobiao.x][zuobiao.y]=='<')
					{
						mp[zuobiao.x][zuobiao.y]='^';
						cout<<zuobiao.x<<" "<<zuobiao.y<<" "<<mp[zuobiao.x][zuobiao.y]<<endl;
					}
					break;
				case 'l'://向左 
					if(mp[zuobiao.x][zuobiao.y]=='^')
					{
						mp[zuobiao.x][zuobiao.y]='<';
						cout<<zuobiao.x<<" "<<zuobiao.y<<" "<<mp[zuobiao.x][zuobiao.y]<<endl;
					} 
					else if(mp[zuobiao.x][zuobiao.y]=='<')
					{
						mp[zuobiao.x][zuobiao.y]='v';
						cout<<zuobiao.x<<" "<<zuobiao.y<<" "<<mp[zuobiao.x][zuobiao.y]<<endl;
					}
					else if(mp[zuobiao.x][zuobiao.y]=='v')
					{
						mp[zuobiao.x][zuobiao.y]='>';
						cout<<zuobiao.x<<" "<<zuobiao.y<<" "<<mp[zuobiao.x][zuobiao.y]<<endl;
					}
					else if(mp[zuobiao.x][zuobiao.y]=='>')
					{
						mp[zuobiao.x][zuobiao.y]='^';
						cout<<zuobiao.x<<" "<<zuobiao.y<<" "<<mp[zuobiao.x][zuobiao.y]<<endl;
					}
					break;
				case 'f'://向前一格 
					func3();
					t=mp[zuobiao.x][zuobiao.y];
					if(mp[zuobiao.x][zuobiao.y]=='^')
					{
						mp[zuobiao.x][zuobiao.y]='.';//边空 
						zuobiao.x--;
						while(mp[zuobiao.x][zuobiao.y]!='.')
						{
							func();
							func2();
						}
						mp[zuobiao.x][zuobiao.y]=t;
					}
					else if(mp[zuobiao.x][zuobiao.y]=='>')
					{
						t=mp[zuobiao.x][zuobiao.y];
						mp[zuobiao.x][zuobiao.y]='.';
						zuobiao.y++;
						while(mp[zuobiao.x][zuobiao.y]!='.')
						{
							func();
							func2();//cout<<"mp["<<zuobiao.x<<"]["<<zuobiao.y<<"]="<<mp[zuobiao.x][zuobiao.y]<<" t="<<t<<endl;
						}
						mp[zuobiao.x][zuobiao.y]=t;
					}
					else if(mp[zuobiao.x][zuobiao.y]=='v')
					{
						t=mp[zuobiao.x][zuobiao.y];
						mp[zuobiao.x][zuobiao.y]='.';
						zuobiao.x++;
						while(mp[zuobiao.x][zuobiao.y]!='.')
						{
							func();
							func2();
						}
						mp[zuobiao.x][zuobiao.y]=t;
					}
					else if(mp[zuobiao.x][zuobiao.y]=='<')
					{
						t=mp[zuobiao.x][zuobiao.y];
						mp[zuobiao.x][zuobiao.y]='.';
						zuobiao.y--;
						while(mp[zuobiao.x][zuobiao.y]!='.')
						{
							func();
							func2();
						}
						mp[zuobiao.x][zuobiao.y]=t;
					}
					//cout<<zuobiao.x<<" "<<zuobiao.y<<" "<<mp[zuobiao.x][zuobiao.y]<<endl;
					func3();
					mp[zuobiao.x][zuobiao.y]=t;
					break;
			}
			output();
		}
	}
	return 0;
}
