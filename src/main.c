#include <stdio.h>
#include <malloc.h>
#include <stdint.h>

/*
    Проанализировать весь код и подумать над итоговой программой
*/

#define Byte            unsigned char
#define SIGNATURE_PNG   8



typedef struct format_png {
    int png;
}PNG;

int is_png(Byte* buffer);


int main(int argc, char** argv)
{
    if(argc < 2) {
        printf("error:\n");
    }

    // START FILE ZONE
    FILE* read_png = fopen(argv[1], "rb");
    if(!read_png) 
    {
        printf("error:\n");
        return 1;
    }
    fseek(read_png, 0, SEEK_END);

    int size     = ftell(read_png);
    Byte* buffer = malloc(sizeof(Byte) * (size + 1)); // На всякий size + 1

    fseek(read_png, 0, SEEK_SET);

    while(!feof(read_png)){
        fread(buffer, sizeof(Byte), size, read_png);
    } fclose(read_png);
    // END FILE ZONE

    
    if(!is_png(buffer)){
        printf("error: file is not png");
    }

    PNG pg;


    return 0;
}


int is_png(Byte* buffer)
{
    Byte png_code[SIGNATURE_PNG];

    png_code[0] = 0x89;
    png_code[1] = 0x50;
    png_code[2] = 0x4E;
    png_code[3] = 0x47;
    png_code[4] = 0x0D;
    png_code[5] = 0x0A;
    png_code[6] = 0x1A;
    png_code[7] = 0x0A;

    for (int i = 0; i < SIGNATURE_PNG; i++) {
        if(png_code[i] != buffer[i]) { return 0; }
    }
    return 1;
}