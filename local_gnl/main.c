#include "get_next_line.h"
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {

	int fd;
	char *la;


	fd = open("test.txt", O_RDONLY);

	while (la != NULL)
	{
		la = get_next_line(fd);
		printf("%s", la);
		free(la);
	}

// Fin --> Si \n est suivie d'un char, save dans static buffer
// 			Sinon Buffer = NULL
// Début --> Si buffer != NULL
// Après \n on récup

	return 0;
}
