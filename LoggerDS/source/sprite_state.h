#ifndef SPRITE_STATE_H
#define SPRITE_STATE_H

#include <nds.h>
#include <stdio.h>

#include "sprites.h"
#include "state.h"
/* state interface.
 * will be used to facilitate menu transitions,
 */

class sprite_state: public state
{
  public:
    // All initialization functions needed when changing to this state.
    virtual void init() = 0;

    // Update state, called once per frame.
    virtual void updateState(touchPosition *touch) = 0;

    // Update sprites, called once per frame directly after swiWaitForVBlank.
    virtual void updateSprites();

    // Returns the state's ID 
    virtual int stateId() = 0;

    // This is completely handled by the "transition" variable being set.
    // Returns -1 for no change or the state which should be changed to.
    //virtual int changeState() = 0;

  protected:
    void linkInfo();
  
    /* Sprite Variables */
    SpriteEntry* spriteEntry[SPRITE_COUNT];
    SpriteEntry* spriteEntry_sub[SPRITE_COUNT];

    SpriteInfo spriteInfo[SPRITE_COUNT];
    SpriteInfo spriteInfo_sub[SPRITE_COUNT];

    OAMTable *oam;
    OAMTable *oam_sub;
};

#endif
