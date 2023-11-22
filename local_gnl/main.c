#include "get_next_line.h"
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	// char buffer[100];
	// ssize_t bytesRead;

	// printf("Entrez quelque chose : ");
	// bytesRead = read(0, buffer, sizeof(buffer));
	// printf("%s | [%ld]", buffer, bytesRead);
	printf("se : %s\n", get_next_line(0));
	return 0;
}
