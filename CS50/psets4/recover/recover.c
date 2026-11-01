#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // check the cli arguments
    if (argc != 2)
    {
        printf("Incorrect usage. Usage: ./recover FILE\n");
        return 1;
    }

    // open and read the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("File does not exist!\n");
        return 1;
    }

    // create a buffer with size 512 bytes
    uint8_t buffer[512];

    int count = 0;
    char filename[8];

    FILE *img = NULL;

    // read the entire remaining data in memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // look for beginning of a JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", count);
            count++;

            img = fopen(filename, "w");

            // write 512 bytes until a new JPEG is found
            fwrite(buffer, 512, 1, img);
        }
        else
        {
            if (img != NULL)
            {
                // write 512 bytes until a new JPEG is found
                fwrite(buffer, 512, 1, img);
            }
        }
    }

    fclose(img);
    fclose(card);
    return 0;
}

