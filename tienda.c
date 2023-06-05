#include <stdio.h>

struct electrodomestico {
    char nombre[50];
    float precio;
    int stock;
};

void agregarElectrodomestico(struct electrodomestico inventario[], int *cantidad) {
    if (*cantidad < 100) {
        struct electrodomestico nuevo;

        printf("Ingrese el nombre del electrodomestico: ");
        scanf("%s", nuevo.nombre);
        printf("Ingrese el precio del electrodomestico: ");
        scanf("%f", &nuevo.precio);
        printf("Ingrese la cantidad en stock: ");
        scanf("%d", &nuevo.stock);

        inventario[*cantidad] = nuevo;
        (*cantidad)++;

        printf("Electrodomestico agregado correctamente.\n");
    } else {
        printf("El inventario está lleno, no se pueden agregar más electrodomesticos.\n");
    }
}

void mostrarInventario(struct electrodomestico inventario[], int cantidad) {
    if (cantidad > 0) {
        printf("Inventario de electrodomesticos:\n");
        for (int i = 0; i < cantidad; i++) {
            printf("Electrodomestico %d:\n", i + 1);
            printf("Nombre: %s\n", inventario[i].nombre);
            printf("Precio: %.2f\n", inventario[i].precio);
            printf("Stock: %d\n", inventario[i].stock);
            printf("---------------------------\n");
        }
    } else {
        printf("El inventario está vacío.\n");
    }
}

int main() {
    struct electrodomestico inventario[100];
    int cantidad = 0;
    int opcion;

    do {
        printf("1. Agregar electrodomestico\n");
        printf("2. Mostrar inventario\n");
        printf("3. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarElectrodomestico(inventario, &cantidad);
                break;
            case 2:
                mostrarInventario(inventario, cantidad);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion incorrecta.\n");
                break;
        }
    } while (opcion != 3);

    return 0;
}
