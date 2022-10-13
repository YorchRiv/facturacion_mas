#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<windows.h> 
using namespace std;

struct art //articulos
{
    int codigo;
    int codProveedor;
    string nombre;
    int cantidadTienda;
    int cantidadBodega;
    float precio;

} articulos[50];

void generarDatos() //Esta Funcion sirve para Generar los datos base, se generaran 5 array por estructura
{
    //Datos de Articulos
    articulos[1].codigo = 1;
    articulos[1].codProveedor = 200;
    articulos[1].nombre = "Carne de Res (libra)";
    articulos[1].cantidadTienda = 50;
    articulos[1].cantidadBodega = 140;
    articulos[1].precio = 30.50;

    articulos[2].codigo = 2;
    articulos[2].codProveedor = 400;
    articulos[2].nombre = "Carton de Huevos";
    articulos[2].cantidadTienda = 30;
    articulos[2].cantidadBodega = 100;
    articulos[2].precio = 30.45;

    articulos[3].codigo = 3;
    articulos[3].codProveedor = 400;
    articulos[3].nombre = "Galon de Leche Lala";
    articulos[3].cantidadTienda = 24;
    articulos[3].cantidadBodega = 39;
    articulos[3].precio = 25.64;

    articulos[4].codigo = 4;
    articulos[4].codProveedor = 400;
    articulos[4].nombre = "Aceite de Cocina";
    articulos[4].cantidadTienda = 60;
    articulos[4].cantidadBodega = 200;
    articulos[4].precio = 14.69;

    articulos[5].codigo = 5;
    articulos[5].codProveedor = 400;
    articulos[5].nombre = "Libra de Arroz";
    articulos[5].cantidadTienda = 49;
    articulos[5].cantidadBodega = 600;
    articulos[5].precio = 5.50;
}

void ingresarArticulos()
{
    system("cls");
    for(int x = 1; x<5; x++)
    {
        cout<<articulos[x].codigo<<endl;
        cout<<articulos[x].codProveedor<<endl;
        cout<<articulos[x].nombre<<endl;
        cout<<articulos[x].cantidadTienda<<endl;
        cout<<articulos[x].cantidadBodega<<endl;
        cout<<articulos[x].precio<<endl<<endl;
    }
    system("pause");
}

main()
{
    int opcion, op1;
    bool repeticion = true;
    generarDatos();
    while(repeticion == true)
    {
        system("cls"); //Se inicia el primer menu de inicio
        cout<<"SUPERTIENDA MAS+"<<endl<<endl;
        cout<<"Menu Principal"<<endl;
        cout<<"1.) Articulos"<<endl;
        cout<<"2.) Clientes"<<endl;
        cout<<"3.) Facturacion"<<endl;
        cout<<"4.) Proveedores"<<endl;
        cout<<"5.) Empleados"<<endl;
        cout<<"6.) Reportes"<<endl;
        cout<<"7.) Salir"<<endl<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion;
        switch (opcion)
        {
            //Articulos
            case 1:
                system("cls");
                cout<<"SUPERTIENDA MAS+"<<endl<<endl;
                cout<<"Articulos"<<endl;
                cout<<"1.) Ingresar"<<endl;
                cout<<"2.) Modificar"<<endl;
                cout<<"3.) Buscar"<<endl;
                cout<<"4.) Eliminar"<<endl;
                cout<<"5.) Traslados"<<endl;
                cout<<"6.) Regresar"<<endl<<endl;
                cout<<"Seleccione una opcion: ";
                cin>>op1;
                switch (op1)
                {
                    case 1:
                        ingresarArticulos();
                    break;

                    case 2:
                    break;

                    case 3:
                    break;

                    case 4:
                    break;

                    case 5:
                    break;
                    
                    case 6:
                        repeticion = true;
                    break;

                    default:
                    break;
                }
            break;

            //Clientes
            case 2:
                system("cls");
                cout<<"SUPERTIENDA MAS+"<<endl<<endl;
                cout<<"Clientes"<<endl;
                cout<<"1.) Ingresar"<<endl;
                cout<<"2.) Modificar"<<endl;
                cout<<"3.) Buscar"<<endl;
                cout<<"4.) Eliminar"<<endl;
                cout<<"5.) Regresar"<<endl<<endl;
                cout<<"Seleccione una opcion: ";
                cin>>op1;
                switch (op1)
                {
                    case 1:
                    break;

                    case 2:
                    break;

                    case 3:
                    break;

                    case 4:
                    break;

                    case 5:
                        repeticion = true;
                    break;

                    default:
                    break;
                }
            break;

            //Facturacion
            case 3:
                //Llamar funcion facturacion()
            break;

            //Proveedores
            case 4:
                system("cls");
                cout<<"SUPERTIENDA MAS+"<<endl<<endl;
                cout<<"Proveedores"<<endl;
                cout<<"1.) Ingresar"<<endl;
                cout<<"2.) Modificar"<<endl;
                cout<<"3.) Buscar"<<endl;
                cout<<"4.) Eliminar"<<endl;
                cout<<"5.) Regresar"<<endl<<endl;
                cout<<"Seleccione una opcion: ";
                cin>>op1;
                switch (op1)
                {
                    case 1:
                    break;

                    case 2:
                    break;

                    case 3:
                    break;

                    case 4:
                    break;

                    case 5:
                        repeticion = true;
                    break;

                    default:
                    break;
                }
            break;

            //Empleados
            case 5:
                system("cls");
                cout<<"SUPERTIENDA MAS+"<<endl<<endl;
                cout<<"Empleados"<<endl;
                cout<<"1.) Ingresar"<<endl;
                cout<<"2.) Modificar"<<endl;
                cout<<"3.) Buscar"<<endl;
                cout<<"4.) Eliminar"<<endl;
                cout<<"5.) Regresar"<<endl<<endl;
                cout<<"Seleccione una opcion: ";
                cin>>op1;
                switch (op1)
                {
                    case 1:
                    break;

                    case 2:
                    break;

                    case 3:
                    break;

                    case 4:
                    break;

                    case 5:
                        repeticion = true;
                    break;

                    default:
                    break;
                }
            break;

            //Reportes
            case 6:
                system("cls");
                cout<<"SUPERTIENDA MAS+"<<endl<<endl;
                cout<<"Reportes"<<endl;
                cout<<"1.) Facturas"<<endl;
                cout<<"2.) Articulos mas vendidos"<<endl;
                cout<<"3.) Articulos en bodega"<<endl;
                cout<<"4.) Articulos en tienda"<<endl;
                cout<<"5.) Clientes"<<endl;
                cout<<"6.) Proveedores"<<endl;
                cout<<"7.) Empleados"<<endl;
                cout<<"8.) Regresar"<<endl<<endl;
                cout<<"Seleccione una opcion: ";
                cin>>op1;
                switch (op1)
                {
                    case 1:
                    break;

                    case 2:
                    break;

                    case 3:
                    break;

                    case 4:
                    break;

                    case 5:
                    break;

                    case 6:
                    break;

                    case 7:
                    break;

                    case 8:
                        repeticion = true;
                    break;

                    default:
                    break;
                }
            break;

            case 7:
                repeticion = false;
            break;
        
            default:    
            break;
        }
    }
}