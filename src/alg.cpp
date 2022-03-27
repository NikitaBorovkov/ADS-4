// Copyright 2021 NNTU-CS
void sorting(int *arr, int len) {
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int c = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = c;
      }
    }
  }
}
int countPairs1(int *arr, int len, int value) {
  sorting(arr, len);
  int k = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        k += 1;
      }
    }
  }
  return k;
}
int countPairs2(int *arr, int len, int value) {
  int last = len;
  for (int i = len; i < 0; i--) {
    if (arr[i] > value)
      last--;
    else
      break;
  }
  int k = 0;
  for (int i = 0; i < last - 1; i++) {
    for (int j = i+1; j < last; j++) {
      if (arr[i] + arr[j] == value)
        k++;
      else if (arr[i] + arr[j] > value)
        break;
    }
  }
  return k;
}
int countPairs3(int *arr, int len, int value) {
    int last = len;
  for (int i = len; i < 0; i--) {
    if (arr[i] > value)
      last--;
    else
      break;
  }
  int k = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; j > i + 1; j--) {
      if (arr[i] + arr[j] == value) 
        k++;
      else if (arr[i] + arr[j] < value)
        break;
    }
  }
  return k;
}
