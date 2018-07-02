#include <stdio.h>
#include "mpi.h"

int main(int argc, char** argv){
	int my_pe_num, numbertoreceive, numbertosend=6, numbertosend_now, numbertoreceive_final;
	
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_pe_num);

	if (my_pe_num == 0){		
		MPI_Send( &numbertosend, 1,MPI_INT, 1, 10,MPI_COMM_WORLD);
		MPI_Recv( &numbertoreceive_final, 1, MPI_INT,7 , 10, MPI_COMM_WORLD, &status);}
	else if (my_pe_num < 7){
		MPI_Recv( &numbertoreceive, 1, MPI_INT,my_pe_num-1 , 10, MPI_COMM_WORLD, &status);
		MPI_Send( &numbertosend_now, 1,MPI_INT, my_pe_num+1, 10,MPI_COMM_WORLD);}
	else{
		MPI_Recv( &numbertoreceive, 1, MPI_INT,my_pe_num-1 , 10, MPI_COMM_WORLD, &status);
		MPI_Send( &numbertosend_now, 1,MPI_INT, 0, 10,MPI_COMM_WORLD);
	}

	MPI_Barrier(MPI_COMM_WORLD);

	if (my_pe_num == 0){
		printf("I am PE 0. I sent  %d and received %d.\n", numbertosend,numbertoreceive_final);
	}	

	MPI_Finalize();
} 
