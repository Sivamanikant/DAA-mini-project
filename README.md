# DAA-mini-project

Social Network Analysis Using BFS and DFS
Overview
This project provides an implementation of social network analysis using Breadth-First Search (BFS) and Depth-First Search (DFS) algorithms in C. 
It allows users to:

1.Find the shortest path between two nodes (users) using BFS.
2.Identify connected components or communities within the network using DFS.

Features

Shortest Path Analysis:

Finds the shortest path between two users in the network.
Displays the distance and path between the nodes if a connection exists.
Community Detection:
Identifies all connected components (communities) within the network.
Uses recursive DFS to traverse the graph and print community members.

How to Run
Clone or download this repository.
Compile the code using a C compiler, e.g.:
bash
Copy code
gcc social_network_analysis.c -o social_network_analysis
Run the program
./social_network_analysis
Follow the prompts to input:
Number of users.
Adjacency matrix of the social network.
Desired operation (BFS or DFS).


