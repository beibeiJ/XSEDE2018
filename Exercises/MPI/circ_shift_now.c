#include <stdio.h>
#include "mpi.h"

int main(int argc, char** argv){
        int my_pe_num, numbertoreceive, numbertosend, numbertosend_now, numbertoreceive_final;

        MPI_Status status;

        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &my_pe_num);

        if (my_pe_num == 0 ){
                printf("What number do you want to send? ");
        }

     
        MPI_Barrier(MPI_COMM_WORLD);

        if (my_pe_num == 0){
                printf("I am PE 0. I sent  %d and received %d.\n", numbertosend,numbertoreceive_final);
        }

        MPI_Finalize();
}
