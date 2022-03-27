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
int cbinsearch(int* arr, int left, int len, int value) {
  int count = 0, i = left, j = len - 1, mid, z;
  while (i <= j) {
    mid = i + (j - i) / 2;
    if (arr[mid] == value && mid != left && mid != len) {
      count++;
      z = mid;
      while (arr[--mid] == value && mid > left) {
        count++;
      }
      while (arr[++z] == value && z < len) {
        count++;
      }
      return count;
    } else if (arr[mid] > value) {
      j = mid - 1;
    } else {
      i = mid + 1;
    }
  }
  return 0;;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    count += cbinsearch(arr, i, len, value - arr[i]);
  }
  return count;
}
