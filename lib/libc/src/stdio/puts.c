#include <string.h>
#include <unistd.h>


int puts( const char* str ) {
	return write(1, str, strlen(str));
}
