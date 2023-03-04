#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char *TipoProductos[] = {"Galletas", "Snack", "Cigarrilos", "Caramelos", "Bebidas"};

typedef struct Producto
{
    int productoID;
    int cantidad;
    char *tipoProducto;
    float precioUnitario;
}Producto;

typedef struct Cliente
{
    int clienteID;
    char *nombreCliente;
    int cantidadProductosAPedir;
    Producto *productos;
}Cliente;

float costoProducto(Producto prod);

int main(int argc, char const *argv[])
{
    Cliente *listaClientes;
    int numClientes;
    char *buff;
    srand(time(NULL));
    buff = (char *)malloc(sizeof(char) * 100);
    printf("Ingrese la cantidad de clientes (hasta 5):");
    scanf("%d", &numClientes);
    getchar();

    listaClientes = (Cliente *)malloc(sizeof(Cliente) * numClientes);

    printf("********************************************************\n");
    for (int i = 0; i < numClientes; i++)
    {
        listaClientes[i].clienteID = i + 1;
        printf("Ingrese el nombre del cliente %d: ", listaClientes[i].clienteID);
        gets(buff);
        listaClientes[i].nombreCliente = (char *)malloc(sizeof(char) * strlen(buff));
        strcpy(listaClientes[i].nombreCliente, buff);
        listaClientes[i].cantidadProductosAPedir = rand() % 5 + 1;
        listaClientes[i].productos = (Producto *)malloc(sizeof(Producto) * listaClientes[i].cantidadProductosAPedir);
        for (int j = 0; j < listaClientes[i].cantidadProductosAPedir ; j++)
        {
            listaClientes[i].productos[j].productoID = j + 1;
            listaClientes[i].productos[j].cantidad = rand() % 10 + 1;
            listaClientes[i].productos[j].tipoProducto = TipoProductos[rand() % 4 + 1];
            listaClientes[i].productos[j].precioUnitario = rand() % 100 + 10;
        }
        
    }
    printf("*********************************************************\n");
    printf("Modulo que muestra el listado de clientes\n");
    printf("##################################################################\n");
    for (int i = 0; i < numClientes; i++)
    {
        float totalProducto = 0;
        printf("ID del cliente: %d\n", listaClientes[i].clienteID);
        printf("Nombre del cliente: %s\n", listaClientes[i].nombreCliente);
        printf("cantidad de productos pedidos: %d\n", listaClientes[i].cantidadProductosAPedir);
        printf("lista de producto pedidos\n");
        printf("-------------------------------------------------------------\n");
        for (int j = 0; j < listaClientes[i].cantidadProductosAPedir; j++)
        {
            printf("ID del producto: %d \n",listaClientes[i].productos[j].productoID );
            printf("cantidad del producto: %d \n",listaClientes[i].productos[j].cantidad);
            printf("tipo de producto: %s \n",listaClientes[i].productos[j].tipoProducto);
            printf("Precio unitario del producto: %.2f\n",listaClientes[i].productos[j].precioUnitario );
            totalProducto = totalProducto + costoProducto(listaClientes[i].productos[j]);
        }
        printf("Monto total a pagar: %.2f\n", totalProducto);
        printf("##################################################################\n");
    }
    
    free(buff);
    return 0;
}


float costoProducto(Producto prod){
    return (prod.cantidad * prod.precioUnitario);
}