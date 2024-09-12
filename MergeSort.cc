#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

void show_array(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void MERGE(int* A, int p, int q, int r){

    int i, j; //---> O(1)
    int nl = q - p + 1;  //---> O(1) //Tamaño de la primera mitad 
    int nr = r - q; //Tamaño de la segunda mitad //---> O(1)
    int L[nl + 1]; //---> O(1)
    int R[nr + 1]; //---> O(1)
    // Es +1 porque se necesita un espacio para el centinela, es decir, un valor que sea mayor 
    //a todos los demás, esto me servira para saber cuando ya no hay más elementos en la lista


    //Es lineal pero en un primer momento hay que hacer la distinción de uno es O(n) y el otro es O(n/2)
    
    for(i = 0; i < nl; i++){ // Este for es para llenar la lista L, es decir, la primera mitad
        L[i] = A[p + i]; // Se llena la lista L con los valores de la lista A, pero solo de la primera mitad
        // Es p + i porque p es el inicio de la lista, y se le suma i para que vaya recorriendo la lista
        //viendolo desde la recta numerica:
        //p + 0, p + 1, p + 2, p + 3, p + 4, p + 5, p + 6
        //donde p es el inicio de la lista
    }

    L[nl] = INT_MAX; // Se le asigna el valor de INT_MAX al último elemento de la lista L

    for(j = 0; j < nr; j++){ // Este for es para llenar la lista R, es decir, la segunda mitad
        R[j] = A[q + j + 1]; 
        // Se llena la lista R con los valores de la lista A, pero solo de la segunda mitad
        // Es q + j + 1 porque q es el punto medio de la lista, y se le suma j + 1 para que vaya recorriendo la lista
        //viendolo desde la recta numerica
        //q + j + 1, q + j + 2, q + j + 3, q + j + 4, q + j + 5, q + j + 6
        //donde q es el punto medio de la lista
        //Se le suma 1, porque el punto medio ya se tomo en cuenta en la lista L
        //Por lo que se empieza a contar desde el siguiente elemento
    }

    R[nr] = INT_MAX; 
    // Se le pone INT_MAX al último elemento de la lista R, para saber que ya no hay más elementos

    i = j = 0; // Se inicializan los contadores en 0 nuevamente, porque arriba se usaron para llenar las listas L y R
    //In situ = en el mismo lugar, es decir, se hace el merge en el mismo arreglo, no se crea uno nuevo

    //El for estrictamente es O(n), pero el cuerpo del for es O(1), pero como se repite n veces, entonces es O(n)
    // Como es lineal, el cuerpo es O(1), pero como se repite n veces, entonces es O(n)
    //
    for(int k = p, i = 0, j = 0; k <= r; k++){
        //i par L
        //j para R
        //El cuerpo del if es O(1), y el del else es O(1), por lo tanto el cuerpo del for es O(1)
        if(L[i] <= R[j]){
            A[k] = L[i]; //Si el tope de la lista L es menor o igual al tope de la lista R, se pone el tope de la lista L en la lista A
            i++;
        }else{
            A[k] = R[j]; // Si el tope de la lista R es menor al tope de la lista L, se pone el tope de la lista R en la lista A
            j++;
        }

        //La variable que acabe primero, se le asigna el valor de INT_MAX, para que no se vuelva a comparar
        //Es decir, si ya no hay más elementos en la lista L, se le asigna INT_MAX a la lista L
    }

    //Toda esta funcion es O(n), porque el for es O(n), y el cuerpo del for es O(1)

}

void MERGE_SORT(int* A, int p, int r){
    if(p < r){
        //Hay lenguajes de tipeo fuerte y lenguajes de tipeo débil, en este caso, C++ es de tipeo débil
        //Por lo que no es necesario hacer un cast para el p y r, es decir no hacer un floor, ceil, etc.
        int q = (p + r) / 2; //Calcular ese punto medio
        MERGE_SORT(A, p, q); // Aca se corta la primera mitad, es decir, se divide en dos, y se vuelve a llamar a la función
        MERGE_SORT(A, q + 1, r); // Aca se corta la segunda mitad, es decir, se divide en dos, y se vuelve a llamar a la función
        //Aca se hace el merge

        MERGE(A, p, q, r); //Se hace el merge de las dos mitades
    }

    // Lo no recursivo es O(n), y lo recursivo es O(log n), por lo que la complejidad es O(n log n)

    //Por lo tnto 
    //T(n) = 2T(n/2) + O(n)
    //T(n) = O(n log n)
    //Y por lo tanto la complejidad es O(n log2 n)
}

int main(void){
    int arr[] = {8, 4, 6, 9, 5, 3, 1};
    show_array(arr, 6);

    MERGE_SORT(arr, 0, 6);

    show_array(arr, 6);
}

