#include <stdio.h>
int main() {
    int n, i, j = 0;
    scanf("%d", &n);
    int arr[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(i = 1; i < n; i++) {
        if(arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    for(i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}