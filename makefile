##74395666 G - Miguel Pérez Giménez
OPTS = -Wall -O3 -std=c++0x

maze: maze_greedy.cc
	g++ ${OPTS} -o maze_greedy maze_greedy.cc	 


tar: maze_greedy.cc makefile
	tar cvfz 74395666G.tar.gz maze_greedy.cc  makefile

clean: 
	rm maze_greedy
