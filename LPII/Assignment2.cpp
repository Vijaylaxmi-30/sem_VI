#include <iostream>
using namespace std;

int cost[10][10], heuristic[10];
int open[10], closed[10];
int n;

// Function to find node with minimum cost
int minNode()
{
    int min = 999;
    int index = -1;

    for(int i = 0; i < n; i++)
    {
        if(closed[i] == 0 && open[i] < min)
        {
            min = open[i];
            index = i;
        }
    }

    return index;
}

// A* Algorithm
void astar(int start, int goal)
{
    // Initialize arrays
    for(int i = 0; i < n; i++)
    {
        open[i] = 999;
        closed[i] = 0;
    }

    // Starting node
    open[start] = heuristic[start];

    while(true)
    {
        int current = minNode();

        // No path found
        if(current == -1)
        {
            cout << "\nPath not found!";
            return;
        }

        // Print current node
        cout << current << " ";

        // Goal reached
        if(current == goal)
        {
            cout << "\nGoal reached!";
            return;
        }

        // Mark visited
        closed[current] = 1;

        // Remove from open list
        open[current] = 999;

        // Check neighbors
        for(int i = 0; i < n; i++)
        {
            if(cost[current][i] != 0 && closed[i] == 0)
            {
                open[i] = cost[current][i] + heuristic[i];
            }
        }
    }
}

int main()
{
    int choice = 0;

    while(choice != 3)
    {
        cout << "\n\n--- A* Menu ---";
        cout << "\n1. Enter Graph";
        cout << "\n2. Run A*";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";

        cin >> choice;

        switch(choice)
        {
            case 1:

                cout << "\nEnter number of nodes: ";
                cin >> n;

                cout << "\nEnter cost matrix:\n";

                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        cin >> cost[i][j];
                    }
                }

                cout << "\nEnter heuristic values:\n";

                for(int i = 0; i < n; i++)
                {
                    cin >> heuristic[i];
                }

                break;

            case 2:

                int start, goal;

                cout << "\nEnter start node: ";
                cin >> start;

                cout << "Enter goal node: ";
                cin >> goal;

                cout << "\nPath: ";

                astar(start, goal);

                break;

            case 3:

                cout << "\nProgram Ended!";
                break;

            default:

                cout << "\nInvalid Choice!";
        }
    }

    return 0;
}