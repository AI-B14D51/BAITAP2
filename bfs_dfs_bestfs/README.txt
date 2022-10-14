
Since estimating F in influence maximization is very time consuming, our code uses OpenMP for parallelization (https://en.wikipedia.org/wiki/OpenMP).

To build our code, run:
	g++ -std=c++11 *.cpp -o ksub -DIL_STD -fopenmp -g

After building, to run our code, run:
	/ksub -f test.txt -V 20 -a 2 -st 0 -en 12
		////////////////////////////////////////////
		-V <size of V> 
		-t <type of experiment, 0: influence maximization, 1: sensor placement> 
		-k <value of k> 
		-B <value of B> 
		-M <value of M> 
		-e <value of epsilon>
		-n <value of eta - denoise step for RStream> 
		-g <value of gamma> 
		-a <algorithm, 0:dfs, 1:bfs, 2:bestfs. Please use SSA source code for testing IM algorithm>
		-p <number of threads (OpenMP) to running algorithms>
		/////////////////////////////////////
		-V  n_node
		-f  data file
		-st start
		-en end
		-l  limit
		-a  algorithm 0:dfs, 1:bfs, 2:bestfs


We conducted experiments on a Linux machine with 2.3Ghz Xeon 18 core processor and 256Gb of RAM. With 70 threads, DStream usually terminates after 20 minutes, RStream is 2 hours.
