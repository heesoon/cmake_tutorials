#include <iostream>
#include <gnu/libc-version.h>

int main(int argc, char** argv)
{
	std::printf("glibc version: %s\n", gnu_get_libc_version());
	return 0;
}
