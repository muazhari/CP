// #include <stdio.h>

int main() {

  int arr[] = {1, 3, 8, 9, 12, 48, 93, 99, 101};

  int toFind = 48;

  int min = 0;
  int max = sizeof(arr) / sizeof(arr[0]) - 1;
  int mid = max / 2;

  while (1) {
    printf("%d %d\n", mid, arr[mid]);
    if (toFind == arr[mid]) {
      printf("Found");
      break;
    } else if (mid == min) {
      printf("Not Found");
      break;
    }

    if (toFind < arr[mid]) {
      max = mid /= 2;
    } else if (toFind > arr[mid]) {
      min = mid += (mid) / 2;
      printf("%d\n", (max));
    }
  }

  return 0;
}