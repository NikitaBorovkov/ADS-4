// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
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
  }
  int k = 0;
  for (int i = 0; i < last - 1; i++) {
    for (int j = i+1; j < last; j++) {
      if (arr[i] + arr[j] == value)
        k++;
    }
  }
  return k;
}
int countPairs3(int *arr, int len, int value) {
  int last = len;
  for (int i = len; i < 0; i--) {
    if (arr[i] > value)
      last--;
  }
  int k = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; j > i + 1; j--) {
      if (arr[i] + arr[j] == value)
        k++;
    }
  }
  return k;
}
