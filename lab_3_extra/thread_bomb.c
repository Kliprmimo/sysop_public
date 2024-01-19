#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

/*******************************************
Autor: Grzegorz Dziechciarz
*******************************************/

/*
po wykonaniu programu dla liczby 10
└─$ pstree -p 7007
thread_bomb(7007)─┬─{thread_bomb}(7008)
                  ├─{thread_bomb}(7009)
                  ├─{thread_bomb}(7010)
                  ├─{thread_bomb}(7011)
                  ├─{thread_bomb}(7012)
                  ├─{thread_bomb}(7013)
                  ├─{thread_bomb}(7014)
                  ├─{thread_bomb}(7015)
                  ├─{thread_bomb}(7016)
                  └─{thread_bomb}(7017)

*/

void *thread_function(void *arg)
{
    printf("Thread running Thread ID: %ld\n", (long)pthread_self());
    // funkcja działa w nieskończonść aby wątki nie kończyły się i zajmowały zasoby
    while (1)
    {
        sleep(1);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    
    if (argc != 2)
    {
        printf("Usage: %s <integer>\n", argv[0]);
        return 1;
    }

    int NUM_THREADS = atoi(argv[1]);

    pthread_t threads[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++)
    {
        // sprawdzamy czy nie ma błędu podczas tworzenia wątku
        // <do threads zapisujemy id każdego wątku><z domyślną konfiguracją>
        // <wykonujemy thread_function, działające w nieskończoność><nie podajemy do thread_function żadnych argumentów> 
        if (pthread_create(&threads[i], NULL, thread_function, NULL))
        {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }
    
    for (i = 0; i < NUM_THREADS; i++)
    {
        // czekamy na zakończenie się każdego z wątków (co nigdy nie nastąpi)
        // robimy to po to aby program nie zakończył działania w nieoczekiwany sposób
        if (pthread_join(threads[i], NULL))
        {
            fprintf(stderr, "Error joining thread\n");
            return 2;
        }
    }

    return 0;
}
