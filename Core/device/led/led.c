#include "led.h"




int init_led(){

	ARGB_Init();  // Initialization

	ARGB_Clear(); // Clear stirp

	while (ARGB_Show() != ARGB_OK); // Update - Option 1

	ARGB_SetBrightness(100);  // Set global brightness to 40%



}

int led_setcolor(int r, int g, int b, int n){
	ARGB_SetRGB(n, r, g, b); // Set LED №3 with 255 Green
	while (!ARGB_Show());  // Update - Option 2
}
