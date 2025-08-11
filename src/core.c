

void state_controller_init() {
	fonts[0] = font_load("font00_14x14", 14, fvc_renderer);
}


void state_controller_frame() {
	font_render_text("Press SPACE for Adventure", fonts[0], fvc_renderer, (SDL_Rect) { 20, 20, 300, 200 });
	
}
