//brandon gomez 20132020626
#include <iostream>
using namespace std;

struct Estud{
	string name, carr, hobby;
	int edad;
	int sig_name, sig_edad, sig_carr, sig_hobby;
};

struct cabezas{
	string nombre;
	int pos_cab;
};


Estud *Lista= new Estud[50];
cabezas *cab= new cabezas[10];
Estud *aux= new Estud;

void init_cabeza(){
	cab[0].nombre="nombre";
	cab[0].pos_cab=-1;
	cab[1].nombre="edad";
	cab[1].pos_cab=-1;
	cab[2].nombre="sistemas";
	cab[2].pos_cab=-1;
	cab[3].nombre="electronica";
	cab[3].pos_cab=-1;
	cab[4].nombre="industrial";
	cab[4].pos_cab=-1;
	cab[5].nombre="catastral";
	cab[5].pos_cab=-1;
	cab[6].nombre="danza";
	cab[6].pos_cab=-1;
	cab[7].nombre="natacion";
	cab[7].pos_cab=-1;
	cab[8].nombre="basket";
	cab[8].pos_cab=-1;
	cab[9].nombre="beisbol";
	cab[9].pos_cab=-1;
}

void ordenar_nombre(int estud){
	int j;
	int i=cab[0].pos_cab;  
	
	if(estud<1){
		cab[0].pos_cab=0;
		return;
	}
	
	string str1=Lista[estud].name;
	string str2=Lista[i].name;
	
	if(str1.compare(str2)<0){
		Lista[estud].sig_name=cab[0].pos_cab;
		cab[0].pos_cab=estud;
				
	}else{
		while(Lista[i].sig_name!=-1){
			j=Lista[i].sig_name;
			str2=Lista[j].name;
			
			if(str1.compare(str2)<0){
				Lista[estud].sig_name=j;
				Lista[i].sig_name=estud;	
				
				return;	
			}	
			i=j;	
		}
		Lista[j].sig_name=estud;
		Lista[estud].sig_name=-1;		
	}	
	
}

void ordenar_carrera(int estud){
	 
	int k;
	string carr=Lista[estud].carr;
	
	if(carr=="sistemas"){
		k=2;
	}else if(carr=="electronica"){
		k=3;
	}else if(carr=="industrial"){
		k=4;
	}else if(carr=="catastral"){
		k=5;
	}else{
		cout<<"la carrera no existe \n";
		return;
	}
	int j;
	int i=cab[k].pos_cab; 
	
	if(cab[k].pos_cab==-1){
		cab[k].pos_cab=estud;
	}else{
		int i=cab[k].pos_cab; 
		while(Lista[i].sig_carr!=-1){
			j=Lista[i].sig_carr;
			i=j;	
		}
		Lista[i].sig_carr=estud;
		Lista[estud].sig_carr=-1;
	}	
}

void ordenar_hobby(int estud){
	
	string hobb=Lista[estud].hobby;
	int k=-1;
	
	if(Lista[estud].hobby=="danza"){
		k=6;
	}
	if(Lista[estud].hobby=="natacion"){
		k=7;
	}
	if(Lista[estud].hobby=="basket"){
		k=8;
	}
	if(Lista[estud].hobby=="beisbol"){
		k=9;
	}
	if(k==-1){
		cout<<"el hobby no existe\n";
		return;
	}
	
	int j;
	int i=cab[k].pos_cab; 
	
	if(cab[k].pos_cab==-1){
		cab[k].pos_cab=estud;
	}else{
		while(Lista[i].sig_hobby!=-1){
			j=Lista[i].sig_hobby;
			i=j;	
		}
		Lista[i].sig_hobby=estud;
		Lista[estud].sig_hobby=-1;
	}	
}

void ordenar_edad(int estud){
	int j;
	int i=cab[1].pos_cab;  
	
	if(estud<1){
		cab[1].pos_cab=0;
		return;
	}
	
	int edad1=Lista[estud].edad;
	int edad2=Lista[i].edad;
	
	if(edad1>edad2){
		Lista[estud].sig_edad=cab[1].pos_cab;
		cab[1].pos_cab=estud;
				
	}else{
		while(Lista[i].sig_edad!=-1){
			j=Lista[i].sig_edad;
			edad2=Lista[j].edad;
			
			if(edad1>edad2){
				Lista[estud].sig_edad=j;
				Lista[i].sig_edad=estud;				
				return;	
			}	
			i=j;	
		}
		Lista[j].sig_edad=estud;
		Lista[estud].sig_edad=-1;		
	}	
	
}

void mostrar_nombre(){
	int j=cab[0].pos_cab;
	int i;  
	do{
		i=j;
		cout<<Lista[i].name<<"\n";
		j=Lista[i].sig_name;	
			
	}while(Lista[i].sig_name!=-1);
}

void mostrar_edad(){
	int j=cab[1].pos_cab;
	int i;  
	do{
		i=j;
		cout<<Lista[i].name<<" "<<Lista[i].edad<<"\n";
		j=Lista[i].sig_edad;	
			
	}while(Lista[i].sig_edad!=-1);
}

void mostrar_carrera(int k){
	int j=cab[k].pos_cab;
	int i;  
	if(cab[k].pos_cab==-1){
		cout<<"no hay";
		return;
	}
	do{
		i=j;
		cout<<Lista[i].name<<"\n";
		j=Lista[i].sig_carr;	
			
	}while(Lista[i].sig_carr!=-1);
}

void mostrar_hobby(int k){
/*	int k;
	if(carr=="danza"){
		k=2;
	}else if(carr=="natacion"){
		k=3;
	}else if(carr=="basquet"){
		k=4;
	}else if(carr=="beisbol"){
		k=5;
	}else{
		cout<<"el hobby no existe\n";
		return;
	}
*/	
	int j=cab[k].pos_cab;
	int i;  
	if(cab[k].pos_cab==-1){
		cout<<"no hay\n";
		return;
	}
	do{
		i=j;
		cout<<Lista[i].name<<"\n";
		j=Lista[i].sig_hobby;	
			
	}while(Lista[i].sig_hobby!=-1);
}

void anadir(int numeroEstud){
	Lista[numeroEstud].sig_name=-1;
    Lista[numeroEstud].sig_carr=-1;
    Lista[numeroEstud].sig_edad=-1;
    Lista[numeroEstud].sig_hobby=-1;
	ordenar_nombre(numeroEstud);  	
	ordenar_carrera(numeroEstud);
	ordenar_edad(numeroEstud);
	ordenar_hobby(numeroEstud);
}

int ejemplo(){
	Lista[0].name="raquel";
	Lista[0].carr="electronica";
	Lista[0].hobby="danza";
	Lista[0].edad=21;
	anadir(0);
	
	Lista[1].name="jaime";
	Lista[1].carr="industrial";
	Lista[1].hobby="natacion";
	Lista[1].edad=18;
	anadir(1);
	
	Lista[2].name="arturo";
	Lista[2].carr="electronica";
	Lista[2].hobby="basket";
	Lista[2].edad=16;
	anadir(2);
	
	Lista[3].name="andres";
	Lista[3].carr="catastral";
	Lista[3].hobby="danza";
	Lista[3].edad=24;
	anadir(3);
	
	Lista[4].name="ariana";
	Lista[4].carr="sistemas";
	Lista[4].hobby="basket";
	Lista[4].edad=19;
	anadir(4);
	
	Lista[5].name="juanny";
	Lista[5].carr="industrial";
	Lista[5].hobby="natacion";
	Lista[5].edad=17;
	anadir(5);
	
	Lista[6].name="marypaz";
	Lista[6].carr="sistemas";
	Lista[6].hobby="danza";
	Lista[6].edad=25;
	anadir(6);
	
	Lista[7].name="italia";
	Lista[7].carr="catastral";
	Lista[7].hobby="beisbol";
	Lista[7].edad=22;
	anadir(7);
	
	Lista[8].name="mario";
	Lista[8].carr="sistemas";
	Lista[8].hobby="basket";
	Lista[8].edad=20;
	anadir(8);
	
	Lista[9].name="pilar";
	Lista[9].carr="sistemas";
	Lista[9].hobby="beisbol";
	Lista[9].edad=23;
	anadir(9);
	
	return 10;	
}





