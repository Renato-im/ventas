
#include <stdio.h>

int main() {
    int stock, cantidad, opcion, valid = 0, result, acum = 0;
    float precio, descuento, total_ganancias = 0, venta = 0, vent_desc;
    char nombre[30], id[30], opc;

    do {
        printf("==========================================\n");
        printf("______Menu de opciones______\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar informacion del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("==========================================\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();
        
        if (opcion >= 2 && opcion <= 5 && valid == 0) {
            printf("No se ha registrado ningún producto. Ingrese primero en la opcion 1.\n");
            continue;
        }

        switch (opcion) {
        case 1:
            printf("Ingrese el ID del producto: ");
            fflush (stdin);
            fgets(id, 30, stdin);
          
            printf("Ingrese el nombre del producto: ");
            fflush (stdin);
            fgets(nombre, 30, stdin);

            do {
                printf("Ingrese la cantidad inicial en stock: ");
                result = scanf("%d", &stock);
                if (result != 1) { // Si scanf no puede leer un número
                    printf("Entrada inválida. Por favor, ingrese un número entero.\n");
                    while (getchar() != '\n'); // Limpia el buffer de entrada
                    stock = -1; // Fuerza la repetición del bucle
                } else if (stock <= 0) {
                    printf("Cantidad no válida, no se acepta el 0 o un número menor\n");
                }
            
            } while (stock <= 0);

            do {
                printf("Ingrese el precio unitario del producto: ");
                result= scanf("%f", &precio);
                if (result != 1) { // Si scanf no puede leer un número
                    printf("Entrada inválida. Por favor, ingrese un número entero.\n");
                    while (getchar() != '\n'); // Limpia el buffer de entrada
                    precio = -1; // Fuerza la repetición del bucle
                } else if (precio <= 0) {
                    printf("Precio no valido, no se acepta el 0 o un número menor\n");
                }
            } while (precio <= 0);

            valid = 1; 
            break;
            
        if (valid == 0){
            printf("No se ha registrado ningún producto, tiene que ingresar primero en la opción 1\n");
        }else{
        case 2:
            
            do {
                printf("Ingrese la cantidad a vender: ");
                result = scanf("%d", &cantidad);
                if (result != 1) { // Si scanf no puede leer un número
                    printf("Entrada inválida. Por favor, ingrese un número entero.\n");
                    while (getchar() != '\n'); // Limpia el buffer de entrada
                    cantidad = -1; // Fuerza la repetición del bucle
                }
                else if (cantidad < 1) {
                    printf("La cantidad debe ser mayor a 0, vuelva a ingresar\n");
                }
                else if (cantidad > stock) {
                    printf("No existe la cantidad necesaria para esta venta\n");
                    
                }
                
            } while (cantidad < 1 || cantidad > stock);

            venta = cantidad * precio; 
            acum = acum + cantidad;

            if (cantidad > 20) {
                printf("Se aplicará un descuento del 10%% por comprar más de 20 productos.\n");
                vent_desc = venta * 0.90;
                printf("Precio final sin descuento; %.2f\n", venta);
                printf("Precio final con descuento: %.2f\n", vent_desc);
                total_ganancias += vent_desc;
                stock -= cantidad;
            }else{
                
                printf("El precio final de la venta es: %.2f\n", venta);
                total_ganancias += venta;
                stock -= cantidad;
            }
            break;

        case 3:
            
            do {
                printf("Ingrese la cantidad a agregar al stock: ");
                result = scanf("%d", &cantidad);
                if (result != 1) { 
                    printf("Entrada inválida. Por favor, ingrese un número entero.\n");
                    while (getchar() != '\n'); 
                    cantidad = -1;
                }
                else if (cantidad <= 0) {
                    printf("Cantidad no válida\n");
                }
            } while (cantidad <= 0);
            stock += cantidad;
            
            break;

        case 4:
            
            printf("-------------------------------------------\n");
            printf("| %-20s | %-10s |\n", "ID", id);
            printf("-------------------------------------------\n");
            printf("| %-20s | %-10s |\n", "Nombre", nombre);
            printf("-------------------------------------------\n");
            printf("| %-20s | %-10d |\n", "Stock disponible", stock);
            printf("-------------------------------------------\n");
            printf("| %-20s | $%-9.2f |\n", "Precio unitario", precio);
            printf("-------------------------------------------\n");
            
            break;

        case 5: 
            printf("Productos vendidos: %d\n", acum);
            printf("Total de ganancias: $%.2f\n", total_ganancias);
        
        break;
        }

        case 6:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    return 0;
}