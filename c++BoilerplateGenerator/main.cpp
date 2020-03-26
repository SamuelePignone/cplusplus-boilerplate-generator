#include "header.h"

int main(){

	msg::init();

	string directory, name, header; 
	vector<string> aux;

	directory = path::UserRequest();
	name = ma::UserRequest();
	createFile(name, directory);
	header = head::UserRequest();
	createFile(header, directory);
	aux = requestAux();
	for (int i=0; i<aux.size(); i++) createFile(aux[i], directory);
	cout << "\n\n" << name << "\n" << header << "\n" << directory << "\n\n";
	linkFile(name, header, aux, directory);
	
	msg::end(directory, name, aux);

	return 0;

}