/*
	Munkhtulga Batjargal
	Chapter 10
	Program #11
	
	Given an adjacency matrix of a graph and a positive integer 'n', find the number of paths of length 'n' between two vertices.
	*Produce a version that works for directed and undirected graphs.
*/

#include <string>
#include <iostream>

using namespace std;

const int h = 4; //Matrix size

//Matrix for Directed Graph
int graphDir[h][h] = { {0, 1, 1, 1},
					   {0, 0, 1, 1},
					   {0, 0, 0, 1},
					   {0, 0, 0, 0}};

//Matrix for Undirected Graph
int graphUndir[h][h] = {{0, 1, 1, 1},
					    {1, 0, 1, 1},
					    {1, 1, 0, 1},
					    {1, 1, 1, 0}};
int res[h][h];

void displayD();
void displayU();
void mult(int graphA[h][h], int graphB[h][h], int res[h][h]);

//output Directed and Undirected Graphs
void displayD()
{
	cout << "Given adjacency matrix of Directed Graph: " << endl;

	for (int i = 0; i < h; i++)		//outer
	{
		for (int j = 0; j < h; j++)		//inner 
		{
			cout << graphDir[i][j] << " ";
		}
		cout << endl;
	}

}
void displayU()
{
	cout << "Given adjacency matrix of Undirected Graph: " << endl;

	for (int i = 0; i < h; i++)		//outer
	{
		for (int j = 0; j < h; j++)		//inner 
		{
			cout << graphUndir[i][j] << " ";
		}
		cout << endl;
	}
}



//multiplication of given matrices 
void mult(int graphA[h][h], int graphB[h][h], int res[h][h])
{
	//initialize temp array to store multiplied matrix
	int temp[h][h];
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < h; j++)
		{
			temp[i][j] = 0;
			for (int k = 0; k < h; k++)
			{
				temp[i][j] += graphA[i][k] * graphB[k][j];
			}
		}
	}

	//store values of temp matrix into result matrix 
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < h; j++)
		{
			res[i][j] = temp[i][j];
		}
	}
}

int main()
{
	char dir = ' '; //input for directed/undirected
	int n, u, v; // variables for user input; n - length; u and v - vertices;

	//display given directed/undirected matrices
	displayD();
	displayU();

	// enter 'q' to quit
	while (dir != 'q')
	{
		cout << "Undirected (u) or Directed (d): ";
		cin >> dir;

		if (dir == 'u') //undirected
		{
			cout << "enter pos int for u and v: " << endl;
			cin >> u >> v;
			cout << "enter pos int n: " << endl;
			cin >> n;
			

			//if statements after the input of n and matrix 
			//NOTE: due to the size of the given matrix, and to avoid overlapping edges, 
			// 'n' must be between 0 -> 3 
			if (n < 4) 
			{
				//square matrix 
				mult(graphUndir, graphUndir, res);
				
				if (n == 1)
				{
					cout << "Number of paths of length " << n << " between vertices "
						<< u << " " << v << ": " << res[u][v] << endl;
				}

				if (res[u][v])
				{
					
					cout << "Number of paths of length " << n << " between vertices "
						<< u << " " << v << ": " << res[u][v] << endl;
				}
				
				else
				{
					cout << "no such path exist with a length of " << n << " for vertices " << u << " " << v << endl;
				}

			}
			
			else
			{
				cout << "error, n must be between 0 - > 3" << endl;
			}
			
			cout << "\n";
			
		}
		//----------------------------------------------------------------------------------------------
		//----------------------------------------------------------------------------------------------

		else if (dir == 'd') //Directed graph
		{
			
			cout << "enter pos int for u and v: " << endl;
			cin >> u >> v;
			cout << "enter pos int n: " << endl;
			cin >> n;

			//NOTE: due to the size of the given matrix, and to avoid overlapping edges, 
			// 'n' must be between 0 -> 3 

			int path = 0;

		
			if (n == 1 && graphDir[u][v] == 1) // since its limited to 0 -> 3 
			{
				path++;
				//cout << "Number of paths of given length " << n << " is " << path << endl;
			}

			if (n == 2)
			{
				for (int i = 0; i < h; i++)
				{
					if (graphDir[u][i] == 1 && graphDir[i][v] == 1)
					{
						path++; //+ 1 
					}

				}
			}

			if (n == 3)
			{
				for (int i = 0; i < h; i++)
				{
					for (int j = 0; j < h; j++)
					{
						//check if edges are adjacent 
						if (graphDir[u][i] == 1 && graphDir[i][j] == 1) 
						{
							if (graphDir[i][j] == 1 && graphDir[j][v] == 1)
								path++; 
						}
					}
				}
			}
			
			//output path result

			if (path != 0)
			{
				cout << "Number of paths of length " << n << " between vertices " << u << " " << v << " : " << path << endl;
			}
			else
			{
				cout << "no such path exist with a length of " << n << " for vertices " << u << " " << v << endl;
			}

		}
		else
		{
			cout << "wrong input!" << endl;
		}
	}


	
	return 0;
}