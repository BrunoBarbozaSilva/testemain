#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/events.h>
#include<allegro5/keyboard.h>

const int width = 800; //variável para largura do display
const int height = 600; //variável para altura do display


int main(void) {

	bool done = false;
	float altera_y = 0;
	ALLEGRO_DISPLAY* display = NULL; // definindo ponteiro para display
	ALLEGRO_FONT* font = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;

	if (!al_init()) //inicializa a library allegro.h
		return -1; //erro ao inicializar o allegro

	display = al_create_display(width, height); // definindo tamanho do display

	al_init_primitives_addon(); //inicializa a library primitives.h
	al_init_ttf_addon(); //inicializa a library tff.h
	al_init_font_addon(); //inicializa a library tff.h
	al_install_keyboard(); //inicializa a library keyboard.h


	if (!display)
		return -1; //erro ao incializar o display

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));




	while (!done) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {

			done = true;
		}

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {

			if (ev.keyboard.keycode == ALLEGRO_KEY_UP) {
				altera_y = altera_y - 10;
			}
		}

		if (ev.type == ALLEGRO_EVENT_KEY_UP) {


		}
		al_clear_to_color(al_map_rgb(255, 255, 255));
		al_draw_filled_circle(width / 2, height / 2, 30, al_map_rgb(0, 0, 0));
		al_flip_display();
	}

	al_destroy_display(display);
	al_destroy_font(font);
	al_destroy_event_queue(event_queue);



	return 0;
}