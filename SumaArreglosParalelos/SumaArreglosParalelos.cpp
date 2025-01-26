#include <iostream>
#include <omp.h>

#define N 10        //Numero de elementos de arreglos
#define chunk 5     //Tamaño de porción de operaciones por arreglo
#define nthreads 2  //Numero de threads

void imprimearreglo(float* a) {
    for (int i = 0; i < N; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    float A[N], B[N], C[N];

    // Inicializamos los arreglos
    for (int i = 0; i < N; i++) {
        A[i] = i;
        B[i] = rand() % 100;  // Números aleatorios entre 0 y 99
    }

    // Sumamos los arreglos en paralelo
#pragma omp parallel num_threads(nthreads)
    {
#pragma omp for schedule(static, chunk)
        for (int i = 0; i < N; i++) {
            C[i] = A[i] + B[i];
        }
    }

    // Imprimimos los arreglos
    std::cout << "Arreglo A: ";
    imprimearreglo(A);

    std::cout << "Arreglo B: ";
    imprimearreglo(B);

    std::cout << "Arreglo C (suma): ";
    imprimearreglo(C);

}