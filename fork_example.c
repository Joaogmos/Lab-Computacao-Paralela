 # include <stdio.h>
 # include <unistd.h>
 # include <sys/wait.h>
 #include <stdlib.h>
 #define N 4

 int main () {
 pid_t pid = fork ();
 printf("Processo pai principal com PID %d.\n", getpid());
 printf("------------------------------------\n");

 for(int i =0; i < N; i++){
    pid = fork();
 
    if ( pid < 0) { // Erro
        fprintf (stderr , " Fork falhou !\n");
        return 1;
    } else if (pid == 0) { // Processo Filho
        printf ("Eu sou o filho ! Meu PID eh %d, meu pai eh %d. e alem disso eu sou o FILHO\n", getpid () , getppid ());
        exit(0);
    }
} 
for(int i = 0; i < N; i++){ // Processo Pai
    printf ("Eu sou o pai! Meu PID eh %d, criei o filho %d. Repetindo eu sou o PAI\n", getpid () , pid);
    wait ( NULL ); // Pai espera o filho terminar
    printf ("Meu filho terminou , agora eu posso terminar.\n");
}

 return 0;
}