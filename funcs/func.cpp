#include "./func.hpp"

#include <cmath>
#include <iostream>

void fill_matrix(int matrix[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

void print_matrix(int matrix[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int has_similar_rows(int matrix[100][100], int n) {
    bool same = true;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (not same) break;
                if (matrix[i][k] != matrix[j][k]) same = false;
            }
            if (same) return true;
            same = true;
        }
    }
    return false;
}

void change_mininmal_elements_in_columns(int matrix[100][100], int n, int value) {
    for (int i = 0; i < n; i++) {
        int minimal = 1000000, index;
        for (int j = 0; j < n; j++) {
            if (matrix[j][i] < minimal) {
                minimal = matrix[j][i];
            }
        }
        for (int j = 0; j < n; j++) {
            if (matrix[j][i] == minimal) {
                matrix[j][i] = value;
            }
        }
    }
}

bool is_primal(int n) {
    if (n < 0) return false;
    if (0 < n & n < 3) return true;
    
    for (int i = 2; i < ceil(sqrt(n)) + 1; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int find_maximal_primal(int matrix[100][100], int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (is_primal(matrix[i][j]) & max < matrix[i][j]) max = matrix[i][j];
        }
    }
    return max;
}