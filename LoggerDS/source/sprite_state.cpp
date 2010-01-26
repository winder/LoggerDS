#include "sprite_state.h"

void sprite_state::linkInfo()
{
  // Link member variables with oamBuffer
  for (int i=0; i< SPRITE_COUNT; i++)
  {
    spriteEntry[i] = &oam->oamBuffer[i];
    spriteEntry_sub[i] = &oam_sub->oamBuffer[i];
  }
}

void sprite_state::updateSprites()
{
  updateOAM(oam);
  updateOAM_SUB(oam_sub);
}
