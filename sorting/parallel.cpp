#include <mpi.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0)));

    MPI_Init(&argc, &argv);
    
    int world_size, world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    
    const int n = 100;
    std::vector<int> x_global(n);
    
    if (world_rank == 0) {
        for (int i = 0; i < n; i++) {
            x_global[i] = (rand() % 9) + 1;
        }
        std::cout << "Process 0 generated array : ";
        for (int i = 0; i < n; i++) {
            std::cout << x_global[i] << " ";
        }
        std::cout << std::endl;
    }
    
    int next_rank = (world_rank + 1) % world_size;
    int prev_rank = (world_rank - 1 + world_size) % world_size;
    
    if (world_rank == 0) {
        MPI_Send(x_global.data(), n, MPI_INT, next_rank, 0, MPI_COMM_WORLD);
        MPI_Recv(x_global.data(), n, MPI_INT, prev_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    } else {
        MPI_Recv(x_global.data(), n, MPI_INT, prev_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Send(x_global.data(), n, MPI_INT, next_rank, 0, MPI_COMM_WORLD);
    }
    
    int even_count = 0;
    for (int i = 0; i < n; i++) {
        if (world_rank == 0 || x_global[i] % world_rank == 0) {
            if (x_global[i] % 2 == 0)
                even_count++;
        }
    }
    
    std::cout << "Process " << world_rank << " found " 
              << even_count 
              << " even numbers among elements that are multiples of " 
              << world_rank << std::endl;
    
    if (world_rank != 0) {
        MPI_Send(&even_count, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    } else {
        std::vector<int> even_number(world_size);
        even_number[0] = even_count;
        for (int source = 1; source < world_size; source++) {
            MPI_Recv(&even_number[source], 1, MPI_INT, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        std::cout << "Final results - even_number array: ";
        for (int i = 0; i < world_size; i++) {
            std::cout << even_number[i] << " ";
        }
        std::cout << std::endl;
    }
    
    MPI_Finalize();
    return 0;
}
