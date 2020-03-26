#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

namespace ma{
	string richiestaUtente();										/* chiede all'utente una path per il boilerplate */
}

namespace head{
	string richiestaUtente();										/* chiede all'utente una path per il boilerplate */
}

namespace path{
	string richiestaUtente();										/* chiede all'utente una path per il boilerplate */
}

namespace msg{
	void inizializza();												/* funzione decorativa per il terminale */
	void termina(string, string, vector<string>);					/* funzione decorativa per il terminale */
}

void creaFile(string, string);										/* crea un file con nome passato */
vector<string> richiediAux();										/* chiede all'utente tutti i file ausiliari e li salva in un vettore */
void creaDirectory(string); 										/* crea una directory per il progetto */
void collegaFile(string, string, vector<string>, string);			/* inserisce il testo atto a collegare i file */
