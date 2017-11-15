#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include <graphics.h>
#define INF 999999  //Number of stations
#define N 10
int SPR(int cst[N][N][2],int sr,int dst);
int JHON (int A[N][N][2], int src, int dest);
int dijkstra(int G[N][N][2], int startnode, int lnode);
int FW(int cst[N][N][2],int s,int d);
int path(int startnode, int lnode);
void display_stations();
void Avg();
void bargraph();
void t_calc();

int src,dest,pred[N],lk=0,pt_spr=0,pt_john=0,pt_dj=0,pt_fw=0;
double t_spr[100],t_john[100],t_fw[100],t_dj[100];
double Tspr=0.0,Tjohn=0.0,Tfw=0.0,Tdj=0.0;
int cost[N][N][2] = {
            {{0,0},{8,8},{INF,INF},{INF,INF},{INF,INF},{INF,INF},{INF,INF},{INF,INF},{8,8},{INF,INF}},
            {{8,8},{0,0},{10,10},{INF,INF},{9,9},{INF,INF},{INF,INF},{INF,INF},{8,8},{INF,INF}},
            {{INF,INF},{10,10},{0,0},{3,3},{3,3},{INF,INF},{INF,INF},{INF,INF},{INF,INF},{INF,INF}},
            {{INF,INF},{INF,INF},{3,3},{0,0},{3,3},{INF,INF},{INF,INF},{INF,INF},{INF,INF},{INF,INF}},
            {{INF,INF},{9,9},{3,3},{3,3},{0,0},{7,7},{2,2},{2,2},{INF,INF},{INF,INF}},
            {{INF,INF},{INF,INF},{INF,INF},{INF,INF},{7,7},{0,0},{5,5},{INF,INF},{INF,INF},{INF,INF}},
            {{INF,INF},{INF,INF},{INF,INF},{INF,INF},{2,2},{5,5},{0,0},{12,12},{11,11},{6,6}},
            {{INF,INF},{INF,INF},{INF,INF},{INF,INF},{2,2},{INF,INF},{12,12},{0,0},{17,17},{INF,INF}},
            {{8,8},{8,8},{INF,INF},{INF,INF},{INF,INF},{INF,INF},{11,11},{17,17},{0,0},{9,9}},
            {{INF,INF},{INF,INF},{INF,INF},{INF,INF},{INF,INF},{INF,INF},{6,6},{INF,INF},{9,9},{0,0}}
        };
/*
function used to repeat the process of searching routes
*/
void execute()
{
        char destinations[20][20]={"Banglore","Chennai","Mumbai","Ahemdabad","Hyderabad","Vishakapatnam","Howrah","Guwahati","Patna","Lucknow","Meerut","Jaipur","Delhi","Dehradun"};
        display_stations();
        printf("enter Source number \n");
        scanf("%d",&src);
        printf("enter Destination number \n");
        scanf("%d",&dest);
        src=src-1;
        dest=dest-1;
        printf("%d %s\t >>\t %d %s\n",src+1,destinations[src],
        dest+1,destinations[dest]);
        /*
	Printing all the values given as output by differnt algorithms
	*/
        printf(
        "The Minimum cost to reach from %s to %s using SPR is : ",destinations[src],destinations[dest]);
        int spr = SPR(cost,src,dest);
        printf("\n%d\n",spr);
        printf("%d\n",pt_spr/xm);
        printf(
        "The Minimum cost to reach from %s to %s using Dijkstra's is : ",destinations[src],destinations[dest]);
        int dj=dijkstra(cost,src,dest);
        printf("\n%d\n",dj);
        printf(
        "The Minimum cost to reach from %s to %s using Johnson is : ",destinations[src],destinations[dest]);
        int jhon = JHON(cost,src,dest);
        printf("\n%d\n",jhon);
        printf(
        "The Minimum cost to reach from %s to %s using Floyd Warshall is : ",destinations[src],destinations[dest]);
        int fw = FW(cost,src,dest);
        printf("\n%d\n",fw);
        printf(
        "Path for minimum distance is : ");
        path(src,dest);

        t_calc();

}
void authenticate()
{
    char uname[10],pass[10]="raghav",pass_scan[10];
	printf("Enter the Username and Password to continue...\n");
	scanf("%c%c",&uname,&pass_scan);
	authenticate(uname,pass);
    if(strcmp(pass,pass_scan)!=0)
    {
        printf("\n Wrong Password.\n");
        printf("\nenter password again\n");
        authenticate();

    }
    else
    {
            printf("\nsuccessful login\n");
    }

}


int main(int argc, char **argv)
{

    authenticate();

    printf("*****************************************************************\n");
    printf("Welcome to the analysis of various Algorithm for ROUTE OPTIMIZATION\n");
    printf("Under the supervision of Ms. SHAHINA ANWARUL\\ Assistant Professor Department of Cyber Platform\n");
    printf("*****************************************************************\n");

 	int i=1;
 	while(i==1)
    {
        /*
        Repeating process for searching
        */
 		execute();
 		printf("\nPress 1 to test again \n");
 		scanf("%d",&i);
		lk++;
 	}
    Avg();
    return 0;
}
void Avg()
{
    /*
    to Calculate average time taken by each algorithm for each test case possible
    */
    int j,i;

        //calculating time for 90 test cases
    lk=0;
    for(j=1;j<=10;j++)
    {
    	for(i=1;i<=10;i++)
        {
		if(i!=j)//we are not checking for source=destination
		{
		int spr = SPR(cost,j,i);
		int dj = dijkstra(cost,j,i);
        	int jhon = JHON(cost,j,i);
        	int fw = FW(cost,j,i);
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
    printf("\nAverage time req. by algo(after 100 comparisions) =");
    printf("\nSPR = %lf msec",Tspr);
    printf("\nDJ = %lf msec",Tdj);
    printf("\nJohn = %lf msec",Tjohn);
    printf("\nFW = %lf msec\n",Tfw);
    sleep(5);
    bargraph();
}
void t_calc()
{
    printf("\nTime req. by algo =");
    printf("\nSPR = %lf msec",t_spr[lk]);
    printf("\nDJ = %lf msec",t_dj[lk]);
    printf("\nJohn = %lf msec",t_john[lk]);
    printf("\nFW = %lf msec\n",t_fw[lk]);
}
void display_stations()
{
    printf("Select Source and Destination from the list of cities\n");
    printf("Please enter 'CORRESPONDING NUMBER' against the city.\n");
    printf("\t\t1. Banglore\n");
    printf("\t\t2. Chennai\n");
    printf("\t\t3. Mumbai\n");
    printf("\t\t4. Ahemdabad\n");
    printf("\t\t5. Hyderabad\n");
    printf("\t\t6. Vishakapatnam\n");
    printf("\t\t7. Howrah\n");
    printf("\t\t8. Guwahati\n");
    printf("\t\t9. Patna\n");
    printf("\t\t10. Lucknow\n");
}
/*
 A recursive function to find the shortest path from
 source 's' to destination 'd'.
*/
int SPR(int cst[N][N][2],int sr,int dst)
{
    clock_t start,end;
    start = clock();
    void swap()
    {
        /*
    if the source number is greater than destination number
    SWAPPING THE VALUES
	*/
        int temp;
        temp=sr;
        sr=dst;
        dst=temp;
    }
    int minCostRec(int cost[N][N][2], int s, int d)
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
            int c = minCostRec(cost, s, i) + minCostRec(cost, i, d);
            if (c < min)
            {
                min = c;
            }
        }
        end = clock();
        t_spr[lk]=end-start;
        return min;
    }
    if(sr>dst)
    {
        swap();
    }
    /*
// This function returns the smallest possible cost to
// reach station N-1 from station 0. This function mainly
// uses minCostRec().
*/

    return minCostRec(cst,sr,dst);
}
int JHON (int A[N][N][2], int src, int dest)
{
  int i, j,k, source, source_n, destination, adjacencyMatrix[N][N][2],potential[N+2],result[N+1];
  clock_t start, end;
  start = clock ();
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
        for (k = 0; k < 2; k++)
    adjacencyMatrix[i][j][k] = A[i][j][k];
  source_n = N + 1;
  int augmentedMatrix[N + 2][N + 2][2];
  int allPairShortestPath[N + 1][N + 1][2];

  int bellmanFord (int source, int adjacencymatrix[N + 2][N + 2][2])
  {
    int numberofvertices =11, distances[12], node, sourcenode, destinationnode;


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

      for (sourcenode = 1; sourcenode <= numberofvertices; sourcenode++)
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
	}
    }

    for (i = 0; i < 12; i++)
      {
	potential[i] = distances[i];
      }
  }

  int DJ (int startnode, int G[N + 1][N + 1][2])
  {

    int cost[N + 1][N + 1][2], distance[N + 1];
    int visited[N + 1], count, mindistance, nextnode, i, j;
    for (i = 0; i < N + 1; i++)
      for (j = 0; j < N + 1; j++)
	if (G[i][j][0] == 0)
	  {cost[i][j][0] = INF;
           cost[i][j][1] = INF;
          }
	else
	  { cost[i][j][0] = G[i][j][0];
            cost[i][j][1] = G[i][j][1];
          }
    for (i = 0; i < N + 1; i++)
      {
	distance[i] = cost[startnode][i][0];
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
	    if (mindistance + cost[nextnode][i][0] < distance[i])
	      {
		distance[i] = mindistance + cost[nextnode][i][0];
	      }
	count++;
      }
    for (i = 0; i < 11; i++)
      {
	result[i] = distance[i];
      }
  }


  // computeAugmentedGraph()
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
  end = clock ();
  t_john[lk] = end - start;
  return allPairShortestPath[src + 1][dest + 1][0];
}
int FW (int ct[N][N][2], int s, int d)    // s=>source   d=>destination
{
// variables to traverse the path using the adjacency matrix cst[N][N]

  int i, j, k, cst[N][N][2];

// Initialize the solution matrix same as input graph matrix.
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
     for (k = 0; k < 2; k++)
       cst[i][j][k] = ct[i][j][k];

// define the variables of the clock

  clock_t start, end;

// clock started

  start = clock ();

//Add all vertices one by one to the set of intermediate vertices.

  for (k = 0; k < N; k++)
    {

// Pick all vertices as source one by one
      for (i = 0; i < N; i++)
	{

// Pick all vertices as destination for the above picked source
	  for (j = 0; j < N; j++)
	    {
// check if the vertices are not the same and the cost from i to k or k to j exists on the first place
	      if ((cst[i][k][0] * cst[k][j][0] != 0) && (i != j))


		{
// If vertex k is on the shortest path from i to j
		  if ((cst[i][k][0] + cst[k][j][0] < cst[i][j][0]) || (cst[i][j][0] == 0))

		    {
//then update the value of cst[i][j]
		      cst[i][j][0] = cst[i][k][0] + cst[k][j][0];
		    }
		}
	    }
	}
    }
// clock ended
  end = clock ();
// clock time calculated
  t_fw[lk] = end - start;
// returns the total cost of the path
  return cst[s][d][0];
}
int dijkstra (int G[N][N][2], int startnode, int lnode)
{
  clock_t start, end;
  start = clock ();
  int cost[N][N][2], distance[N];
  int visited[N], count, mindistance, nextnode, i, j;
	//creating cost matrix
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      if (G[i][j][0] == 0)
	cost[i][j][0] = INF;
      else
	cost[i][j][0] = G[i][j][0];
//pred[] stores the predecessor of each node
//initialize pred[],distance[] and visited[]
  for (i = 0; i < N; i++)
    {
      distance[i] = cost[startnode][i][0];
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
	  if (mindistance + cost[nextnode][i][0] < distance[i])
	    {
	      distance[i] = mindistance + cost[nextnode][i][0];
	      pred[i] = nextnode;
	    }
      count++;
    }
  end = clock ();
  t_dj[lk] = end - start;

  return distance[lnode];
}
/*
Function used to print the shotest possible path
*/
int path(int startnode, int lnode)
{        int j;
    printf("%d", lnode+1);
    j=lnode;
    do
    {
        j=pred[j];
        printf(" <-%d", j+1);
    }
    while(j!=startnode);
    printf("\n");
}
/*
Function used to show the Bar graph for different algorithm
*/
void bargraph()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "X:\\TC\\BGI");//init graph(graph driver,graphmode,path driver)

   outtextxy(275,0,"BAR GRAPH");

   setcolor(9);//LIGHTBLUE

   line(90,410,90,50);//line(x1,y1,x2,y2) draw line from x1,y1 to x2,y2
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
   bar3d(150,100,200,410,15,1);//void bar3d(x coordinate on upper left,y coordinate on upper left, x coordinate on lower right,y coordinate on lower right,int  bar depth,int top portion of flag is shown or not);
   bar3d(225,400,275,410,15,1);
   bar3d(300,350,350,410,15,1);
   bar3d(375,300,425,410,15,1);

   sleep(15);
   closegraph();
}
