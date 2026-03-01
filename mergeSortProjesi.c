/*
Bu program, Merge Sort algoritmasını açıklamak ve örneklerle göstermek için yazılmıştır.

1. Merge Sort Algoritması:
   - Merge Sort, "böl ve fethet" (divide and conquer) yaklaşımını kullanır.
   - Dizi, daha küçük alt dizilere bölünür ve bu alt diziler sıralandıktan sonra birleştirilir.
   - Örneğin, [16, 21, 11, 8, 12, 22] dizisi sıralanırken:
     1. Bölme aşaması:
        [16, 21, 11] ve [8, 12, 22]
        [16] [21, 11] ve [8] [12, 22]
        [16] [21] [11] ve [8] [12] [22]
     2. Birleştirme aşaması:
        [16] [11, 21] ve [8] [12, 22]
        [11, 16, 21] ve [8, 12, 22]
        [8, 11, 12, 16, 21, 22]
   - Bu algoritmanın zaman karmaşıklığı O(n log n) olarak ifade edilir.
*/

#include <stdio.h>

// Bu fonksiyon, diziyi ekrana yazdırır. Her adımda dizinin mevcut durumunu görmek için kullanılır.
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Merge işlemi: İki alt diziyi birleştirir.
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort algoritması: Diziyi sıralar.
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Alt dizileri sıralama
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Alt dizileri birleştirme
        merge(arr, left, mid, right);

        // Her birleştirme adımını yazdır
        printf("Birleştirme aşaması: ");
        printArray(arr, right - left + 1);
    }
}

int main() {
    // Merge Sort için örnek dizi
    int arr[] = {16, 21, 11, 8, 12, 22};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Başlangıç dizisi: ");
    printArray(arr, size);

    // Merge Sort algoritmasını çalıştır
    printf("\nMerge Sort Aşamaları:\n");
    mergeSort(arr, 0, size - 1);

    printf("\nSıralı dizi: ");
    printArray(arr, size);

    // Big-O gösterimi
    printf("\nBig-O Gösterimi: O(n log n)\n");

    return 0;
}
