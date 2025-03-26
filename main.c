
#include <stdio.h>


int main() {
    int id, stock, cantidad, opcion;
    float precio, total_ganancias=0, venta = 0;
    char nombre[30];

    do {
        printf("\nMenú de Opciones:\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar información del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                // Registro del producto
                printf("Ingrese el ID del producto: ");
                scanf("%d", &id);
                
                printf("Ingrese el nombre del producto: ");
                fflush(stdin);
                fgets(nombre, 30, stdin);

                do{
                    
                    printf("Ingrese la cantidad inicial en stock: ");
                    scanf("%d", &stock);
                    if(stock < 0){
                        printf("La cantidad inicial debe ser mayor a 0. Ingrese nuevamente\n");
                    }
                }while(stock < 0);

                do{
                    printf("Ingrese el precio unitario del producto: ");
                    scanf("%f", &precio);
                    if(precio < 0){
                        printf("El precio debe ser mayor a 0. Ingrese nuevamente\n");
                    }

                }while(precio < 0);

                break;

            case 2:
                do{
                    printf("Ingrese la cantidad a vender: ");
                    scanf("%d", &cantidad);
                    if(cantidad < 1){
                        printf("La cantidad debe ser mayor a 1. Ingrese de Nuevo");
                    }

                    if(cantidad > stock){
                        printf("Productos insuficientes para esta venta. Ingrese nuevamente");
                    }

                }while(cantidad < 1 || cantidad > stock);

                venta = cantidad * precio;
                printf("El total de la venta es: %.2f\n", venta);

                total_ganancias+=venta;
                stock-=cantidad;

                break;

            case 3:
                do{
                    printf("Ingrese la cantidad a agregar al stock: ");
                    scanf("%d", &cantidad);
                    stock+=cantidad;
                }while(cantidad < 1);
                
                break;

            case 4:
                printf("\nInformación del producto:\n");
                printf("ID: %d\n", id);
                printf("Nombre: %s", nombre);
                printf("Stock disponible: %d\n", stock);
                printf("Precio unitario: %.2f\n", precio);
                break;

            case 5:
                printf("Total de ganancias: $%.2f\n", total_ganancias);
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    return 0;
}
