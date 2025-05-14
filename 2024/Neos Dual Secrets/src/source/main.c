#include <nds.h>
#include <stdio.h>
#include <stdlib.h>

char levels[2][32] = {"Matrix Mash", "Matrix Mastery"};

// UHCTF{FOLLOW_THE_WHITE_RABBIT}
char * easyFlag[6] = {"RABBIT", "FOLLOW", "TF{",  "THE", "WHITE", "H"};

// TODO: consider adding this hint or not
//const char * hint = "UHCTF{NOT_A_FLAG_BUT_CHEATING_IS_RECOMMENDED}";

void showEasyFlag(PrintConsole * topScreen) {
	consoleSelect(topScreen);
    consoleClear();
	topScreen->cursorX = 0;
	topScreen->cursorY = 0;

	iprintf("Challenge 1 complete! Flag: \n\n");

	iprintf("U%sC%s%s_%s_%s_%s}\n\n\n\n", easyFlag[5], easyFlag[2], easyFlag[4], easyFlag[3], easyFlag[1], easyFlag[0]);

	iprintf("Restart the game to try and beat\nchallenge 2\n");
	while (1) {
		// infinite loop to make sure this flag is seen
	}
}

/*
flag:
UHCTF{NEO_IS_PROUD}

Ascii art:

0   0 0   0 00000 00000 00000 
0   0 0   0 0       0   0      
0   0 00000 0       0   00000 
0   0 0   0 0       0   0      
00000 0   0 00000   0   0

  000 0   0 00000 00000
 0    00  0 0     0   0
0     0 0 0 0000  0   0
 0    0  00 0     0   0
  000 0   0 00000 00000 00000


00000 00000       00000 00000
  0   0           0   0 0   0
  0   00000       00000 00000
  0       0       0     000
00000 00000 00000 0     0  00


00000 0   0 0000  000
0   0 0   0 0  0     0
0   0 0   0 0   0     0
0   0 0   0 0  0     0
00000 00000 0000  000
*/
void showHardFlag(PrintConsole * topScreen) {
	consoleSelect(topScreen);
    consoleClear();
	topScreen->cursorX = 0;
    topScreen->cursorY = 0;

	iprintf("0   0 0   0 00000 00000 00000 \n");
	iprintf("0   0 0   0 0       0   0      \n");
	iprintf("0   0 00000 0       0   00000 \n");
	iprintf("0   0 0   0 0       0   0   \n");
	iprintf("00000 0   0 00000   0   0\n");

	iprintf("\n");

	iprintf("  000 0   0 00000 00000\n");
	iprintf(" 0    00  0 0     0   0\n");
	iprintf("0     0 0 0 0000  0   0\n");
	iprintf(" 0    0  00 0     0   0\n");
	iprintf("  000 0   0 00000 00000 00000\n");

	iprintf("\n");

	iprintf("00000 00000       00000 00000\n");
	iprintf("  0   0           0   0 0   0\n");
	iprintf("  0   00000       00000 00000\n");
	iprintf("  0       0       0     000\n");
	iprintf("00000 00000 00000 0     0  00\n");

	iprintf("\n");

	iprintf("00000 0   0 0000  000\n");
	iprintf("0   0 0   0 0   0    0\n");
	iprintf("0   0 0   0 0   0     0\n");
	iprintf("0   0 0   0 0   0    0\n");
	iprintf("00000 00000 0000  000\n");

	while (1) {
		// infinite loop to make sure this flag is seen
	}
}

typedef struct GameInfo {
	int userScore;		// amount of points the user has acquired (counted negatively for slightly more difficult challenge)
	int targetScore;	// amount of points the user needs to score for the win-condition to trigger
	char currentLetter;		// the current letter that is shown/button that needs to be pressed
	int currentLetterScore;	// how much points does the current letter add to the
	int remainingFrames;	// count the total amount of frames remaining before the game ends
} GameInfo;

GameInfo * initGame(int targetScore, int totalFrames) {
	GameInfo * game = malloc(sizeof(GameInfo));
	game->userScore = 0;
	game->targetScore = targetScore;
	game->currentLetter = 'A';
	game->currentLetterScore = 1000;
	game->remainingFrames = totalFrames;

	return game;
}

// every frame we remove some of the points that the user can win
void decreaseCurrentLetterScore(GameInfo * info) {
	info->currentLetterScore = (int) (info->currentLetterScore * 0.99);
}

// NDS runs at 60 fps, so divide by 60
float calcRemainingSeconds(GameInfo * info) {
	return (float) (info->remainingFrames) / 60;
}

// returns true if the score is "higher" than the target
bool userHasWon(GameInfo * info) {
	return ( (0 - info->userScore) >= info->targetScore);
}

void updateUserScore(GameInfo * info) {
	info->userScore = info->userScore - info->currentLetterScore;
}

int randomNumber0To4(GameInfo * info) {
	return info->remainingFrames % 4;
}

void setNewLetter(GameInfo * info) {
	int randomNumber = randomNumber0To4(info);
	switch (randomNumber) {
		case 0:
			info->currentLetter = 'A';
			break;
		case 1:
			info->currentLetter = 'B';
			break;
		case 2:
			info->currentLetter = 'X';
			break;
		case 3:
			info->currentLetter = 'Y';
			break;
		default:
			// letter stays the same if there is an issue
			break;
	}
	info->currentLetterScore = 1000;
}

void printLetter(PrintConsole * topScreen, char shownLetter) {
	consoleSelect(topScreen);
    consoleClear();

	if (shownLetter == 'A') {
		iprintf("AAAAAAA\n");
		iprintf("A     A\n");
		iprintf("A     A\n");
		iprintf("AAAAAAA\n");
		iprintf("A     A\n");
		iprintf("A     A\n");
		iprintf("A     A\n");
	} else if (shownLetter == 'B') {
		iprintf("BBBBBB\n");
		iprintf("B     B\n");
		iprintf("B     B\n");
		iprintf("BBBBBBB\n");
		iprintf("B     B\n");
		iprintf("B     B\n");
		iprintf("BBBBBB\n");
	} else if (shownLetter == 'Y') {
		iprintf("Y     Y\n");
		iprintf(" Y   Y\n");
		iprintf("  Y Y\n");
		iprintf("   Y\n");
		iprintf("   Y\n");
		iprintf("   Y\n");
		iprintf("   Y\n");
	} else if(shownLetter == 'X') {
		iprintf("X     X\n");
		iprintf(" X   X\n");
		iprintf("  X X\n");
		iprintf("   X\n");
		iprintf("  X X\n");
		iprintf(" X   X \n");
		iprintf("X     X\n");
	}
}

void gameOver(PrintConsole * topScreen) {
	consoleSelect(topScreen);
    consoleClear();
	iprintf("GAME OVER!\n\nPress A to go back to try again...\n");
	while (1) {
		scanKeys();			
		int keys = keysDown();
		if(keys & KEY_A) {
			return;
		}
	}
}

void playGame(PrintConsole * topScreen, int targetScore, int gameDuration, int level) {
	GameInfo * game = initGame(targetScore, gameDuration);

	bool playing = true;
	int keys;
	char pressedKey = '_';

	// main game loop
	while (playing) {
		// PART A: show all game-info
		printLetter(topScreen, game->currentLetter);

		char remainingSecBuffer[20]; // Adjust the size based on your requirements
    	sprintf(remainingSecBuffer, "%f", calcRemainingSeconds(game));

		iprintf("\n\nTime remaining: %s s\n", remainingSecBuffer);
		iprintf("\nScore: %06d / %06d\n\n", (0 - game->userScore), game->targetScore);
		iprintf("Current letter value: %d\n\n", game->currentLetterScore);

		iprintf("Hit the button on screen as fastas you can. The faster you hit\nit, the more points you receive.\n\nReach the target score to\ncomplete the challenge.\n");

		// PART B: handle use inputs
		scanKeys();			
		keys = keysDown();
		pressedKey = '_';

		if(keys & KEY_A) {
			pressedKey = 'A';
		}
		if(keys &  KEY_B) {
			pressedKey = 'B';
		}
		if(keys & KEY_X) {
			pressedKey = 'X';
		}
		if(keys & KEY_Y) {
			pressedKey = 'Y';
		}	// spamming all buttons at once just makes it Y

		if (pressedKey == game->currentLetter) {
			updateUserScore(game);
			setNewLetter(game);
		} else {
			decreaseCurrentLetterScore(game);
		}

		game->remainingFrames--;
		swiWaitForVBlank();	// waits for the frame to end

		if(userHasWon(game)) {
			playing = false;
			if (level == 1) {
				showEasyFlag(topScreen);
			} else if (level == 2) {
				showHardFlag(topScreen);
			}
		}
		
		// out of frames --> game over, reset
		if (game->remainingFrames <= 0) {
			playing = false;
			gameOver(topScreen);
		}
	}
}

void drawTop(int activeSelection, PrintConsole * topScreen, int frame) {
    consoleSelect(topScreen);
    consoleClear();

    if(activeSelection == -1) {
		// "Neo's Dual Saga" - Use Neo from the matrix as backstory
        iprintf("\n\n\t\tNeo's Dual Secrets\n");
    } else {
        iprintf("\n\n\t\t  NDS (Challenge %d)\n", activeSelection + 1);
        iprintf("\t\t <<Go back with B>>\n");
    }
    switch (activeSelection) {
        case 0:
			// score 5000, 5 seconds
            playGame(topScreen, 5000, 300, 1);
			activeSelection = -1;
			break;
        case 1:
			// score 500 000, 3 seconds
            playGame(topScreen, 500000, 180, 2);
			activeSelection = -1;
            break;
        case -1:
            iprintf("\n\n<<Choose challenge with arrows>>\n");
            iprintf("\t<<Confirm option with A>>\n");
        default:
            break;
    }
}

//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------
	PrintConsole topScreen;
	PrintConsole bottomScreen;
	
	videoSetMode(MODE_0_2D);
	videoSetModeSub(MODE_0_2D);

	vramSetBankA(VRAM_A_MAIN_BG);
	vramSetBankC(VRAM_C_SUB_BG);

	consoleInit(&topScreen, 3,BgType_Text4bpp, BgSize_T_256x256, 31, 0, true, true);
	consoleInit(&bottomScreen, 3,BgType_Text4bpp, BgSize_T_256x256, 31, 0, false, true);

	consoleSelect(&bottomScreen);

    int keys;

    int frame = 0;

    int selectedLevel = 0;
	bool selected = false;
	int levelCount = 2;
    int activeSelection = -1;

	while(1) {		
		videoSetModeSub(MODE_0_2D);
		consoleDemoInit();
		
		while(!selected) {
            frame++;

			scanKeys();
			
			keys = keysDown();
			
			if(keys & KEY_UP) selectedLevel--;
			if(keys & KEY_DOWN) selectedLevel++;
			if(keys & KEY_A) selected = true;
            if(keys & KEY_B) activeSelection = -1;
			
			if(selectedLevel < 0) selectedLevel = levelCount - 1;
			if(selectedLevel >= levelCount) selectedLevel = 0;

            if (selected) {
                activeSelection = selectedLevel;
            }
			
			swiWaitForVBlank();
			consoleClear();
			for(int i = 0; i < levelCount; i++) {
				iprintf("%c Challenge %d: %s\n", i == selectedLevel ? '*' : ' ', i + 1, levels[i]); 		
			}

            drawTop(activeSelection, &topScreen, frame);

            consoleSelect(&bottomScreen);
		}
		
		selected = false;
	}
}
