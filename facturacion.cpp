#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<windows.h> 
#include<string>
#include<conio.h>
#include<ctime>

using namespace std;

/*Pendientes
    No se muestran bien los acentos, corregir
    Que se pueda modificar codigo de producto en funcion modificarArticulos
    que pregunte si de verdad quiere modifcar el articulo
    hacer que tire mensaje de error cuando no encuentre buscando por nombre
    *Que no se puedan Ingresar Proveedores Repetidos(consultar las demas categorias)
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

struct codFac
{
    int codigo = 0;
    bool activo = false;
    bool prodActivo[100];
    char nombre[100];
    char direccion[100];
    char empleado[100];
    char puesto[100];
    int codProductos[100];
    int cantProductos[100];
    double total;

}factura[100];

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
    strcpy(articulos[2].nombre, "Consome");
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
    strcpy(articulos[4].nombre, "Pure de tomate");
    articulos[4].cantidadTienda = 60;
    articulos[4].cantidadBodega = 200;
    articulos[4].precio = 14.69;
    articulos[4].activo = true;

    articulos[5].codigo = 5;
    articulos[5].codProveedor = 400;
    strcpy(articulos[5].nombre, "Alimento para bebes");
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
    strcpy(articulos[8].nombre, "Azucar");
    articulos[8].cantidadTienda = 30;
    articulos[8].cantidadBodega = 90;
    articulos[8].precio = 5.5;
    articulos[8].activo = true;

    articulos[9].codigo = 9;
    articulos[9].codProveedor = 200;
    strcpy(articulos[9].nombre, "Chile piquin");
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
    if(proveedores[cod].activo == false && codd <= 1000 && codd >= 100) //queda mejor con un if
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
    else if(codd > 1000 or codd < 100)
    {
        system("cls");
        cout<<"Codigo Incorrecto, esta fuera de rango."<<endl;
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
    if(articulos[cod].activo == false && cod <=100 && cod > 0) //Para que codigo sea menor a 100
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
    else if(cod > 100 or cod == 0)
    {
        system("cls");
        cout<<"Codigo Incorrecto, esta fuera de rango."<<endl;
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
    int y = 4, codP;
	gotoxy(70,0); cout<<"REPORTE DE ARTICULOS";
    gotoxy(5,2); cout<<"CODIGO";
	gotoxy(15,2); cout<<"DESCRIPCION";
    gotoxy(50,2); cout<<"PRECIO UNITARIO";
	gotoxy(70, 2); cout<<"CANT. TIENDA";
    gotoxy(90, 2); cout<<"CANT. BODEGA";
    gotoxy(110,2); cout<<"COD. PROV";
    gotoxy(125,2); cout<<"NOMBRE DE PROVEEDOR";
    for(int x = 1; x <= 100; x++)
    {
        if(articulos[x].activo == true)
        {
            codP = generarCodProv(articulos[x].codProveedor);
            gotoxy(5, y); cout<<articulos[x].codigo;
            gotoxy(15, y); cout<<articulos[x].nombre;
            gotoxy(50, y); cout<<"Q. "<<articulos[x].precio;
			gotoxy(70, y); cout<<articulos[x].cantidadTienda;
            gotoxy(90, y); cout<<articulos[x].cantidadBodega;
            gotoxy(110, y); cout<<"("<<articulos[x].codProveedor<<") ";
			gotoxy(125, y); cout<<proveedores[codP].nombre;
            y+=1;
        }
    }
    cout<<endl<<endl;
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
    if(clientes[cod].activo == false && cod <= 100 && cod > 0) //queda mejor con un if
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
    else if(cod > 100 or cod == 0)
    {
        system("cls");
        cout<<"Codigo Incorrecto, esta fuera de rango."<<endl;
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
    if(empleados[cod].activo == false && codd < 100 && codd > 0) //queda mejor con un if
    {
        empleados[cod].activo = true;
        empleados[cod].codigo = codd;
        cout<<"Ingrese Nombre del Empleado: ";
        fflush(stdin); //Sepa, pero sin esta linea no funciona el cin.getline xd
        cin.getline(empleados[cod].nombre, 100);
        cout<<"Ingrese el Puesto del Empleado: ";
        fflush(stdin); //Sepa, pero sin esta linea no funciona el cin.getline xd
        cin.getline(empleados[cod].puesto, 100);
        system("cls");
        cout<<"Este es el Empleado: "<<endl<<endl;
        mostrarEmpleados(cod);
        system("pause");
    }
    else if(codd > 100 or codd == 0)
    {
        system("cls");
        cout<<"Codigo Incorrecto, esta fuera de rango."<<endl;
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

//6. REPORTES
void reporteArtBodega(){
	system("cls");
    int y = 4, codP;
	gotoxy(60,0); cout<<"REPORTE DE ARTICULOS EN BODEGA";
    gotoxy(5,2); cout<<"CODIGO";
	gotoxy(15,2); cout<<"DESCRIPCION";
    gotoxy(50,2); cout<<"PRECIO UNITARIO";
    gotoxy(70, 2); cout<<"CANT. BODEGA";
    gotoxy(90,2); cout<<"COD. PROV";
    gotoxy(110,2); cout<<"NOMBRE DE PROVEEDOR";
    for(int x = 1; x <= 100; x++)
    {
        if(articulos[x].activo == true && articulos[x].cantidadBodega > 0)
        {
            codP = generarCodProv(articulos[x].codProveedor);
            gotoxy(5, y); cout<<articulos[x].codigo;
            gotoxy(15, y); cout<<articulos[x].nombre;
            gotoxy(50, y); cout<<"Q. "<<articulos[x].precio;
            gotoxy(70, y); cout<<articulos[x].cantidadBodega;
            gotoxy(90, y); cout<<"("<<articulos[x].codProveedor<<") ";
			gotoxy(110, y); cout<<proveedores[codP].nombre;
            y+=1;
        }
    }
    cout<<endl<<endl;
    system("pause");
}

void reporteArtTienda(){
	system("cls");
    int y = 4, codP;
	gotoxy(60,0); cout<<"REPORTE DE ARTICULOS EN TIENDA";
    gotoxy(5,2); cout<<"CODIGO";
	gotoxy(15,2); cout<<"DESCRIPCION";
    gotoxy(50,2); cout<<"PRECIO UNITARIO";
    gotoxy(70, 2); cout<<"CANT. TIENDA";
    gotoxy(90,2); cout<<"COD. PROV";
    gotoxy(110,2); cout<<"NOMBRE DE PROVEEDOR";
    for(int x = 1; x <= 100; x++)
    {
        if(articulos[x].activo == true && articulos[x].cantidadTienda > 0)
        {
            codP = generarCodProv(articulos[x].codProveedor);
            gotoxy(5, y); cout<<articulos[x].codigo;
            gotoxy(15, y); cout<<articulos[x].nombre;
            gotoxy(50, y); cout<<"Q. "<<articulos[x].precio;
            gotoxy(70, y); cout<<articulos[x].cantidadTienda;
            gotoxy(90, y); cout<<"("<<articulos[x].codProveedor<<") ";
			gotoxy(110, y); cout<<proveedores[codP].nombre;
            y+=1;
        }
    }
    cout<<endl<<endl;
    system("pause");
}

void reporteClientes(){
	system("cls");
    int y = 4;
	gotoxy(30,0); cout<<"LISTADO DE CLIENTES";
    gotoxy(5,2); cout<<"CODIGO";
	gotoxy(15,2); cout<<"NOMBRE";
    gotoxy(50,2); cout<<"DIRECCION";
    gotoxy(70, 2); cout<<"NIT";
    for(int x = 1; x <= 100; x++)
    {
        if(clientes[x].activo == true)
        {
            gotoxy(5, y); cout<<clientes[x].codigo;
            gotoxy(15, y); cout<<clientes[x].nombre;
            gotoxy(50, y); cout<<clientes[x].direccion;
            gotoxy(70, y); cout<<clientes[x].nit;
            y+=1;
        }
    }
    cout<<endl<<endl;
    system("pause");
}

void reporteProveedores(){
	system("cls");
    int y = 4, codP;
	gotoxy(35,0); cout<<"REPORTE DE PROVEEDORES";
    gotoxy(5,2); cout<<"CODIGO";
	gotoxy(15,2); cout<<"NOMBRE";
    gotoxy(50,2); cout<<"DIRECCION";
    gotoxy(70, 2); cout<<"TELEFONO";
    gotoxy(90,2); cout<<"NIT";
    for(int x = 1; x <= 100; x++)
    {
        if(proveedores[x].activo == true)
        {
            codP = generarCodProv(proveedores[x].codigo);
            gotoxy(5, y); cout<<proveedores[x].codigo;
            gotoxy(15, y); cout<<proveedores[codP].nombre;
            gotoxy(50, y); cout<<proveedores[x].direccion;
            gotoxy(70, y); cout<<proveedores[x].telefono;
            gotoxy(90, y); cout<<proveedores[x].nit;
            y+=1;
        }
    }
    cout<<endl<<endl;
    system("pause");
}

void reporteEmpleados(){
	system("cls");
    int y = 4;
	gotoxy(18,0); cout<<"REPORTE DE EMPLEADOS";
    gotoxy(5,2); cout<<"CODIGO";
	gotoxy(15,2); cout<<"NOMBRE";
    gotoxy(40,2); cout<<"PUESTO";
    for(int x = 1; x <= 100; x++)
    {
        if(empleados[x].activo == true)
        {
            gotoxy(5, y); cout<<empleados[x].codigo;
            gotoxy(15, y); cout<<empleados[x].nombre;
            gotoxy(40, y); cout<<empleados[x].puesto;
            y+=1;
        }
    }
    cout<<endl<<endl;
    system("pause");
}

int generarArrayNit(int cod) //Esta funcion recibiara el nit del cliente y devolvera su valor en el array
{
    for(int x = 1; x <= 100; x++)
    {
        if(clientes[x].nit == cod)
        {
            return x;
            break;
        }
    }
}

int generarCodFactura() //Esta funcion genera un numero aleatorio en el array mas proximo y retorna su pocicion.
{
    int aleatorio, DESDE=10000, HASTA=999999;
    for(int x = 1; x <= 100; x++)
    {
        if(factura[x].activo == false)
        {
            srand(time(NULL));
            aleatorio = rand()%(HASTA-DESDE+1)+DESDE;
            factura[x].codigo = aleatorio;
            factura[x].activo = true;
            return x;
            break;
        }
        else if (x == 100)
        {
            return 0;
            break;
        }
    }
}

double totalFactura(int cod)
{
    double total = 0;
    for(int x = 1; x <= 100; x++)
    {
        if(factura[cod].prodActivo[x] == true)
        {
            total += (articulos[x].precio * factura[cod].cantProductos[x]);
        }
    }
    return total;
}

void verFactura(int cod)
{
    int y = 9;
	gotoxy(25,7); cout<<"DESCRIPCION DE LA FACTURA";
    gotoxy(5,8); cout<<"CODIGO";
	gotoxy(15,8); cout<<"DESCRIPCION";
    gotoxy(50,8); cout<<"PRECIO UNITARIO";
	gotoxy(70,8); cout<<"CANTIDAD";
    gotoxy(85,8); cout<<"SUBTOTAL";
    if(factura[cod].activo == true)
    {
        for(int z = 1; z <=100; z++)
        {
            if(factura[cod].prodActivo[z] == true)
            {
                gotoxy(5, y); cout<<factura[cod].codProductos[z];
                gotoxy(15, y); cout<<articulos[z].nombre;
                gotoxy(50, y); cout<<"Q. "<<articulos[z].precio;
                gotoxy(70, y); cout<<factura[cod].cantProductos[z];
                gotoxy(85, y); cout<<"Q. "<<articulos[z].precio * factura[cod].cantProductos[z];
                y+=1;
            }
        }
        gotoxy(78, y+1); cout<<"TOTAL: Q. "<<totalFactura(cod);
    }
}

bool existeNit(int nit)
{
    for(int x = 1; x <= 100; x++)
    {
        if(clientes[x].nit == nit)
        {
            return true;
            break;
        }
        else if (x == 100)
        {
            return false;
        }
    }
}

void facturacion()
{
    int nit, op, cod, nitGen;
    int fac, codF, cant, x = 1;
    bool c = true, facturar = true;
    system("cls");
    cout<<"BIENVENIDO AL SISTEMA DE FACTURACION"<<endl<<endl;
    cout<<"Ingrese su nit: ";
    cin>>nit;
    while(c == true)
    {
        if(existeNit(nit) == true) //nit validado
        {
            nitGen = generarArrayNit(nit); //array del nit
            fac = generarCodFactura(); //codigo de factura
            while(facturar == true)
            {
                system("cls");
                cout<<"BIENVENIDO AL SISTEMA DE FACTURACION"<<endl<<endl;
                cout<<"SUPERTIENDA MAS+"<<endl;
                cout<<"Nombre: "<<clientes[nitGen].nombre<<endl;
                cout<<"Direccion: "<<clientes[nitGen].direccion<<endl;
                cout<<"Numero de Factura: "<<factura[fac].codigo<<endl;
                verFactura(fac);
                cout<<endl<<endl;
                cout<<"Ingrese codigo de producto a agregar (0 = Finalizar): ";
                cin>>codF;
                if(articulos[codF].activo == true && codF > 0)
                {
                    cout<<"Su articulo seleccionado es: "<<articulos[codF].nombre<<endl;
                    cout<<"Ingrese la cantidad que desea: ";
                    cin>>cant;
                    if(cant > 0 && articulos[codF].cantidadTienda >= cant)
                    {
                        factura[fac].codProductos[codF] = codF;
                        factura[fac].prodActivo[codF] = true;
                        if(factura[fac].cantProductos[codF] == 0) //si la cantidad de productos en la factura es igual a 0, la cantidad ingresada es igual a la cantidad de productos
                        {
                            factura[fac].cantProductos[codF] = cant;
                        }
                        else if(factura[fac].cantProductos[codF] > 0) //si la cantidad de productos de la factura es mayor a 0, la cantidad ingresada se suma a la cantidad de productos
                        {
                            factura[fac].cantProductos[codF] += cant;
                        }
                        articulos[codF].cantidadTienda -= cant; //Restar de tienda
                    }
                    else if (articulos[codF].cantidadTienda < cant)
                    {
                        cout<<endl<<"No existen suficientes productos en tienda, realize peticion a bodega"<<endl;
                        cout<<"Cantidad de "<<articulos[codF].nombre<<" en tienda: "<<articulos[codF].cantidadTienda<<endl;
                        system("pause");
                    }
                    else
                    {
                        cout<<"Datos Invalidos"<<endl;
                        system("pause");
                    }
                }
                else if(articulos[codF].activo == false && codF > 0)
                {
                    cout<<"Producto no existente"<<endl;
                    system("pause");
                }
                else if(codF == 0)
                {
                    facturar = false;
                }
            }
        }
        else
        {
            system("cls");
            cout<<"No existe ningun cliente registrado con ese nit, Desea crear un nuevo usuario? (1 = Si, 2 = No): ";
            cin>>op;
            switch (op)
            {
                case 1:
                    system("cls");
                    cout<<"Ingresar Clientes"<<endl;
                    cout<<"Ingrese Codigo (1-100): ";
                    cin>>cod;
                    ingresarClientes(cod);
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
                        reporteClientes();
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
                facturacion();
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
                        reporteProveedores();
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
                cout<<"6.) Regresar"<<endl<<endl;
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
                        reporteEmpleados();
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
