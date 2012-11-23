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

void main() {
	
	static Game game;
	
	while(1){
		game.title();
		game.init();
		while(1){ game.draw(); }
		/*
		Run all Game functions
		1. titlescreen / init
		2. game
		3. game over
		4. cleanup method
		*/
	}
}