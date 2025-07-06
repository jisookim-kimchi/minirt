#include "Precompiled/loadresource.h"

typedef struct mlx_image
{
	const uint32_t	width;
	const uint32_t	height;
	uint8_t*		pixels;
	mlx_instance_t*	instances;
	size_t			count;
	bool			enabled;
	void*			context;
}	mlx_image_t;

//since MLX42 does not provide high-level APIs for drawing lines like OpenGL or DirectX, so we must put pixels.
void    put_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
    if (x < 0 || y < 0 || x >= (int)img->width || y >= (int)img->height)
        return;
    uint32_t *pixels = (uint32_t *)img->pixels;
    pixels[y * img->width + x] = color;
}

//vertical_line
/*
    y0 : start, y1 : end
*/
void draw_vertical_line(mlx_image_t *img, int x, int y0, int y1, uint32_t color)
{
    int y;
    int t;

    t = 0;
    y = y0;
    if (x < 0 || x >= (int)img->width)
        return ;
    if (y0 > y1)
    { 
        t = y0;
        y0 = y1;
        y1 = t;
    }
    while(y <= y1)
    {
        put_pixel(img, x, y, color);
        y++;
    }
}

void draw_horizontal_line(mlx_image_t *img, int x0, int x1, int y, uint32_t color)
{
    int x;
    int t;

    t = 0;
    x = x0;
    if (x < 0 || x >= (int)img->width)
        return ;
    if (x0 > x1)
    { 
        t = x0;
        x0 = x1;
        x1 = t;
    }
    while(x <= x1)
    {
        put_pixel(img, x, y, color);
        x++;
    }
}

/**
 * draw_gizmo2d - Draws a 2D grid and axes
 * @grid_unit: Pixel spacing between grid lines.
 * draws X/Y axes the center of the image.
 */

void draw_gizmo2d(mlx_image_t *img, int grid_unit)
{
    int w = img->width;
    int h = img->height;
    // uint32_t grid_color = LIGHT_GRAY ;
    // uint32_t x_axis_color = RED;
    // uint32_t y_axis_color = GREEN;

    int x = 0;
    while(x < w)
    {
        draw_vertical_line(img, x, 0, h - 1, grid_color);
        x = x + grid_unit;
    }
    int y = 0;
    while (y < h)
    {
        draw_horizontal_line(img, 0, w - 1, y, grid_color); 
        y = y + grid_unit;
    }
    int origin_x = w / 2;
    int origin_y = h / 2;

    draw_horizontal_line(img, 0, w - 1, origin_y, x_axis_color);
    draw_vertical_line(img, origin_x, 0, h - 1, y_axis_color);
}

void    load_scene2d()
{

}

void    updated2d(float in_deltasecconds)
{

}