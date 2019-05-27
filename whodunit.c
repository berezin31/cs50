// Evgenij Boguslavec
// CS50 - pset3 - whodunit
// Copies a BMP file
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        fprintf(stderr, "Usage: ./whodunit infile outfile\n");
        return 1;
    }

    // Remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // Open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // Open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // Read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // Read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // Write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // Write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // Iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // Iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // Temporary storage
            RGBTRIPLE triple;
            
            // Read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
            
            if (triple.rgbtRed == 0xff && triple.rgbtGreen == 0x00 && triple.rgbtBlue == 0x00)
            {
                triple.rgbtRed = 0xff;
                triple.rgbtGreen = 0xff;
                triple.rgbtBlue = 0xff;
            }
            // By converting the pure red pixels to white made the image
            // So giving the blue and green pixels a boost
            else if (triple.rgbtRed != 0xff)
            {
                triple.rgbtRed = 0x00;
                triple.rgbtGreen = 0xff;
                triple.rgbtBlue = 0xff;
            }
                
            // Write RGBTRIPLE to outptr
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // Skip over padding
        fseek(inptr, padding, SEEK_CUR);

        // Then add it back 
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // Close inptr
    fclose(inptr);

    // Close outptr
    fclose(outptr);

    // Success
    return 0;
}
