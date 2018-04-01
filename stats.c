/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Zhen Yao>
 * @date <04/01/2018>
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_statistics(test, SIZE);
  sort_array(test, SIZE);
  print_array(test, SIZE);

}
void print_array(unsigned char *array, unsigned int size){
  int n = 0;
  for(int i = 0; i < size; i++){
    printf("%u, ", array[i]);
    n++;
    if(n%10 == 0) printf("\n");
  }
}

double find_mean(unsigned char *array, unsigned int size){
  double average = 0;
  for(int i = 0; i < size; i++){
    average += *array;
    array++;
  }
  return average/size;
}

double find_median(unsigned char *array, unsigned int size){
  sort_array(array, size);
  if(size % 2 != 0) return (array[size/2]);
  else return (array[size/2 - 1] + array[size/2])/2.0;
}
int find_maximum(unsigned char *array, unsigned int size){
  int max = 0;
  for(int i = 0; i < size; i++){
    if(*array > max){
      max = *array;
    }
  array++;
  }
  return max;
}
int find_minimum(unsigned char *array, unsigned int size){
  int min = 255;
  for(int i = 0; i < size; i++){
    if(*array < min){
      min = *array;
    }
  array++;
  }
  return min;
}
int print_statistics(unsigned char *array, unsigned int size){
  printf("print array: \n");
  print_array(array, size);
  printf("avarage of array is: %f\n", find_mean(array, size));
  printf("maximum of array is: %d\n", find_maximum(array, size));
  printf("minimum of array is: %d\n", find_minimum(array, size));
  printf("median of array is: %f\n", find_median(array, size));
  
}
void sort_array(unsigned char *array, unsigned int size){
  int comparison(const void *a, const void *b){
    return (*(unsigned char *)b - *(unsigned char *)a);
  }
  qsort((void*)array, size, sizeof(array[0]), comparison);
}

/* Add other Implementation File Code Here */
