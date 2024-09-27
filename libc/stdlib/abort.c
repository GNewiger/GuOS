#include <stdlib.h>

__attribute__((__noreturn__))
void abort(void) {
#if defined(__is_libk)
	int x = 1/0; //throw error to crash so I can know the kernel aborted
#else
	//TODO: Abnormally terminate the process as if by SIGABRT
	int x = 1/0;
#endif
}
