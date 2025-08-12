
SDL_Texture * spriteshit;

float title_x_pos;
float title_y_pos;
float title_x_vel;
float title_y_vel;

void state_controller_init() {
	fonts[0] = font_load("font00_14x14", 14, fvc_renderer);
	// load the spriteshit
	SDL_Surface * image = SDL_LoadBMP("assets/spriteshit.bmp");
	if (!image) {
		printf("ASSET LOAD ERROR: %s\n", SDL_GetError());
		exit(0);
	}
	printf("spriteshit pixel depth : %d\n", image->format->BitsPerPixel);
	SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 0, 0, 0)); 
	spriteshit = SDL_CreateTextureFromSurface(fvc_renderer, image);
	SDL_FreeSurface(image);
	// set title position
	title_x_pos = 0.0;
	title_y_pos = 0.0;
	title_x_vel = 1.33;
	title_y_vel = 0.89;
}


void state_controller_frame() {
	font_render_text("Press SPACE for Adventure", fonts[0], fvc_renderer, (SDL_Rect) { 20, 20, 300, 200 });
	// moving the title around
	title_x_pos += title_x_vel;
	if ((int) title_x_pos + 210 > 419) title_x_vel = -1.33;
	if ((int) title_x_pos <= 0) title_x_vel = 1.33;
	title_y_pos += title_y_vel;
	if ((int) title_y_pos + 80 > 199) title_y_vel = -0.89;
	if ((int) title_y_pos <= 0) title_y_vel = 0.89;
	SDL_RenderCopy(fvc_renderer, spriteshit,
		&(SDL_Rect) { 210, 120, 210, 80 },
		&(SDL_Rect) { (int) title_x_pos, (int) title_y_pos, 210, 80 });
	
}
