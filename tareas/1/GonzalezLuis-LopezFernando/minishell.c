#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


#define MAX_INPUT 500
#define MAX_TOKENS 50
// Crear el bucle de la terminal
// Procesar la linea


//Shell (todo el funcionamiento)
void minishell(){
    char input[MAX_INPUT];
    char* parametros[MAX_TOKENS];

    // Ciclo donde vive la terminal
    while (1){
        // (1) Imprime el prompt
        printf("8=D --- ");
        fflush(stdout);

        // (2) leer linea usuario
        //Se recibe el texto introducido por el usuairo:
        fgets(input, sizeof(input), stdin);

        printf("%s", input);
        // Tokenizar los comandos
        int i_parametros = 0;
        char* token = strtok(input, " ");
        while (token != NULL){
            parametros[i_parametros++] = token;
            //printf("%s\n", parametros[i_parametros-1]);  DEBUG
            token = strtok(NULL, " ");
        }
        parametros[i_parametros] = NULL;

        // CREACIÓN DEL FORK
        pid_t nvo_pid = fork();
        pid_t pid = getpid();
       

        if (nvo_pid < 0){ // fork sin exito
           
        }else if (nvo_pid == 0){ // pid del hijo
            printf("Soy el proceso hijo, %i. Mi PID es: %i \n", nvo_pid, pid);


           /* if(execvp(parametros[0], parametros) == -1){
                printf("Comando invalido");
            }*/
        }else{ // pid del padre
            printf("Soy el proceso hijo, %i. Mi PID es: %i \n", nvo_pid, pid);
            sleep(1);
        }

    }
}


int main(){
    //aqui se instalan manejadores de señales
    minishell();
    return 0;
}