/*How do you detect A cycle using Kahn's algorithm?
To detect a cycle using Kahn's algorithm, count the number of nodes processed. If, at the end of the algorithm, some nodes remain unprocessed, 
a cycle is present. In a valid directed acyclic graph (DAG), Kahn's algorithm should process all nodes; if it doesn't, 
a cycle exists.*/