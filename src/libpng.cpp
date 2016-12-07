/*
 * libpng.cpp
 *
 *  Created on: 6 déc. 2016
 *      Author: alexandre
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <png.h>

#include "Image.h"
#include "Pixel.h"

/* Write "bitmap" to a PNG file specified by "path"; returns 0 on success, non-zero on error. */

static int save_png_to_file (Image * bitmap, const char *path)
{
	FILE * fp;
	png_structp png_ptr = NULL;
	png_infop info_ptr = NULL;
	size_t x, y;
	png_byte ** row_pointers = NULL;

	/* "status" contains the return value of this function. At first it is set to a value which means 'failure'. When the routine has finished its work, it is set to a value which means 'success'. */
	int status = -1;

	int pixel_size = 3;
	int depth = 8;

	fp = fopen (path, "wb");
	if (! fp) {
		goto fopen_failed;
	}

	png_ptr = png_create_write_struct (PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL) {
		goto png_create_write_struct_failed;
	}

	info_ptr = png_create_info_struct (png_ptr);
	if (info_ptr == NULL) {
		goto png_create_info_struct_failed;
	}

	/* Set up error handling */

	if (setjmp (png_jmpbuf (png_ptr))) {
		goto png_failure;
	}

	/* Set image attributes. */

	png_set_IHDR (png_ptr, info_ptr, bitmap->getWidth(), bitmap->getHeight(), depth, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

	/* Initialize rows of PNG. */

	row_pointers = (png_byte **) png_malloc (png_ptr, bitmap->getHeight() * sizeof (png_byte *));
	for (y = 0; y < bitmap->getHeight(); y++) {
		png_byte *row = (uint8_t *) png_malloc (png_ptr, sizeof (uint8_t) * bitmap->getWidth() * pixel_size);
		row_pointers[y] = row;
		for (x = 0; x < bitmap->getHeight(); x++) {
			Pixel * pixel = bitmap->getOnePixel(x,y);
			*row++ = pixel->getR();
			*row++ = pixel->getG();
			*row++ = pixel->getB();
		}
	}

	/* write the image data to "fp". */

	png_init_io (png_ptr, fp);
	png_set_rows (png_ptr, info_ptr, row_pointers);
	png_write_png (png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);

	/* The routine has successfully written the file, so we set "status" to a value wich indicates success. */

	status = 0;

	for (y = 0; y < bitmap->getHeight(); y++) {
		png_free (png_ptr, row_pointers[y]);
	}
	png_free (png_ptr, row_pointers);

	png_failure:
	png_create_info_struct_failed :
		png_destroy_write_struct (&png_ptr, &info_ptr);
	png_create_write_struct_failed:
		fclose (fp);
	fopen_failed:
	return status;
}

/* Given "value" and "max", the maximum value which we expect "value" to take, this returns an integer between 0 and 255 proportional to "value" divided by "max". */

static int pix (int value, int max)
{
	if (value < 0) {
		return 0;
	}
	return (int) (256.0 *((double) (value)/(double) max));
}

/*int main ()
{
	Image fruit;
	int x,y;

	/* create an image */

	/*fruit.width = 100;
	fruit.height = 100;

	fruit.pixels = (Pixel *) calloc (fruit.width * fruit.height, sizeof (Pixel));

	if (! fruit.pixels) {
		return -1;
	}

	for (y = 0; y < fruit.height; y++) {
		for (x = 0; x < fruit.width; x++) {
			Pixel * pixel = fruit->getOnePixel(x,y);
			pixel ->red = pix (x, fruit.width);
			pixel->green = pix (y, fruit.height);
		}
	}

	/* Write the image to a file 'fruit.png'. */

	/*save_png_to_file (& fruit, "fruit.png");

	free (fruit.pixels);

	return 0;
}*/



