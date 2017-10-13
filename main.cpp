#include <iostream>
#include <string>
#include "lista.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	
	
	int numeroEstud=0;  // Número de estudiantes que ya tenemos
	int i;   
	int k;            // Para bucles
	int opcion; // La opcion del menu que elija el usuario
	init_cabeza();         
	numeroEstud=ejemplo(); //ejemplo propuesto en clase
	
	do
    {
        // Menu principal
        cout << endl;
        cout << "Escoja una opción:" << endl;
        cout << "1.- Añadir datos de un nuevo estudiante" << endl;
        cout << "2.- Mostrar los nombres de todos los estudiantes" << endl;
        cout << "3.- Mostrar los nombre de los estudiantes segun su carrera" << endl;
        cout << "4.- Mostrar los nombre de los estudiantes segun su edad"  << endl;
        cout << "5.- Mostrar los nombre de los estudiantes segun su hobby"  << endl;
        cout << "6.- Salir" << endl;
 
        cin >> opcion;
 
        // Hacemos una cosa u otra según la opción escogida
        switch(opcion){
            case 1: // Añadir un dato nuevo
                if (numeroEstud < 50){ // Si queda hueco
                    cout << "Introduce el nombre del estudiante: ";
                    cin >> Lista[numeroEstud].name;
                    cout << "Introduce la carrera: ";
                    cin >> Lista[numeroEstud].carr;
                    cout << "Introduce la edad: ";
                    cin >> Lista[numeroEstud].edad;
                    cout << "Introduce la hobby: ";
                    cin >> Lista[numeroEstud].hobby;
                    
                    anadir(numeroEstud);			                
                    	
                    numeroEstud++;  // Y tenemos un estudiante más
                }
                else   // Si no hay hueco para más estudiante, avisamos
                    cout << "Máximo de festudiantes (50)!" << endl;
                break;
 
            case 2: // Mostrar todos
            	mostrar_nombre();
                break;
 
 
            case 3: // Mostrar según la carrera
            	
				cout << endl;
		        cout << "Escoje una carrera:" << endl;
		        cout << "1.- sistemas" << endl;
		        cout << "2.- electronica" << endl;
		        cout << "3.- industrial" << endl;
		        cout << "4.- catastral"  << endl;
		        cout << "5.- Regresar" << endl;            	
                cin >> opcion;
                switch(opcion){
                	case 1:
                		mostrar_carrera(2);
                		break;
                	case 2:
                		mostrar_carrera(3);
                		break;
                	case 3:
                		mostrar_carrera(4);
                		break;
                	case 4:
                		mostrar_carrera(5);
                		break;                		
				}
                break;
 
            case 4: // Mostrar todos por edad
            	mostrar_edad();
                break;
                
            case 5: // Mostrar según hobby
				cout << endl;
		        cout << "Escoje un hobby:" << endl;
		        cout << "1.- danza" << endl;
		        cout << "2.- natacion" << endl;
		        cout << "3.- basket" << endl;
		        cout << "4.- beisbol"  << endl;
		        cout << "5.- Regresar" << endl;            	
                cin >> opcion;
                switch(opcion){
                	case 1:
                		mostrar_hobby(6);
                		break;
                	case 2:
                		mostrar_hobby(7);
                		break;
                	case 3:
                		mostrar_hobby(8);
                		break;
                	case 4:
                		mostrar_hobby(9);
                		break;
                		
				}
                break;
 
            case 6: // Salir: avisamos de que salimos
                cout << "Fin del programa" << endl;
                break;
 
            default: // Otra opcion: no válida
                cout << "Opción desconocida!" << endl;
                break;
        }
    } while (opcion != 6);  // Si la opcion es 5, terminamos 
	return 0;
}
