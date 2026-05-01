//Count Subarrays with Sum Zero
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int freq[200001] = {0};
    int offset = 100000;
    int sum = 0;
    long long count = 0;
    freq[offset] = 1;  
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        count += freq[sum + offset];
        freq[sum + offset]++;
    }
    printf("%lld", count);
    return 0;
}