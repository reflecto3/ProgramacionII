/* Escriba un programa en C que simule la gestión de una tienda de electrónica. 
El programa debe ser capaz de realizar las siguientes operaciones: 
1. Definir una estructura Producto que almacene la siguiente información de un producto: 
• ID del producto (entero). 
• Nombre del producto (cadena de caracteres de longitud máxima fija). 
• Precio del producto (flotante). 
• Cantidad en stock (entero).
2. Definir un arreglo de estructuras Producto para almacenar una lista de productos. 
La lista debe contener al menos 10 productos iniciales.
3. Implementar las siguientes funciones: 
• Agregar un nuevo producto a la lista. 
• Actualizar la información de un producto existente (nombre, precio, cantidad en stock).
• Eliminar un producto de la lista. 
• Mostrar la lista de productos disponibles, incluyendo ID, nombre, precio y cantidad en stock.
• Realizar una venta, reduciendo la cantidad en stock del producto vendido.
4. Utilizar punteros para pasar estructuras a las funciones y realizar las operaciones de forma eficiente.
5. Implementar un bucle de menú que permita al usuario seleccionar las operaciones mencionadas 
y ejecutarlas según su elección.
*/

#include "producto.h"

int main() {
    int capacidad_inicial = 10;

    Producto* productos = (Producto*) calloc(capacidad_inicial, sizeof(Producto));

    if (productos == NULL) {
        printf("Error al asignar memoria inicial.\n");
        return 1;
    }


    int capacidad = capacidad_inicial;
    int cantidad_productos_actual = 0;
    //variable para la escogencia del usuario
    int eleccion;

    printf("Bienvenido al registro de productos de la tienda.\n");
    do {
        //Menu interactivo
        printf("Seleccione una de las siguientes opciones (1-6):\n");
        printf("1. Agregar un nuevo producto \n");
        printf("2. Actualizar la informacion de un producto \n");
        printf("3. Eliminar un producto \n");
        printf("4. Mostrar la lista de productos disponibles \n");
        printf("5. Registrar una venta \n");
        printf("6. Salir del programa \n");

        if (scanf("%d", &eleccion) != 1 || eleccion < 1 || eleccion > 6) {
            printf("Error al registrar la eleccion. \n");
            return 1;
        }
        getchar(); //consumir el salto de linea

        Producto producto; //para almacenar datos de producto a incluir o actualizado
        int longitud_nombre; //longitud del nombre de producto una vez establiecido

        switch (eleccion) {
            case 1:
                printf("Nombre del producto: ");
                fgets(producto.nombre, sizeof(producto.nombre), stdin);
                if ((longitud_nombre=strlen(producto.nombre)) > 0 && producto.nombre[longitud_nombre-1] == '\n') {
                    producto.nombre[longitud_nombre-1] = '\0';
                }
                printf("Id: ");
                scanf("%d", &producto.id);
                printf("Cantidad en stock: ");
                scanf("%d", &producto.cantidad_en_stock);
                printf("Precio: ");
                scanf("%f", &producto.precio);

                agregar_producto(&productos, &capacidad, &cantidad_productos_actual, producto);
                break;
            case 2:
                printf("ID del producto a actualizar: ");
                scanf("%d", &producto.id);
                getchar();
                printf("Nombre del producto: ");
                fgets(producto.nombre, sizeof(producto.nombre), stdin);
                if ((longitud_nombre=strlen(producto.nombre)) > 0 && producto.nombre[longitud_nombre-1] == '\n') {
                    producto.nombre[longitud_nombre-1] = '\0';
                }

                printf("Cantidad en stock: ");
                scanf("%d", &producto.cantidad_en_stock);
                printf("Precio: ");
                scanf("%f", &producto.precio);

                actualizar_producto(&productos, &cantidad_productos_actual, producto);
                break;
            case 3:
                printf("ID del producto a eliminar: ");
                scanf("%d", &producto.id);
                eliminar_producto(&productos, &cantidad_productos_actual, producto.id);
                break;
            case 4:
                imprimir_productos(&productos, &cantidad_productos_actual);
                break;
            case 5:
                int cantidad_vendida;
                printf("ID del producto vendido: ");
                scanf("%d", &producto.id);
                printf("Cantidad vendida: ");
                scanf("%d", &cantidad_vendida);
                realizar_venta(&productos, &cantidad_productos_actual, producto.id, cantidad_vendida);
                break;
        }
        




    } while (eleccion != 6);
    free(productos);

    return 0;
}
