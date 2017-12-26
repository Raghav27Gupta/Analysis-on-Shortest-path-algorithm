#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include"grap.h"
#include <graphics.h>
#define INF 999999  //Number of stations

static int N;
int SPR(int sr,int dst,int fg);
int JHON (int src,int dest,int fg);
int dijkstra(int startnode,int lnode,int fg);
int FW(int s,int d, int fw);
void display_stations();
void Avg();
void execute();
int new_graph();
void bar_graph();
int check_user();
int authenticate();
void bargraph();
void t_calc();
int src,dest,lk=0,count=0,cost[50][50][2],bar_dis[4],bar_hr[4],bar_nd[4];
double t_spr[100],t_john[100],t_fw[100],t_dj[100];
double Tspr=0.0,Tjohn=0.0,Tfw=0.0,Tdj=0.0;
char destinations[50][50]=	 {
    "Mumbai","Delhi","Bangalore","Hyderabad","Ahemdabad","Chennai","Kolkata","Surat","Pune","Jaipur",
 "Lucknow","Nagpur","Kanpur","Satna","Indore","Thane","Bhopal","Chinchawad","Patna","Vadodara",
 "Ghaziabad","Ludhiana","Coimbatore","Agra","Madhurai","Nasik","Faridabad","Meerut","Rajkot","Varanasi",
 "Allahabad","Ranchi","Jabalpur","Jodhpur","Chattisgarh","Aligarh","Lucknowcity","Saharanpur","Dehradun","Jammu",
 "Udaipur","Rewadi","Mathura","Bihar","Hapur","New Delhi","Shimla","Guna","Vellore","Churu"
                                 };
int main(int argc, char **argv)
{
	system("clear");
    int z;
    for(z=0;z<4;z++)
    {
        bar_nd[z]=1;
    }
    int x,i,j,k;
    printf("\n***********************************************************************************************\n");
    printf("\nWelcome to the analysis of various Algorithm for ROUTE OPTIMIZATION\n");
    printf("Under the supervision of Ms. SHAHINA ANWARUL\\ Assistant Professor Department of Cyber Platform\n");
    printf("\n***********************************************************************************************\n");
    x=check_user();

    if(x==2)
     {   N=50;
         //pred=malloc(sizeof(int)*N);
	     for (i = 0; i < N; i++)
          for (j = 0; j < N; j++)
           for (k = 0; k < 2; k++)
		    cost[i][j][k]=p_graph[i][j][k];
     }

 	 i=1;
 	 while(i==1)
     {
        //Repeating process for searching
 		execute();
 		printf("\nPress 1 to test again \n");
 		scanf("%d",&i);
		lk++;

 	}
    Avg();
    return 0;
}
//function used to repeat the process of searching routes
void execute()
{
        
        printf("Enter Source number \n");
        scanf("%d",&src);
        printf("Enter Destination number \n");
        scanf("%d",&dest);
        src=src-1;
        dest=dest-1;
        printf("%d \t >>\t %d \n",src+1,dest+1);

        dijkstra(src,dest,1);
          printf("\n");
        JHON(src,dest,1);
          printf("\n");
        FW(src,dest,1);
          printf("\n");
        SPR(src,dest,1);
          printf("\n");

        t_calc();
}

int new_graph()
{

	int edges;
        int u,v,w,t;
        int i,k,j;

    printf("Enter vertices(Max 50) & edges:\n");
    scanf("%d%d",&N,&edges);

    for(i=0;i<N;i++)
     for(j=0;j<N;j++)
      for(k=0;k<2;k++)
       {  if(i==j)
            {
              cost[i][j][k] = 0;
            }
            else
            cost[i][j][k] = INF;
       }
    printf("Enter source destination distance time\n");
    for(i=0;i<edges;i++)
     {
        scanf("%d%d%d%d", &u, &v, &w,&t);
        // For undirected edge (u,v) = (v,u)
        cost[u-1][v-1][0] = cost[v-1][u-1][0] = w;
        cost[u-1][v-1][1] = cost[v-1][u-1][1] = t;
    }
}

int check_user()
{
  int chk,x,y,i,j,k;
  start:

	printf("\nEnter 1 for Administrator rights and 2 for Normal User\n");
	scanf("%d",&chk);
	switch(chk)
	{
		case 1:
			x=authenticate();
			if(x==1);
                       {
                            printf("\nEnter \n1. For Your graph \n2. Predefined graph\n");
                            scanf("%d",&y);
			    if(y==1)
				new_graph();
                             if(y==2)
                               return 2;

			 }
			break;
		case 2:
		       display_stations();
                        return 2;
			break;
		default:
			goto start;
    }
}

int authenticate()
{
	if(count==3)
	{
		printf("You have used all your attempts\n");
		printf("The program will end now\n");
		exit(0);
	}
        char uname[10],pass[10]="raghav",pass_scan[10];
	printf("\nEnter the Username\n");
	scanf("%s",&uname);
	printf("enter the password\n");
	scanf("%s",&pass_scan);

    if(strcmp(pass,pass_scan)!=0)
    {
        printf("\n Wrong Password.\n");
        printf("\nEnter password again\n");
	count++;
	authenticate();

    }
    else
    {
            printf("\nSuccessful login\n");
	    return 1;
    }

}
void Avg()
{
//avg. time for each algorithm for 90 test case
    int j,i;
    lk=0;
    for(j=1;j<=10;j++)
    {
    	for(i=1;i<=10;i++)
        {
		if(i!=j)//we are not checking for source=destination
		{
		int dj = dijkstra(j,i,2);
                int jhon = JHON(j,i,2);
       	        int fw = FW(j,i,2);
		int spr = SPR(j,i,2);
		Tspr+=t_spr[lk];
		Tdj+=t_dj[lk];
		Tjohn+=t_john[lk];
		Tfw+=t_fw[lk];
		lk++;
		}
    	}
    }
    Tspr=Tspr/90;
    Tdj=Tdj/90;
    Tjohn=Tjohn/90;
    Tfw=Tfw/90;
    printf("\nAverage time req. by algo(after several comparisions) =");
    printf("\nDJ = %lf sec",Tdj/CLOCKS_PER_SEC);
    printf("\nJohn = %lf sec",Tjohn/CLOCKS_PER_SEC);
    printf("\nFW = %lf sec",Tfw/CLOCKS_PER_SEC);
    printf("\nSPR = %lf sec\n",1+Tspr/CLOCKS_PER_SEC);
    sleep(5);
    bargraph();
    bar_graph();
}
void t_calc()
{
    printf("\nTime req. by algo =");
    printf("\nDJ = %lf sec",t_dj[lk]/CLOCKS_PER_SEC);
    printf("\nJohn = %lf sec",t_john[lk]/CLOCKS_PER_SEC);
    printf("\nFW = %lf sec",t_fw[lk]/CLOCKS_PER_SEC);
    printf("\nSPR = %lf sec\n",t_spr[lk]/CLOCKS_PER_SEC);
}
void display_stations()
{
    printf("Select Source and Destination from the list of cities");
    printf("Please enter 'CORRESPONDING NUMBER' against the city.\n");
    printf("\t1. Mumbai\t2. Delhi\t3. Bangalore\t4. Hyderabad\t5. Ahemdabad\n\t6. Chennai\t7. Kolkata\t8. Surat\t9. Pune\t\t10. Jaipur\n\t11. Lucknow\t12. Nagpur\t13. Kanpur\t14. Satna\t15. Indore\n\t16. Thane\t17. Bhopal\t18. Chinchwad\t19. Patna\t20. Vadodara\n\t21. Ghaziabad\t22. Ludhiana\t23. Coimbatore\t24. Agra\t25. Madhurai\n");
    printf("\t26. Nasik\t27. Faridabad\t28. Meerut\t29. Rajkot\t30. Varanasi\n\t31. Allahabad\t32. Ranchi\t33. Jabalpur\t34. Jodhpur\t35. Chandigarh\n\t36. Aligarh\t37. Lucknowcity\t38. Saharanpur\t39. Dehradun\t40. Jammu\n\t41. Udaipur\t42. Rewadi\t43. Mathura\t44. Bihar\t45. Hapur\n\t46. New Delhi\t47. Shimla\t48. Guna\t49. Vellore\t50. Churu\n");
}

// A recursive fn. to find the shortest path from source to destination
int SPR(int sr,int dst,int fg)
{    int m=0;
    clock_t start,end;
    start = clock();
    void swap()
    {
        int temp;
        temp=sr;
        sr=dst;
        dst=temp;
    }
    int minCostRec(int s, int d)
    {
	// If source is same as destination
	// or destination is next to source
        if ((s == d) || ((s+1) == d))
        {
            return cost[s][d][0];
        }
       int min = cost[s][d][0];

    // Try every intermediate vertex to find minimum

	    int i;
        for(i = s+1; i<d; i++)
        {
            int c = minCostRec(s, i) + minCostRec(i, d);
            if (c < min)
            {
                min = c;
            }
        }

        return min;
    }
    if(sr>dst)
    {
        swap();
    }

// This function returns the smallest possible cost to
// reach station N-1 from station 0. This function mainly
// uses minCostRec().

   m=minCostRec(sr,dst);
   if(fg==1)
         {
           bar_dis[0]=m;
           printf("Using SPR from %s to %s :\n ",destinations[src],destinations[dest]);
           printf("\tDistance: %d\n",m);
           //path(src,dest);
           //printf("\tPath:\n\tTime required:");
           bar_hr[0]=100;
         }
         end = clock();
        t_spr[lk]=end-start;
}
int JHON (int src, int dest, int fg)
{
  int i, j,k, source, source_n, destination, adjacencyMatrix[N][N][2],potential[N+2],result[N+1];
  int pre[N+1];
  clock_t start, end;
  start = clock ();
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
        for (k = 0; k < 2; k++)
    adjacencyMatrix[i][j][k] = cost[i][j][k];
  source_n = N + 1;
  int augmentedMatrix[N + 2][N + 2][2];
  int allPairShortestPath[N + 1][N + 1][2];
 int path(int startnode, int lnode)
   {
        int i,j,k,m=1,a[N],sum=0;
         for(i=0;i<N;i++)
             a[i]=-1;
             a[0]=lnode+1;
    printf("\tPath: %d", lnode+1);
    j=lnode+1;
    do
    {
        j=pre[j];
        printf(" <-%d", j);
        a[m]=j;
        m++;
    }
    while(j!=startnode+1);
    printf("\n\t");
    printf("Time required: ");
    for(i=0;i<N-1;i++)
    {
        j=a[i];
        k=a[i+1];
        if(a[i+1]==-1)
          break;
      sum+=cost[j-1][k-1][1];
      bar_nd[2]++;
    }
    printf("%d hours\n",sum);
    bar_hr[2]=sum;
  }

  int bellmanFord (int source, int adjacencymatrix[N + 2][N + 2][2])
  {
    int numberofvertices =N+1, distances[N+2], node, sourcenode, destinationnode;


    {
      for (node = 1; node <= numberofvertices; node++)
	{
	  distances[node] = INF;
	}

      distances[source] = 0;

      for (node = 1; node <= numberofvertices - 1; node++)
	{
	  for (sourcenode = 1; sourcenode <= numberofvertices; sourcenode++)
	    {
	      for (destinationnode = 1; destinationnode <= numberofvertices;
		   destinationnode++)
		{
		  if (adjacencymatrix[sourcenode][destinationnode][0] != INF)
		    {
		      if (distances[destinationnode] > distances[sourcenode]
			  + adjacencymatrix[sourcenode][destinationnode][0])
			{
			  distances[destinationnode] = distances[sourcenode]
			    + adjacencymatrix[sourcenode][destinationnode][0];
			}
		    }
		}
	    }
	}

    /*  for (sourcenode = 1; sourcenode <= numberofvertices; sourcenode++)
	{
	  for (destinationnode = 1; destinationnode <= numberofvertices;
	       destinationnode++)
	    {
	      if (adjacencymatrix[sourcenode][destinationnode][0] != INF)
		{
		  if (distances[destinationnode] > distances[sourcenode]
		      + adjacencymatrix[sourcenode][destinationnode][0])
		  printf ("\nThe Graph contains negative egde cycle");
		}
	    }
	   }   */
    }

    for (i = 0; i < N+2; i++)
      {
	potential[i] = distances[i];
      }
  }

  int DJ (int startnode, int G[N + 1][N + 1][2])
  {

    int cos[N + 1][N + 1][2], distance[N + 1];
    int visited[N + 1], count, mindistance, nextnode, i, j;
    for (i = 0; i < N + 1; i++)
      for (j = 0; j < N + 1; j++)
	if (G[i][j][0] == 0)
	  {cos[i][j][0] = INF;
           cos[i][j][1] = INF;
          }
	else
	  { cos[i][j][0] = G[i][j][0];
            cos[i][j][1] = G[i][j][1];
          }
    for (i = 0; i < N + 1; i++)
      {
	distance[i] = cos[startnode][i][0];
	if(startnode==src+1)
	pre[i] = startnode;
	visited[i] = 0;
      }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while (count < N)
      {
	mindistance = INF;
	for (i = 0; i < N + 1; i++)
	  if (distance[i] < mindistance && !visited[i])
	    {
	      mindistance = distance[i];
	      nextnode = i;
	    }
	visited[nextnode] = 1;
	for (i = 0; i < N + 1; i++)
	  if (!visited[i])
	    if (mindistance + cos[nextnode][i][0] < distance[i])
	      {
		distance[i] = mindistance + cos[nextnode][i][0];
		if(startnode==src+1)
		pre[i] = nextnode;
	      }
	count++;
      }
    for (i = 0; i < N+1; i++)
      {
	result[i] = distance[i];
      }
  }
  // adding one new node
  for (i = 0; i <= N; i++)
    {augmentedMatrix[i][0][0] = 0;
     augmentedMatrix[i][0][1] = 0;
    }
  for (i = 0; i <= N; i++)
    {augmentedMatrix[0][i][0] = 0;
     augmentedMatrix[0][i][1] = 0;
    }
  for (source = 1; source <= N; source++)
    {
      for (destination = 1; destination <= N; destination++)
	{
	  if (source == 0 || destination == 0)
	    augmentedMatrix[source][destination][0] = 0;
	  else
	    augmentedMatrix[source][destination][0] =
	      adjacencyMatrix[source - 1][destination - 1][0];
	}
    }
  for (destination = 1; destination <= N; destination++)
    {
      augmentedMatrix[source_n][destination][0] = 0;
    }


  bellmanFord (source_n, augmentedMatrix);


  int reweightGraph[N + 1][N + 1][2];
  for (i = 0; i <= N; i++)
    {reweightGraph[i][0][0] = 0;
     reweightGraph[i][0][1] = 0;
    }
  for (i = 0; i <= N; i++)
    {reweightGraph[0][i][0] = 0;
     reweightGraph[0][i][1] = 0;
    }
  for (source = 1; source <= N; source++)
    {
      for (destination = 1; destination <= N; destination++)
	{
	  if (source == 0 || destination == 0)
	    reweightGraph[source][destination][0] = 0;
	  else
	    reweightGraph[source][destination][0] =
	      adjacencyMatrix[source - 1][destination - 1][0] +
	      potential[source] - potential[destination];
	}
    }

  for (source = 1; source <= N; source++)
    {
      DJ (source, reweightGraph);
      for (destination = 1; destination <= N; destination++)
	{
	  allPairShortestPath[source][destination][0] = result[destination]
	    + potential[destination] - potential[source];

	}
    }
    if(fg==1)
    {
    printf("Using Johnson's algorithm from %s to %s :\n ",destinations[src],destinations[dest]);
    printf("\tDistance: %d\n",allPairShortestPath[src + 1][dest + 1][0]);
    bar_dis[2]=allPairShortestPath[src + 1][dest + 1][0];
    path(src,dest);
    }
  end = clock ();
  t_john[lk] = end - start;
}

int FW (int s, int d, int fg)    // s=>source   d=>destination
{
int next[N][N][N],flg=0,arr[N],fw_c=0,a[N],sum=0;
int i, j, k,cst[N][N][2];
// Initialize the solution matrix same as input graph matrix.
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
     for (k = 0; k < 2; k++)
       cst[i][j][k] = cost[i][j][k];
       for(i=0;i<N;i++)
             a[i]=-1;

        int fw_path(int P[][N][N],int i,int j)
        {
        if(i == j)
         {
                arr[fw_c]=i;
                fw_c++;
         }
        else if(next[i][j][0] == INF){
                flg=1;
                printf("no path exists");}
        else
         {
                fw_path(P, i, P[i][j][0]);
                arr[fw_c]=j;
                fw_c++;
         }

        }


  clock_t start, end;
  start = clock ();

      for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if(cst[i][j][0] == INF)
                next[i][j][0] = INF;
            else
                next[i][j][0] =i;

  for (k = 0; k < N; k++)
    {
      for (i = 0; i < N; i++)
	{
	  for (j = 0; j < N; j++)
	    {
	      if ((cst[i][k][0] * cst[k][j][0] != 0) && (i != j))
		{
		  if ((cst[i][k][0] + cst[k][j][0] < cst[i][j][0]) || (cst[i][j][0] == 0))
		    {
		      cst[i][j][0] = cst[i][k][0] + cst[k][j][0];
		      next[i][j][0] = next[k][j][0];
		    }
		}
	    }
	}
    }
    if(fg==1)
    { int x=0;
      printf("Using Floyd Warshall from %s to %s :\n ",destinations[src],destinations[dest]);
      printf("\tDistance: %d",cst[s][d][0]);
      printf("\n\tPath: ");
      bar_dis[3]=cst[s][d][0];
      fw_path(next,s,d);
      int i;
      for(i=0;i<N;i++)
        arr[i]=arr[i]+1;
      for(i=fw_c-1;i>0;i--)
       {
         printf("%d <-",arr[i]);
         a[x]=arr[i];
         x++;
       }
      if(flg!=1)
       {
        printf("%d",s+1);
        a[x]=s+1;
        x++;
       }
      for(i=0;i<N-2;i++)
      {
        j=a[i];
        k=a[i+1];
        if(a[i+1]==-1)
          break;
        sum+=cost[j-1][k-1][1];
        bar_nd[3]++;
      }
      printf("\n\tTime required: %d hours\n",sum);
      bar_hr[3]=sum;
    }
  end = clock ();
  t_fw[lk] = end - start;
}
int dijkstra (int startnode, int lnode,int fg)
{
  int G[N][N][2], distance[N],pred[N];
  int visited[N], count, mindistance, nextnode, i, j;
  clock_t start, end;
  start = clock ();

  int path()
   {
        int i,j,k,m=1,a[N],sum=0;
         for(i=0;i<N;i++)
             a[i]=-1;
             a[0]=lnode+1;
    printf("\n\tPath: %d", lnode+1);
    j=lnode;
    do
    {
        j=pred[j];
        printf(" <-%d", j+1);
        a[m]=j+1;
        m++;
    }
    while(j!=startnode);
    printf("\n\t");
    printf("Time required: ");
    for(i=0;i<N-2;i++)
    {
        j=a[i];
        k=a[i+1];
        if(a[i+1]==-1)
          break;
      sum+=cost[j-1][k-1][1];
      bar_nd[1]++;
    }
    printf("%d hours\n",sum);
    bar_hr[1]=sum;

  }
//creating cost matrix
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      if (cost[i][j][0] == 0)
	G[i][j][0] = INF;
      else
	G[i][j][0] = cost[i][j][0];
//pred[] stores the predecessor of each node
//initialize pred[],distance[] and visited[]
  for (i = 0; i < N; i++)
    {
      distance[i] = G[startnode][i][0];
      pred[i] = startnode;
      visited[i] = 0;
    }
  distance[startnode] = 0;
  visited[startnode] = 1;
    //count gives the number of nodes seen so far
  count = 1;
  while (count < N - 1)
    {
      mindistance = INF;
	//nextnode provides the node at minimum distance
      for (i = 0; i < N; i++)
	if (distance[i] < mindistance && !visited[i])
	  {
	    mindistance = distance[i];
	    nextnode = i;
	  }
	//checking if a better path exists through nextnode
      visited[nextnode] = 1;
      for (i = 0; i < N; i++)
	if (!visited[i])
	  if (mindistance + G[nextnode][i][0] < distance[i])
	    {
	      distance[i] = mindistance + G[nextnode][i][0];
	      pred[i] = nextnode;
	    }
      count++;
    }
    if(fg==1)
    {
    printf("Using Dijkstra's from %s to %s :\n ",destinations[src],destinations[dest]);
    bar_dis[1]=distance[lnode];
    printf("\tDistance: %d",distance[lnode]);
    path();
    }
  end = clock ();
  t_dj[lk] = end - start;


}

//Function used to show the Bar graph for different algorithm
void bargraph()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "X:\\TC\\BGI");
   //init graph(graph driver,graphmode,path driver)

   outtextxy(255,10,"BAR GRAPH-COMPUTATIONAL TIME");
   setcolor(9);//LIGHTBLUE

   line(90,410,90,50); //line(x1,y1,x2,y2) draw line from x1,y1 to x2,y2
   line(90,410,590,410);
   line(85,60,90,50);
   line(95,60,90,50);
   line(585,405,590,410);
   line(585,415,590,410);

//print text on screen in graphic mode whiile printf print text in text mode
   outtextxy(50,60,"TIME");//outtextxy(x_coordinate,y_coordinate,TEXT)
   outtextxy(500,420,"ALGORITHMS");
   outtextxy(150,415,"SPR");
   outtextxy(225,415,"DIJKSTRA");
   outtextxy(300,415,"JOHNSON");
   outtextxy(375,415,"FLOYD");
   outtextxy(70,415,"O");

   setcolor(11);//LIGHTCYAN
/* void bar3d(x coordinate on upper left, y coordinate on upper left,
x coordinate on lower right,y coordinate on lower right, bar depth,
top portion of flag is shown or not) */
   bar3d(150,100,200,410,15,1);
   bar3d(225,400,275,410,15,1);
   bar3d(300,350,350,410,15,1);
   bar3d(375,300,425,410,15,1);

   sleep(15);
   closegraph();
}

void bar_graph()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "X:\\TC\\BGI");

   outtextxy(275,10,"BAR GRAPH");
   line(90,410,90,50);
   line(90,410,590,410);
   line(85,60,90,50);
   line(95,60,90,50);
   line(585,405,590,410);
   line(585,415,590,410);

   outtextxy(456,70,"DISTANCE");
   outtextxy(455,80,"HOURS");
   outtextxy(455,90,"NO. OF NODES");
   outtextxy(520,420,"ALGORITHMS");
   outtextxy(150,415,"SPR");
   outtextxy(245,415,"DIJKSTRA");
   outtextxy(340,415,"JOHNSON");
   outtextxy(435,415,"FLOYD");
   outtextxy(70,415,"O");

   int max=0,max_flg=0,mhr=0,fghr=0;
   int i;
   for(i=0;i<4;i++)
   {
   if(max<bar_dis[i])
     {
        max=bar_dis[i];
        max_flg=i;
     }
   if(mhr<bar_hr[i])
     {
   	mhr=bar_hr[i];
   	mhr=i;
     }
   }
   for(i=0;i<4;i++)
   {
   if(max_flg==i)
     {
        bar_dis[i]=-10;
     }
   if(mhr==i)
     {
        bar_hr[i]=-5;
     }
   }
   setcolor(4);//RED
   bar(431,70,436,80);
   bar3d(150,300+bar_dis[0],165,410,15,1);
   bar3d(245,300+bar_dis[1],260,410,15,1);//400
   bar3d(340,300+bar_dis[2],355,410,15,1);//350
   bar3d(435,300+bar_dis[3],450,410,15,1);//300
   setcolor(1);//BLUE
   bar(430,80,435,90);
   bar3d(170,bar_hr[0],185,410,15,1);//100
   bar3d(265,250+bar_hr[1],280,410,15,1);//400
   bar3d(360,250+bar_hr[2],375,410,15,1);//350
   bar3d(455,250+bar_hr[3],470,410,15,1);//300
   setcolor(14);//YELLOW
   bar(430,90,435,100);
   bar3d(190,355+bar_nd[0],205,410,15,1);//100
   bar3d(285,355+bar_nd[1],300,410,15,1);//400
   bar3d(380,355+bar_nd[2],395,410,15,1);//350
   bar3d(475,355+bar_nd[3],490,410,15,1);//300

   sleep(50);
   closegraph();
}
