#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void TriParSelection(int T[]) {
    int min, temp;
    for (int i = 0; i < 999; i++) {
        min = i;
        for (int j = i + 1; j < 1000; j++) {
            if (T[j] < T[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = T[min];
            T[min] = T[i];
            T[i] = temp;
        }
    }
}

void TriParInsertion(int T[]) {

	int x, y;

	for(int i = 1; i < 1000; i++) {
	
		x = T[i];
		y = i - 1;
		while((y >= 0) && (T[y] > x)) {
		
			T[y + 1] = T[y];
			y--;
		}

		T[y + 1] = x;
	}
}

void TriABulles(int T[]) {
	int temp;
	for(int i = 0; i < 999; i++) {
	
		for(int j = 0; j < 999 - i; j++) {
		
			if(T[j] > T[j + 1]) {
			
				temp = T[j];
				T[j] = T[j + 1];
				T[j + 1] = temp;
			}
		}
	}
}

int partition(int T[], int debut, int fin) {

    int pivot = T[fin];
    int i = (debut - 1);
    for(int j = debut; j < fin; j++) {

        if(T[j] <= pivot) {
            i++;
            int temp = T[i];
            T[i] = T[j];
            T[j] = temp;
        }
    }

    int temp = T[i + 1];
    T[i + 1] = T[fin];
    T[fin] = temp;
    return (i + 1);
}

void TriRapide(int T[], int debut, int fin) {

	if(debut < fin) {

		int pi = partition(T, debut, fin);
		TriRapide(T, debut, pi - 1);
		TriRapide(T, pi + 1, fin);
	}
}
void Fusion(int T[], int debut, int millieu, int fin) {

	int i1 = debut, i2 = millieu + 1, i = 0, temp[1000];
	while((i1 <= millieu) && (i2 <= fin)) {
	
		if(T[i1] < T[i2]) {
		
			temp[i] = T[i1];
			i1++;

		}else {
		
			temp [i] = T[i2];
			i2++;
		}
		i++;
	}
	while(i1 <= millieu) {
	
		temp[i] = T[i1];
		i++;
		i1++;
	}
 
	while(i2 <= fin) {
	
		temp[i] = T[i2];
		i++;
		i2++;
	}

	for(int k = 0; k < i; k++) {
		
		T[debut + k] = temp[k];
	}
}


void TriFusion(int T[], int debut, int fin) {

	int millieu;
	if(debut < fin) {
		
		millieu = (debut + fin) / 2;
		TriFusion(T, debut, millieu);
		TriFusion(T, millieu + 1, fin);
		Fusion(T, debut, millieu, fin);
	}
}

int main () {
    int T1[1000];
    int T2[1000];
    int T3[1000];
    int T4[1000];
    int T5[1000];
    srand(time(NULL));
    clock_t start_time, end_time;
    float temps;
    
    for (int i = 0; i < 1000; i++) {
        T1[i] = rand() % 1001;
    }
    for (int i = 0; i < 1000; i++) {
        T2[i] = rand() % 1001;
    }
    for (int i = 0; i < 1000; i++) {
        T3[i] = rand() % 1001;
    }
    for (int i = 0; i < 1000; i++) {
        T4[i] = rand() % 1001;
    }
	for (int i = 0; i < 1000; i++) {
		T5[i] = rand() % 1001;
	}

    start_time = clock();
	TriParSelection(T1);
    end_time = clock();
	temps = ((double)end_time -start_time) / (double)CLOCKS_PER_SEC;
	printf("Le temps pour Tri par selection est : %.3f seconde(s) .\n", temps);

    start_time = clock();
	TriParInsertion(T2);
    end_time = clock();
	temps = ((double)end_time -start_time) / (double)CLOCKS_PER_SEC;
	printf("Le temps pour Tri par insertion est : %.3f seconde(s) .\n", temps);

    start_time = clock();
	TriABulles(T3);
    end_time = clock();
	temps = ((double)end_time -start_time) / (double)CLOCKS_PER_SEC;
	printf("Le temps pour Tri a bulles est : %.3f seconde(s) .\n", temps);

    start_time = clock();
	TriRapide(T4, 0, 999);
    end_time = clock();
	temps = ((double)end_time -start_time) / (double)CLOCKS_PER_SEC;
	printf("Le temps pour Tri rapide est : %.3f seconde(s) .\n", temps);
	return 0;
}