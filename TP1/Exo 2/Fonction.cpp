#include <iostream>
int rechseq(int T[], int n, int x);//recherche sequentielle
int rechdich(int T[], int n, int x);//recherche dichotomique

int rechseq(int T[], int n, int x) {//recherche sequentielle
    int iterations = 0;
    for (int i = 0; i < n; ++i) {
        ++iterations;
        if (T[i] == x) break;
    }
    return iterations;
}

int rechdich(int T[], int n, int x) {//recherche dichotomique
    int left = 0, right = n - 1;
    int iterations = 0;
    while (left <= right) {
        ++iterations;
        int mid = left + (right - left) / 2;
        if (T[mid] == x) return iterations;
        if (T[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return iterations;
}

int main()
{
    int T[10000];
    int n = 10000;
    int seqIterations = 0, dichIterations = 0, x;

    for (int i = 0; i < n; ++i) {
        T[i] = i + 1;
    }

    std::cout << "donner un entier : ";
    std::cin >> x;

    seqIterations = rechseq(T, n, x);
    dichIterations = rechdich(T, n, x);

    std::cout << "\n le nombre d'iteration en utilisant une recherche sequentielle est : " << seqIterations << std::endl;
    std::cout << "\n le nombre d'iteration en utilisant une recherche dichotomique est : " << dichIterations << std::endl;

    return 0;
}
