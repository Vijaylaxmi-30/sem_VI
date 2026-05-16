#include <iostream>
using namespace std;

int graph[10][10];
int visited[10];
int queue[10];

int n;
int front, rear;

// DFS Function
void DFS(int node)
{
    visited[node] = 1;

    cout << node << " ";

    for(int i = 0; i < n; i++)
    {
        if(graph[node][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

// BFS Function
void BFS(int start)
{
    // Reset visited array
    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    front = 0;
    rear = 0;

    queue[rear] = start;
    rear++;

    visited[start] = 1;

    while(front < rear)
    {
        int current = queue[front];
        front++;

        cout << current << " ";

        for(int i = 0; i < n; i++)
        {
            if(graph[current][i] == 1 && visited[i] == 0)
            {
                queue[rear] = i;
                rear++;

                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int choice = 0;
    int start;

    while(choice != 4)
    {
        cout << "\n\n--- GRAPH MENU ---";
        cout << "\n1. Enter Graph";
        cout << "\n2. DFS";
        cout << "\n3. BFS";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";

        cin >> choice;

        switch(choice)
        {
            case 1:

                cout << "\nEnter number of vertices: ";
                cin >> n;

                cout << "\nEnter adjacency matrix:\n";

                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        cin >> graph[i][j];
                    }
                }

                break;

            case 2:

                // Reset visited array
                for(int i = 0; i < n; i++)
                {
                    visited[i] = 0;
                }

                cout << "\nEnter starting vertex: ";
                cin >> start;

                cout << "\nDFS Traversal: ";

                DFS(start);

                break;

            case 3:

                cout << "\nEnter starting vertex: ";
                cin >> start;

                cout << "\nBFS Traversal: ";

                BFS(start);

                break;

            case 4:

                cout << "\nProgram Ended!";
                break;

            default:

                cout << "\nInvalid Choice!";
        }
    }

    return 0;
}