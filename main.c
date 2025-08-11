// gives program stdout access
#define SDL_MAIN_HANDLED

#include "./fcl/core.c"



void main(int argc, char* args[]) {
	debug_output_target = all;
	debug_level = 4;
	debug_out(1, "King Duck of Cluck Mountain");

	// core init
	fcl_init();
	audio_init(32000, 2, 1024, AUDIO_F32SYS, &audio_callback);
	window_state_set_filename("guest_warrior");
	window_init("Guest Warrior");
	//dpipe_init("src/state_game_play.c");
	fvc_init(SCREEN_W, SCREEN_H);
	font_init();
	grafx_init();
	map_grafx_init();
	state_controller_init();

	// core main
	// XXX specific for dev pipeline
//	SDL_MinimizeWindow(window);
//	SDL_RestoreWindow(window);
//	SDL_RaiseWindow(window);
//	window_focus();
	frame_set_fps(60);
	while (fcl_running) {
		SDL_SetRenderTarget(fvc_renderer, fvc_texture);
		state_controller_frame();
		frame_counter++;
		frame_wait_next();
		fcl_update();
		if (keys[SDL_SCANCODE_ESCAPE]) fcl_shutdown();
	}
	fcl_quit();
	return;
}

