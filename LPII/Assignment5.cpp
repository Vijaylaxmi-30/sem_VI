#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class GreedyAlgorithms
{
public:

    // ---------------- SELECTION SORT ----------------
    void selectionSort()
    {
        int n;

        cout << "\nEnter number of elements: ";
        cin >> n;

        vector<int> arr(n);

        cout << "Enter elements:\n";

        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        // Selection Sort Logic
        for(int i = 0; i < n - 1; i++)
        {
            int minIndex = i;

            for(int j = i + 1; j < n; j++)
            {
                if(arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }

            // Swap
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }

        cout << "\nSorted Array:\n";

        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // ---------------- PRIM'S MST ----------------
    void primMST()
    {
        int n;

        cout << "\nEnter number of vertices: ";
        cin >> n;

        vector<vector<int>> graph(n, vector<int>(n));

        cout << "Enter adjacency matrix:\n";

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> graph[i][j];
            }
        }

        vector<int> key(n, INT_MAX);
        vector<bool> mstSet(n, false);
        vector<int> parent(n);

        key[0] = 0;
        parent[0] = -1;

        for(int count = 0; count < n - 1; count++)
        {
            int min = INT_MAX;
            int u;

            // Find minimum key vertex
            for(int v = 0; v < n; v++)
            {
                if(mstSet[v] == false && key[v] < min)
                {
                    min = key[v];
                    u = v;
                }
            }

            mstSet[u] = true;

            // Update adjacent vertices
            for(int v = 0; v < n; v++)
            {
                if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        cout << "\nEdges in Minimum Spanning Tree:\n";

        int totalCost = 0;

        for(int i = 1; i < n; i++)
        {
            cout << parent[i] << " - " << i
                 << "  Weight = " << graph[i][parent[i]] << endl;

            totalCost += graph[i][parent[i]];
        }

        cout << "Total Cost = " << totalCost << endl;
    }

    // ---------------- DIJKSTRA ----------------
    void dijkstra()
    {
        int n;

        cout << "\nEnter number of vertices: ";
        cin >> n;

        vector<vector<int>> graph(n, vector<int>(n));

        cout << "Enter adjacency matrix:\n";

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> graph[i][j];
            }
        }

        int source;

        cout << "Enter source vertex: ";
        cin >> source;

        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        dist[source] = 0;

        for(int count = 0; count < n - 1; count++)
        {
            int min = INT_MAX;
            int u;

            // Find minimum distance vertex
            for(int v = 0; v < n; v++)
            {
                if(!visited[v] && dist[v] <= min)
                {
                    min = dist[v];
                    u = v;
                }
            }

            visited[u] = true;

            // Update distances
            for(int v = 0; v < n; v++)
            {
                if(!visited[v] &&
                   graph[u][v] &&
                   dist[u] != INT_MAX &&
                   dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        cout << "\nShortest distances from source vertex " << source << ":\n";

        for(int i = 0; i < n; i++)
        {
            cout << "Vertex " << i << " -> " << dist[i] << endl;
        }
    }
};

// ---------------- MAIN FUNCTION ----------------
int main()
{
    GreedyAlgorithms obj;

    int choice;

    do
    {
        cout << "\n========== GREEDY ALGORITHMS ==========\n";
        cout << "1. Selection Sort\n";
        cout << "2. Prim's Minimum Spanning Tree\n";
        cout << "3. Dijkstra Shortest Path\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                obj.selectionSort();
                break;

            case 2:
                obj.primMST();
                break;

            case 3:
                obj.dijkstra();
                break;

            case 4:
                cout << "\nProgram Exited.\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}