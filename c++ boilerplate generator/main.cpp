#include "header.h"

int main(){

	inizializza();

	string project_name;
	string name;
	string header; 
	vector<string> aux;

	/* 
		project_name = 1
		name = 2
		header = 3
	*/
	project_name = richiestaUtente(1);
	creaDirectory(project_name);
	name = richiestaUtente(2);
	creaFile(name, project_name);
	header = richiestaUtente(3);
	creaFile(header, project_name);
	aux = richiediAux();
	for (int i=0; i<aux.size(); i++) creaFile(aux[i], project_name);
	collegaFile(name, header, aux, project_name);
	
	cout << "\n\nGrazie per aver usato c++ boilerplate generator. Troverai la cartella "+project_name+" del progetto con i boilerplate insieme all'eseguibile di questo file.\n\n\033[1;35mPer compilare i file ti basterà eseguire questo comando:\n\ng++ "+name+" ";
	for (int i=0; i<aux.size(); i++) cout << aux[i]+" ";
	cout << "\033[0m\n\n\nCopyright @samuelepignone & @milogalli\n\nSe ti va seguici su github:\n\n\t@SamuelePignone\n\t@Peek-Ink\n" << endl;

	return 0;

}