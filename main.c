// gives program stdout access
#define SDL_MAIN_HANDLED

#include "./fcl/core.c"
#include "./src/core.c"



int main(int argc, char* args[]) {
	debug_output_target = all;
	debug_level = 4;
	debug_out(1, "guest_warrior init");

	// core init
	fcl_init();
	audio_init(32000, 2, 1024, AUDIO_F32SYS, &audio_callback);
	window_state_set_filename("guest_warrior");
	window_init("Guest Warrior");
	//dpipe_init("src/state_game_play.c");
	fvc_init(420, 200);
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
		frame_wait_next();
		fcl_update();
		if (keys[SDL_SCANCODE_ESCAPE]) fcl_shutdown();
	}
	fcl_quit();
	return 0;
}

