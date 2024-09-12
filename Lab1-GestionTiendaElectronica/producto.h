<<<<<<< HEAD
#include <stdbool.h>
=======
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ERROR_ID printf("Valor ID no encontrado.\n")

#define ERROR_VAL printf("Valores invalidos. \n")
>>>>>>> 0a1eb9e (version del desktop de la carpeta)

typedef struct {
    int id;
    char nombre[50];
    float precio;
    int cantidad_en_stock;
} Producto;

<<<<<<< HEAD
void agregar_producto(Producto** productos, int* capacidad_arreglo, int* cantidad_productos_actual, const char* nombre, int id, int cantidad_en_stock, float precio);

void copiar_string(const char* fuente, char* destino); //credito a Diego Orozco

bool error_en_producto(Producto** productos, int* cantidad_productos_actual, int id, int cantidad_en_stock, float precio);
=======
void agregar_producto(Producto** productos, int* capacidad_arreglo, int* cantidad_productos_actual, Producto producto);

void copiar_string(const char* fuente, char* destino); //credito a Diego Orozco

bool error_en_producto(Producto producto);
>>>>>>> 0a1eb9e (version del desktop de la carpeta)

void imprimir_productos(Producto** productos, int* cantidad_productos_actual);

void eliminar_producto(Producto** productos, int* cantidad_productos_actual, int id);

<<<<<<< HEAD
int buscar_pos_id(Producto** productos, int* cantidad_productos_actual, int id);
=======
int buscar_pos_id(Producto** productos, int* cantidad_productos_actual, int id);

void actualizar_producto(Producto** productos, int* cantidad_productos_actual, Producto producto);

int buscar_pos_id(Producto** productos, int* cantidad_productos_actual, int id);

void modificar_producto(Producto* producto, Producto producto_actualizado);

void duplicar_capacidad(Producto** productos, int* capacidad_arreglo);

void realizar_venta(Producto** productos, int* cantidad_productos_actual, int id, int cantidad_vendida);
>>>>>>> 0a1eb9e (version del desktop de la carpeta)
