#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*******************************************
Autor: Grzegorz Dziechciarz
*******************************************/

/*
nie możemy napisać programu w taki sposób:

for (i = 0; i < NUM_FORKS; i++){
    fork();
    }

ponieważ wtedy powstałoby 2^NUM_FORKS procesów
ale gdybyśmy chcieli wykonać atak to wtedy dobrym pomysłem byłoby wykożystanie podobnego kodu:

while (1)
{
    fork();
}
*/

/*
po wykonaniu programu dla liczby 10:

└─$ pstree -p 4194
fork_bomb(4194)─┬─fork_bomb(4195)
                ├─fork_bomb(4196)
                ├─fork_bomb(4197)
                ├─fork_bomb(4198)
                ├─fork_bomb(4199)
                ├─fork_bomb(4200)
                ├─fork_bomb(4201)
                ├─fork_bomb(4202)
                ├─fork_bomb(4203)
                └─fork_bomb(4204)

*/

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <integer>\n", argv[0]);
        return 1;
    }

    int NUM_FORKS = atoi(argv[1]);
    int i;
    int fork_status = 1;

    printf("Parent process running PID: %d\n", getpid());

    for (i = 0; i < NUM_FORKS; i++)
    {
        // sprawdzamy czy nie ma błędu podczas forka
        if (fork_status == -1)
        {
            fprintf(stderr, "Error creating fork\n");
            return 1;
        }
        // sprawdzamy czy jesteśmy child procesem
        else if (fork_status == 0)
        {
            printf("Child process running PID: %d\n", getpid());
            // nigdy nie kończymy swojego działania aby zasoby były wykożystane
            while (1)
            {
                sleep(1);
            }
        }
        else
        {
            // jeśli jesteśmy parent procesem to wykonujemy forka
            fork_status = fork();
        }
    }

    while (1)
    {
        sleep(1);
    }

    return 0;
}
