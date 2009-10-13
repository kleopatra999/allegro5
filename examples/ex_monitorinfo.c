#define ALLEGRO_USE_CONSOLE
#include "allegro5/allegro5.h"
#include <stdio.h>

#include "common.c"

int main(void)
{
   ALLEGRO_MONITOR_INFO info;
   int num_adapters;
   int i, j;

   if (!al_init()) {
      abort_example("Could not init Allegro.\n");
      return 1;
   }

   num_adapters = al_get_num_video_adapters();

   printf("%d adapters found...\n", num_adapters);

   for (i = 0; i < num_adapters; i++) {
      al_get_monitor_info(i, &info);
      printf("Adapter %d: ", i);
      printf("(%d, %d) - (%d, %d)\n", info.x1, info.y1, info.x2, info.y2);
      al_set_current_video_adapter(i);
      printf("   Available fullscreen display modes:\n");
      for (j = 0; j < al_get_num_display_modes(); j++) {
         ALLEGRO_DISPLAY_MODE mode;

         al_get_display_mode(j, &mode);

         printf("   Mode %3d: %4d x %4d, %d Hz\n",
            j, mode.width, mode.height, mode.refresh_rate);
      }
   }

   return 0;
}
END_OF_MAIN()

/* vim: set sts=3 sw=3 et: */
