/* 
	ShiftingBricks
 */

#include "game.h"

AssetSlot MainSlot = AssetSlot::allocate()
    .bootstrap(GameAssets);
	
static Metadata M = Metadata()
    .title("ShiftingBricks")
    .package("com.sifteo.shiftbrick", "0.1")
    .icon(Icon)
    .cubeRange(NUM_CUBES);

/* Structure of main comes from examples/Membrane provided with SDK */
void main() {
	
	static Game game;

    game.title();
    game.init();
    game.run();
	game.cleanup();
    //TODO: game.gameOverScreen();
}