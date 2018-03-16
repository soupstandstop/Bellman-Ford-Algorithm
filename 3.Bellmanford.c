#include<stdio.h>
#include<stdlib.h>

#define node_range 51  
#define edge_range 201  

int edge[edge_range][3]; 
int dis[node_range]={0},node_p[node_range]={0}; 
int node_num=0,edge_num=0,source=0; 
bool neg_circle=false;  
void BellmanFord();  

int main()
{
	for(int i=0;i<node_range;i++)
		dis[i]=10000; //source至各點的最短路徑長，初值為無限大

	scanf("%d%d",&node_num,&edge_num); 

	for(int i=1;i<=edge_num;i++)
		scanf("%d%d%d",&edge[i][0],&edge[i][1],&edge[i][2]); 

	scanf("%d",&source); 

	BellmanFord();  

	if(neg_circle==true)  
		printf("There is a negative weight circle in the graph\n");
	else
	{
	    printf("\n");
	    for(int i=1;i<=node_num;i++)
	    	printf("%d ",dis[i]);
	    printf("\n");  

	    for(int i=1;i<=node_num;i++)
		    printf("%d ",node_p[i]);
	    printf("\n");  
	}

	system("pause");
	return 0;
}

void BellmanFord()
{
	dis[source]=0; //s至s的距離為0
	node_p[source]=0;  //s的父點為0

	int c_loop=0; 
	while(c_loop!=node_num-1)  
	{
		for(int i=1;i<=edge_num;i++)  
		{
			if(dis[edge[i][1]]>dis[edge[i][0]]+edge[i][2])  
			{
				dis[edge[i][1]] = dis[edge[i][0]]+edge[i][2];  
				node_p[edge[i][1]] = edge[i][0];  
			}
		}

		c_loop++;  
	}
	for(int i=1;i<=edge_num;i++)
	{
		if(dis[edge[i][1]]>dis[edge[i][0]]+edge[i][2])  
		{
			neg_circle=true;
			break;
		}
	}
}//因為dis[edge[i][1]]都已更新完畢，所以如果繼續更新發現dis的值還會繼續更新變小，那就代表有負cycle
