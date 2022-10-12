#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<windows.h> 
using namespace std;
main()
{
    int opcion, op1;
    bool repeticion = true;
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