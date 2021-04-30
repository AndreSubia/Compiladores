#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int findPos(vector<int> ascii,int num){
    vector<int>::iterator it;
    it = find(ascii.begin(),ascii.end(),num);
    if(it!=ascii.end()){
        return it-ascii.begin();
    }
    return 0;
}

void ejercicioA(){
    string instruccion;
    getline(cin,instruccion);
    for(int i=0;i<instruccion.length();i++){
        cout<<instruccion[i]<<endl;
    }
}

void ejercicioB(string nombreArchivo){
    ifstream archivo;
    char letra;
    archivo.open(nombreArchivo);
    if(archivo.fail()){return;}
    while(!archivo.eof()){
        archivo.get(letra);
        cout<<letra<<endl;
    }
}

class Cesar{
    private:
        vector<int> alfabeto_ascii {9,10,11,
                                    31,32,33,34,35,36,37,38,39,40,
                                    41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,
                                    61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,
                                    81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,
                                    101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,
                                    121,122,123,124,125,126};
    public:
        Cesar(){};
        void cifrar(string nombreArchivo,int clave){
            ifstream archivo;
            ofstream mensajeCifrado;
            char letra;
            int pos;
            archivo.open(nombreArchivo);
            mensajeCifrado.open("mensajeCifrado.txt",ios::out);
            if(archivo.fail()){return;}
            while(!archivo.eof()){
                archivo.get(letra);
                pos = findPos(alfabeto_ascii,int(letra));
                int num = alfabeto_ascii[(pos+clave)%(alfabeto_ascii.size()-1)];
                mensajeCifrado<<char(num);
            }
            archivo.close();
            mensajeCifrado.close();
        }

        void descifrar(string nombreArchivo,int clave){
            ifstream archivo;
            ofstream mensajeDescifrado;
            char letra;
            int pos;
            archivo.open(nombreArchivo);
            mensajeDescifrado.open("mensajeDescifrado.txt",ios::out);
            if(archivo.fail()){return;}
            while(!archivo.eof()){
                archivo.get(letra);
                pos = findPos(alfabeto_ascii,int(letra));
                int num = alfabeto_ascii[(pos-clave)%(alfabeto_ascii.size()-1)];
                mensajeDescifrado<<char(num);
            }
            archivo.close();
            mensajeDescifrado.close();
        }
};

void ejercicioD(string nombreArchivo){
    ifstream archivo;
    char letra;
    archivo.open(nombreArchivo);
    if(archivo.fail()){return;}
    bool n = true,p = true;
    while(!archivo.eof()){
        archivo.get(letra);
        cout<<letra;
        if(letra==10||letra==11||letra==32||archivo.eof()){
            if(n==true && p==false){cout<<" es un numero"<<endl;}
            if(n==false && p==true){cout<<" es una palabra"<<endl;}
            if( (n==false && p==false) || (n==true && p==true) ){cout<<" es un caracter especial"<<endl;}
            n = true;
            p = true;
        }
        else{
            n = (letra>=48 && letra<=57)? true : false;
            p = (letra>=97 && letra<=122)? true : false;
        }
    }
}


int main(){
    ejercicioA();
    ejercicioB("pseudocodigo.txt");
    Cesar a;
    a.cifrar("pseudocodigo.txt",1);
    a.descifrar("mensajeCifrado.txt",1);
    ejercicioD("pseudocodigo.txt");
    return 0;
}