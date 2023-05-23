#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <math.h>

using namespace std;
//declaracion de variables
float imp;
struct TIENDA 
{
	string games;
	float precio, articulo, clasf;
	float imp;
	int year;
	int tot;
	string juego, cons, descrip, status;
};
int alta;
TIENDA* JUEGOS; // uso de punteros
//funciones con void
void Alta();
void eliminar();
void listas();
void modificar();
void archivos();

int main()
{
	int opc;
	 printf("\t\t\t%c%c%c%c BIENVENIDO A LA TIENDA EN LINEA,QUE DESEA HACER?%c%c%c%c \n", 205,221,221,221,221,221,221,205);
	 printf("\t\t\t\t\t\t1.-Alta\n \t\t\t\t\t\t2.-Mostrar\n \t\t\t\t\t\t3.-Limpiar pantalla\n \t\t\t\t\t\t4.-Modificar\n \t\t\t\t\t\t5.-Eliminar\n \t\t\t\t\t\t6.-Salir\n");
	cin >> opc;

	switch (opc)
	{
	case 1:
		Alta();
		return main();
		break;

	case 2:
		listas();
		return main();
		break;

	case 3:
		system("cls"); //system("clear");
		return main();
		break;

	case 4:
		modificar();
		return main();
		break;
		
	case 5:
		eliminar();
		return main();
		break;

	case 6:
		archivos();
		break;
	}
}
void Alta()
{
	printf("cuantos registros desea dar de alta \n");
	scanf_s("%d", &alta);
	JUEGOS = new TIENDA[alta]; // uso de new para hacer el arreglo dinamico
	for (int i = 0; i < alta; i++)
	{
		printf("Ingrese numero del art%cculo\n",161 ); //printf
		scanf_s("%f", &JUEGOS[i].articulo); //scanf %d
		cin.ignore();
		cout << "Ingrese nombre\n";
		getline(cin, JUEGOS[i].juego); //permite los espacios en el nombre
		printf("Ingrese la clasificaci%cn del juego (edad para jugar)\n", 162); //printf
		scanf_s("%f", &JUEGOS[i].clasf); //scanf %d
		printf("Ingrese para que consola es\n");
		cin.ignore();
		getline(cin, JUEGOS[i].cons);
		printf("De una peque%ca descripci%cn del juego\n", 164,162 ); //printf
		cin.ignore();// se vacía el buffer o el espacio
		getline(cin, JUEGOS[i].descrip); // permite los espacios en la descripción
		printf("Ingrese el precio del juego\n");
		scanf_s("%f", &JUEGOS[i].precio);
		JUEGOS[i].imp = JUEGOS[i].precio * .16;
		printf("El impuesto es de %f\n", JUEGOS[i].imp);
		JUEGOS[i].tot = JUEGOS[i].precio + JUEGOS[i].imp;
		printf("Total de su compra es %d\n", JUEGOS[i].tot);
		printf("Ingrese en qu%c a%co sali%c el juego\n",130,164, 162); //printf
		scanf_s("%d", &JUEGOS[i].year);

	}
}

void listas()
{
	for (int i = 0; i < alta; i++)
	{
		//if (matricula[i] == 0)
		if (JUEGOS[i].status == "ELIMINADO")
		{
			printf("REGISTRO ELIMINADO %d\n", i + 1);
		}
		else
		{
			printf("\t\t\t\t\t\t%c%c%c%cREGISTRO NUMERO%c%c%c%c %d\n", 205, 221, 221, 221, 221, 221, 221, 205, i + 1);
			printf("\t\t\tArt%cculo: %f\n",161, JUEGOS[i].articulo);
			printf("\t\t\tJuego: %s\n", JUEGOS[i].juego.c_str());
			printf("\t\t\tClasificaci%cn: %f\n",162, JUEGOS[i].clasf);
			printf("\t\t\tConsola: %s\n", JUEGOS[i].cons.c_str());
			printf("\t\t\tDescripci%cn: %s\n",162,  JUEGOS[i].descrip.c_str());
			printf("\t\t\tPrecio: %f\n", JUEGOS[i].precio);
			printf("\t\t\tImpuesto: %f\n", JUEGOS[i].imp);
			printf("\t\t\tA%co de lanzamiento: %d\n",164, JUEGOS[i].year);
			printf("\t\t\tTotal con impuesto: %d\n", JUEGOS[i].tot);
		}
	}
}
void eliminar()
{
	int j;
	printf ("Ingrese el  registro a eliminar");
	cin >> j;
	j = j - 1;
	for (int i = j; i == j; i++)
	{
		printf("REGISTRO ELIMINADO %d\n", i + 1);
		JUEGOS[i].status = "ELIMINADO";
		JUEGOS[i].articulo = 0;
		JUEGOS[i].clasf=0;
		JUEGOS[i].tot=0;
	}
}
void modificar()
{
	int j, opcion, op2;
	do
	{
		printf("Ingrese el n%cmero de registro a modificar: ",163 );
		cin >> j;
		j = j - 1; // Esto se hace para ajustar el índice al arreglo que comienza en 0

		for (int i = j; i <= j; i++)
		{
			if (JUEGOS[i].status == "ELIMINADO")
			{
				printf("REGISTRO ELIMINADO\n");
				printf("Ingrese un nuevo juego:\n");
				op2 = 1;
			}
			else
			{
				op2 = 2;
			}
		}
	} while (op2 == 1);
	printf ("Ingrese que desea modificar\n1.-Articulo\n2.-Juego\n3.- Clasficacion\n");
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			printf ("Ingrese el N%c articulo\n", 248);
			scanf_s ("%f", &JUEGOS[i].articulo);
		}
		break;
	case 2:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			cout << "Ingrese nombre\n" << endl;
			getline(cin, JUEGOS[i].juego);
		}
		break;

	case 3:
		for (int i = j; i == j; i++)
		{
			printf ("Ingrese la clasificaci%cn del juego\n", 162);
			scanf_s ("%f", &JUEGOS[i].clasf);
		}
	}


}

void archivos()
{
	ofstream archivo;
	string nombrearchivo;
	int texto;
	string texto2;
		nombrearchivo = "altasvideojuegos.txt";

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		cout << "ERROR: NO SE PUDO CREAR EL ARCHIVO";
		exit(1);
	}

	archivo << "ARTICULO" << "\t";
	archivo << "JUEGO" << "\t";
	archivo << "CLASIFICACIÓN" << "\t";
	archivo << "AÑO DE LANZAMIENTO" << "\t";
	archivo << "CARACTERISTICAS" << "\t";
	archivo << "DESCRIPCIÓN" << "\t";
	archivo << "PRECIO UNITARIO" << "\t";
	archivo << "IMPUESTO" << "\t";
	archivo << "TOTAL" << "\t";
	archivo << "\n";

	for (int i = 0; i < alta; i++)
	{
		if (JUEGOS[i].status == "ELIMINADO")
		{
			texto2 = "REGISTRO ELIMINADO ";
			texto = i;
			archivo << texto2 << texto << "\n";
		}
		else
		{
			texto = JUEGOS[i].articulo;
			archivo << texto << "\t";
			texto2 = JUEGOS[i].juego;
			archivo << texto2 << "\t";
			texto = JUEGOS[i].clasf;
			archivo << texto << "\t";
			texto = JUEGOS[i].year;
			archivo << texto << "\t";
			texto2 = JUEGOS[i].descrip;
			archivo << texto2 << "\t";
			texto = JUEGOS[i].precio;
			archivo << texto << "\t";
			texto = JUEGOS[i].imp;
			archivo << texto << "\t";
			texto = JUEGOS[i].tot;
			archivo << texto << "\t";
			archivo << "\n";
		}
	}

	archivo.close();
}




