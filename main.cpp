//
//  main.cpp
//  Tarea-3-2
//
//  Created by Javier Curiel on 10/7/15.
//  Copyright © 2015 Javier Curiel. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class linea{
    int maxTam;
    int b;
    int total;
    vector<int> palabras;
public:
    linea(int maxTam,int b){
        this->maxTam = maxTam;
        this->b = b;
        total = 0;
    }
    bool insertarPalabra(int palabra){
        if(getLongitud()+palabra > maxTam){
            if(compara(palabra)){
                while(b>=2){
                    b--;
                    if (getLongitud()+palabra <= maxTam){
                        palabras.push_back(palabra);
                        total += palabra;
                        return true;
                    }
                }
            }
            else{
                while(getLongitud() != maxTam){
                    b++;
                }
                return false;
            }
        }
        else{
            palabras.push_back(palabra);
            total += palabra;
            return true;
        }
        return false;
    }

    bool compara(int palabra){
        int original = b;
        int costoAchicar = 0;
        int costoPasarSiguiente = 0;
        while(b>=2){
            b--;
            costoAchicar++;
        }
        while(getLongitud() != maxTam){
            b++;
            costoPasarSiguiente++;
        }
        b = original;
        return costoAchicar > costoPasarSiguiente;
    }
    
    void setB(int b){
        this->b = b;
    }
    int getB(){
        return b;
    }
    unsigned long getLongitud(){
        return total+(b*(palabras.size()-1));
    }
    void clear(){
        total = 0;
        palabras.clear();
    }
    void print(){
        for(int i = 0; i < palabras.size();i++){
            cout << palabras[i] << " ";
        }
    }
};


int main(int argc, const char * argv[]) {
    int tamLinea = 26;
    int b = 2;
    vector<int> longitudes = {10,10,4,8,10,12,12};
    
    vector<linea> parrafo;
    linea nueva(tamLinea,b);
    int i = 0;
    while(i<longitudes.size()){
        if(nueva.insertarPalabra(longitudes[i]))
            i++;
        else{
            parrafo.push_back(nueva);
            nueva.clear();
            nueva.setB(b);
        }
    }
    parrafo.push_back(nueva);
    
    for(int j = 0; j < parrafo.size();j++){
        parrafo[j].print();
        cout << " con b: " << parrafo[j].getB() <<endl;
    }

    
}
