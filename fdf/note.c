void	draw_tile(t_img_vars *img, t_colors *col, t_coord *co) // moche, pas beau, connard
{
	int pixel;

	while (co->y != 450)
	{
		pixel = (co->x *img->line_bytes) + (co->y * img->pixel_bits / 8);
		draw_pixel(img->buffer, pixel, *col, img->endian);
		co->x--;
		co->y += 2;
	}
	while (co->x != 350)
	{
		pixel = (co->x *img->line_bytes) + (co->y * img->pixel_bits / 8);
		draw_pixel(img->buffer, pixel, *col, img->endian);
		co->x++;
		co->y += 2;
	}
	while (co->y != 450)
	{
		pixel = (co->x *img->line_bytes) + (co->y * img->pixel_bits / 8);
		draw_pixel(img->buffer, pixel, *col, img->endian);
		co->x++;
		co->y -= 2;
	}
	while (co->x != 350)
	{
		pixel = (co->x *img->line_bytes) + (co->y * img->pixel_bits / 8);
		draw_pixel(img->buffer, pixel, *col, img->endian);
		co->x--;
		co->y -= 2;
	}
}

void	real_draw(t_img_vars *img, t_colors *col, t_coord *co)
{
	int pixel;
	int countpi;
	double angle;

	countpi = 0;
	while (countpi != 200)
	{
		pixel = (co->x * img->line_bytes) + (co->y * img->pixel_bits / 8);
		draw_pixel(img->buffer, pixel, *col, img->endian);
		co->x++;
		co->y++;
		countpi++;
	}
	angle = 120 * M_PI / 180.0;
	printf("%d | %d \n", co->x, co->y);
	co->x = co->x + countpi * cos(angle);
	co->y = co->y + countpi * sin(angle);
	printf("%d | %d | %lf \n", co->x, co->y, cos(120));
	countpi = 0;
	while (countpi != 200)
	{
		pixel = (co->x * img->line_bytes) + (co->y * img->pixel_bits / 8);
		draw_pixel(img->buffer, pixel, *col, img->endian);
		co->x--;
		co->y++;
		countpi++;
	}
}


void	plothight(t_img_vars *img, t_colors *col, t_coord *co)
{
	int 	delta_x;
	int 	delta_y;
	int 	x;
	int 	y;
	int 	d;

	delta_x = co->x1 - co->x0;
	if (delta_x < 0)
		delta_x *= -1;
	delta_y = co->y1 - co->y0;
	x = co->x0;
	y = co->y0;
	d = 2 * delta_x - delta_y;
	while ((y != co->y1))
	{
		if (d < 0)
			d = d + 2 * delta_x;
		else
		{
			d = d + (2 * delta_x) - (2 * delta_y);
			x++;
		}
		y++;
		pix_draw(img, col, x, y);
	}
	printf("h | Debut : x0 : %d  | y0 : %d\n", co->x0, co->y0);
	printf("h | Final : x : %d | y : %d\n", x, y);
	printf("h | Voulu : x : %d | y : %d\n", co->x1, co->y1);
}

void	plotlow(t_img_vars *img, t_colors *col, t_coord *co)
{
	int 	delta_x;
	int 	delta_y;
	int 	x;
	int 	y;
	int 	d;

	delta_x = co->x1 - co->x0;
	delta_y = co->y1 - co->y0;
	if (delta_y < 0)
		delta_y *= -1;
	x = co->x0;
	y = co->y0;
	d = 2 * delta_x - delta_y;
	while ((x != co->x1))
	{
		if (d < 0)
			d = d + 2 * delta_y;
		else
		{
			d = d + (2 * delta_y) - (2 * delta_x);
			y++;
		}
		x++;
		pix_draw(img, col, x, y);
	}
	printf("l | Debut : x0 : %d | y0 : %d\n", co->x0, co->y0);
	printf("l | Final : x : %d | y : %d\n", x, y);
	printf("l | Voulu : x : %d | y : %d\n", co->x1, co->y1);
}
t_coord *reverse_coord(t_coord *co)
{
	t_coord	*result;
	int 	tempx;
	int 	tempy;

	result = co;
	tempx = result->x0;
	tempy = result->y0;
	result->y0 = result->y1;
	result->x0 = result->x1;
	result->x0 = tempx;
	result->y0 = tempy;

	return (result);
}

void	drawto(t_img_vars *img, t_colors *col, t_coord *co)
{
	if (abs(co->y1 - co->y0) < abs(co->x1 - co->x0))
	{
		if (co->x0 > co->x1)
			plotlow(img, col, reverse_coord(co));
		else
			plotlow(img, col, co);
	}
	else
	{
		if (co->y0 > co->y1)
			plothight(img, col, reverse_coord(co));
		else
			plothight(img, col, co);
	}
}
