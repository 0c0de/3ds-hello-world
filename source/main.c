#include <string.h>
#include <stdio.h>

#include <3ds.h>
#include <citro3d.h>

int main(int argc, char **argv) {

	gfxInitDefault();

	PrintConsole topScreen, bottomScreen;

	consoleInit(GFX_TOP, &topScreen);
	consoleInit(GFX_BOTTOM, &bottomScreen);


	consoleSelect(&topScreen);
	printf("\x1b[20;13H");
	printf("\x1b[32mJose Luis Fernandez Mateo");
	consoleSelect(&bottomScreen);
    printf("\x1b[20;8H");
	printf("\x1b[31mPress B for exit this shit");



	// Main loop
	while (aptMainLoop()) {

		gspWaitForVBlank();
		hidScanInput();

		// Your code goes here

		u32 kDown = hidKeysDown();
		if (kDown & KEY_B)
			break; // break in order to return to hbmenu

		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();
	}

	gfxExit();
	return 0;
}
