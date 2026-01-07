#include "Utils.h"


int gameLoop() {
	char c;
	string playerName;
	int board[16][16] = { 0 };
	bool loopmenu = false;
	int boardSize = mainMenuFunction();
	int tempBoard[16][16] = { 0 };
	int input = -1;
	int playerMoves = 0;
	int computerMoves = 0;
	if (boardSize == 2) return 1;
	if (boardSize == 0) return 0;
	int playerMode = 0;
	while (playerMode == 0) {
		playerMode = getPlayerMode(); // 1 = Mensch, 2 = Computer, 0 = Invalid
	};
	generateBoard(board, boardSize);
	eraseAllBridges(board, boardSize);
	system("cls");
	//	drawRules();
	logEvent("\n\n---- Neues Spiel gestartet ----");
	if (playerMode == 1) {//////////////////
		logEvent("Mensch spielt.");
		logEvent("Spielfeldgroesse: " + to_string(boardSize) + "x" + to_string(boardSize));
		logEvent("Hier ist das Spielfeld:");
		logBoard(board, boardSize);
		bool run = false;
		drawNameInput();
		playerName = getName();
		logEvent("Name des menschlichen Spielers: " + playerName);
		logEvent("Zuege von " + playerName + ":");
		printBoard(board, boardSize, 0, 0);
		do {
			if (scanForInput(board, boardSize) == 0) {
				cout << playerName << " hat aufgegeben!\n";
				logEvent(playerName + " hat aufgegeben!");
				logEvent("Board von " + playerName + ":");
				logBoard(board, boardSize);
				logEvent("---- Ende vom Spiel ----");
				cout << "Geben sie [1] ein um den Log anzzuzeigen, oder ein beliebiges Zeichen ein um Fortzufahren..." << endl;
				cin >> c;
				if (c == '1') {
					printLog();
				}
				return 1;
			}
			printBoard(board, boardSize, getCursorX(), getCursorY());
			run = !((checkWin(board, boardSize) == true));
			if (run == false) {
				printBoard(board, boardSize, 0, 0);
				playerMoves = getPlayerMoves();
				cout << "Sie haben in " << playerMoves << " Zuegen gewonnen!\n";
				logEvent(playerName + " hat " + to_string(playerMoves) + " Zuege gebraucht.");
				logEvent("Board von " + playerName + ":");
				logBoard(board, boardSize);
				logEvent("---- Ende vom Spiel ----");
				cout << "Geben sie [1] ein um den Log anzzuzeigen, oder ein beliebiges Zeichen ein um Fortzufahren..." << endl;
				cin >> c;
				if (c == '1') {
					printLog();
				}
				return 1;
			}
		} while (run);
		return 1;
	}

	if (playerMode == 2) {
		input = -1;
		logEvent("Spieler gegen Computer");
		logEvent("Spielfeldgroesse: " + to_string(boardSize) + "x" + to_string(boardSize));
		cout << "Computerspiel";
		logEvent("Hier ist das Spielfeld:");
		logBoard(board, boardSize);

		for (int xi = 0; xi < boardSize; xi++) { // Board fuer Computerspieler speichern
			for (int yi = 0; yi < boardSize; yi++) {
				tempBoard[xi][yi] = board[xi][yi];
			}
		}

		bool run = false; /////
		drawNameInput();
		playerName = getName();
		logEvent("Name des menschlichen Spielers: " + playerName);
		logEvent("Zuege von " + playerName + ":");
		printBoard(board, boardSize, 0, 0);
		do {
			printBoard(board, boardSize, getCursorX(), getCursorY());
			input = scanForInput(board, boardSize);
			run = ((checkWin(board, boardSize) == false) || input == 0);
			if (run == false && checkWin(board, boardSize) == true) {
				printBoard(board, boardSize, 0, 0);
				playerMoves = getPlayerMoves();
				cout << "Sie haben in " << playerMoves << " Zuegen gewonnen!\n";
				logEvent(playerName + " hat das Raetsel in " + to_string(playerMoves) + " Zuegen geloest.");
			}
			if (input == 0) {
				cout << playerName << " hat aufgegeben!\n";
				logEvent(playerName + " hat aufgegeben!");
				run = false;
			}
		} while (run);
		/////
		cout << "Geben sie ein beliebiges Zeichen ein um den Computerspieler zu starten!" << endl;
		cin >> c;
		logEvent("\n\nNun ist der Computer dran:");
		logEvent("Zuege des Computers:");

		computerMoves = solveBoard(tempBoard, boardSize);
		if (checkWin(tempBoard, boardSize)) {
			cout << "\nDer Computer hat das Raetsel in " << computerMoves << " Zuegen geloest\n";
			logEvent("Computer hat " + to_string(computerMoves) + " Zuege gebraucht.");
			if (input != 0) {
				cout << playerName << " hat das Raetsel in " << playerMoves << " Zuegen geloest!\n";
				logEvent(playerName + " hat " + to_string(playerMoves) + " Zuege gebraucht.");
				if (playerMoves < computerMoves) {
					cout << playerName << " hat mit weniger Zuegen gewonnen!\n";
					logEvent(playerName + " hat mit weniger Zuegen gewonnen!");
				}
				else {
					if (playerMoves > computerMoves) {
						cout << "Der Computer hat mit weniger Zuegen gewonnen!\n";
						logEvent("Der Computer hat mit weniger Zuegen gewonnen!");
					}
					else {
						cout << playerName << " hat gleich viele Zuege gebraucht wie der Computer. UNENTSCHIEDEN!\n";
						logEvent(playerName + " hat gleich viele Zuege gebraucht wie der Computer. UNENTSCHIEDEN!");
					}
				}
			}
			else {
				cout << "Der Computer hat gewonnen, da " << playerName << " aufgegeben hat!\n";
				logEvent("Der Computer hat gewonnen, da " + playerName + " aufgegeben hat!");
			}
			logEvent("Board von " + playerName + ":");
			logBoard(board, boardSize);
			logEvent("Board von Computer:");
			logBoard(tempBoard, boardSize);
		}
		else {
			cout << "Der Computer konnte das Raetsel nicht losen\n";
			logEvent("Computer konnte das Raetsel nicht loesen\n");
			if (input != 0) {
				cout << playerName << " hat gewonnen!\n";
				logEvent(playerName + " hat gewonnen!");
			}
			else {
				cout << "Sowohl " << playerName << " als auch der Computer haben aufgegeben! Beide verloren!\n";
				logEvent("Sowohl " + playerName + " als auch der Computer haben aufgegeben! Beide verloren!");
			}
			logEvent("Board von " + playerName + ":");
			logBoard(board, boardSize);
			logEvent("Board von Computer:");
			logBoard(tempBoard, boardSize);
		}
		logEvent("---- Ende vom Spiel ----");
		cout << "Geben sie [1] ein um den Log anzzuzeigen, oder ein beliebiges Zeichen ein um Fortzufahren..." << endl;
		cin >> c;
		if (c == '1') {
			printLog();
		}
		return 1;
	}
	return 1;
}