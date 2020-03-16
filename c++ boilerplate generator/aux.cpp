#include "header.h"
#include <sys/stat.h> 
#include <sys/types.h> 

void inizializza(){
	cout << "\x1B[2J\x1B[H";
	cout << "\e[8;40;170t";
	cout << R"(

  _____                ____          _  _                     _         _           _____                                 _               
 / ____|  _      _    |  _ \        (_)| |                   | |       | |         / ____|                               | |              
| |     _| |_  _| |_  | |_) |  ___   _ | |  ___  _ __  _ __  | |  __ _ | |_  ___  | |  __   ___  _ __    ___  _ __  __ _ | |_   ___   _ __ 
| |    |_   _||_   _| |  _ <  / _ \ | || | / _ \| '__|| '_ \ | | / _` || __|/ _ \ | | |_ | / _ \| '_ \  / _ \| '__|/ _` || __| / _ \ | '__|
| |____  |_|    |_|   | |_) || (_) || || ||  __/| |   | |_) || || (_| || |_|  __/ | |__| ||  __/| | | ||  __/| |  | (_| || |_ | (_) || |   
 \_____|              |____/  \___/ |_||_| \___||_|   | .__/ |_| \__,_| \__|\___|  \_____| \___||_| |_| \___||_|   \__,_| \__| \___/ |_|   
	                                              | |  
	                                              |_|                                                                               
	)" << endl;
}

string richiestaUtente(int type){
	switch(type){
		case 1: {
			string project; 
			cout << "Inserisci il nome del progetto: ";
			cin >> project;
			return project;
			}break;
		case 2: {
			string name;
			cout << "Inserisci un nome per il main file: ";
			cin >> name;
			return name = name.substr(0, name.find(".", 0))+".cpp";
			}break;
		case 3: {
			string header; 
			cout << "Inserisci un nome per l'header: ";
			cin >> header;
			return header = header.substr(0, header.find(".", 0))+".h";
			}break;
	}
}

vector<string> richiediAux(){
	vector<string> aux;
	char choice;
	string tmp;
	do {
		cout << "Inserisci un nome per il file ausiliario: ";
		cin >> tmp;
		tmp = tmp.substr(0, tmp.find(".", 0))+".cpp";
		if(find(aux.begin(), aux.end(), tmp) != aux.end()) {
		    choice = 'y';
		    cout << "\n\033[1;31mInserisci un nome diverso da quelli già inseriti!\033[0m\n" << endl;
		} else {
		    aux.push_back(tmp);
			cout << "Vuoi creare altri file ausiliari? (y/N) ";
			cin >> choice;
		}
	} while(choice == 'y' || choice == 'Y');
	return aux;
}

void creaDirectory(string directory){
	mkdir(directory.c_str(), 0777);
}

void creaFile(string nome, string directory){
	ofstream myfile;
  	myfile.open("./" + directory + "/" + nome);
  	myfile.close();
}

void collegaFile(string main_name, string header_name, vector<string> aux_name, string project_name){
	ofstream main;
	main.open("./" + project_name + "/" + main_name);
	main << "#include \""+header_name+"\"\n\nint main(){\n\n\treturn 0;\n}";
	main.close();
	ofstream header;
	header.open("./" + project_name + "/" + header_name);
	header << "#include <iostream>\n\nusing namespace std;\n\n/* Prototipi funzioni ed eventuale implementazione di un namespace */";
	header.close();
	for (int i=0; i<aux_name.size(); i++){
		ofstream aux;
		aux.open("./" + project_name + "/" + aux_name[i]);
		aux << "#include \""+header_name+"\"\n\n/* Implementazione funzioni */";
		aux.close();
	}
}









