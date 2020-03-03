/*******************************************************************************************
 * circular_static_queue_menu
 * @author: Carlos Huerta García
 * @description: Displays a menu to execute static queue functions with int and char queues
 * ****************************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "circular_static_char_queue.h"
#include "circular_static_int_queue.h"
void main() {
    iQueue * intQueue = NULL;
    Queue * charQueue = NULL;
    char go = 's', newChar;
	int option, charQueueSize, intQueueSize, newInt;
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
		puts("9 Quitar el primer caracter");
		puts("10 Quitar el primer entero");
		puts("11 Agregar un caracter");
		puts("12 Agregar un entero");
		puts("13 Vaciar la cola de caracteres");
		puts("14 Vaciar la cola de enteros");
        puts("\nIntroduzca la opción deseada: ");
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
                puts("Introduza la capacidad de la cola de caracteres:");
				scanf("%d", &charQueueSize);
                charQueue = createQueue(charQueueSize);
                break;
            case 2:
                puts("Introduza la capacidad de la cola de enteros:");
				scanf("%d", &intQueueSize);
                intQueue = createiQueue(intQueueSize);
                break;
            case 3:
                printQueue(charQueue);
                break;
            case 4:
                printiQueue(intQueue);
                break;
            case 5:
                newChar = queueFront(charQueue);
                if(newChar != CHAR_MIN)
                    printf("\nFront: %c\n", newChar);
                else
                    puts("Current queue is empty");
                break;
            case 6:
                newInt = iqueueFront(intQueue);
                if(newInt != INT_MIN)
                    printf("\nFront: %d\n", newInt);
                else
                    puts("Current queue is empty");
                break;
            case 7:
                newChar = queueRear(charQueue);
                if(newChar != CHAR_MIN)
                    printf("\nRear: %c\n", newInt);
                else
                    puts("Current queue is empty");
                break;
            case 8:
                newInt = iqueueRear(intQueue);
                if(newInt != INT_MIN)
                    printf("\nRear: %d\n", newInt);
                else
                    puts("Current queue is empty");
                break;
            case 9:
                newChar = deQueue(charQueue);
                if(newChar != CHAR_MIN)
                    printf("\nDequeued: %c\n", newChar);
                else
                    puts("Current queue is empty");
                break;
            case 10:
                newInt = ideQueue(intQueue);
                if(newInt != INT_MIN)
                    printf("\nDequeued: %d\n", newInt);
                else
                    puts("Current queue is empty");
                break;
            case 11:
                if(charQueue && !queueIsFull(charQueue)){
					fflush(stdin);
					printf("Introduzca el caracter: ");
					fflush(stdin);
					scanf("%c", &newChar);
					scanf("%c", &newChar);
					enQueue(newChar, charQueue);
				} else 
					puts("Current queue is invalid");
                break;
            case 12:
                if(intQueue && !iqueueIsFull(intQueue)){
					fflush(stdin);
					printf("Introduzca el caracter: ");
					fflush(stdin);
					scanf("%d", &newInt);
					scanf("%d", &newInt);
					ienQueue(newInt, intQueue);
				} else 
					puts("Current queue is invalid");
                break;
            case 13:
                clearQueue(charQueue);
                break;
            case 14:
                cleariQueue(intQueue);
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
