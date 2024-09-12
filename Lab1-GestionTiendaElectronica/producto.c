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

<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
=======
>>>>>>> 0a1eb9e (version del desktop de la carpeta)
#include "producto.h"

/*
Esta funcion fue copiada del ejemplo del profe Diego Orozco del ejercicio de ejemplo de punteros de registro de estudiantes.
Función para copiar una cadena de caracteres manualmente
*/
void copiar_string(const char* fuente, char* destino) {

    int indice = 0;
    while (fuente[indice] != '\0') {
        destino[indice] = fuente[indice];
        ++indice;
    }
    destino[indice] = '\0'; // Agregar el terminador nulo
}

// Funcion que agrega un producto a un arreglo de productos dado
<<<<<<< HEAD
void agregar_producto(Producto** productos, int* capacidad_arreglo, int* cantidad_productos_actual, const char* nombre, int id, int cantidad_en_stock, float precio) {
    // Verificar si los datos tienen sentido
    if (error_en_producto(productos, cantidad_productos_actual, id, cantidad_en_stock, precio)) {
        printf("Valores invalidos.\n");
=======
void agregar_producto(Producto** productos, int* capacidad_arreglo, int* cantidad_productos_actual, Producto producto) {
    // Verificar si los datos tienen sentido
    if (error_en_producto(producto)) {
        ERROR_VAL;
        return;
    }

    if (buscar_pos_id(productos, cantidad_productos_actual, producto.id)>-1) {
        printf("Ya existe un producto con este id. \n");
>>>>>>> 0a1eb9e (version del desktop de la carpeta)
        return;
    }
   
    // Duplicar el tamano del arreglo en caso de necesidad
    if (*cantidad_productos_actual == *capacidad_arreglo) {
<<<<<<< HEAD
        *capacidad_arreglo *= 2;
        Producto* productos_temp = (Producto*) realloc(*productos, (*capacidad_arreglo) * sizeof(Producto));
        if (productos_temp == NULL) {
            printf("Error al asignar memoria.\n");
            return;
        }
        *productos = productos_temp;
    }

    modificar_producto(*productos+*cantidad_productos_actual, nombre, id, cantidad_en_stock, precio);
=======
        duplicar_capacidad(productos, capacidad_arreglo);
    }

    modificar_producto(*productos+*cantidad_productos_actual, producto);
>>>>>>> 0a1eb9e (version del desktop de la carpeta)

    ++(*cantidad_productos_actual);
}

<<<<<<< HEAD
bool error_en_producto(Producto** productos, int* cantidad_productos_actual, int id, int cantidad_en_stock, float precio) {
    bool id_repetido = false;
    for (int i = 0; i < *cantidad_productos_actual; ++i) {

        id_repetido = (id_repetido || id == (*productos)[i].id);

    }

    return (cantidad_en_stock < 0 || precio < 0 || id_repetido);
=======
void duplicar_capacidad(Producto** productos, int* capacidad_arreglo) {
    *capacidad_arreglo *= 2;
    Producto* productos_temp = (Producto*) realloc(*productos, (*capacidad_arreglo) * sizeof(Producto));
    if (productos_temp == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }
    *productos = productos_temp;
}

bool error_en_producto(Producto producto) {
    return (producto.cantidad_en_stock < 0 || producto.precio < 0 || strlen(producto.nombre) < 1);
>>>>>>> 0a1eb9e (version del desktop de la carpeta)
}

void imprimir_productos(Producto** productos, int* cantidad_productos_actual) {
    printf("   ID          Nombre    Stock     Precio\n");
    printf("----- --------------- -------- ----------\n");
<<<<<<< HEAD

    for (int i = 0; i < *cantidad_productos_actual; ++i) {
        printf("%5d %15s %8d %10.2f\n", (*productos)[i].id, (*productos)[i].nombre, (*productos)[i].cantidad_en_stock, (*productos)[i].precio);
    }

    return;
}

void actualizar_producto(Producto** productos, int* cantidad_productos_actual, const char* nombre, int id, int cantidad_en_stock, float precio) {
    //verificar valores para el producto
    if (error_en_producto(productos, cantidad_productos_actual, id, cantidad_en_stock, precio)) {
        printf("Valores invalidos.\n");
        return;
    }
    
    posicion = buscar_pos_id(productos, cantidad_productos_actual, id)
    if (posicion == -1) {
        printf("Valor ID no encontrado.\n")
        return;
    }

    modificar_producto(*(productos+posicion), nombre, id, cantidad_en_stock, precio);
    return;
=======
    for (int i = 0; i < *cantidad_productos_actual; ++i) {
        printf("%5d %15s %8d %10.2f\n", (*productos)[i].id, (*productos)[i].nombre, (*productos)[i].cantidad_en_stock, (*productos)[i].precio);
    }
}

void actualizar_producto(Producto** productos, int* cantidad_productos_actual, Producto producto) {
    //verificar valores para el producto
    if (error_en_producto(producto)) {
        ERROR_VAL;
        return;
    }
    
    int posicion = buscar_pos_id(productos, cantidad_productos_actual, producto.id);
    if (posicion == -1) {
        ERROR_ID;
        return;
    }

    modificar_producto(*(productos+posicion), producto);
    printf("Producto con ID %d actualizado exitosamente.", producto.id);
>>>>>>> 0a1eb9e (version del desktop de la carpeta)
    }

int buscar_pos_id(Producto** productos, int* cantidad_productos_actual, int id) {
    //buscamos el indice del producto segun el id
<<<<<<< HEAD
    for (int i = 0; i < cantidad_productos_actual; ++i) {
        if (id == (*productos)[i]) {
=======
    for (int i = 0; i < *cantidad_productos_actual; ++i) {
        if (id == (*productos)[i].id) {
>>>>>>> 0a1eb9e (version del desktop de la carpeta)
            return i;
        }
    }
    return -1;
}

<<<<<<< HEAD
void modificar_producto(Producto* producto, const char* nombre, int id, int cantidad_en_stock, float precio) {
    copiar_string(nombre, (*producto).nombre);
    (*producto).id = id;
    (*producto).cantidad_en_stock = cantidad_en_stock;
    (*producto).precio = precio;
}

void eliminar_producto(Producto** productos, int* cantidad_productos_actual, int id) {
    posicion = buscar_pos_id(productos, cantidad_productos_actual, id)
    if (posicion == -1) {
        printf("Valor ID no encontrado.\n")
        return;
    }

    for (int i=posicion+1; i<cantidad_productos_actual; ++i) {
        *(productos+i) = *(productos+i+1)
    }

    *(productos+cantidad_productos_actual) = &(Producto producto);
=======
void modificar_producto(Producto* producto, Producto producto_actualizado) {
    copiar_string(producto_actualizado.nombre, (*producto).nombre);
    (*producto).id = producto_actualizado.id;
    (*producto).cantidad_en_stock = producto_actualizado.cantidad_en_stock;
    (*producto).precio = producto_actualizado.precio;
}

void eliminar_producto(Producto** productos, int* cantidad_productos_actual, int id) {
    int pos = buscar_pos_id(productos, cantidad_productos_actual, id);
    if (pos == -1) {
        ERROR_ID;
        return;
    }

    printf("Producto %s con ID %d sera eliminado.\n", (*productos)[pos].nombre, (*productos)[pos].id);

    //hacer que cada puntero iniciando por el que apunta al producto a eliminar apunte al siguiente
    for (int i=pos; i < *cantidad_productos_actual-1; ++i) {
        *(*productos+i) = *(*productos+i+1);
    }

    //y que el ultimo puntero de la lista apunte a un nuevo producto vacio
    Producto producto;
    *(productos+*cantidad_productos_actual) = &producto;

    --(*cantidad_productos_actual);
}

void realizar_venta(Producto** productos, int* cantidad_productos_actual, int id, int cantidad_vendida) {
    int pos = buscar_pos_id(productos, cantidad_productos_actual, id);
    if (pos == -1) {
        ERROR_ID;
        return;
    }

    if (cantidad_vendida > (*productos)[pos].id) {
        ERROR_VAL;
        return;
    }

    (*productos)[pos].cantidad_en_stock -= cantidad_vendida;
    printf("Cantidad en stock del producto %s: %d --> %d \n", (*productos)[pos].nombre, (*productos)[pos].cantidad_en_stock+cantidad_vendida, (*productos)[pos].cantidad_en_stock);
>>>>>>> 0a1eb9e (version del desktop de la carpeta)
}