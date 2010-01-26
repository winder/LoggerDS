#ifndef MENU_STATE_H
#define MENU_STATE_H

#include <nds.h>

/* state enums */
#include "global.h"

/* super class */
#include "sprite_state.h"

/* Backgrounds */

class menu_state: public sprite_state
{
  public:
    menu_state(OAMTable *oam_i, OAMTable *oam_sub_i);

    virtual void init();
    virtual void updateState(touchPosition *touch);
    virtual int stateId(){ return MENU_STATE; }
    virtual void updateSprites();

    int getVerticies(){ return verticies; }

  private:

    /* setupVideo must be called before the other two. */
    void setupVideo();
    void setupSprites();
    void setupBackgrounds();

    void initializeSubSprites();
    void initializeSprites();

    void handleInput(touchPosition *touch);

    int verticies;
};

#endif
