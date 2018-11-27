#include "sanitize_test.h"
#include <stdlib.h>
#include <stdio.h>
int main(){
        int result = use_after_free();
//	int result = use_after_return();
//	int result = heap_buffer_overflow();
//	int result = stack_buffer_overflow();
//	int result = memory_leaks();
	printf("result : %d\n", result);
	return result;
}

