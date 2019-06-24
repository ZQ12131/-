#include "xiaqi.h"
Game::Game(void)
{
	for(int i=0;i<9;i++)
	status[i]=' ';
	counter=0;
	fail=0;
}
void Game::Print()
{
cout<<"-------------------"<<endl;
cout<<"|  "<<status[0]<<"  |  "<<status[1]<<" |   "<<status[2]<<"  | "<<endl;
cout<<"+-----------------+"<<endl;
cout<<"|  "<<status[3]<<"  |  "<<status[4]<<" |   "<<status[5]<<"  | "<<endl;
cout<<"+-----------------+"<<endl;
cout<<"|  "<<status[6]<<"  |  "<<status[7]<<" |   "<<status[8]<<"  | "<<endl;
cout<<"-------------------"<<endl;
}
 int Game::Cal(int i,int j)
{
	int result=0;
	if ((status[i-1]=='X')&&(status[j-1]=='X'))
	{
		result=50;
		
	}
	if ((status[i-1]=='O')&&(status[j-1]=='O'))
	{result=25;}
	if( ((status[i-1]=='X')&&(status[j-1]<'A'))||((status[i-1]<'A')&&(status[j-1]=='X')))
	{result=10;	}
	if( ((status[i-1]=='O')&&(status[j-1]<'A'))||((status[i-1]<'A')&&(status[j-1]=='O')))
	{result=8;}
	if ((status[i-1]<'A')&&(status[j-1]<'A'))
	{
		result=4;
	}
	return result;
}
bool Game::Judge(int i,int j,int k,char q)
{
	return ((status[i-1]==q)&&(status[j-1]==q)&&(status[k-1]==q));
}
void Game::Play()
{
int n=0,max=0,temp=0;
char ch,q;
Print();
cout<<"请选择先下还是后下（选择F/S，F--Fist，S--Second）?";
cin>>ch;
cout<<"请选择棋子（'X'或'O'）";
cin>>q;
if((ch=='s')||(ch=='S'))
{
	if(q=='X')status[4]='O';
	else status[4]='X';
	counter=counter+1;
	Print();
	cout<<"电脑选择 5位置!";
}
do
{
do 
{
	cout<<"请选择 (1..9)位置。";
	cin>>n;
} while (status[n-1]>='A');
   if(q=='X')status[n-1]='X';
   else status[n-1]='O';
   counter++;
   Print();
   if((Judge(1,2,3,q))||(Judge(4,5,6,q))||(Judge(7,8,9,q))||
	   (Judge(1,4,7,q))||(Judge(2,5,8,q))||(Judge(3,6,9,q))||
	   (Judge(1,5,9,q))||(Judge(3,5,7,q)))
	   fail=1;
 if((fail<1)&&(counter<9))
   {
	   for(int k=0;k<9;k++)
		   if(status[k]<'A')
		   {
			   switch(k)
			   {
			   case 0:score[0]=Cal(2,3)+Cal(4,7)+Cal(5,9);
				   break;
			   case 1:score[1]=Cal(1,3)+Cal(5,8);
				   break;
			   case 2:score[2]=Cal(1,2)+Cal(6,9)+Cal(5,7);
				   break;
			   case 3:score[3]=Cal(5,6)+Cal(1,7);
				   break;
			   case 4:score[4]=Cal(4,6)+Cal(2,8)+Cal(1,9);
				   break;
			   case 5:score[5]=Cal(4,5)+Cal(3,9);
				   break;
			   case 6:score[6]=Cal(8,9)+Cal(1,4)+Cal(3,5);
				   break;
			   case 7:score[7]=Cal(7,9)+Cal(2,5);
				   break;
			   case 8:score[8]=Cal(7,8)+Cal(3,6)+Cal(1,5);
				   break;
            }
	  }
		   else score[k]=-1;
		   max=score[0];
		   int k;
		   for(k=1;k<9;k++)
			   if (score[k]>max)
			   {
				   max=score[k];
				   temp=k;
			   }
			if(q=='O')   status[temp]='X';
			else status[temp]='O';
			   counter++;
			   cout<<"computer play"<<temp+1<<"!"<<endl;
			   Print();

   }
}while((fail<=0)&&(counter<9));
if(fail==0)
	cout<<"we drew"<<endl;
else if(fail==1)
	cout<<"you have win!"<<endl;
else cout<<"computer has win!"<<endl;
}


