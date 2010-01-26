#ifndef TITLE_STATE_H
#define TITLE_STATE_H

#include <nds.h>
#include <stdio.h>

/* state enums */
#include "global.h"

/* super class */
#include "sprite_state.h"

/* sprite helper functions */
#include "sprites.h"

/* Backgrounds */

/* Sprites */

class title_state: public sprite_state
{
  public:
    title_state(OAMTable *oam_i, OAMTable *oam_sub_i);

    virtual void init();
    virtual void updateState(touchPosition *touch);
    virtual int stateId(){ return TITLE_STATE; }

  private:

    /* setupVideo must be called before the other two. */
    void setupVideo();
    void setupSprites();
    void setupBackgrounds();

    void initializeSubSprites();
    void initializeSprites();

    void handleInput(touchPosition *touch);

};

#endif
