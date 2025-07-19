#include<iostream>

const int ROWS = 2;
const int COLS = 2;

// Function to initialize the matrix with 0
void MatrixInitializer(int matrix[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = 0;
        }
    }
}

// Function to add two matrices
void AddMatrix(int result[][COLS], int matrix1[][COLS], int matrix2[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply a matrix by a scalar
void MultMatrixByScalar(int result[][COLS], int scalar, int matrix[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            result[i][j] = scalar * matrix[i][j];
        }
    }
}

// Function to display the matrix
void DisplayMatrix(int matrix[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int A[ROWS][COLS] = { {1, 2}, {3, 4} };
    int B[ROWS][COLS] = { {1, 0}, {0, 1} };
    int result[ROWS][COLS];

    // Initialize matrix C to 0
    MatrixInitializer(result);

    // Display matrices A and B
    std::cout << "Matrix A:" << std::endl;
    DisplayMatrix(A);

    std::cout << "Matrix B:" << std::endl;
    DisplayMatrix(B);

    // Compute 2*B
    MultMatrixByScalar(result, 2, B);
    std::cout << "2*B:" << std::endl;
    DisplayMatrix(result);

    // Add matrices A and 2*B
    AddMatrix(result, A, result);
    std::cout << "Final Result (A + 2*B):" << std::endl;
    DisplayMatrix(result);

    return 0;
}

