#include "GameController.h"
#include "GameMenu/FontHolder.h"
#include "GameMenu/ImagesButtons.h"
int main()
{
	ImagesButton::loadAllTextures(); // תעינת תמונות מל תפריט
	FontHolder::loadFont();

	GameController gameController;
	gameController.run();
}