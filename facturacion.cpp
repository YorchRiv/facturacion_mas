#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<windows.h> 
#include<string>
using namespace std;

/*Pendientes
    Hacer que no se puedan ingresar codigos repetidos /////////ya  me rendi ma;ana sigo jajajaja
    hacer la parte del provedor para que cuando no concida el codigo del proveedor cree uno nuevo
*/

int maxArt = 5;

struct art //articulos
{
    int codigo;
    int codProveedor;
    char nombre[100];
    int cantidadTienda;
    int cantidadBodega;
    float precio;

} articulos[100];

void generarDatos() //Esta Funcion sirve para Generar los datos base, se generaran 5 array por estructura
{
    //Datos de Articulos
    articulos[1].codigo = 1;
    articulos[1].codProveedor = 200;
    strcpy(articulos[1].nombre, "Arroz");
    articulos[1].cantidadTienda = 50;
    articulos[1].cantidadBodega = 140;
    articulos[1].precio = 30.50;

    articulos[2].codigo = 2;
    articulos[2].codProveedor = 400;
    strcpy(articulos[2].nombre, "Consomé");
    articulos[2].cantidadTienda = 30;
    articulos[2].cantidadBodega = 100;
    articulos[2].precio = 30.45;

    articulos[3].codigo = 3;
    articulos[3].codProveedor = 400;
    strcpy(articulos[3].nombre, "Crema de cacahuate");
    articulos[3].cantidadTienda = 24;
    articulos[3].cantidadBodega = 39;
    articulos[3].precio = 25.64;

    articulos[4].codigo = 4;
    articulos[4].codProveedor = 400;
    strcpy(articulos[4].nombre, "Puré de tomate");
    articulos[4].cantidadTienda = 60;
    articulos[4].cantidadBodega = 200;
    articulos[4].precio = 14.69;

    articulos[5].codigo = 5;
    articulos[5].codProveedor = 400;
    strcpy(articulos[5].nombre, "Alimento para bebés");
    articulos[5].cantidadTienda = 49;
    articulos[5].cantidadBodega = 600;
    articulos[5].precio = 50;

    articulos[6].codigo = 6;
    articulos[6].codProveedor = 100;
    strcpy(articulos[6].nombre, "Alimento para mascotas");
    articulos[6].cantidadTienda = 15;
    articulos[6].cantidadBodega = 310;
    articulos[6].precio = 9.5;

    articulos[7].codigo = 7;
    articulos[7].codProveedor = 100;
    strcpy(articulos[7].nombre, "Incaparina");
    articulos[7].cantidadTienda = 25;
    articulos[7].cantidadBodega = 200;
    articulos[7].precio = 10;

    articulos[8].codigo = 8;
    articulos[8].codProveedor = 100;
    strcpy(articulos[8].nombre, "Azúcar");
    articulos[8].cantidadTienda = 30;
    articulos[8].cantidadBodega = 90;
    articulos[8].precio = 5.5;

    articulos[9].codigo = 9;
    articulos[9].codProveedor = 350;
    strcpy(articulos[9].nombre, "Chile piquín");
    articulos[9].cantidadTienda = 3;
    articulos[9].cantidadBodega = 21;
    articulos[9].precio = 13.5;

    articulos[10].codigo = 10;
    articulos[10].codProveedor = 200;
    strcpy(articulos[10].nombre, "Flan en Polvo");
    articulos[10].cantidadTienda = 15;
    articulos[10].cantidadBodega = 200;
    articulos[10].precio = 9.5;

    articulos[11].codigo = 11;
    articulos[11].codProveedor = 300;
    strcpy(articulos[11].nombre, "Gelatina en polvo");
    articulos[11].cantidadTienda = 40;
    articulos[11].cantidadBodega = 100;
    articulos[11].precio = 16.5;

    articulos[12].codigo = 12;
    articulos[12].codProveedor = 400;
    strcpy(articulos[12].nombre, "Sal");
    articulos[12].cantidadTienda = 24;
    articulos[12].cantidadBodega = 891;
    articulos[12].precio = 1.5;

    articulos[13].codigo = 13;
    articulos[13].codProveedor = 100;
    strcpy(articulos[13].nombre, "Sazonador");
    articulos[13].cantidadTienda = 51;
    articulos[13].cantidadBodega = 159;
    articulos[13].precio = 1;

    articulos[14].codigo = 14;
    articulos[14].codProveedor = 200;
    strcpy(articulos[14].nombre, "Catsup");
    articulos[14].cantidadTienda = 19;
    articulos[14].cantidadBodega = 210;
    articulos[14].precio = 20;

    articulos[15].codigo = 15;
    articulos[15].codProveedor = 500;
    strcpy(articulos[15].nombre, "Mayonesa");
    articulos[15].cantidadTienda = 43;
    articulos[15].cantidadBodega = 100;
    articulos[15].precio = 9.5;
}

void mostrarArticulo(int cod)
{
    cout<<"Este es el articulo ingresado: "<<endl<<endl;
    cout<<"Codigo de Producto: "<<articulos[cod].codigo<<endl;
    cout<<"Codigo de Provedor: "<<articulos[cod].codProveedor<<endl;
    cout<<"Nombre de Producto: "<<articulos[cod].nombre<<endl;
    cout<<"Cantidad en Tienda: "<<articulos[cod].cantidadTienda<<endl;
    cout<<"Cantidad en Bodega: "<<articulos[cod].cantidadBodega<<endl;
    cout<<"Precio de Producto: "<<articulos[cod].precio<<endl<<endl;
}

void ingresarArticulos()
{
    int cod;
    system("cls");
    cout<<"SUPERTIENDA MAS+"<<endl<<endl;
    cout<<"Ingresar Articulos"<<endl;
    cout<<"Ingrese Codigo (1-100): ";
    cin>>cod;
    while (cod =! articulos[cod].codigo){    //el while es para ver que el codigo que se ingrese no sea igual a que tenemos ya
        articulos[cod].codigo = cod;
        cout<<"Ingrese Codigo de Proveedor: ";
        cin>>articulos[cod].codProveedor;
        cout<<"Ingrese Nombre del Producto: ";
        fflush(stdin); //Sepa, pero sin esta linea no funciona el cin.getline xd
        cin.getline(articulos[cod].nombre, 100); //Para que se pueda ingresar cadenas de texto con espacios
        cout<<"Ingrese la Cantidad en Tienda: ";
        cin>>articulos[cod].cantidadTienda;
        cout<<"Ingrese la Cantidad en Bodega: ";
        cin>>articulos[cod].cantidadBodega;
        cout<<"Ingrese el Precio: ";
        cin>>articulos[cod].precio;
        system("cls");
        mostrarArticulo(cod);
        system("pause");
        }
        system("cls");
        cout<<"Articulo ya ingresado."<<endl;
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
                cout<<"3.) Ver"<<endl;
                cout<<"4.) Buscar"<<endl;
                cout<<"5.) Eliminar"<<endl;
                cout<<"6.) Traslados"<<endl;
                cout<<"7.) Regresar"<<endl<<endl;
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