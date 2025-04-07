Email: yuvali532@gmail.com

# Project README

## Overview ##
This C++ project implements several graph algorithms and custom data structures without using any built-in C++ libraries such as **STL**. The goal is to explore different graph algorithms like Dijkstra, Kruskal, Prim, BFS, and DFS, while implementing all the necessary data structures manually. These data structures include stacks, queues, union-find sets, and priority queues.

In addition to the graph algorithms, the project also includes extensive test coverage using **Doctest**, a testing framework for C++.

## Graph Algorithms

# Graph Class
The `Graph` class represents a weighted graph. It allows you to:
- Add and remove edges between nodes.
- Traverse the graph using BFS and DFS algorithms.

## Graph Algorithms Implementations

#### BFS (Breadth-First Search)
The **BFS** algorithm traverses a graph level by level starting from a given node. It is implemented using a queue and explores the graph in a breadth-first manner.

#### DFS (Depth-First Search)
The **DFS** algorithm explores the graph by moving along a branch as far as possible before backtracking. It is implemented using recursion, relying on the system's stack.

#### Dijkstra's Algorithm
This **shortest path algorithm** finds the shortest path between nodes in a graph with non-negative edge weights. It uses a **priority queue** to efficiently extract the minimum cost node. 

**Note on Pointer Usage in Dijkstra**:  
In the Dijkstra implementation, I use a **pointer** to create the graph and convert it back in the `main` function before returning it. This approach was chosen because I encountered an issue where the algorithm accessed memory that was not initialized, which resulted in errors. By using a pointer, I was able to bypass this memory access issue and correctly manage the memory, thus solving the problem. The pointer is used to create a new graph during the algorithm's execution, and the graph is returned properly in the end.

#### Prim's Algorithm
Prim's algorithm finds the **Minimum Spanning Tree (MST)** of a graph. It grows the MST by always selecting the edge with the smallest weight that connects a vertex in the tree to a vertex outside the tree. This is implemented using a **priority queue**.

#### Kruskal's Algorithm
Kruskal’s algorithm also finds the **Minimum Spanning Tree (MST)** but works by sorting all the edges in increasing order of weight and adding them to the MST as long as they don't form a cycle. It uses the **Union-Find** data structure to detect cycles during the process.

## Explanation of data structures

- **Stack**: A simple stack implementation with push and pop operations. It is used to store nodes during DFS traversal.
- **Queue**: A queue implementation for BFS traversal.
- **Priority Queue**: A priority queue is used in algorithms like Dijkstra and Prim to always select the node with the smallest edge weight.
- **Union-Find (Disjoint Set)**:The Union-Find* data structure is used in Kruskal's algorithm to keep track of the connected components of the graph. It supports two operations:
*Find: Determines the root (or representative) of the set containing a particular element.
*Union: Merges two sets into one.
We employ **path compression** in the `find` function and **union by rank** in the `unionSets` function to optimize the Union-Find operations.

## Algorithm Choices and Data Structures

### Why Bubble Sort in Kruskal’s Algorithm?
Although not the most efficient sorting algorithm, **Bubble Sort** was used for simplicity in this implementation. It is primarily used for educational purposes, but for production code, more efficient sorting algorithms like **Quick Sort** or **Merge Sort** would typically be preferred.

### Why Use a Priority Queue?
A **priority queue** is used in algorithms like **Dijkstra** and **Prim** to efficiently select the next node to explore. The priority queue ensures that the algorithm always picks the node with the smallest edge weight, which is key to both the shortest path and Minimum Spanning Tree problems.

## Error Handling and Exceptions

Error handling is done using **error messages** printed to the standard error stream (`std::cerr`). For example:
- If trying to pop from an empty stack, a message is printed: `Stack underflow!`.
- If trying to add an edge to a full stack or queue, an error message is printed: `Stack overflow!`.

These checks ensure that the program behaves predictably and the user is informed when an invalid operation is attempted.

## Testing with Doctest

The project uses **Doctest** for testing various functionalities. It includes tests for:
- Basic graph operations like adding/removing edges.
- Algorithm correctness, including BFS, DFS, Dijkstra, Prim, and Kruskal.
- Custom data structures such as stacks, queues, and union-find sets.

The tests verify that each component of the project is working as expected. You can find all the tests in the `tests` folder.


## Important Notes

### No Built-in C++ Data Structures
One of the key design choices in this project is that no built-in C++ libraries or Data Structures (like STL) were used. Instead, all data structures and algorithms were implemented from scratch, which includes:
- Manual implementation of **stacks**, **queues**, **union-find**, **priority queues**.
- All sorting and searching algorithms were custom-written without using STL Data Structures.

### How the Graph and Algorithms Work in `main`
In the `main` function, you can see how the algorithms are demonstrated in action. You will find that:
- Vertices and edges are manually added to the graph.
- The algorithms (BFS, DFS, Dijkstra, Kruskal, and Prim) are run sequentially to show how they work with the graph.
- Special cases and edge cases (e.g., disconnected graphs, graphs with no edges, graphs with duplicate edges) are also tested and printed for demonstration.

### Output Example

When running the program, you may see an output that lists the neighbors of each vertex.
This means that **Vertex 1** has a neighbor, **Vertex 3**, with an edge weight (or "weight") of **2**. The number inside the parentheses represents the **neighbor** first, followed by the **edge weight**.

For instance:
- `VERTEX 1: (3, 2)` means that Vertex 1 is connected to Vertex 3 with a weight of 2.


This output format helps demonstrate the connections between the graph vertices and their associated weights.

## Special Cases and Edge Cases

### Dijkstra's Algorithm and Negative Edge Weights
**Dijkstra's Algorithm** cannot handle graphs with negative edge weights. The algorithm assumes that once a node's shortest path is found, it cannot be improved, which is not true when negative edge weights are present. In such cases, the algorithm would give incorrect results.

For this reason, if you attempt to run Dijkstra on a graph with negative edge weights, the program will produce an error message or an incorrect result.

### Kruskal's Algorithm and Disconnected Graphs
In **Kruskal’s Algorithm**, if the graph is disconnected, the algorithm will still proceed and form a **forest** instead of a single **minimum spanning tree**. In such cases, the algorithm will not be able to connect all vertices, and the result will consist of multiple disjoint components.

### Prim's Algorithm and Sparse Graphs
**Prim's Algorithm** works best with dense graphs, as it requires the edge weights to be known beforehand. In very sparse graphs, it might take more time because it will repeatedly check edges that are not part of the MST.

### Empty Graphs and Graphs with No Edges
Graphs that are empty or have no edges will still work with the traversal algorithms like BFS and DFS, but they will not produce meaningful results, since there are no edges to traverse. In these cases, the algorithms will terminate immediately or just return the starting vertex without visiting any neighbors.

### Cyclic Graphs
Graphs with cycles (e.g., loops in the graph) are handled correctly in the algorithms. For example:
- **DFS** will mark vertices as "visited" to avoid infinite loops in cyclic graphs.
- **Kruskal’s Algorithm** uses the **Union-Find** data structure to ensure no cycles are formed while building the MST.

### Makefile and Execution

The project includes a Makefile that allows easy compilation and testing of the project.
Here are the important commands:
- make Main: Compiles the full program for running the graph and algorithms demonstration.
- make test: Compiles the test file and links all the necessary object files for running the tests with Doctest.
- make clean: Removes all compiled object files and executables.
- make valgrind: Runs the program using Valgrind to check for memory leaks and improper memory usage.

You can use these commands from the terminal to compile and test the project efficiently.

## Conclusion

This project demonstrates the implementation of various graph algorithms and data structures, all without using any built-in C++ functions like those from STL. By leveraging efficient algorithms such as Dijkstra and Kruskal, as well as custom data structures like Union-Find and Priority Queue, we can solve a wide range of graph-related problems. Additionally, comprehensive test coverage with **Doctest** ensures the correctness of every component, providing confidence in the implementation.
