#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<windows.h> 
#include<string>
#include<conio.h>

using namespace std;

/*Pendientes
    Hacer que no se puedan ingresar codigos repetidos /////////yo si puede gei jeje
    hacer la parte del provedor para que cuando no concida el codigo del proveedor cree uno nuevo, ya que deve existir el proveedor para ingresar el articulo.
    No se muestran bien los acentos, corregir
    Que se pueda modificar codigo de producto en funcion modificarArticulos
    que pregunte si de verdad quiere modifcar el articulo
    hacer que tire mensaje de error cuando no encuentre buscando por nombre
    Hacer que los datos se vean como en una tabla en la funcion verArticulos() con gotoxy
    */

struct art //articulos
{
    int codigo = 0;
    int codProveedor;
    char nombre[100];
    int cantidadTienda;
    int cantidadBodega;
    float precio;
    bool activo = false; //para detectar que codigos estan en uso.

} articulos[100];

struct client //Clientes
{
    int codigo = 0;
    char nombre[100];
    char direccion[100];
    int nit;
    bool activo = false;
} clientes[100];


void generarDatos() //Esta Funcion sirve para Generar los datos base, se generaran 15 array por estructura
{
    //Datos de Articulos
    articulos[1].codigo = 1;
    articulos[1].codProveedor = 200;
    strcpy(articulos[1].nombre, "Arroz");
    articulos[1].cantidadTienda = 50;
    articulos[1].cantidadBodega = 140;
    articulos[1].precio = 30.50;
    articulos[1].activo = true;

    articulos[2].codigo = 2;
    articulos[2].codProveedor = 400;
    strcpy(articulos[2].nombre, "Consomé");
    articulos[2].cantidadTienda = 30;
    articulos[2].cantidadBodega = 100;
    articulos[2].precio = 30.45;
    articulos[2].activo = true;

    articulos[3].codigo = 3;
    articulos[3].codProveedor = 400;
    strcpy(articulos[3].nombre, "Crema de cacahuate");
    articulos[3].cantidadTienda = 24;
    articulos[3].cantidadBodega = 39;
    articulos[3].precio = 25.64;
    articulos[3].activo = true;

    articulos[4].codigo = 4;
    articulos[4].codProveedor = 400;
    strcpy(articulos[4].nombre, "Puré de tomate");
    articulos[4].cantidadTienda = 60;
    articulos[4].cantidadBodega = 200;
    articulos[4].precio = 14.69;
    articulos[4].activo = true;

    articulos[5].codigo = 5;
    articulos[5].codProveedor = 400;
    strcpy(articulos[5].nombre, "Alimento para bebés");
    articulos[5].cantidadTienda = 49;
    articulos[5].cantidadBodega = 600;
    articulos[5].precio = 50;
    articulos[5].activo = true;

    articulos[6].codigo = 6;
    articulos[6].codProveedor = 100;
    strcpy(articulos[6].nombre, "Alimento para mascotas");
    articulos[6].cantidadTienda = 15;
    articulos[6].cantidadBodega = 310;
    articulos[6].precio = 9.5;
    articulos[6].activo = true;

    articulos[7].codigo = 7;
    articulos[7].codProveedor = 100;
    strcpy(articulos[7].nombre, "Incaparina");
    articulos[7].cantidadTienda = 25;
    articulos[7].cantidadBodega = 200;
    articulos[7].precio = 10;
    articulos[7].activo = true;

    articulos[8].codigo = 8;
    articulos[8].codProveedor = 100;
    strcpy(articulos[8].nombre, "Azúcar");
    articulos[8].cantidadTienda = 30;
    articulos[8].cantidadBodega = 90;
    articulos[8].precio = 5.5;
    articulos[8].activo = true;

    articulos[9].codigo = 9;
    articulos[9].codProveedor = 350;
    strcpy(articulos[9].nombre, "Chile piquín");
    articulos[9].cantidadTienda = 3;
    articulos[9].cantidadBodega = 21;
    articulos[9].precio = 13.5;
    articulos[9].activo = true;

    articulos[10].codigo = 10;
    articulos[10].codProveedor = 200;
    strcpy(articulos[10].nombre, "Flan en Polvo");
    articulos[10].cantidadTienda = 15;
    articulos[10].cantidadBodega = 200;
    articulos[10].precio = 9.5;
    articulos[10].activo = true;

    articulos[11].codigo = 11;
    articulos[11].codProveedor = 300;
    strcpy(articulos[11].nombre, "Gelatina en polvo");
    articulos[11].cantidadTienda = 40;
    articulos[11].cantidadBodega = 100;
    articulos[11].precio = 16.5;
    articulos[11].activo = true;

    articulos[12].codigo = 12;
    articulos[12].codProveedor = 400;
    strcpy(articulos[12].nombre, "Sal");
    articulos[12].cantidadTienda = 24;
    articulos[12].cantidadBodega = 891;
    articulos[12].precio = 1.5;
    articulos[12].activo = true;

    articulos[13].codigo = 13;
    articulos[13].codProveedor = 100;
    strcpy(articulos[13].nombre, "Sazonador");
    articulos[13].cantidadTienda = 51;
    articulos[13].cantidadBodega = 159;
    articulos[13].precio = 1;
    articulos[13].activo = true;

    articulos[14].codigo = 14;
    articulos[14].codProveedor = 200;
    strcpy(articulos[14].nombre, "Catsup");
    articulos[14].cantidadTienda = 19;
    articulos[14].cantidadBodega = 210;
    articulos[14].precio = 20;
    articulos[14].activo = true;

    articulos[15].codigo = 15;
    articulos[15].codProveedor = 500;
    strcpy(articulos[15].nombre, "Mayonesa");
    articulos[15].cantidadTienda = 43;
    articulos[15].cantidadBodega = 100;
    articulos[15].precio = 9.5;
    articulos[15].activo = true;

    clientes[1].codigo = 1;
    strcpy(clientes[1].nombre, "Jorge Mejicanos");
    strcpy(clientes[1].direccion, "Amatitlan");
    clientes[1].nit = 111449022;
    clientes[1].activo = true;

    clientes[2].codigo = 2;
    strcpy(clientes[2].nombre, "Oscar Tobias");
    strcpy(clientes[2].direccion, "Palin");
    clientes[2].nit = 449988445;
    clientes[2].activo = true;

    clientes[3].codigo = 3;
    strcpy(clientes[3].nombre, "Juan Gutierrez");
    strcpy(clientes[3].direccion, "Villa nueva");
    clientes[3].nit = 666888775;
    clientes[3].activo = true;

    clientes[4].codigo = 4;
    strcpy(clientes[4].nombre, "Madai Cabrera");
    strcpy(clientes[4].direccion, "San jose");
    clientes[4].nit = 999887744;
    clientes[4].activo = true;

    clientes[5].codigo = 5;
    strcpy(clientes[5].nombre, "Baldomero Fuentes");
    strcpy(clientes[5].direccion, "Zona 13");
    clientes[5].nit = 668889758;
    clientes[5].activo = true;
}

//Metodos de Articulos
void mostrarArticulo(int cod)
{
    cout<<"Codigo de Producto: "<<articulos[cod].codigo<<endl;
    cout<<"Codigo de Provedor: "<<articulos[cod].codProveedor<<endl;
    cout<<"Nombre de Producto: "<<articulos[cod].nombre<<endl;
    cout<<"Cantidad en Tienda: "<<articulos[cod].cantidadTienda<<endl;
    cout<<"Cantidad en Bodega: "<<articulos[cod].cantidadBodega<<endl;
    cout<<"Precio de Producto: "<<articulos[cod].precio<<endl<<endl;
    //cout<<"Activo?: "<<articulos[cod].activo<<endl<<endl;
}

void ingresarArticulos(int cod) //Pendientes, hacer lo del codigo del proveedor
{
    if(articulos[cod].activo == false) //queda mejor con un if
    {
        articulos[cod].activo = true;
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
        cout<<"Este es el articulo: "<<endl<<endl;
        mostrarArticulo(cod);
        system("pause");
    }
    else
    {
        system("cls");
        cout<<"Codigo ya Existente, ingrese uno diferente."<<endl;
        system("pause");
    }
}

void modificarArticulos()
{
    int cod;
    system("cls");
    cout<<"Ingrese el codigo del articulo que desea modificar: ";
    cin>>cod;
    if(articulos[cod].activo == true)
    { 
        cout<<"Estos son los datos actuales del producto: "<<endl<<endl;
        mostrarArticulo(cod);
        system("pause");
        //system("cls");
        articulos[cod].activo = false;
        ingresarArticulos(cod);
    }
    else
    {
        system("cls");
        cout<<"Codigo no Existente"<<endl;
        system("pause");
    }
}

void verArticulos()
{
    system("cls");
    for(int x = 1; x <= 100; x++)
    {
        if(articulos[x].activo == true)
        {
            mostrarArticulo(x);
        }
    }
    system("pause");
}

void eliminarArticulos()
{
    int cod, op;
    system("cls");
    cout<<"Ingrese el codigo del articulo que desea eliminar: ";
    cin>>cod;
    if(articulos[cod].activo == true)
    { 
        cout<<"Estos son los datos actuales del producto: "<<endl<<endl;
        mostrarArticulo(cod);
        cout<<endl<<"Esta seguro de eliminar este articulo? (1 = si, 2 = no): ";
        cin>>op;
        if(op == 1)
        {
            articulos[cod].activo = false;
            system("cls");
            cout<<"Articulo Eliminado Exitosamente"<<endl;
            system("pause");
        }
    }
    else
    {
        system("cls");
        cout<<"Codigo no Existente"<<endl;
        system("pause");
    }
}

void buscarArticulos()
{
    int op, cod, codP, p = 0;

    //Para opcion de busqueda;
    string texto, nombre;
    size_t posicion;

    system("cls");
    cout<<"Buscar Articulos"<<endl;
    cout<<"1.) Por Codigo de Producto"<<endl;
    cout<<"2.) Por Codigo de Proveedor"<<endl;
    cout<<"3.) Por Nombre de Articulo"<<endl;
    cout<<"4.) Cancelar"<<endl<<endl;
    cout<<"Seleccione una opcion de busqueda: ";
    cin>>op;
    switch (op)
    {
        case 1: //por codigo
            system("cls");
            cout<<"Ingrese codigo de articulo: ";
            cin>>cod;
            cout<<endl;
            if(articulos[cod].activo == true)
            {
                mostrarArticulo(cod); 
                system("pause");
            }
            else
            {
                system("cls");
                cout<<"Codigo no Existente"<<endl;
                system("pause");
            }
        break;
    
        case 2: //por proveedor
            system("cls");
            cout<<"Ingrese codigo de proveedor: ";
            cin>>codP;
            cout<<endl;
            system("cls");
            for(int x = 1; x <= 100; x++)
            {
                if(articulos[x].codProveedor == codP)
                {
                    mostrarArticulo(x);
                    p += 1;
                }
            }
            if (p == 0)
            {
                cout<<"Proveedor no existente"<<endl;
            }
            system("pause");
        break;

        case 3:
            system("cls");
            cout<<"Ingrese nombre a buscar: ";
            cin>>nombre;
            for(int x = 1; x <= 100; x++)
            {
                texto = articulos[x].nombre;
                posicion = texto.find(nombre);

                if(posicion != string::npos)
                {
                    mostrarArticulo(x);
                }
            }
            system("pause");
        break;

        default:
        break;
    }
}

void trasladarArticulos()
{
    int cod, op, traslado;
    system("cls");
    cout<<"Ingrese el codigo del articulo a trasladar: ";
    cin>>cod;
    if(articulos[cod].activo == true)
    {
        system("cls");
        cout<<"Informacion del Articulo: "<<endl<<endl;
        mostrarArticulo(cod);
        cout<<"1.) Trasladar de Tienda a Bodega"<<endl;
        cout<<"2.) Trasladar de Bodega a tienda"<<endl;
        cout<<"3.) Cancelar"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>op;
        if(op == 1 && articulos[cod].cantidadTienda > 0) //Tienda a bodega
        {
            system("cls");
            cout<<"Existen "<<articulos[cod].cantidadTienda<<" unidades de "<<articulos[cod].nombre<<" en tienda"<<endl;
            cout<<"Cuantos Requiere trasladar a bodega?: ";
            cin>>traslado;
            if(traslado <= articulos[cod].cantidadTienda && traslado > 0)
            {
                system("cls");
                articulos[cod].cantidadTienda -= traslado;
                articulos[cod].cantidadBodega += traslado;
                cout<<"Se trasladaron "<<traslado<<" unidades de "<<articulos[cod].nombre<<" a bodega"<<endl;
                system("pause");
            }
            else
            {
                system("cls");
                cout<<"Datos invalidos"<<endl;
                system("pause");
            }
        }
        else if(articulos[cod].cantidadTienda == 0)
        {
            system("cls");
            cout<<"No existen Articulos en tienda"<<endl;
            system("pause");
        }
        if(op == 2 && articulos[cod].cantidadBodega > 0) //bodega a tienda
        {
            system("cls");
            cout<<"Existen "<<articulos[cod].cantidadBodega<<" unidades de "<<articulos[cod].nombre<<" en bodega"<<endl;
            cout<<"Cuantos Requiere trasladar a tienda?: ";
            cin>>traslado;
            if(traslado <= articulos[cod].cantidadBodega && traslado > 0)
            {
                system("cls");
                articulos[cod].cantidadTienda += traslado;
                articulos[cod].cantidadBodega -= traslado;
                cout<<"Se trasladaron "<<traslado<<" unidades de "<<articulos[cod].nombre<<" a tienda"<<endl;
                system("pause");
            }
            else
            {
                system("cls");
                cout<<"Datos invalidos"<<endl;
                system("pause");
            }
        }
        else if(articulos[cod].cantidadBodega == 0)
        {
            system("cls");
            cout<<"No existen Articulos en bodega"<<endl;
            system("pause");
        }
    }
    else
    {
        system("cls");
        cout<<"Codigo no Existente"<<endl;
        system("pause");
    }
}

// Metodos de Clientes
void mostrarCliente(int cod)
{
    cout<<"Codigo de Cliente: "<<clientes[cod].codigo<<endl;
    cout<<"Nombre de Cliente: "<<clientes[cod].nombre<<endl;
    cout<<"Direccion de Cliente: "<<clientes[cod].direccion<<endl;
    cout<<"Nit de Cliente: "<<clientes[cod].nit<<endl<<endl;
}

void ingresarClientes(int cod)
{
    if(clientes[cod].activo == false) //queda mejor con un if
    {
        clientes[cod].activo = true;
        clientes[cod].codigo = cod;
        cout<<"Ingrese Nombre del Cliente: ";
        fflush(stdin); //Sepa, pero sin esta linea no funciona el cin.getline xd
        cin.getline(clientes[cod].nombre, 100);
        cout<<"Ingrese la Direccion: ";
        cin>>clientes[cod].direccion;
        cout<<"Ingrese el Nit: ";
        cin>>clientes[cod].nit;
        system("cls");
        cout<<"Este es el cliente: "<<endl<<endl;
        mostrarCliente(cod);
        system("pause");
    }
    else
    {
        system("cls");
        cout<<"Codigo ya Existente, ingrese uno diferente."<<endl;
        system("pause");
    }
}

void modificarClientes()
{
    int cod;
    system("cls");
    cout<<"Ingrese el codigo del cliente que desea modificar: ";
    cin>>cod;
    if(clientes[cod].activo == true)
    { 
        cout<<"Estos son los datos actuales del cliente: "<<endl<<endl;
        mostrarCliente(cod);
        system("pause");
        //system("cls");
        clientes[cod].activo = false;
        ingresarClientes(cod);
    }
    else
    {
        system("cls");
        cout<<"Codigo no Existente"<<endl;
        system("pause");
    }
}

void buscarClientes()
{
    int op, cod, codP, p = 0;

    //Para opcion de busqueda;
    string texto, nombre;
    size_t posicion;

    system("cls");
    cout<<"Buscar Clientes"<<endl;
    cout<<"1.) Por Codigo de Cliente"<<endl;
    cout<<"2.) Por NIT de Cliente"<<endl;
    cout<<"3.) Por Nombre de Cliente"<<endl;
    cout<<"4.) Por Direccion de Cliente"<<endl;
    cout<<"5.) Cancelar"<<endl<<endl;
    cout<<"Seleccione una opcion de busqueda: ";
    cin>>op;
    switch (op)
    {
        case 1: //por codigo
            system("cls");
            cout<<"Ingrese codigo de Cliente: ";
            cin>>cod;
            cout<<endl;
            if(clientes[cod].activo == true)
            {
                mostrarCliente(cod); 
                system("pause");
            }
            else
            {
                system("cls");
                cout<<"Codigo no Existente"<<endl;
                system("pause");
            }
        break;
    
        case 2: //por proveedor
            system("cls");
            cout<<"Ingrese NIT de Cliente: ";
            cin>>codP;
            cout<<endl;
            system("cls");
            for(int x = 1; x <= 100; x++)
            {
                if(clientes[x].nit == codP)
                {
                    mostrarCliente(x);
                    p += 1;
                }
            }
            if (p == 0)
            {
                cout<<"NIT no existente"<<endl;
            }
            system("pause");
        break;

        case 3:
            system("cls");
            cout<<"Ingrese nombre a buscar: ";
            cin>>nombre;
            for(int x = 1; x <= 100; x++)
            {
                texto = clientes[x].nombre;
                posicion = texto.find(nombre);

                if(posicion != string::npos)
                {
                    system("cls");
                    cout<<"Datos Encontrados: "<<endl;
                    mostrarCliente(x);
                }
            }
            system("pause");
        break;

        case 4:
            system("cls");
            cout<<"Ingrese Direccion a buscar: ";
            cin>>nombre;
            for(int x = 1; x <= 100; x++)
            {
                texto = clientes[x].direccion;
                posicion = texto.find(nombre);

                if(posicion != string::npos)
                {
                    system("cls");
                    cout<<"Datos Encontrados: "<<endl;
                    mostrarCliente(x);
                }
            }
            system("pause");
        break;

        default:
        break;
    }
}

void eliminarClientes()
{
    int cod, op;
    system("cls");
    cout<<"Ingrese el codigo del Cliente que desea eliminar: ";
    cin>>cod;
    if(clientes[cod].activo == true)
    { 
        cout<<"Estos son los datos actuales del Cliente: "<<endl<<endl;
        mostrarCliente(cod);
        cout<<endl<<"Esta seguro de eliminar este Cliente? (1 = si, 2 = no): ";
        cin>>op;
        if(op == 1)
        {
            clientes[cod].activo = false;
            system("cls");
            cout<<"Cliente Eliminado Exitosamente"<<endl;
            system("pause");
        }
    }
    else
    {
        system("cls");
        cout<<"Codigo no Existente"<<endl;
        system("pause");
    }
}

void verClientes()
{
    system("cls");
    for(int x = 1; x <= 100; x++)
    {
        if(clientes[x].activo == true)
        {
            mostrarCliente(x);
        }
    }
    system("pause");
}

//Metodos de Proveedores


main()
{
    int opcion, op1, cod;
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
                cout<<"5.) Ver todo"<<endl;
                cout<<"6.) Traslados"<<endl;
                cout<<"7.) Regresar"<<endl<<endl;
                cout<<"Seleccione una opcion: ";
                cin>>op1;
                switch (op1)
                {
                    case 1:
                        system("cls");
                        cout<<"SUPERTIENDA MAS+"<<endl<<endl;
                        cout<<"Ingresar Articulos"<<endl;
                        cout<<"Ingrese Codigo (1-100): ";
                        cin>>cod;
                        ingresarArticulos(cod);
                    break;

                    case 2:
                        modificarArticulos();
                    break;

                    case 3:
                        buscarArticulos();
                    break;

                    case 4:
                        eliminarArticulos();
                    break;

                    case 5:
                        verArticulos();
                    break;
                    
                    case 6:
                        trasladarArticulos();
                    break;

                    case 7:
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
                cout<<"5.) Ver todo"<<endl;
                cout<<"6.) Regresar"<<endl<<endl;
                cout<<"Seleccione una opcion: ";
                cin>>op1;
                switch (op1)
                {
                    case 1:
                        system("cls");
                        cout<<"SUPERTIENDA MAS+"<<endl<<endl;
                        cout<<"Ingresar Clientes"<<endl;
                        cout<<"Ingrese Codigo (1-100): ";
                        cin>>cod;
                        ingresarClientes(cod);
                    break;

                    case 2:
                        modificarClientes();
                    break;

                    case 3:
                        buscarClientes();
                    break;

                    case 4:
                        eliminarClientes();
                    break;

                    case 5:
                        verClientes();
                    break;

                    case 6:
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