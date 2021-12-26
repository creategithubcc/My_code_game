#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x;
	int y;
	int step; 
}zuobiao;
int n=10,m=10,k=30;
char op,t;
char mp[11][11]={'?','?','?','?','?','?','?','?','?','?','?',
				 '?','a','1','.','.','.','.','.','d','/','q',
				 '?','\\','2','/','.','>','a','1','\\','/','.',
				 '?','2','\\','/','d','.','.','.','.','q','.',
				 '?','/','/','/','/','/','/','/','/','/','/',
				 '?','.','.','.','.','/','.','u','.','.','.',
				 '?','.','c','.','.','.','.','.','k','.','.',
				 '?','u','.','.','.','k','.','.','.','.','.',
				 '?','/','/','.','.','.','.','c','.','/','.',
				 '?','s','.','.','\\','.','.','.','/','/','.',
				 '?','.','.','.','.','.','s','/','#','/','.'};
int gol()
{
	if(mp[zuobiao.x][zuobiao.y]=='#')
	{
		cout<<"恭喜你到达了终点！！你的最终分数为:"<<(30-zuobiao.step)*100/30<<"/100"<<endl;
		exit(0);
	}
}
void func2()
{
	gol();
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
	gol();
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
	cout<<"///////////////////////////////////////////////////////////////////////////////////////////"<<endl<< 
          "////                                                                                   ////"<<endl<<
		  "////                      欢迎来到苍苍密室逃脱小游戏！游戏概要：                       ////"<<endl<<
		  "////                                                                                   ////"<<endl<<
		  "//// 1.某天醒来，你发现自己被困在一个密室里，这是一个10x10的密室，没有窗户，没有大门   ////"<<endl<<
		  "//// 2.你发现房间内似乎有一个井盖在离你不远处(#),你直觉认为它将是离开该房间的唯一出口  ////"<<endl<<
		  "//// 3.你准备往井盖的方向走，但下一瞬间却出现在了房间另一侧！你发现这里居然有传送设备  ////"<<endl<<
		  "//// 4.不仅仅只有传送设备，你摸了下房间的墙壁，发现你的手穿过墙壁到达了房间的另一侧！  ////"<<endl<<
		  "//// 5.房间里还有几面镜子，当你走到镜子面前时，下一秒你就发现自己出现在了镜子另一边！  ////"<<endl<<
		  "//// 6.观察完房间后，你发现自己身上居然绑着一颗袖珍炸弹！上面写着'50步后炸弹将会爆炸'  ////"<<endl<<
		  "//// 7.你是一名资深拆弹专家，只要有剪刀你就可以拆掉炸弹，你发现唯一的剪刀就在井盖旁边  ////"<<endl<<
		  "//// 8.你算了一下，刚刚观察房间的时候你大概走了20步，也就是说你还剩下30步可以走到终点  ////"<<endl<<
		  "//// 9.也就是说，你要利用传送设备、魔镜和神奇的鬼打墙现象来在尽可能短的时间内走到终点！////"<<endl<<
		  "////                                                                                   ////"<<endl<<
		  "////                                  游戏规则：                                       ////"<<endl<<
		  "////   你控制着人物'>'(<|v|^),输入q指令会显示当前坐标和剩余步数,输入l指令人物会向左转 ////"<<endl<<
		  "////   输入r指令人物会向右转,输入f指令人物会向前走.地图上有两种魔镜[/][\],还有由大小写  ////"<<endl<<
		  "////   字母和数字组成的传送装置,当你到达墙壁边缘时你还会被传送到房间另一头。请在步数限 ////"<<endl<<
		  "////   制内到达房间上的[#]地点,那里有剪刀和唯一的出口,我们将记录你的最短步数,祝你好运! ////"<<endl<<
		  "////                                                                                   ////"<<endl<<
		  "///////////////////////////////////////////////////////////////////////////////////////////"<<endl; 
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
	zuobiao.x=2,zuobiao.y=5,zuobiao.step=0;//起点 
	output();
	while(zuobiao.step<=30)//命令 
	{
		cin>>op; 
		switch(op)
		{
			case 'q'://输出当前位置方向 
				cout<<"当前坐标:"<<zuobiao.x<<" "<<zuobiao.y<<" "<<mp[zuobiao.x][zuobiao.y]<<endl; 
				cout<<"剩余步数:"<<30-zuobiao.step<<endl; 
				_sleep(2000);
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
				_sleep(1000);
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
				_sleep(1000);
				break;
			case 'f'://向前一格 
				zuobiao.step++;
				func3();
				t=mp[zuobiao.x][zuobiao.y];
				if(mp[zuobiao.x][zuobiao.y]=='^')
				{
					mp[zuobiao.x][zuobiao.y]='.';//边空 
					zuobiao.x--;
					while(mp[zuobiao.x][zuobiao.y]!='.')
					{
						gol();
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
						gol();
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
						gol();
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
						gol();
						func();
						func2();
					}
					mp[zuobiao.x][zuobiao.y]=t;
				}
				func3();
				mp[zuobiao.x][zuobiao.y]=t;
				break;
		}
		system("cls"); 
		output();
	}
	cout<<"你没在步数限制内到达终点，炸弹引爆了，砰！Game Over！！"<<endl; 
	return 0;
}
