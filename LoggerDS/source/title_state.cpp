#include "title_state.h"

title_state::title_state(OAMTable *oam_i, OAMTable *oam_sub_i)
{
    transition = -1;
    oam = oam_i;
    oam_sub = oam_sub_i;

    linkInfo();

    updateSprites();
}

void title_state::init()
{
  transition = -1;
  swiWaitForVBlank();
  setupVideo();
  setupSprites();
  setupBackgrounds();
}

/*
 * Update state, sprite locations.
 */
void title_state::updateState(touchPosition *touch)
{
  handleInput(touch);
}

void title_state::initializeSprites()
{
}

void title_state::initializeSubSprites()
{
}

void title_state::setupSprites()
{
    initOAM(oam);
    initOAM(oam_sub);

    initializeSprites();
    initializeSubSprites();

    for (int i=0; i< SPRITE_COUNT; i++)
    {
      spriteEntry[i] = &oam->oamBuffer[i];
      spriteEntry_sub[i] = &oam_sub->oamBuffer[i];
    }
}

void title_state::setupVideo()
{
}

void title_state::setupBackgrounds()
{
}

void title_state::handleInput(touchPosition *touch)
{
  int pressed = keysDown();
  int held = keysHeld(); 

  if (pressed & KEY_RIGHT)
  {
  }
  if (pressed & KEY_LEFT)
  {
  }

  if (pressed & KEY_DOWN)
  {
  }

}
