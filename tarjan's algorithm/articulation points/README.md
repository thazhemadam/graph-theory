<!-- Markdown file that is the README.md for implementation of Tarjan's Algorithm for Detecing Articulation Points -->

# Tarjan's Algorithm for Detecting Articulation Points

Vertex numbering begins from 0.

## Requirements for Compilation
*	gcc 9.3.0+
*	Command Line Interface/Terminal

## Requirements for Development
*	Any IDE or editor of developer's choice

## Compiling and Running the Program
*	Compilation:
	```
	gcc tarjan_articulation.c -o tarjan
	```
	Note: Any compilation flags can be specified, as necessary.

*	Execution:
	```
	./tarjan
	```
	The program now gets executed, and awaits user input.

## Input Format
*	First line of input contains *V* - the total number of vertexes and *E* - the total number of edges, separated by a single space.
*	Next E lines of input represet the source edge and destination edge, separated by a single space.

Ex:
```
5 2
0 1
3 4
```
Here, the total number of vertexes = 5. The total number of edges = 2. <br />
The first edge is from vertex 0 to vertex 1. <br />
The second edge is from vertex 3 to vertex 4. <br />

## Output Format
All the articulations are printed, separated by a single space.
If there are no articulation points in the graph, then a message stating that there are no articulation points is printed instead.
