#ifndef SANITIZER_TEST_H_
#define SANITIZER_TEST_H_
#ifdef __cplusplus
extern "C"{
#endif
int use_after_free();
int heap_buffer_overflow();
int stack_buffer_overflow();
int global_buffer_overflow();
int use_after_return();
int use_after_scope();
int init_order_bugs();
int memory_leaks();
#ifdef __cplusplus
}
#endif
#endif
