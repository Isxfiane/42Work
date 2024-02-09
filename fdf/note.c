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
/*
int	main(void)
{
	t_mlx		mlx;
	t_img_vars	img;
	t_coord		coord;
	int			pixel;
	t_colors	color;


	color.a = 1;
	color.r = 164;
	color.g = 255;
	color.b = 164;
//---------------------Init--------------------------//
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, HEIGHT, WIDTH, "Hello world!");
//---------------------Hook--------------------------//
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
//---------------------IMG--------------------------//
	img.img = mlx_new_image(mlx.mlx, 1920, 1080);
	img.buffer = mlx_get_data_addr(img.img, &img.pixel_bits, &img.line_bytes, &img.endian);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
//---------------------Loop-------------------------//
	mlx_loop(mlx.mlx);
//---------------------Free-------------------------//
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
	return (0);
}
*/
/*
int main (int argc, char **argv)
{
	char **result;
	t_map	*map;
	void	*start;

	(void)argc;
	map = NULL;
	result = parsing(argv[1]);
	if (!result)
		return (1);
	fill_list(result, &map);
	calculate_coord(map);
	start = map;
	while (map->next != NULL)
	{
		printf("|\t%.1f\t| ", map->x);
		printf("|\t%.1f\t| ", map->y);
		printf("|\t%d\t| ", map->z);
		printf("|\t%d\t| ", map->real);
		printf("%s\t|\n", map->color);
		map = map->next;
	}
	printf("|\t%.1f\t| ", map->x);
	printf("|\t%.1f\t| ", map->y);
	printf("|\t%d\t| ", map->z);
	printf("|\t%d\t| ", map->real);
	printf("%s\t|\n", map->color);
	free_char(result, 0);
	ft_lst_clear(start);
}
*/





--



//	coord.x0 = (1 / sqrtf(2)) * coord.x0 + (1 / sqrt(2)) * coord.y0;
//	coord.y0 = -(1 / sqrtf(6)) * coord.x0 + (1 / sqrt(6)) * coord.y0 - (2 / sqrt(6)) * coord.z0;