#include "header.h"

int main(){

	msg::inizializza();

	string directory, name, header; 
	vector<string> aux;

	directory = path::richiestaUtente();
	name = ma::richiestaUtente();
	creaFile(name, directory);
	header = head::richiestaUtente();
	creaFile(header, directory);
	aux = richiediAux();
	for (int i=0; i<aux.size(); i++) creaFile(aux[i], directory);
	cout << "\n\n" << name << "\n" << header << "\n" << directory << "\n\n";
	collegaFile(name, header, aux, directory);
	
	msg::termina(directory, name, aux);

	return 0;

}