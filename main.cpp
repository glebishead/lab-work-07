#include "funcs/func.hpp"
#include <iostream>

int main()
{
    int matrix[100][100] = {0};
    int n;

    for (int i = 0; i < 20; i++) {
        std::cout << i << " " << is_primal(i) << std::endl;
    }
    std::cout << "Enter n and matrix" << std::endl;
    std::cin >> n;
    
    fill_matrix(matrix, n);
    
    if (has_similar_rows) {
        change_mininmal_elements_in_columns(matrix, n, 
                                            find_maximal_primal(matrix, n));
        std::cout << std::endl;
        print_matrix(matrix, n);
    }

    return 0;
} 