/*******************************************************************************************
 * circular_static_queue_menu
 * @author: Carlos Huerta García
 * @description: Displays a menu to execute static queue functions with int and char queues
 * ****************************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "circular_static_char_queue.h"
#include "circular_static_int_queue.h"
void main() {
    iQueue * intQueue = NULL;
    Queue * charQueue = NULL;
    char go = 's', newChar;
	int option, charStackCapacity, intStackCapacity, newInt;
	do{
        puts("0 Salir");
		puts("1 Crear cola de caracteres");
		puts("2 Crear cola de enteros");
		puts("3 Mostrar cola de caracteres");
		puts("4 Mostrar cola de enteros");
		puts("5 Tomar el primer caracter");
		puts("6 Tomar el primer entero");
        puts("7 Tomar el último caracter");
		puts("8 Tomar el último entero");
		puts("9 Quitar el último caracter");
		puts("10 Quitar el último entero");
		puts("11 Agregar un caracter");
		puts("12 Agregar un entero");
		puts("13 Vaciar la cola de caracteres");
		puts("14 Vaciar la cola de enteros");
		scanf("%d", &option);
		switch(option){
            case 0:
            clearQueue(charQueue);
            cleariQueue(intQueue);
            free(charQueue);
            free(intQueue);
                exit(0);
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                break;
            case 14:
                break;
            default:
                puts("Operación inválida");
                break;
        }
        printf("\n¿Desea realizar más operaciones? (s/n): ");
        fflush(stdin);
		scanf("%c", &go);
		scanf("%c", &go);
    } while(go == 's');
    clearQueue(charQueue);
    cleariQueue(intQueue);
    free(charQueue);
    free(intQueue);
}
