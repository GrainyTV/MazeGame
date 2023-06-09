# a-MAZE-ing game

## Backstory
<p align="justify">This was one of my best coding projects to work on. The backstory to this is that, during the first programming class in university, we had to use plain old C to work on an application idea that we chose for ourselves. I didn't really know what I should make, but I thought making an algorithm that generates a labyrinth could be a lot of fun. At that point, I didn't really know, that there are hundreds of different ways to generate labyrinths and that coding in C is nothing compared to C#. I had to realize that good readability and documentation was traded for speed. I had a lot of trouble with using pointers, creating strings and getting "Segmentation fault (core dumped)" messages, but it was a fun learning process. So, this is how this project came to life.</p>

## Prim's modified algorithm
<p align="justify">The algorithm I chose for this project is called as the title says, Prim's modified algorithm. Basically how this works is, that we start off with an (n * n) large matrix, where each element is a cell of the maze. At the start, each of them is considered a wall, so it's not really a maze yet. Then we iterate through the matrix and mark the horizontal and vertical edges as "unmodifyable" walls. Next, we mark the bottom left corner as the starting point. Now this is where the essential part comes. We create a container for tracking neighboring cells. We add all the unvisited and available neighbors of the chosen cell to that container. This can range from 2-4, depending on the cell's position in the maze. Then we select one of these neighbors randomly and connect it with the originally selected cell. We mark the original as finished and the new one to be used. We continue this same process until no neighboring cells are available in the container. Finally we add an entrance and exit point at the two diagonally opposite side. Here is a small clip that shows the generation process visually:  </p>


<p align="center"><img alt="Generation" src="MazeGame/generation.gif" width="50%" height="50%"/></p>
