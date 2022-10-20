#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<windows.h> 
#include<string>
#include<conio.h>

using namespace std;

/*Pendientes
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

struct prov
{
    int codigo = 0;
    char nombre[100];
    char direccion[100];
    int nit;
    int telefono;
    bool activo = false;
}proveedores[100];

struct emp //empleados
{
    int codigo = 0;
    char nombre[100];
    char puesto[100];
    bool activo = false;

}empleados[100];

void gotoxy(int x,int y){  
	HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos; 
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}

void generarDatos() //Esta Funcion sirve para Generar los datos base, se generaran 15 array por estructura
{
    //Datos de Articulos
    articulos[1].codigo = 1;
    articulos[1].codProveedor = 100;
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
    articulos[9].codProveedor = 200;
    strcpy(articulos[9].nombre, "Chile piquín");
    articulos[9].cantidadTienda = 3;
    articulos[9].cantidadBodega = 21;
    articulos[9].precio = 13.5;
    articulos[9].activo = true;

    articulos[10].codigo = 10;
    articulos[10].codProveedor = 300;
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

    proveedores[1].codigo = 100;
    strcpy(proveedores[1].nombre, "Productos Macarena");
    strcpy(proveedores[1].direccion, "Guatemela");
    proveedores[1].nit = 668889758;
    proveedores[1].telefono = 50889976;
    proveedores[1].activo = true;
    
    proveedores[2].codigo = 200;
    strcpy(proveedores[2].nombre, "La Popular");
    strcpy(proveedores[2].direccion, "Guatemela");
    proveedores[2].nit = 864884458;
    proveedores[2].telefono = 60604500;
    proveedores[2].activo = true;

    proveedores[3].codigo = 300;
    strcpy(proveedores[3].nombre, "Productos Castilla");
    strcpy(proveedores[3].direccion, "Zona 10");
    proveedores[3].nit = 333445566;
    proveedores[3].telefono = 40658977;
    proveedores[3].activo = true;

    proveedores[4].codigo = 400;
    strcpy(proveedores[4].nombre, "MexiProductos");
    strcpy(proveedores[4].direccion, "Mexico");
    proveedores[4].nit = 3145689;
    proveedores[4].telefono = 50889976;
    proveedores[4].activo = true;

    proveedores[5].codigo = 500;
    strcpy(proveedores[5].nombre, "Ingenio Pantaleon");
    strcpy(proveedores[5].direccion, "Escuintla");
    proveedores[5].nit = 667854233;
    proveedores[5].telefono = 90904500;
    proveedores[5].activo = true;

    empleados[1].codigo = 1;
    strcpy(empleados[1].nombre, "Alberto Monroy" );
    strcpy(empleados[1].puesto, "Cajero" );
    empleados[1].activo = true;

    empleados[2].codigo = 2;
    strcpy(empleados[2].nombre, "Roberto Ramirez" );
    strcpy(empleados[2].puesto, "Cajero" );
    empleados[2].activo = true;

    empleados[3].codigo = 3;
    strcpy(empleados[3].nombre, "Mynor Osorio" );
    strcpy(empleados[3].puesto, "Cajero" );
    empleados[3].activo = true;

    empleados[4].codigo = 4;
    strcpy(empleados[4].nombre, "Juan Gutierrez" );
    strcpy(empleados[4].puesto, "Cajero" );
    empleados[4].activo = true;
}

bool existeProv(int cod)
{
    for(int x = 1; x <= 100; x++)
    {
        if(proveedores[x].codigo == cod)
        {
            return true;
            break;
        }
        if(x == 100 and proveedores[x].codigo != cod)
        {
            return false;
            break;
        }
    }
}

//Metodos de Proveedores
int generarCodProv(int cod) //Esta funcion recibiara el codigo del proveedor y devolvera su valor en el array
{
    for(int x = 1; x <= 100; x++)
    {
        if(proveedores[x].codigo == cod)
        {
            return x;
            break;
        }
    }
}

int arrayProv() //Esta funcion devolvera el numero del array mas cercano que este vacio.
{
    for(int x = 1; x <= 100; x++)
    {
        if(proveedores[x].activo == false)
        {
            return x;
            break;
        }
    }
}

void mostrarProv(int cod)
{
    cout<<"Codigo de Proveedor: "<<proveedores[cod].codigo<<endl;
    cout<<"Nombre de Proveedor: "<<proveedores[cod].nombre<<endl;
    cout<<"Direccion de Proveedor: "<<proveedores[cod].direccion<<endl;
    cout<<"Nit de Proveedor: "<<proveedores[cod].nit<<endl;
    cout<<"Telefono de Proveedor: "<<proveedores[cod].telefono<<endl<<endl;
}

void ingresarProv(int codd)
{
    int cod;
    cod = arrayProv();
    if(proveedores[cod].activo == false) //queda mejor con un if
    {
        proveedores[cod].activo = true;
        proveedores[cod].codigo = codd;
        cout<<"Ingrese Nombre del Proveedor: ";
        fflush(stdin);
        cin.getline(proveedores[cod].nombre, 100);
        cout<<"Ingrese la Direccion: ";
        fflush(stdin);
        cin.getline(proveedores[cod].direccion, 100);
        cout<<"Ingrese el Nit: ";
        cin>>proveedores[cod].nit;
        cout<<"Ingrese el Telefono: ";
        cin>>proveedores[cod].telefono;
        system("cls");
        cout<<"Este es el Proveedor: "<<endl<<endl;
        mostrarProv(cod);
        system("pause");
    }
    else
    {
        system("cls");
        cout<<"Codigo ya Existente, ingrese uno diferente."<<endl;
        system("pause");
    }
}

void modificarProv()
{
    int cod, codPP;
    system("cls");

    system("cls");
    cout<<"Ingrese el codigo del proveedor que desea modificar: ";
    cin>>cod;
    codPP = generarCodProv(cod);
    cout<<codPP<<endl;
    system("pause");
    if(proveedores[codPP].activo == true)
    { 
        cout<<"Estos son los datos actuales del Proveedor: "<<endl<<endl;
        mostrarProv(codPP);
        cout<<endl;
        system("pause");
        cout<<endl;
        //system("cls");
        proveedores[codPP].activo = false;
        ingresarProv(cod);
    }
    else
    {
        system("cls");
        cout<<"Codigo no Existente"<<endl;
        system("pause");
    }
}

void buscarProv()
{
    int op, cod, codP, p = 0;
    int codPP;

    //Para opcion de busqueda;
    string texto, nombre;
    size_t posicion;

    system("cls");
    cout<<"Buscar Clientes"<<endl;
    cout<<"1.) Por Codigo de Proveedor"<<endl;
    cout<<"2.) Por NIT de Proveedor"<<endl;
    cout<<"3.) Por Nombre de Proveedor"<<endl;
    cout<<"4.) Por Direccion de Proveedor"<<endl;
    cout<<"5.) Cancelar"<<endl<<endl;
    cout<<"Seleccione una opcion de busqueda: ";
    cin>>op;
    switch (op)
    {
        case 1: //por codigo
            system("cls");
            cout<<"Ingrese codigo de Proveedor: ";
            cin>>cod;
            codPP = generarCodProv(cod);
            cout<<endl;
            if(proveedores[codPP].activo == true)
            {
                mostrarProv(codPP);
                system("pause");
            }
            else
            {
                system("cls");
                cout<<"Codigo no Existente"<<endl;
                system("pause");
            }
        break;
    
        case 2: //por nit
            system("cls");
            cout<<"Ingrese NIT de Proveedor: ";
            cin>>codP;
            cout<<endl;
            system("cls");
            for(int x = 1; x <= 100; x++)
            {
                if(proveedores[x].nit == codP)
                {
                    mostrarProv(x);
                    p += 1;
                }
            }
            if (p == 0)
            {
                cout<<"NIT no existente"<<endl;
            }
            system("pause");
        break;

        case 3: //nombre
            system("cls");
            cout<<"Ingrese nombre a buscar: ";
            cin>>nombre;
            for(int x = 1; x <= 100; x++)
            {
                texto = proveedores[x].nombre;
                posicion = texto.find(nombre);

                if(posicion != string::npos)
                {
                    system("cls");
                    cout<<"Datos Encontrados: "<<endl;
                    mostrarProv(x);
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
                texto = proveedores[x].direccion;
                posicion = texto.find(nombre);

                if(posicion != string::npos)
                {
                    system("cls");
                    cout<<"Datos Encontrados: "<<endl;
                    mostrarProv(x);
                }
            }
            system("pause");
        break;

        default:
        break;
    }
}

void eliminarProv()
{
    int cod, codd, op;
    system("cls");
    cout<<"Ingrese el codigo del Proveedor que desea eliminar: ";
    cin>>codd;
    cod = generarCodProv(codd);
    if(proveedores[cod].activo == true)
    { 
        cout<<"Estos son los datos actuales del Proveedor: "<<endl<<endl;
        mostrarProv(cod);
        cout<<endl<<"Esta seguro de eliminar este Proveedor? (1 = si, 2 = no): ";
        cin>>op;
        if(op == 1)
        {
            proveedores[cod].activo = false;
            system("cls");
            cout<<"Proveedor Eliminado Exitosamente"<<endl;
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

void verProv()
{
    system("cls");
    for(int x = 1; x <= 100; x++)
    {
        if(proveedores[x].activo == true)
        {
            mostrarProv(x);
        }
    }
    system("pause");
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

void ingresarArticulos(int cod)
{
    int codp, codpp, op;
    bool c = true;
    if(articulos[cod].activo == false) //queda mejor con un if
    {
        cout<<"Ingrese Codigo de Proveedor: ";
        cin>>codpp;
        while(c == true)
        {
            codp = generarCodProv(codpp);
            if(existeProv(codpp) == true)
            {
                system("cls");
                cout<<"Codigo de Producto: "<<cod<<endl;
                cout<<"Codigo de Proveedor: "<<proveedores[codp].codigo<<endl;
                cout<<"Nombre del Proveedor: "<<proveedores[codp].nombre<<endl;
                cout<<"Ingrese Nombre del Producto: ";
                fflush(stdin); //Sepa, pero sin esta linea no funciona el cin.getline xd
                cin.getline(articulos[cod].nombre, 100); //Para que se pueda ingresar cadenas de texto con espacios
                cout<<"Ingrese la Cantidad en Tienda: ";
                cin>>articulos[cod].cantidadTienda;
                cout<<"Ingrese la Cantidad en Bodega: ";
                cin>>articulos[cod].cantidadBodega;
                cout<<"Ingrese el Precio: ";
                cin>>articulos[cod].precio;
                articulos[cod].codProveedor = codpp;
                articulos[cod].activo = true;
                articulos[cod].codigo = cod;
                system("cls");
                cout<<"Este es el articulo: "<<endl<<endl;
                mostrarArticulo(cod);
                system("pause");
                c = false; //termina ciclo;
            }
            else
            {
                system("cls");
                cout<<"Proveedor no existe, desea crearlo? (1 = si, 2 = no): ";
                cin>>op;
                switch (op)
                {
                    case 1:
                        ingresarProv(codpp);
                    break;

                    case 2:
                        c = false;
                    break;
                
                    default:
                    break;
                }
            }
        }
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

//Metodos de Empleados
int generarCodEmpleado(int cod) //Esta funcion recibiara el codigo del empleado y devolvera su valor en el array
{
    for(int x = 1; x <= 100; x++)
    {
        if(empleados[x].codigo == cod)
        {
            return x;
            break;
        }
    }
}

int arrayEmpleados() //Esta funcion devolvera el numero del array mas cercano que este vacio.
{
    for(int x = 1; x <= 100; x++)
    {
        if(empleados[x].activo == false)
        {
            return x;
            break;
        }
    }
}
void mostrarEmpleados(int cod)
{
    cout<<"Codigo de Empleados: "<<empleados[cod].codigo<<endl;
    cout<<"Nombre de Empleados: "<<empleados[cod].nombre<<endl;
    cout<<"Puesto de Empleados: "<<empleados[cod].puesto<<endl<<endl;
}

void ingresarEmpleados(int codd)
{
	int cod;
	cod = arrayEmpleados();
    if(empleados[cod].activo == false) //queda mejor con un if
    {
        empleados[cod].activo = true;
        empleados[cod].codigo = codd;
        cout<<"Ingrese Nombre del Empleado: ";
        fflush(stdin); //Sepa, pero sin esta linea no funciona el cin.getline xd
        cin.getline(empleados[cod].nombre, 100);
        cout<<"Ingrese el Puesto del Empleado: ";
        cin>>empleados[cod].puesto;
        system("cls");
        cout<<"Este es el Empleado: "<<endl<<endl;
        mostrarEmpleados(cod);
        system("pause");
    }
    else
    {
        system("cls");
        cout<<"Codigo ya Existente, ingrese uno diferente."<<endl;
        system("pause");
    }
}

void modificarEmpleados()
{
    int cod;
    system("cls");
    cout<<"Ingrese el codigo del Empleado que desea modificar: ";
    cin>>cod;
    if(empleados[cod].activo == true)
    { 
        cout<<"Estos son los datos actuales del Empleado: "<<endl<<endl;
        mostrarEmpleados(cod);
        system("pause");
        //system("cls");
        empleados[cod].activo = false;
        ingresarEmpleados(cod);
    }
    else
    {
        system("cls");
        cout<<"Codigo no Existente"<<endl;
        system("pause");
    }
}

void buscarEmpleados()
{
    int op, cod, codP, p = 0;

    //Para opcion de busqueda;
    string texto, nombre;
    size_t posicion;

    system("cls");
    cout<<"Buscar Clientes"<<endl;
    cout<<"1.) Por Codigo de Empleados"<<endl;
    cout<<"2.) Por Nombre de Empleados"<<endl;
    cout<<"3.) Cancelar"<<endl<<endl;
    cout<<"Seleccione una opcion de busqueda: ";
    cin>>op;
    switch (op)
    {
        case 1: //por codigo
            system("cls");
            cout<<"Ingrese codigo del empleado: ";
            cin>>cod;
            cout<<endl;
            if(empleados[cod].activo == true)
            {
                mostrarEmpleados(cod); 
                system("pause");
            }
            else
            {
                system("cls");
                cout<<"Codigo no Existente"<<endl;
                system("pause");
            }
        break;
    
        case 2:
            system("cls");
            cout<<"Ingrese nombre a buscar: ";
            cin>>nombre;
            for(int x = 1; x <= 100; x++)
            {
                texto = empleados[x].nombre;
                posicion = texto.find(nombre);

                if(posicion != string::npos)
                {
                    system("cls");
                    cout<<"Datos Encontrados: "<<endl;
                    mostrarEmpleados(x);
                }
            }
            system("pause");
        break;

        default:
        break;
    }
}

void eliminarEmpleados()
{
    int cod, op;
    system("cls");
    cout<<"Ingrese el codigo del Empleado que desea eliminar: ";
    cin>>cod;
    if(empleados[cod].activo == true)
    { 
        cout<<"Estos son los datos actuales del Empleado: "<<endl<<endl;
        mostrarEmpleados(cod);
        cout<<endl<<"Esta seguro de eliminar este Empleado? (1 = si, 2 = no): ";
        cin>>op;
        if(op == 1)
        {
            empleados[cod].activo = false;
            system("cls");
            cout<<"Empleado Eliminado Exitosamente"<<endl;
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

void verEmpleados()
{
    system("cls");
    for(int x = 1; x <= 100; x++)
    {
        if(empleados[x].activo == true)
        {
            mostrarEmpleados(x);
        }
    }
    system("pause");
}

//6. REPORTES
void reporteArtBodega(){
	system("cls");
	gotoxy(40,0); cout<<"REPORTE DE ARTICULOS EN BODEGA";
	gotoxy(5,2); cout<<"DESCRIPCION";
	gotoxy(40, 2); cout<<"CANTIDAD EN BODEGA";
	gotoxy(50,2); cout<<"PRECIO UNITARIO";
	gotoxy(100,2); cout<<"PRECIO TOTAL";
	
	for (int x=0; x <101; x++){
		if (articulos[x].cantidadBodega > 0){
			int y= 3;
			for (int i = 0; i< x; i++){
			gotoxy(5, y); cout<<articulos[i].nombre;
			gotoxy(25, y); cout<<articulos[i].cantidadBodega;
			gotoxy(50, y); cout<<"Q. "<<articulos[i].precio;
			gotoxy(100, y); cout<<"Q. "<<articulos[i].precio * articulos[i].cantidadBodega;
			y++;
			}
		}
	
	}
	getch();
}

void reporteArtTienda(){
	system("cls");
	gotoxy(40,0); cout<<"REPORTE DE ARTICULOS EN TIENDA";
	gotoxy(5,2); cout<<"DESCRIPCION";
	gotoxy(40, 2); cout<<"CANTIDAD EN TIENDA";
	gotoxy(50,2); cout<<"PRECIO UNITARIO";
	gotoxy(100,2); cout<<"PRECIO TOTAL";
	
	for (int x=0; x <101; x++){
		if (articulos[x].cantidadTienda > 0){
			int y= 3;
			for (int i = 0; i< x; i++){
			gotoxy(5, y); cout<<articulos[i].nombre;
			gotoxy(25, y); cout<<articulos[i].cantidadTienda;
			gotoxy(50, y); cout<<"Q. "<<articulos[i].precio;
			gotoxy(100, y); cout<<"Q. "<<articulos[i].precio * articulos[i].cantidadTienda;
			y++;
			}
		}
	
	}
	getch();
}
void reporteClientes(){
	system("cls");
	gotoxy(40,0); cout<<"REPORTE DE ARTICULOS DE CLIENTES";
	gotoxy(5,2); cout<<"NOMBRE";
	gotoxy(40, 2); cout<<"DIRECCION";
	gotoxy(50,2); cout<<"NIT";
	gotoxy(100,2); cout<<"CODIGO";
	
	for (int x=0; x <101; x++){
		if (clientes[x].codigo > 0){
			int y= 3;
			for (int i = 0; i< x; i++){
			gotoxy(5, y); cout<<clientes[i].nombre;
			gotoxy(25, y); cout<<clientes[i].direccion;
			gotoxy(50, y); cout<<clientes[i].nit;
			gotoxy(100, y); cout<<clientes[i].codigo;
			y++;
			}
		}
	
	}
	getch();
}

void reporteProveedores(){
	system("cls");
	gotoxy(40,0); cout<<"REPORTE DE ARTICULOS DE PROVEEDORES";
	gotoxy(5,2); cout<<"NOMBRE";
	gotoxy(40, 2); cout<<"DIRECCION";
	gotoxy(50,2); cout<<"NIT";
	gotoxy(100,2); cout<<"CODIGO";
	
	for (int x=00; x <100; x++){
		if (proveedores[x].codigo > 0){
			int y= 3;
			for (int i = 0; i< x; i++){
			gotoxy(5, y); cout<<proveedores[i].nombre;
			gotoxy(25, y); cout<<proveedores[i].direccion;
			gotoxy(50, y); cout<<proveedores[i].nit;
			gotoxy(100, y); cout<<proveedores[i].codigo;
			y++;
			}
		}
	
	}
	getch();
}

void reporteEmpleados(){
	system("cls");
	gotoxy(40,0); cout<<"REPORTE DE EMPLEADOS";
	gotoxy(5,2); cout<<"NOMBRE";
	gotoxy(40, 2); cout<<"DIRECCION";
	gotoxy(50,2); cout<<"NIT";
	gotoxy(100,2); cout<<"CODIGO";
	
	for (int x=0; x <101; x++){
		if (empleados[x].codigo > 0){
			int y= 3;
			for (int i = 0; i< x; i++){
			gotoxy(5, y); cout<<empleados[i].nombre;
			gotoxy(45, y); cout<<empleados[i].puesto;
			gotoxy(60, y); cout<<empleados[i].codigo;
			y++;
			}
		}
	
	}
	getch();
}

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
                cout<<"5.) Ver todo"<<endl;
                cout<<"6.) Regresar"<<endl<<endl;
                cout<<"Seleccione una opcion: ";
                cin>>op1;
                switch (op1)
                {
                    case 1:
                        system("cls");
                        cout<<"SUPERTIENDA MAS+"<<endl<<endl;
                        cout<<"Ingresar Proveedores"<<endl;
                        cout<<"Ingrese Codigo (100-1000): ";
                        cin>>cod;
                        ingresarProv(cod);
                    break;

                    case 2:
                        modificarProv();
                    break;

                    case 3:
                        buscarProv();
                    break;

                    case 4:
                        eliminarProv();
                    break;

                    case 5:
                        verProv();
                    break;

                    case 6:
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
                cout<<"5.) Ver Todo"<<endl;
                cout<<"5.) Regresar"<<endl<<endl;
                cout<<"Seleccione una opcion: ";
                cin>>op1;
                switch (op1)
                {
                    case 1:
                        system("cls");
                        cout<<"SUPERTIENDA MAS+"<<endl<<endl;
                        cout<<"Ingresar Empleados"<<endl;
                        cout<<"Ingrese Codigo (1-100): ";
                        cin>>cod;
                        ingresarEmpleados(cod);
                    break;

                    case 2:
                        modificarEmpleados();
                    break;

                    case 3:
                        buscarEmpleados();
                    break;

                    case 4:
                        eliminarEmpleados();
                    break;

                    case 5:
                        verEmpleados();
                    break;

                    case 6:
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
					
					//articulos en bodega
                    case 3:
                    	reporteArtBodega();
                    break;
                    
                    //articulos en Tienda

                    case 4:
                    	reporteArtTienda();
                    break;
					
					//clientes registrados
                    case 5:
                    	reporteClientes();
                    break;
					
					//Proveedores
                    case 6:
                    	reporteProveedores();
                    break;
					
					//Empleados
                    case 7:
                    	reporteEmpleados();
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
