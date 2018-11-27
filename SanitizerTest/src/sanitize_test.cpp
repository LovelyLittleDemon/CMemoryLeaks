#include "sanitize_test.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int use_after_free(){
    int* array = new int[100];
    delete[] array;
    return array[1]; //boom    
}

int heap_buffer_overflow(){
	int* array = new int[100];
	array[0] = 0;
	int res = array[1 + 100];
	delete[] array;
	return res;
}

int stack_buffer_overflow(){
	int stack_array[100];
	stack_array[1] = 0;
	return stack_array[1001];//boom
}

int global_array[100] = {0};
int global_buffer_overflow(){
	return global_array[10001];
}

int *ptr;
__attribute__((noinline))
int use_after_return_impl(){
	int local[100];
	ptr = &local[0];
	return 0;
}

int use_after_return(){
	use_after_return_impl();
	return ptr[0];
}

volatile int *p = 0;
int use_after_scope(){
	{
		int x = 0;
		p = &x;
	}
	*p = 5;
	return 0;
}

int init_order_bugs(){

}

void *ptr_leak;
int memory_leaks(){
	ptr_leak = malloc(10);
	ptr_leak = 0;//memory is leaked here
	return 0;
}
