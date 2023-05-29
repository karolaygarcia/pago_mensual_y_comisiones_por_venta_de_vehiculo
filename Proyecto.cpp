#include <iostream>
#include <unistd.h>
#include <fstream>// para realizar operaciones de entrada y salida de archivos.
#include <ctime>//manipulación y obtención de información sobre el tiempo y la fecha del sistema. 
#include <cstdlib>//para tener un valor semilla rand, srand
#include <conio.h>
#include <windows.h>
#include <locale.h>
//para usar la funcion sleep()

using namespace std;
static string _nombres; // para extraer
static int _codigos;
int pass1 = 1234, pass2, num_emp_max = 0;
;

// para asignar el nombre y precio a cada auto;
struct autos
{
    string nombre;
    double precio;
} marca_autos[300];

// para estructurar los datos de la persona y utilizar de manera dinamica los datos
class Empleado
{
private:
    string nombre;
    int codigo;

public:
    Empleado() {}//al tener un constructor sin argumentos, se permite crear objetos Empleado sin proporcionar valores iniciales para nombre y codigo. 
    Empleado(string, int);
    void mostrar_dat_emp();  //
    void mostrar_emp_info(); //
    void mostrar_nom_emp();  //
};
Empleado::Empleado(string _nombre, int _codigo)
{
    nombre = _nombre;
    codigo = _codigo;
}
void Empleado::mostrar_dat_emp()
{
    cout << "nombre: " << nombre << endl;
    cout << "código: " << codigo << endl;
    cout << "....................." << endl;
}
void Empleado::mostrar_emp_info()
{
    cout << "empleado: " << nombre << endl;
    cout << "código: " << codigo << endl;
    _nombres = nombre;
    _codigos = codigo;
}
void Empleado::mostrar_nom_emp()
{
    cout << nombre << endl;
}

// implementacion de un menu parea que el usuario pueda entender el programa
int menu()
{
	setlocale(LC_CTYPE, "spanish");
    int opc;
    cout << "  <-----MENU----->" << endl;
    cout <<"1. empleados"<<endl;
    cout <<"2. sorteo" << endl;
    cout <<"3. configuraciones" << endl;
    cout<<"\n0. salir del programa\n"<<endl;
    cout << "opción: ";
    cin >> opc;
    return opc; // retorna una variable de tipo int que se usaara para saber la eleccion del usuario
}

//submenu del menu principal
int sub_menu1(){
	setlocale(LC_CTYPE, "spanish");
	int opc_1;
	cout << "1. añadir empleado" << endl;
    cout << "2. ver empledos" << endl;
    cout << "3. evaluar a un empleado" << endl;
    cout<<"4. mostrar inf. de todas las ventas"<<endl;
    cout<<"5. eliminar un empleado"<<endl;
    cout<<"6. historial de venta de un empleado"<<endl;
    
    cout<<"\n0. volver\n"<<endl;
    cout << "opción: ";
    cin >> opc_1;
    return opc_1;
}
int sub_menu2(){
	setlocale(LC_CTYPE, "spanish");
	int opc_2;
	cout<<"1. cambiar contraseña"<<endl;
	cout<<"2. borrar registro de inf. de todas las ventas"<<endl;
	cout<<"3. eliminar lista de empleados"<<endl;
	cout<<"\n0. volver\n"<<endl;
	cout << "opción: ";
    cin >> opc_2;
	return opc_2;
}

// para seguridad del usuario, en tal sentido de que el tenga uso exclusivo del programa y proteger sus datos
int contrasena()
{
	setlocale(LC_CTYPE, "spanish");
    ifstream contrasenatxt;               // guarda la contrasena antigua/nueva
    contrasenatxt.open("pass1", ios::in); // abrimos el archivo para poder manipularlo
    while (contrasenatxt >> pass1)
    { // leera la contrasena
        pass1;
    }
    contrasenatxt.close(); // para que los cambios qque se hizo esteen guardados
    int intentos = 4;
    cout << "Ingrese la contraseña: " << endl;
    cin >> pass2;
    while (pass2 != pass1)
    {
        intentos--;
        cout << "contraseña incorrecta, intentelo nuevamente" << endl;
        cout << "Ingrese la contraseña: ";
        cin >> pass2;
        cout << endl;

        if (pass1 != pass2)
        {
            system("cls");
            cout << "le quedan " << intentos << " intentos" << endl;
        }

        if (intentos == 0)
        {
            exit(1); // sale del programa sin mostrar nada mas
        }
    }
    return pass2; // retorna una variable de tipo int, en el cual se contendra el numero de acceso al programa, ello se usara en el main
}

void aniadir_empleado()
{
	setlocale(LC_CTYPE, "spanish");
    string nombre;
    int n, codigo;
    Empleado empleado[25]; // arreglo de objetos

    ofstream archivo_es;                         // creamos un archivo para que los empleados queden registrados hasta que el usuario manipule dicha informacion
    archivo_es.open("empleados2.txt", ios::app); // ios::app, lo usamos como alternativa a ios::out, para que el aarchivo no sea remplazado asi mismo eliminado
    if (archivo_es.fail())
    { // si el archivo no se crea correctamenta
        cout << "no se pudo abrir el archivo";
        exit(1);
    }
    cout << "digite la cantidad de empleados que añadirá: ";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". nombre: ";
        cin >> nombre;
        cout << i + 1 << ". código: ";
        cin >> codigo;
        empleado[i] = Empleado(nombre, codigo);//crea un nuevo objeto Empleado utilizando el constructor que toma un nombre y un código como argumentos. Luego, este nuevo objeto se asigna al elemento i del arreglo empleado
        archivo_es << nombre << " " << codigo << endl; // esta guardando en el archivo, en cada iteracion del bucle
        ofstream empleado;//************************
        empleado.open(nombre.c_str(),ios::app);
        empleado.close();
    }
   archivo_es.close(); // cerrando el archivo

    // acontinuacion un complemento para que el programa sea mas amigable con el usuario singular/plural
    if (n == 1)
    {
        cout << "empleado añadido correctamente!";
    }
    if (n > 1)
    {
        cout << "\nempleados añadidos exitosamente!";
    }
    cout << "\n\npresione cualquier tecla para volver al menú.";
    getch(); // para que pause el programa hasta que el usuario presione cualquier tecla para continuar
    system("cls");
}

void mostrar_emp()
{
	setlocale(LC_CTYPE, "spanish");
    Empleado empleado[25]; // para poder mostrar a los empleados de acuerdo a su posicion
    string nombre;
    int codigo;
    system("cls");
    cout << "mostrando empleados";
    Sleep(1000); // para simular procesos que ocurren en tiempo real.
    cout << ".";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << "." << endl;
    Sleep(1000);
    system("cls");
    //creando archivo de lectura
    ifstream archivo_lec;
    archivo_lec.open("empleados2.txt", ios::in);
    if (archivo_lec.fail())// si el archivo no existe
    {
        cout << "no hay empleados registrados!\n\n";
    }
    int i = 1;

    // muestra los empleados
    while (archivo_lec >> nombre >> codigo)//para extraer datos de un flujo de entrada, en este caso, del archivo archivo_lec. En cada iteración del bucle
    {
        cout << i << ":" << endl;
        empleado[i - 1] = Empleado(nombre, codigo);//mostrando empleados 
        Empleado(nombre, codigo).mostrar_dat_emp();
        i++;
    }
    archivo_lec.close();
    cout << "\n\npresione cualquier tecla para volver al menú.";
    getch();
    system("cls");
}

void evaluar_emp()
{
	setlocale(LC_CTYPE, "spanish");
    Empleado empleado[25];
    string nombre;
    int codigo;
    system("cls");
    int num_autos_vendidos, sueldo = 1200;
    float precio_de_auto, suma_total_venta, total_comisiones, sueldo_total;
    
    ifstream archivo_lec;
    ofstream archivo_info;

    archivo_lec.open("empleados2.txt", ios::in);
    if (archivo_lec.fail())
    {
        cout << "no hay empleados registrados a evaluar\n\n";
    }
    archivo_info.open("informacion_mensual", ios::app);
    if (archivo_info.fail())
    {
        cout << "no se pudo abrir el archivo";
        exit(1);
    }

    if (!archivo_lec.fail())
    {
        int i = 1;
        // muestra los empleados
        while (archivo_lec >> nombre >> codigo)
        {
            cout << i << ":" << endl;
            empleado[i - 1] = Empleado(nombre, codigo);
            Empleado(nombre, codigo).mostrar_nom_emp();
            i++;
        }
        cout << endl;
        cout << "número de orden del empleado: ";
        cin >> i;// segun el numero de orden mostrara el objeto, en la pocision que esta guardada
        system("cls");
        empleado[i - 1].mostrar_emp_info();
        cout << endl;
        
        //definimos los vehiculos
        marca_autos[0] = {"TOYOTA", 70000};
        marca_autos[1] = {"BMW", 100000};
        marca_autos[2] = {"MERCEDES BENZ", 120000};
        marca_autos[3] = {"FERRARI", 400000};
        marca_autos[4] = {"MCLAREN", 500000};
        //
        cout << "Ingrese la cantidad de autos vendidos: " << endl;
        cin >> num_autos_vendidos;
        cout << " _______________" << endl;
        cout << "|               |" << endl;
        cout << "|   VEHICULOS   |" << endl;
        cout << "|_______________|" << endl;
        for (int a = 0; a < 5; a++)
        {
            cout << a + 1 << ") " << marca_autos[a].nombre << " " << marca_autos[a].precio << endl;
        }
        for (int c = 1; c <= num_autos_vendidos; c++)
        {
            cout << "Ingrese la marca de auto vendida(1 - 5): " << endl;
            int num_marca_auto;
            cin >> num_marca_auto;
            cout << "Ingrese la cantidad de autos vendidos de esta marca " << marca_autos[num_marca_auto - 1].nombre << ": " << endl;
            int cantidad;
            cin >> cantidad;
            precio_de_auto = marca_autos[num_marca_auto - 1].precio;
            suma_total_venta += precio_de_auto * cantidad;
            cout << endl;
        }

        if (num_autos_vendidos >= 5)
        {
            total_comisiones = (suma_total_venta * 0.007);
        }

        if (num_autos_vendidos < 5)
        {
            total_comisiones = (suma_total_venta * 0.004);
        }
        sueldo_total = total_comisiones + sueldo;

        cout << "creando informe";
        cout << ".";
        Sleep(1000);
        cout << ".";
        Sleep(1000);
        cout << ".";
        Sleep(1000);
        system("cls");
        
        
        //crea informe de ventas
        cout << "\n\n\tINFORME DE VENTAS MENSUAL\n ";
        empleado[i - 1].mostrar_emp_info();
        cout << "............................" << endl;
        cout << "Venta total: "
             << "s/" << suma_total_venta << endl;
        cout << "Sueldo s/" << sueldo << endl;
        cout << "Comisión total: "
             << "s/" << total_comisiones << endl;
        cout << "Pago total (sueldo + comisiones): "
             << "s/" << sueldo_total << endl;
        cout << "............................\n\n";
        
        long ventas_t=0;
        ifstream ingreso_tot;
        ofstream ingreso_total;//registrara las ventas totales echas por todo los empleados
        
        ingreso_tot.open("ventas_totales",ios::in);
        while( ingreso_tot>>ventas_t){
        	
		}
		ingreso_tot.close();
    
        ingreso_total.open("ventas_totales", ios::out);
        ingreso_total << ventas_t << endl; // Escribir el valor actual de las ventas totales
        
        ingreso_tot.open("ventas_totales",ios::in);
        while(ingreso_tot>>ventas_t){
        	// Leer el valor actual de las ventas totales
		}
		ingreso_tot.close();
        ventas_t+=suma_total_venta;
        ingreso_total<<ventas_t<<endl;//luego de la suma, // Escribir el nuevo valor de las ventas totales
        
        
        ingreso_total.close();
        
        
        //establecemos la fecha del sistema para que se guarde en el informe
        int dia, mes, anio,horas, minutos;
        time_t t;
        t=time(NULL);
        struct tm *fecha;    //obtenemos las partes de la fecha
        fecha=localtime(&t);// nos devolvera un puntero a la estructura tm
		dia=fecha->tm_mday;
        mes=fecha->tm_mon+1;
        anio=fecha->tm_year+1900;
        horas=fecha->tm_hour;
        minutos=fecha->tm_min;
        
        ofstream empleado;//************************
        empleado.open(_nombres.c_str(),ios::app);
        empleado<< "\n\n\tINFORME DE VENTAS MENSUAL\n "
                     << "fecha: " << dia << "/" << mes << "/" << anio <<"         "<<horas<<":"<<minutos<<endl
                     << endl
                     << "empleado: " << _nombres << endl
                     << "código: " << _codigos << endl
                     << "............................" << endl
                     << "Venta total: "
                     << "s/" << suma_total_venta << endl
                     << "Comisión total: "
                     << "s/" << total_comisiones << endl
                     << "Pago total (sueldo + comisiones): "
                     << "s/" << sueldo_total << endl
                     << "............................\n\n";
        empleado.close();
        
       
        //guarda el informe en el archivo
        archivo_info << "\n\n\tINFORME DE VENTAS MENSUAL\n "
                     << "fecha: " << dia << "/" << mes << "/" << anio <<"         "<<horas<<":"<<minutos<<endl
                     << endl
                     << "empleado: " << _nombres << endl
                     << "código: " << _codigos << endl
                     << "............................" << endl
                     << "Venta total: "
                     << "s/" << suma_total_venta << endl
                     << "Comisión total: "
                     << "s/" << total_comisiones << endl
                     << "Pago total (sueldo + comisiones): "
                     << "s/" << sueldo_total << endl
                     << "............................\n\n";

        archivo_lec.close();
        archivo_info;
        cout << "\n Evaluación registrada exitosamente!\n";
        cout << "\nPresione cualquier tecla para volver al menú.";
        getch();
        system("cls");
    }
}

void mostrar_inf()
{
	setlocale(LC_CTYPE, "spanish");
    system("cls");
    ifstream archivo_ventas;
    archivo_ventas.open("informacion_mensual", ios::in);
    if (archivo_ventas.fail())
    {
        cout << "ningún empleado realizo alguna venta o se eliminó el historial de ventas\n\n";
        Sleep(2000);
    }
    if (!archivo_ventas.fail())
    {
        cout << "ventas: " << endl;
        string texto;
        while (!archivo_ventas.eof())
        {
            getline(archivo_ventas, texto);
            cout << texto << endl;
        }
        archivo_ventas.close();
        
        long ventas_t;
        ifstream ingreso_tot;
        ingreso_tot.open("ventas_totales",ios::in);
        while(ingreso_tot>>ventas_t){
		}
		
		cout<<"\ntotal de ingresos en ventas: s/. "<<ventas_t<<endl;
		ingreso_tot.close();
    }
    cout << "\n\npresione cualquier tecla para volver al menú.";
    getch();
    system("cls");
}

void sorteo()
{
	setlocale(LC_CTYPE, "spanish");
    Empleado empleado[25];
    string nombre;
    int codigo;
    system("cls");
    string sorteo;
    int num;
    srand(time(0));
    cout << "introduzca (si) para iniciar el sorteo : ";
    cin >> sorteo;

    if (sorteo == "si")
    {
        cout << "\nPARTICIPANTES" << endl;
        ifstream archivo_lec;
        archivo_lec.open("empleados2.txt", ios::in);
        if(archivo_lec.fail()){
        	cout<<"no hay empleados registrados";
        	cout << "\n\npresione cualquier tecla para volver al menu.";
		    getch();
		    system("cls");
		}
		else{
			int i = 1;
	        while (archivo_lec >> nombre >> codigo)
	        {
	            cout << i << ":" << endl;
	            empleado[i - 1] = Empleado(nombre, codigo);
	            Empleado(nombre, codigo).mostrar_nom_emp();
	            i++;
	            if (num_emp_max < i - 1)
	            {
	                num_emp_max = i - 1;
	            }
	        }
	        cout << "\n";
	        cout << "\n3,";
	        Sleep(1000);
	        cout << "2,";
	        Sleep(1000);
	        cout << "1\n";
	        Sleep(1000);
	        num = rand() % num_emp_max;       // creara un valor entre 1 y 7, el cual es la cantidad de empleados,seguidamente lo colocara dentro del vector nom.empleado[]
	        empleado[num].mostrar_emp_info(); //<- , y nos botara un nombre aleatorio;
	        cout << "\nGANADOR(A)!\n\n";
	        cout << "\n\npresione cualquier tecla para volver al menú.";
		    getch();
		    system("cls");
        }
	}
	if(sorteo != "si"){
		cout<<"\nOpción desconocida, volviendo al menú"<<endl;
		Sleep(2000);
		system("cls");
		
	}
        
}

void cambiar_password()
{
	setlocale(LC_CTYPE, "spanish");
    system("cls");
    contrasena();
    system("cls");
    if (pass1 == pass2)
    {
        cout << "introduzca la nueva contraseña: ";
        cin >> pass1;
        cout << "confirme la nueva contraseña: ";
        cin >> pass1;
        ofstream contrasenatxt;
        contrasenatxt.open("pass1", ios::out);
        if (contrasenatxt.fail())
        {
            cout << "no se pudo registrar la nueva contraseña";
        }
        contrasenatxt << pass1;
        contrasenatxt.close();
        system("cls");
        cout << "Se cambio la contraseña correctamente!\n\n";
    }

    contrasena();
    system("cls");
    if (pass1 == pass2)
    {
        cout << "verificando";
        Sleep(1000);
        cout << ".";
        Sleep(1000);
        cout << ".";
        Sleep(1000);
        cout << "." << endl;
        cout << "contraseña correcta!";
        Sleep(1000);

        system("cls");
    }
}

void eliminar_emp()
{
	setlocale(LC_CTYPE, "spanish");
    system("cls");
    string nombre, nom_aux;;
    int codigo, codigo_aux;//
    ifstream lect_elim;
    lect_elim.open("empleados2.txt", ios::in);///////////////
    if (lect_elim.fail())
    {
        cout << "no hay empleados registrados";
        lect_elim.close();
        cout << "\n\npresione cualquier tecla para volver al menú.";
        getch();
        system("cls");
    }

    ofstream temp;
    temp.open("temp.txt", ios::out);
    if (temp.fail())
    {
        cout << "no se pudo eliminar al empleado";
        temp.close();
    }
    ///////////////////
    if(!lect_elim.fail()){
    	cout << "código del empleado: ";
	    cin >> codigo_aux;
	    bool empleadoEliminado = false;
	    while (lect_elim >> nombre >> codigo)
	    { // dentro de la condición del bucle para leer los datos en cada iteración.
	        if (codigo_aux == codigo)
	        {
	            cout << "empleado eliminado!";
	            empleadoEliminado = true;
	            nom_aux=nombre;
	        }
	        else
	        {
	            temp << nombre << " " << codigo << endl;
	        }
        }
	    lect_elim.close();
	    temp.close();
	
	    if (!empleadoEliminado)
	    {
	        cout << "No se encontró un empleado con el código proporcionado" << endl;
	        return;
	    }
	    
	    remove(nom_aux.c_str());
	    remove("empleados2.txt");
	    rename("temp.txt", "empleados2.txt");
	    cout << "\n\npresione cualquier tecla para volver al menú.";
	    getch();
	    system("cls");
	}
    
}
void hist_emp(){
	setlocale(LC_CTYPE, "spanish");
	string nombre;
    string codigo, codigo_aux;
    ifstream vent_emp;
    cout<<"ingrese el nombre del empleado: ";
    cin>>nombre;
    vent_emp.open(nombre.c_str(), ios::in);///////////////
    if (vent_emp.fail())
    {
        cout << "empleado no registrado!";
        vent_emp.close();
        cout << "\n\npresione cualquier tecla para volver al menú.";
        getch();
        system("cls");
    }
    else{
    	string texto;
    	while(!vent_emp.eof()){
    		getline(vent_emp,texto);
    		cout<<texto<<endl;
		}
		vent_emp.close();
		cout << "\n\npresione cualquier tecla para volver al menú.";
        getch();
        system("cls");
	}
}

void eliminar_inf_vent(){
	setlocale(LC_CTYPE, "spanish");
	system("cls");
    string rpt;
    cout<<"eliminar registro si/no: ";
    cin>>rpt;
    if(rpt=="si"){
        cout<<"borrando archivo";
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        ofstream elim_vent;
        //elim_vent.open("informacion_mensual",ios::out);//trunca el archivo(elimina su contenido)
        //elim_vent.close();
        remove("informacion_mensual");
        remove("ventas_totales");
        system("cls");
        cout<<"historial eliminado exitosamente!";
        cout << "\n\npresione cualquier tecla para volver al menú.";
	    getch();
	    system("cls");

    }
}
void eliminar_emps(){
	setlocale(LC_CTYPE, "spanish");
	system("cls");
    string rpt;
    cout<<"eliminar a todos los empleados si/no: ";
    cin>>rpt;
    if(rpt=="si"){
        cout<<"borrando empleados";
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        ofstream elim_vent;
        //elim_vent.open("informacion_mensual",ios::out);//trunca el archivo(elimina su contenido)
        //elim_vent.close();
        remove("empleados2.txt");
        system("cls");
        cout<<"lista de empleados eliminado exitosamente!";
        cout << "\n\npresione cualquier tecla para volver al menú.";
	    getch();
	    system("cls");

    }
}

int main()
{
	setlocale(LC_CTYPE, "spanish");
    // system("COLOR 1F2");
    int pass2 = contrasena();

    if (pass1 == pass2)
    {
        system("cls");
        cout << "verificando";
        Sleep(1000);
        cout << ".";
        Sleep(1000);
        cout << ".";
        Sleep(1000);
        cout << "." << endl;
        cout << "contraseña correcta!";
        Sleep(1000);

        system("cls");
        cout << "............................" << endl;
        cout << "\tBIENVENIDO" << endl;
        cout << "............................\n\n";

        Empleado empleado[25];
        string nombre;
        int codigo, cod_aux;
        int opc;

        opc = menu();
        // ejeciutando opciones del menu
        while (opc != -2)
        {
        	switch(opc){//switch para usar if, no se pueden usar switch dentro de if
        	    case 0:
                	system("cls");
                	cout<<"saliendo del programa";
                	Sleep(2000);
                	system("cls");
                	cout<<"Buen día";
                	Sleep(1000);
                	system("cls");
                	exit(1);
                	
                	break;
                	
        		case 1: 
        		    system("cls");
                    int opc1;
                    cout<<"     EMPLEADOS\n"<<endl;
                    opc1=sub_menu1();
                    if(opc1<=4||opc1>=0){
                    	
                        if(opc1==1){
                            system("cls");
                            aniadir_empleado();
                        }
                        if(opc1==2){
                            system("cls");
                            mostrar_emp();
                        }
                        if(opc1==3){
                            system("cls");
                            evaluar_emp();
                        }
                        if(opc1==4){
                            system("cls");
                            mostrar_inf();
                        }
                        if(opc1==5){
                            system("cls");
                            eliminar_emp();
                            }
                        if(opc1==0){
                            system("cls");
                            break;
                        }
                        if(opc1==6){
                            system("cls");
                            hist_emp();
                            break;
                        }
                    }
                    if(opc>6||opc<0){
                        cout<<"opción invalida!\n"<<endl;
                        Sleep(3000);
                        system("cls");
                        }
					break;
					
				case 2:
					system("cls");
					cout<<"    SORTEO\n"<<endl;
					sorteo();
					break;
					
				case 3:
					system("cls");
					cout<<"    CONFIGURACIONES\n"<<endl;
                    int opc3=sub_menu2();
                    if(opc3<=4||opc3>=0){
                        if(opc3==1){
                            system("cls");
                            cambiar_password();
                        }
                        if(opc3==2){
                            system("cls");
                            eliminar_inf_vent();
                        }
                        if(opc3==3){
                            system("cls");
                            eliminar_emps();
                        }
                    }
        			
                        if(opc>3||opc<0){
                            cout<<"opción invalida!\n"<<endl;
                            Sleep(3000);
                            system("cls");
                        }
                        system("cls");
                        break;
            }
			if(opc>3||opc<0){
            system("cls");
            cout<<"opción invalida, intentelo de nuevo!\n"<<endl;
            }
            opc = menu();
		}
	}
}\
