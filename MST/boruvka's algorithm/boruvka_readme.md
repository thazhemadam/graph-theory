<!-- Markdown file that is the README.md for implementation of Boruvka's Algorithm -->

# Boruvka's Algorithm

Vertex numbering begins from 0.

## Requirements for Compilation
*	gcc 9.3.0+
*	Command Line Interface/Terminal

## Requirements for Development
*	Any IDE or editor of developer's choice

## Compiling and Running the Program
*	Compilation:
	```
	gcc boruvka.c -o boruvka
	```
	Note: Any compilation flags can be specified, as necessary.

*	Execution:
	```
	./boruvka
	```
	The program now gets executed, and awaits user input.


## Input Format
*	First line contains V - the total number of vertexes, and E - the total number of edges, separated by a single blank space.
*	Next E lines of input represet the source edge, destination edge, and the weights separated by a single space.

Ex:
```
5 2
2 3 5 
1 4 7
```
Here, the total number of vertexes = 5. The total number of edges = 2. <br />
The first vertex is from vertex 2 to vertex 3, and has a weight of 5. <br />
The second vertex is from vertex 1 to vertex 4, and has a weight of 7. <br />

## Output Format
The edges present in the Minimum Spanning Tree are each printed out in a new line;
in the format: (Edge 1, Edge 2).
Next, the Minimum Cost, i.e., the cost associated with the Minimum Spanning Tree is printed.

## Tools Required

*	gcc 9.3.0