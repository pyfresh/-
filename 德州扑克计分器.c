#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define N

int flag[10],money[10],jackpot[100],turn=1,lastn,r,joker,n;
void f_add(int n,int turn)
{
	int i,add,addi,times=0;
	add=1;
	for(i=joker;times<n;i++)
	{
		if(i>n)
		i-=n;
		if(flag[i]!=-1)
		{
			printf("%d����Ҽ�עΪ��(���롰0��Ϊ����)\n",i);
			scanf("%d",&addi);
			if(addi==0)
			{
				flag[i]=-1;
				lastn--;
				times++;
				continue;
			}
			else if(addi<add)
			{
			printf("%d����Ҽ�ע������Ϲ淶!\n�����¼�ע,�ٴ�Υ����������\n",i);
			scanf("%d",&addi);
			if(addi<add)
			{
			flag[i]=-1;
			lastn--;}
			else
			{
				money[i]-=addi;
				add=addi;
				jackpot[turn]+=addi;
			 } 
			}
			else
			{
				money[i]-=addi;
				add=addi;
				jackpot[turn]+=addi;
			}
		}
		times++;
		
	}
	r++;
	
}
int main(){
	int i,sum=0,wn=0,ave=0,j=0;
	printf("Game On!\n������������\n");
	scanf("%d",&n);
	lastn=n;
	for(i=1;i<=n;i++)
	{
		printf("%d����ҵĵ׽��ǣ�\n",i);
		scanf("%d",&money[i]);
	}
	printf("������С���ǣ�\n");
	scanf("%d",&joker);
	int ctn=1;
	while(ctn==1)
	{
		printf("��%d����Ϸ��ʼ\n",turn);
		lastn=n;
		money[joker]-=5;
		money[joker+1]-=10;
		jackpot[turn]=15;
		while(lastn>1&&r<4)
		f_add(n,turn);
		printf("��ʤ����Ŀ�ǣ�\n");
		scanf("%d",&wn);
		ave=jackpot[turn]/wn;
		for(i=1;i<=wn;i++)
		{
			printf("��%dλ��ʤ����:\n",i);
			scanf("%d",&j);
			money[j]+=ave;
		}
		for(i=1;i<=n;i++)
		{
			printf("%d��ѡ��ʣ����Ϊ��%d\n",i,money[i]);
			if(money[i]<=0)
			ctn=-1;
		}
		r=0;
		turn++;
		for(i=1;i<=n;i++)
		{
			flag[i]=0;
		}
		joker++;
		
	}
	printf("���˿�ͷ����û�ˣ���ҷŹ�����\n"); 

return 0;
}

