#include "menu_state.h"

menu_state::menu_state(OAMTable *oam_i, OAMTable *oam_sub_i)
{
    transition = -1;
    oam = oam_i;
    oam_sub = oam_sub_i;

    linkInfo();
}

void menu_state::init()
{
  transition = -1;
  setupSprites();
  setupVideo();
  setupBackgrounds();
  updateSprites();
}

void menu_state::updateSprites()
{
}

/*
 * Update state, sprite locations.
 */
void menu_state::updateState(touchPosition *touch)
{
  handleInput(touch);

  consoleClear();
  printf("================================");
  printf("================================");
  printf("== HORRAY MENU =================");
  printf("================================");
  printf("================================");
  printf("========= PRESS LEFT OR RIGHT ==");
  printf("================================");
  printf("================================");
}

void menu_state::initializeSprites()
{
}

void menu_state::initializeSubSprites()
{
}

void menu_state::setupSprites()
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

  updateSprites();
}

void menu_state::setupVideo()
{

  vramSetBankA(VRAM_A_MAIN_BG_0x06000000);
  vramSetBankB(VRAM_B_MAIN_BG_0x06020000);
//  vramSetBankC(VRAM_C_SUB_BG_0x06200000);
  vramSetBankD(VRAM_D_LCD);

  vramSetBankE(VRAM_E_MAIN_SPRITE);
  vramSetBankI(VRAM_I_SUB_SPRITE);

  // Set the video mode on the main screen.
  videoSetMode(MODE_5_2D | // Set the graphics mode to Mode 5
               DISPLAY_BG2_ACTIVE | // Enable BG2 for display
               DISPLAY_BG3_ACTIVE | // Enable BG3 for display
               DISPLAY_SPR_ACTIVE | // Enable sprites for display
               DISPLAY_SPR_1D       // Enable 1D tiled sprites
               );

  // Set the video mode on the sub screen. 
//  videoSetModeSub(MODE_5_2D | // Set the graphics mode to Mode 5
//                  DISPLAY_SPR_ACTIVE |
//                  DISPLAY_SPR_1D |
//                  DISPLAY_BG3_ACTIVE); // Enable BG3 for display

  // Sub screen background
//  dmaCopyHalfWords(3,
//                   starFieldBitmap,
//                   (uint16 *)BG_BMP_RAM(0),
//                   starFieldBitmapLen);

  // Sub screen background
//  dmaCopyHalfWords(3,
//                   starFieldBitmap,
//                   (uint16 *)BG_BMP_RAM_SUB(0),
//                   starFieldBitmapLen);

  consoleDemoInit();
}

void menu_state::setupBackgrounds()
{
#ifdef USING_MENU_STATE_BACKGROUNDS
  /*  Set up affine background 3 on main as a 16-bit color background. */
  REG_BG3CNT = BG_BMP16_256x256 |
               BG_BMP_BASE(0) | // The starting place in memory
               BG_PRIORITY(3); // A low priority

  /*  Set the affine transformation matrix for the main screen background 3
   *  to be the identity matrix.
   */
  REG_BG3PA = 1 << 8;
  REG_BG3PB = 0;
  REG_BG3PC = 0;
  REG_BG3PD = 1 << 8;

  /*  Place main screen background 3 at the origin (upper left of the
   *  screen).
   */
  REG_BG3X = 0;
  REG_BG3Y = 0;

  /*  Set up affine background 2 on main as a 16-bit color background. */
  REG_BG2CNT = BG_BMP16_128x128 |
               BG_BMP_BASE(8) | // The starting place in memory
               BG_PRIORITY(2);  // A higher priority

  /*  Set the affine transformation matrix for the main screen background 3
   *  to be the identity matrix.
   */
  REG_BG2PA = 1 << 8;
  REG_BG2PB = 0;
  REG_BG2PC = 0;
  REG_BG2PD = 1 << 8;

  /*  Place main screen background 2 in an interesting place. */
  REG_BG2X = -(SCREEN_WIDTH / 2 - 32) << 8;
  REG_BG2Y = -32 << 8;

  /*  Set up affine background 3 on the sub screen as a 16-bit color
   *  background.
   */
  REG_BG3CNT_SUB = BG_BMP16_256x256 |
                   BG_BMP_BASE(0) | // The starting place in memory
                   BG_PRIORITY(3); // A low priority

  /*  Set the affine transformation matrix for the sub screen background 3
   *  to be the identity matrix.
   */
  REG_BG3PA_SUB = 1 << 8;
  REG_BG3PB_SUB = 0;
  REG_BG3PC_SUB = 0;
  REG_BG3PD_SUB = 1 << 8;

  /*
   *  Place main screen background 3 at the origin (upper left of the screen)
   */
  REG_BG3X_SUB = 0;
  REG_BG3Y_SUB = 0;


  /*
   * Copy backgrounds to memory.
   */
  int DMA_CHANNEL = 3;
/*
  // Sub screen background
  dmaCopyHalfWords(DMA_CHANNEL,
                   splashBitmap,
                   (uint16 *)BG_BMP_RAM_SUB(0),
                   splashBitmapLen);

  // Main screen background
  dmaCopyHalfWords(DMA_CHANNEL,
                   starFieldBitmap,
                   (uint16 *)BG_BMP_RAM(0),
                   starFieldBitmapLen);
*/
#endif
}

void menu_state::handleInput(touchPosition *touch)
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
  if (pressed & KEY_UP)
  {
  }
}
