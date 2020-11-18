<!-- Markdown file that is the README.md for implementation of Welsh Powell Algorithm for Graph Coloring with Minimum no. of Colours -->

# Welsh Powell Algorithm

Vertex numbering begins from 0.

## Requirements for Compilation
*	gcc 9.3.0+
*	Command Line Interface/Terminal

## Requirements for Development
*	Any IDE or editor of developer's choice

## Compiling and Running the Program
*	Compilation:
	```
	gcc welsh_powell.c -o welsh_powell
	```
	Note: Any compilation flags can be specified, as necessary.

*	Execution:
	```
	./welsh_powell
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
*	The total minimum number of colours required is first printed out.
*	For each vertex, the color of the vertex is printed out on a new line in the following format: <br />
	```Vertex < vertex-number > has been assigned colour: < vertex colour number >```