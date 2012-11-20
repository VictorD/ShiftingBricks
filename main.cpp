/* 
	ShiftingBricks
 */

#include "game.h"

static AssetSlot MainSlot = AssetSlot::allocate()
    .bootstrap(GameAssets);
	
static Metadata M = Metadata()
    .title("ShiftingBricks")
    .package("com.sifteo.shiftbrick", "0.1")
    .icon(Icon)
    .cubeRange(NUM_CUBES);

void main() {

	static Game game;
	VideoBuffer vid;	
	vid.initMode(BG0);
	vid.attach(0);
	vid.bg0.image(vec(0,0), Background);
	
	while(1){
		System::paint();
		/*
		Run all Game functions
		1. titlescreen / init
		2. game
		3. game over
		4. cleanup method
		*/
	}
}