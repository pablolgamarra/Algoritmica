#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void pausar(void);

void cantProductos(int &);

void seleccionOpcion(int &);

main()
{
    system("cls");
    int n, opcion, promedioCostos = 0, promedioVenta = 0;
    bool productosConEscasez = false;
    cout << "Programa de Control de Stock.\n";
    cantProductos(n);
    int ganancias[n];
    struct Productos
    {
        int codigo;
        string descripcion;
        int cantidad;
        int stock_minimo;
        int costo;
        int precio_venta;
    } Producto[n];
    for (int i = 0; i < n; i++)
    {
        system("cls");
        cout << "Carga de Datos. Producto " << i + 1 << "\n";
        cout << "Ingrese codigo del producto: ";
        cin >> Producto[i].codigo;
        cout << "Ingrese la descripcion del producto: ";
        cin >> Producto[i].descripcion;
        cout << "Ingrese la cantidad que posee en Stock: ";
        cin >> Producto[i].cantidad;
        cout << "Ingrese el stock minimo que debe haber en existencia: ";
        cin >> Producto[i].stock_minimo;
        cout << "Ingrese el costo de compra: ";
        cin >> Producto[i].costo;
        promedioCostos = promedioCostos + Producto[i].costo;
        cout << "Ingrese el precio de venta del producto: ";
        cin >> Producto[i].precio_venta;
        ganancias[i] = Producto[i].precio_venta - Producto[i].costo;
        promedioVenta = promedioVenta + Producto[i].precio_venta;
        pausar();
    }
    do
    {   
        system("cls");
        seleccionOpcion(opcion);
        system("cls");
        switch (opcion)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                cout << "Producto " << i + 1 << "\n";
                cout << "Codigo de Producto: " << Producto[i].codigo << "\n";
                cout << "Descripcion: " << Producto[i].descripcion << "\n";
                cout << "Cantidad en Existencia: " << Producto[i].cantidad << "\n";
                cout << "Stock Minimo: " << Producto[i].stock_minimo << "\n";
                cout << "Costo del Producto: " << Producto[i].costo << "\n";
                cout << "Precio de Venta del Producto: " << Producto[i].precio_venta << "\n";
                cout << "========================================\n";
            }
            pausar();
            break;
        case 2:
            cout << "Productos cuya cantidad es menor al stock minimo necesario.\n";
            for (int i = 0; i < n; i++)
            {
                if (Producto[i].stock_minimo > Producto[i].cantidad)
                {
                    cout << "Producto " << i + 1 << "\nCodigo del Producto: " << Producto[i].codigo << "\n";
                    productosConEscasez = true;
                }
            }
            if (!productosConEscasez)
            {
                cout << "No hay ningun producto cuya cantidad en existencia sea menor al stock minimo.\n";
            }
            pausar();
            break;
        case 3:
            cout << "El promedio de los costos de los productos cargados es: " << promedioCostos / n;
            pausar();
            break;
        case 4:
            cout << "El promedio de los precios de ventas de los productos cargados es: " << promedioVenta / n;
            pausar();
            break;
        case 5:
            for (int i = 0; i < n; i++)
            {
                cout << "Las ganancias son: (Si se muestran en negativo significa que hay una perdida en ese producto.)\n";
                cout << "Producto " << i + 1 << ": " << ganancias[i] << "\n";
            }
            pausar();
            break;
        case 6:
            cout << "Gracias por utilizar el programa.\n";
        default:
            cout << "La opcion seleccionada no es valida.\n";
            break;
        }
    } while (opcion != 6);
    pausar();
    return 0;
}

void pausar(void)
{
    cout << "=====================================\n";
    cout << "Ingrese una tecla para continuar....";
    getch();
}

int validadorEnteros(int n)
{
    if (cin.fail())
    {
        while (cin.fail())
        {
            cin.clear();
            fflush(stdin);
            cout << "Debe ingresarse un dato numerico entero.\n";
            cin >> n;
        }
    }
    else
    {
        return n;
    }
}

void cantProductos(int &n)
{
    cout << "Ingrese la cantidad de productos que desea cargar: ";
    cin >> n;
    while (cin.fail())
    {
        cin.clear();
        fflush(stdin);
        cout << "Debe ingresarse un dato numerico entero.\n";
        cin >> n;
    }
}

void seleccionOpcion(int &opcion)
{
    do
    {
        cout << "1. Imprimir el listado de productos cargados.\n";
        cout << "2. Imprimir productos cuya cantidad sea menor al stock minimo.\n";
        cout << "3. Promedio de Costos.\n";
        cout << "4. Promedio de Precios de Venta.\n";
        cout << "5. Ganancias.\n";
        cout << "6. Salir del Programa.\n";
        cout << "Ingrese el numero de la accion que desea realizar.\n";
        cin >> opcion;
        validadorEnteros(opcion);
    } while (opcion < 1 || opcion > 6);
}

/*
Definir la siguiente estructura Productos con los siguientes elementos: codigo, descripcion, cantidad, 
stock_minimo, costo, precio_venta. Declarar el registro como un
array el cual almacenara una serie de elementos. Crea un menú en donde se expresen los siguientes datos:
1- Listado total de registros
2- Productos cuya cantidad sea inferior al stock mínimo
3- Promedio de costos
4- Promedio de ventas
5- Lista de ganancias
*/