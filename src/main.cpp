#include "GameController.h"
#include "GameMenu/FontHolder.h"
#include "GameMenu/ImagesButtons.h"
int main()
{
	ImagesButton::loadAllTextures(); 
	FontHolder::loadFont();

	GameController gameController;
	gameController.run();
}