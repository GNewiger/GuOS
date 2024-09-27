#include <stdlib.h>
#include <stdint.h>

#define STACK_CHK_GUARD 0xa3f80023

uintptr_t __stack_chk_guard = STACK_CHK_GUARD;

__attribute__((noreturn))
void __stack_chk_fail(void)
{
	abort();	
}
