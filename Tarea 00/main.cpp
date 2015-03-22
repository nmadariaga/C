#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <fstream>
#define NUMEROS 14 //cantidad de numeros a elegir
#define NUM_MAX 25 //numero maximo

using namespace std;


int main(int argc, char *argv[])
{
   if(argc!=2)
   {
      cout<<"Comandos aceptados: -g o -v"<<endl;
      exit(1);
   }
    char parametro = argv[1][1];
    if(parametro!='g' && parametro!='v')
    {
        cout<<"Comando Inválido, intente con -g o -v"<<endl;
    }
    if(parametro=='g')
    {
        time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        char output[128];
        strftime(output,128,"%d-%m-%y %H:%M",tlocal);
        int numeros[NUMEROS]; //combinacion ganadora !!!
        int nuevo_numero; // numero elegido
        bool repetido; // por si el numero elegido se repite
        for (int cont=0; cont<NUMEROS; cont++)//inicializar el arreglo
        {
            numeros[cont]=0;
        }
        srand(time(NULL)); //inicializar generador de aleatorios
        //buscar numeros
        for (int i=0; i<NUMEROS; i++)
        {
            do{
                nuevo_numero = rand()%(NUM_MAX)+1; //le agrego 1 por si sale 0
                repetido = false;//verificar que no este repetido
                for (int j=0; j<NUMEROS; j++)
                {
                    if (nuevo_numero==numeros[j])
                    {
                        repetido = true;
                    break;
                    }
                }
            }while (repetido); //hacer mientras no se repita el numero
            numeros[i] = nuevo_numero;
        }
        FILE* archivo = fopen("Fichero.csv", "r");
        if (archivo)
        {
            cout<<endl;
            cout<<"Actualizando el archivo...";
            std::fstream archivo;
            archivo.open ("Fichero.csv", std::fstream::ate|std::fstream::in | std::fstream::out);
            archivo<<endl;
            archivo<<output<<";";
            for (int cont=0; cont<NUMEROS; cont++)
            {
                archivo<<numeros[cont]<<";";
            }
            cout<<endl;
            cout<<"Nuevos datos agregados con éxito!"<<endl;;
            archivo.close();
            cout<<endl;
        }
        else
        {
            cout<<endl;
            printf("El archivo no existe, se creara uno nuevo");
            ofstream fichero("Fichero.csv");
            fichero<<output<<";";
            for (int cont=0; cont<NUMEROS; cont++)
            {
                fichero<<numeros[cont]<<";";
            }
            cout<<endl;
            fichero.close();
            cout<<"El archivo 'Fichero.csv' ha sido creado correctamente!"<<endl;
            cout<<"Busquelo dentro del directorio del proyecto."<<endl;
            cout<<endl;
        }
    }
    if(parametro=='v')
    {
        cout<<endl;
        cout<<"Integrantes del grupo: "<<"\tNeftali Madariaga"<<endl;
        cout<<"\t\t\tJuan Pablo Sepulveda"<<endl;
        cout<<"\t\t\tGladys Cerro"<<endl;
        time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        char output[128];
        strftime(output,128,"%d-%m-%y %H:%M",tlocal);
        cout<<"Fecha de compilacion: "<<output<<endl;
        cout<<endl;
    }
   return 0;
   }
