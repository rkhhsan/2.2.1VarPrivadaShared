#include <cstdio>
#include <iomanip>
#include <iostream>
#include <omp.h>

using namespace std;

char caracter;

int main(int argc, char *argv[]) {
    // Observação 2.1.1.
    /* As variáveis declaradas dentro de uma região paralela são privadas de cada threads.
     * As variáveis declaradas fora de uma região paralela são globais(shared),
     * sendo acessíveis por todos os threads.
    */
    int tid, nt;
    // região paralela
#pragma omp parallel
    {
        tid = omp_get_thread_num();
        nt = omp_get_num_threads();

        printf("\nProcesso %d/%d", tid, nt);
    }
    printf("\nNumero de threads: %d", nt);
    cout <<"\nCondicao de corrida.\n";

/*
 * Isto ocorre por uma situação de condição de corrida (race condition) entre os threads.
 * As variáveis tid e nt foram declaradas antes da região paralela e, desta forma,
 * são variáveis compartilhadas (shared variables) entre todos os threads na região paralela.
 * Os locais na memória em que estas  variáveis estão alocadas é o mesmo para todos os threads.
 * Possível saída:
Processo 2/8
Processo 4/8
Processo 4/8
Processo 5/8
Processo 1/8
Processo 4/8
Processo 6/8
Processo 7/8
8
 */

// Solução 1: Colocar tid como variável private.

#pragma omp parallel private(tid)
    {
        tid = omp_get_thread_num();
        nt = omp_get_num_threads();
        printf("\nProcesso %d/%d", tid, nt);
    }
    printf("\nNumero de threads: %d", nt);
    cout <<"\nAgora funcionou , pois tid eh variavel private.\n";

// Solução 2: As variáveis declaradas dentro de uma região paralela são privadas de cada threads.
#pragma omp parallel
    {
        int tid1, nt1;
        tid1 = omp_get_thread_num();
        nt1 = omp_get_num_threads();
        printf("\nProcesso %d/%d", tid1, nt1);
    }
    printf("\nNumero de threads: %d", nt);
    cout <<"\nAgora funcionou , pois tid1 eh variavel private.";

    cout << "\n\nTecle uma tecla e apos Enter para finalizar...\n";
    cin >> caracter;
    return 0;
}




