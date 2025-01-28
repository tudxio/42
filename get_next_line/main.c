#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd;
    char *line;
    int line_count = 0;

    // Ouvrir un fichier de test
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return 1;
    }

    // Lire le fichier ligne par ligne
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Ligne %d: %s", ++line_count, line);
        free(line);  // Important : libérer la mémoire allouée par get_next_line
    }

    // Fermer le fichier
    close(fd);

    // Test avec un descripteur de fichier invalide
    printf("\nTest avec un fd invalide:\n");
    line = get_next_line(-1);
    if (line)
    {
        printf("Erreur: get_next_line a renvoyé une ligne avec un fd invalide\n");
        free(line);
    }
    else
    {
        printf("OK: get_next_line a correctement géré le fd invalide\n");
    }

    // Test de lecture à partir de l'entrée standard
    printf("\nEntrez quelques lignes (Ctrl+D pour terminer):\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("Vous avez entré: %s", line);
        free(line);
    }

    return 0;
}
