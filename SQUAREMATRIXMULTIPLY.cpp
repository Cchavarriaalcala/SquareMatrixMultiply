#include <stdio.h>
#include <iomanip>
#include <iostream>

using namespace std;

int **allocateMatrix(int row, int col) {
    int **matrix = new int*[row];
    for(int i = 0; i < row; ++i) {
        matrix[i] = new int[col]{0};
    }
    return matrix;
}
int deallocateMatrix(int **matrix, int row) {
    for(int i = 0; i < row; ++i) {
        delete matrix[i];
    }
    delete [] matrix;
    return 0;
}

void initializeMatrix(int **m, int row, int col)
{
    for(auto i = 0; i < row; ++i) {
        for(auto j = 0; j < col; ++j) {
            m[i][j] = rand() % 5;
        }
    }
}

void printMatrix(int **m, int row, int col)
{
    for(auto i = 0; i < row; ++i) {
        for(auto j = 0; j < col; ++j) {
            cout << setw(5) << m[i][j] << "; ";
        }
        cout << endl;
    }
}

int** squareMatrixMultiply(int **m1, int row1, int col1, int **m2, int row2, int col2){
	int n = col1;
	auto matrixC = allocateMatrix(row1,col2);
	
	printf("\nOperaciones:\n");
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k=0; k < n; k++){
				matrixC[i][j] += m1[i][k] * m2[k][j];
				printf("%i [%i,%i] * %i [%i,%i] = %i \n", m1[i][k],i,k,m2[k][j],k,j, matrixC[i][j]);
			}
		}
	}
	return matrixC;
}

int main() {
	//Declaramos las columnas y filas
	int ROW = 2;
	int COL = 2;
	
	//Declaramos las matrices
	int **matrix1 = allocateMatrix(ROW, COL);
    int **matrix2 = allocateMatrix(ROW, COL);
	
	//Inicializar con valores las matrices
	initializeMatrix(matrix1, ROW, COL);
    initializeMatrix(matrix2, COL, ROW);
    
    //Imprimimos las matrices
    cout << "Matriz 1"<< endl;
    printMatrix(matrix1, ROW, COL);
    cout << endl;
    cout << "Matriz 2"<< endl;
    printMatrix(matrix2, COL, ROW);
    
    auto result = squareMatrixMultiply(matrix1, ROW, COL, matrix2, COL, ROW);
    
    cout << endl;
    cout << "Matriz Resultante"<< endl;
    printMatrix(result, ROW, ROW);
    
    //Liberamos la memoria utilizada
    deallocateMatrix(matrix1, ROW);
    deallocateMatrix(matrix2, COL);
    deallocateMatrix(result, ROW);
    
    return EXIT_SUCCESS;
}

