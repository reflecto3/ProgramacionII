#include <stdbool.h>

typedef struct {
    int id;
    char nombre[50];
    float precio;
    int cantidad_en_stock;
} Producto;

void agregar_producto(Producto** productos, int* capacidad_arreglo, int* cantidad_productos_actual, const char* nombre, int id, int cantidad_en_stock, float precio);

void copiar_string(const char* fuente, char* destino); //credito a Diego Orozco

bool error_en_producto(Producto** productos, int* cantidad_productos_actual, int id, int cantidad_en_stock, float precio);

void imprimir_productos(Producto** productos, int* cantidad_productos_actual);

void eliminar_producto(Producto** productos, int* cantidad_productos_actual, int id);

int buscar_pos_id(Producto** productos, int* cantidad_productos_actual, int id);