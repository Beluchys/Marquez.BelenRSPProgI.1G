#include <stdio.h>
#include <stdlib.h>

typedef struct{
int id;
char marca[20];
int tipo;
float peso;

}eVehiculo;

void sortMarca_Peso(eVehiculo vehiculo[], int tam){
	eVehiculo aux;
	for(int i = 0; i < tam-1; i++){
		for(int j = i + 1; j < tam; j++){
			// Marca -> Menor a Mayor (Ascendente alfabeticamente)
			if(strcmp(vehiculo[i].marca, vehiculo[j].marca) > 0){
				aux = vehiculo[i];
				vehiculo[i] = vehiculo[j];
				vehiculo[j] = aux;
			}
			// Peso -> Menor a Mayor
			else if(strcmp(vehiculo[i].marca, vehiculo[j].marca) == 0 &&
					vehiculo[i].peso > vehiculo[j].peso){
				aux = vehiculo[i];
				vehiculo[i] = vehiculo[j];
				vehiculo[j] = aux;
			}
		}
	}
}

void mostrarListado(eVehiculo lista, int tam)
{

    printf("   %d      %10s    Kg  %9.2f     %d \n",
           lista.id,
           lista.marca,
            lista.peso,
           lista.tipo
          );
}

int main()
{
    eVehiculo vehiculo[4] = {//ID   TIPO    MARCA      Peso
								{5000, "Ford", 	205, 	48000},
								{5001, "Wol", 	405, 		35000},
								{5002, "Fiat", 	500, 		33000},
								{5003, "Chevrole", 	10, 	95000} };



sortMarca_Peso(vehiculo, 4);

printf("\n\nMostrar lista de Vehiculos según el Criterio: Marca y peso\n \n"
			"    ID       Marca        tipo      Peso\n");
	for(int i = 0; i <4; i++){
		printf("    %d    %10s    %d   Kg %.2f\n", vehiculo[i].id, vehiculo[i].marca, vehiculo[i].tipo, vehiculo[i].peso);
	}


    return 0;
}
