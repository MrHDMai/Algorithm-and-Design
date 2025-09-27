🚀 Algorithmic Foundations & Complexity Lab

A personal repository dedicated to building classic and advanced algorithms from scratch in C++. This lab is focused on deepening understanding of algorithm design paradigms, data structures, and asymptotic behavior. It also serves as a foundational reference for future projects, interviews, and academic exploration in complexity theory and optimization.

📚 Table of Contents

Overview

Implemented Algorithms

Sorting Algorithms

Divide & Conquer

Graph Algorithms

Dynamic Programming

Greedy & Optimization

Mathematical Utilities

Repository Structure

Installation & Usage

Contributing

License

Acknowledgments

📖 Overview

This repository includes C++ implementations of:

Core algorithms (sorting, searching, DP, etc.)

Graph theory concepts (SCCs, shortest paths, cycle detection)

Mathematical & DP problems (Rod Cutting, LIS, Kadane’s Algorithm)

In-place and efficient data manipulation

Each algorithm is written from scratch with a focus on clarity, modularity, and performance.

🔑 Implemented Algorithms
🧮 Sorting Algorithms
Name	Time Complexity	Notes
Insertion Sort	O(n²)	Stable, in-place
Heap Sort	O(n log n)	Binary heap
Quick Sort	O(n log n) avg / O(n²) worst	Partition-based
Merge Sort	O(n log n)	Stable, recursive
Radix Sort	O(nk)	Integer sort
Bucket Sort	O(n + k)	With insertion sort per bucket
Bubble Sort	O(n²)	Educational, inefficient
Selection Sort	O(n²)	In-place, not stable
🔁 Divide & Conquer

MergeSearch

Max Subarray (Kadane + Divide & Conquer)

🔗 Graph Algorithms

Strongly Connected Components (Kosaraju)

Bellman-Ford (Single source shortest paths)

Dijkstra’s Algorithm

BFS / DFS (recursive & iterative)

Directed Cycle Detection (DFS with recursion stack)

Undirected Cycle Detection (Disjoint Set / Union-Find)

🧠 Dynamic Programming

Rod Cutting (Optimal price with cuts)

Fibonacci (Top-down, Bottom-up, Space-optimized)

Longest Increasing Subsequence (LIS)

Subset Sum (2D DP array)

⚙️ Greedy & Optimization

Disjoint Set (Path Compression + Union by Rank)

Lower Bound Binary Search

Minimum Cycles using Union-Find

📐 Mathematical & Misc

Matrix Multiplication (Component-wise example)

Custom quick utilities (e.g., custom lower_bound)

🗂 Repository Structure
.
├── SortingAlgorithms/          # QuickSort, HeapSort, InsertionSort, etc.
├── DivideAndConquer/           # MergeSort, MaxSubArray
├── GraphAlgorithms/            # SCC, Dijkstra, Bellman-Ford, DFS, BFS
├── DynamicProgramming/         # Rod Cutting, LIS, Subset Sum
├── DataStructures/             # Disjoint Set, Hash Table (Chaining)
├── Utilities/                  # Matrix Ops, Lower Bound, Misc
├── docs/                       # Notes on complexity, asymptotic analysis
├── LICENSE
└── README.md
