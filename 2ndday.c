#include <stdio.h>
int main() {
    int arr[100], size, i, pos;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    printf("Enter %d elements:\n", size);
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position to delete (0 to %d): ", size - 1);
    scanf("%d", &pos);
    if(pos < 0 || pos >= size) {
        printf("Invalid position!\n");
        return 1;
    }
    for(i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Array after deletion:\n");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}