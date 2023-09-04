#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int numeros[] {1,2,3,4,5};
	int inf,sup,mitad,dato;
	char band='f';
	dato=4;
	
	
	while(inf<=sup){
		mitad=(inf+sup)/2;
		
		if(numeros[mitad]==dato){
			
			band='v';
			break;
		}
		if (numeros[mitad]>dato){
			sup=mitad;
			mitad=(inf+sup)/2;
		}
			if (numeros[mitad]<dato){
			inf=mitad;
			mitad=(inf+sup)/2;
	}
	
	}
	if(band =='v'){
		cout<<"el numero a sido encontrado en la posicion:"<<mitad<<endl;
	}
	else{
		cout<<"el numero no ha sido encontrado";
	}
	getch();
	return 0;
}