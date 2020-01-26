#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);


void drawLine(int x0, int y0, int x1, int y1, TGAImage &tgaImage, TGAColor color)
{
	for (float i = 0.; i < 1.; i += .0001)
	{
		int x = x0 * (1. - i) + x1 * i;
		int y = y0 * (1. - i) + y1 * i;
		tgaImage.set(x, y, color);
	}
}

int main(void)
{
	TGAImage image(100, 100, TGAImage::RGB);
	drawLine(13, 20, 80, 40, image, white);
	drawLine(20, 13, 40, 80, image, red);
	drawLine(80, 40, 13, 20, image, red);
	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");
	return 0;
}

