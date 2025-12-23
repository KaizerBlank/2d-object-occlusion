#ifndef ORDENACAO_H
#define ORDENACAO_H
#include "objeto.hpp"
#include "cena.hpp"
#include <cassert>

void insertionSort(Objeto vetor[], int tamanho);
void insertionSort(ItensVisiveis itens[], int tamanho);
void mergeSort(ItensVisiveis vetor[], int tamanho);
void mergePorX(ItensVisiveis vetor[], int inicio, int meio, int fim);
void mergeSortRecursivoPorX(ItensVisiveis vetor[], int inicio, int fim);
void mergeSortPorX(ItensVisiveis vetor[], int tamanho);
void mergeSortRecursivo(ItensVisiveis vetor[], int inicio, int fim);
void merge(ItensVisiveis vetor[], int inicio, int meio, int fim);

inline double min(double a, double b){
    return (a < b) ? a : b;
}
inline double max(double a, double b){
    return (a > b) ? a : b;
}

#endif
