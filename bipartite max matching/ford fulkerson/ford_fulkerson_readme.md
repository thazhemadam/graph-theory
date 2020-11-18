<!-- Markdown file that is the README.md for implementation of Ford Fulkerson Algorithm for Maximum Matching in Bipartite Graphs -->

# Ford Fulkerson Algorithm for Maximum Matching in Bipartite Graphs
Vertex numbering begins from 0.

## Requirements for Compilation
*	gcc 9.3.0+
*	Command Line Interface/Terminal

## Requirements for Development
*	Any IDE or editor of developer's choice

## Compiling and Running the Program
*	Compilation:
	```
	gcc ford_fulkerson.c -o ford_fulkerson
	```
	Note: Any compilation flags can be specified, as necessary.

*	Execution:
	```
	./ford_fulkerson
	```
	The program now gets executed, and awaits user input.

## Input Format
*	First line of input contains *M* - the total number of vertexes in set 1 and *N* - the total number of vertexes in set 2, separated by a single space.
*	Second line of input contains *E* the total number of connections.
*	Next *E* lines of input represet the source edge and destination edge, separated by a single space.

Ex:
```
4 5
2
0 1
3 4
```
Here, the total number of vertexes in set 1 = 4, the total number of vertexes in set 2 = 5. <br />
There are a total number of connections between vertexes in set 1 and set 2. <br />
The first connection is from vertex 0 in set 1 to vertex 1 in set 2. <br />
The second connection is from vertex 3 in set 1 to vertex 4 in set 2. <br />

## Output Format
*	The total minimum number of colours required is first printed out.
*	For each vertex, the color of the vertex is printed out on a new line in the following format: <br />
	```Vertex < vertex-number > has been assigned colour: < vertex colour number >```