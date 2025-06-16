#include "GameController.h"
#include "GameMenu/FontHolder.h"
#include "ImageMenu.h"
#include "GameObject/Images/ImagesObject.h"
int main()
{
	ImagesObject::loadAllImagesObject;
	ImageMenu::loadAllTextures();
	FontHolder::loadFont();

	GameController gameController;
	gameController.run();
}