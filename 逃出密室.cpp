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
		cout<<"��ϲ�㵽�����յ㣡��������շ���Ϊ:"<<(30-zuobiao.step)*100/30<<"/100"<<endl;
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
	if(zuobiao.x>=n&&t=='v')//�������ǽ 
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
	if(zuobiao.x>=n&&t=='v')//�������ǽ 
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
		  "////                      ��ӭ�����Բ���������С��Ϸ����Ϸ��Ҫ��                       ////"<<endl<<
		  "////                                                                                   ////"<<endl<<
		  "//// 1.ĳ���������㷢���Լ�������һ�����������һ��10x10�����ң�û�д�����û�д���   ////"<<endl<<
		  "//// 2.�㷢�ַ������ƺ���һ�����������㲻Զ��(#),��ֱ����Ϊ�������뿪�÷����Ψһ����  ////"<<endl<<
		  "//// 3.��׼�������ǵķ����ߣ�����һ˲��ȴ�������˷�����һ�࣡�㷢�������Ȼ�д����豸  ////"<<endl<<
		  "//// 4.������ֻ�д����豸���������·����ǽ�ڣ���������ִ���ǽ�ڵ����˷������һ�࣡  ////"<<endl<<
		  "//// 5.�����ﻹ�м��澵�ӣ������ߵ�������ǰʱ����һ����ͷ����Լ��������˾�����һ�ߣ�  ////"<<endl<<
		  "//// 6.�۲��귿����㷢���Լ����Ͼ�Ȼ����һ������ը��������д��'50����ը�����ᱬը'  ////"<<endl<<
		  "//// 7.����һ�������ר�ң�ֻҪ�м�����Ϳ��Բ��ը�����㷢��Ψһ�ļ������ھ����Ա�  ////"<<endl<<
		  "//// 8.������һ�£��ոչ۲췿���ʱ����������20����Ҳ����˵�㻹ʣ��30�������ߵ��յ�  ////"<<endl<<
		  "//// 9.Ҳ����˵����Ҫ���ô����豸��ħ��������Ĺ��ǽ�������ھ����̵ܶ�ʱ�����ߵ��յ㣡////"<<endl<<
		  "////                                                                                   ////"<<endl<<
		  "////                                  ��Ϸ����                                       ////"<<endl<<
		  "////   �����������'>'(<|v|^),����qָ�����ʾ��ǰ�����ʣ�ಽ��,����lָ�����������ת ////"<<endl<<
		  "////   ����rָ�����������ת,����fָ���������ǰ��.��ͼ��������ħ��[/][\],�����ɴ�Сд  ////"<<endl<<
		  "////   ��ĸ��������ɵĴ���װ��,���㵽��ǽ�ڱ�Եʱ�㻹�ᱻ���͵�������һͷ�����ڲ����� ////"<<endl<<
		  "////   ���ڵ��﷿���ϵ�[#]�ص�,�����м�����Ψһ�ĳ���,���ǽ���¼�����̲���,ף�����! ////"<<endl<<
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
	zuobiao.x=2,zuobiao.y=5,zuobiao.step=0;//��� 
	output();
	while(zuobiao.step<=30)//���� 
	{
		cin>>op; 
		switch(op)
		{
			case 'q'://�����ǰλ�÷��� 
				cout<<"��ǰ����:"<<zuobiao.x<<" "<<zuobiao.y<<" "<<mp[zuobiao.x][zuobiao.y]<<endl; 
				cout<<"ʣ�ಽ��:"<<30-zuobiao.step<<endl; 
				_sleep(2000);
				break;
			case 'r'://���� 
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
			case 'l'://���� 
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
			case 'f'://��ǰһ�� 
				zuobiao.step++;
				func3();
				t=mp[zuobiao.x][zuobiao.y];
				if(mp[zuobiao.x][zuobiao.y]=='^')
				{
					mp[zuobiao.x][zuobiao.y]='.';//�߿� 
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
	cout<<"��û�ڲ��������ڵ����յ㣬ը�������ˣ��飡Game Over����"<<endl; 
	return 0;
}
