#include "Utils.h"
#include "Visualizer.h"

// drawBridges trägt Werte für die Brücken in die Matrix ein bzw. entfernt diese wieder (create: true / false)
// Brücken haben ein negatives Vorzeichen um sie von den Inseln zu unterscheiden
// ( 0 = keine Brücke, -1 = einfach horizontal, -2 = doppelt horizontal, -3 = einfach vertikal, -4 = doppelt vertikal)
void drawBridge(int board[16][16], int boardSize, int x1, int y1, int x2, int y2, bool create, bool doubleBridge, bool log) {

	// Stellt sicher das immer von groß nach klein gezeichnet wird
	if (x1 > x2) swap(x1, x2);
	if (y1 > y2) swap(y1, y2);

	if (log) {
		if (create) {
			if (doubleBridge) logEvent("Doppelte Bruecke von [" + to_string(x1) + ";" + to_string(y1) + "] nach [" + to_string(x2) + ";" + to_string(y2) + "]");
			else logEvent("Einfache Bruecke von [" + to_string(x1) + ";" + to_string(y1) + "] nach [" + to_string(x2) + ";" + to_string(y2) + "]");
		}
		else logEvent("Bruecke zerstoert zwischen [" + to_string(x1) + ";" + to_string(y1) + "] und [" + to_string(x2) + ";" + to_string(y2) + "]");
	}

	int sign; // Variables Zeichen für die unterschiedlichen Brückenwerte

	// Zeichnet horizontale Brücken
	if (y1 == y2) {
		if (!create) sign = 0;				// 0 falls Brücke zerstört wird
		else if (doubleBridge) sign = -2;	// -2 falls doppelte Brücke 
		else sign = -1;						// -1 falls einfache Brücke

		for (int x = x1 + 1; x < x2; x++) {	// Eintragen von sign in alle Koordinaten ZWISCHEN den Inseln 
			board[x][y1] = sign;
		}
	}

	// Zeichnet vertikale Brücken
	if (x1 == x2) {
		if (!create) sign = 0;				// 0 falls Brücke zerstört wird
		else if (doubleBridge) sign = -4;	// -4 falls doppelte Brücke 
		else sign = -3;						// -3 falls einfache Brücke

		for (int y = y1 + 1; y < y2; y++) {	// Eintragen von sign in alle Koordinaten ZWISCHEN den Inseln 
			board[x1][y] = sign;
		}
	}
}

void drawBridge(int board[16][16], int boardSize, int X, int Y) {
	int currentValue = board[X][Y];
	int replacer;
	int xstart = X, xend = X;
	int ystart = Y, yend = Y;
	int state = 0, state2 = 0, state3 = 0, state4 = 0; // State1 wird 1 wenn das linke X ende der brücke gefunden wurde. State2 bei dem rechten X ende, State 3 beim oberen Y ende, und State4 beim unteren Y ende.
	switch (currentValue) {
	case 0:
	case -1: // Fall horizontal:
		xstart = getLeftDistance(board, boardSize, X, Y, 0);// Nach links prüfen wie weit es geht
		xend = getRightDistance(board, boardSize, X, Y, 0);// Nach rechts prüfen wie weit es geht
		state = getLeftDistance(board, boardSize, X, Y, 1);// Nach links prüfen ob möglich
		state2 = getRightDistance(board, boardSize, X, Y, 1);// Nach rechts prüfen ob möglich
		if (!(state == 2 || state2 == 2)) {
			for (int runX = xstart; runX <= xend; runX++) { // hier aendert es tatsaechlich die werte des arrays.
				board[runX][Y] = currentValue - 1;
			}

			switch (board[X][Y]) {
			case -1:
				logEvent("Einfache Bruecke von [" + to_string(xstart) + ";" + to_string(ystart) + "] nach [" + to_string(xend) + ";" + to_string(yend) + "]");
				break;
			case -2:
				logEvent("Doppelte Bruecke von [" + to_string(xstart) + ";" + to_string(ystart) + "] nach [" + to_string(xend) + ";" + to_string(yend) + "]");
				break;
			}

			// Loggen, dass eine horizontale bruecke gebaut wurde.

			break;
		}
		else { currentValue = -2; }
		//break;
	case -2:
	case -3:
	case -4: // Fall vertikal:
		ystart = getUpDistance(board, boardSize, X, Y, 0); // Nach oben prüfen wie weit es geht
		yend = getDownDistance(board, boardSize, X, Y, 0); // Nach unten prüfen wie weit es geht

		if (currentValue == -4) {
			replacer = 0;
		}
		else {
			replacer = currentValue - 1;
		}
		if (currentValue == -2) {	// Falls noch horizontale brücken vorhanden sind:
			xstart = getLeftDistance(board, boardSize, X, Y, 0);// Nach links prüfen wie weit es geht
			xend = getRightDistance(board, boardSize, X, Y, 0);// Nach rechts prüfen wie weit es geht
			for (int runX = xstart; runX <= xend; runX++) { // Versuch, die horizontalen brücken zu löschen bevor die vertikalen spawnen
				board[runX][Y] = 0;
			}
			if ((getUpDistance(board, boardSize, X, Y, 1) == 2 || getDownDistance(board, boardSize, X, Y, 1) == 2)) {
				board[X][Y] = 0;
			}
			else { board[X][Y] = -2; }
		}
		state3 = getUpDistance(board, boardSize, X, Y, 1);// Nach oben prüfen ob möglich
		state4 = getDownDistance(board, boardSize, X, Y, 1);// Nach unten prüfen ob möglich
		//drawBridge(board, boardSize, 1, xstart, ystart, xend, yend, true, (currentValue == -3)) ;
		if ((getUpDistance(board, boardSize, X, Y, 1) != 2 && getDownDistance(board, boardSize, X, Y, 1) != 2)) {
			for (int runY = ystart; runY <= yend; runY++) { // hier aendert es tatsaechlich die werte des arrays. HIER WERDEN VERTIKALE BRÜCKEN INS ARRAY GESPEICHERT!!!
				board[X][runY] = replacer;
			}
		}

		switch (board[X][Y]) { // loggen dass vertikale brücke gebaut wurde
		case -3:
			logEvent("Einfache Bruecke von [" + to_string(xstart) + ";" + to_string(ystart) + "] nach [" + to_string(xend) + ";" + to_string(yend) + "]");
			break;
		case -4:
			logEvent("Doppelte Bruecke von [" + to_string(xstart) + ";" + to_string(ystart) + "] nach [" + to_string(xend) + ";" + to_string(yend) + "]");
			break;
		}

		break;
	default:
		break;
	}

}
// Löscht alle Brücken im Spielfeld; wird benötigt um Matrix vom Generator zu bereinigen
void eraseAllBridges(int board[16][16], int boardSize) {
	for (int x = 0; x < (boardSize); x++) {
		for (int y = 0; y < (boardSize); y++) {
			if (board[x][y] < 0)
				board[x][y] = 0;
		}
	}
}


void printBoard(int board[16][16], int boardSize, int cursorX, int cursorY) {

	system("cls"); // Konsole leeren

	// Rahmen oben
	cout << "\xC9";
	for (int i = 0; i < boardSize; i++) cout << "\xCD\xCD\xCD";
	cout << "\xBB\n";

	for (int y = 0; y < boardSize; y++) {
		cout << "\xBA"; // Rahmen links
		for (int x = 0; x < boardSize; x++) {

			if (board[x][y] > 0) {
				if (board[x][y] == countBridges(board, boardSize, x, y)) cout << "\033[92m";	// Insel wird grün wenn sie genug Verbindungen hat
				if (board[x][y] < countBridges(board, boardSize, x, y)) cout << "\033[91m";		// Insel wird rot  wenn sie zu viele Verbindungen hat
			}

			if (x == cursorX && y == cursorY) {
				switch (board[x][y]) {
				case  0: cout << "[ ]"; break;
				case -1: cout << "[\xC4]"; break;
				case -2: cout << "[\xCD]"; break;
				case -3: cout << "[\xB3]"; break;
				case -4: cout << "[\xBA]"; break;
				default: cout << '[' << board[x][y] << ']' << "\033[0m";
				}
			}
			else {
				switch (board[x][y]) {
				case  0: cout << "   "; break;
				case -1: cout << "\xC4\xC4\xC4"; break;
				case -2: cout << "\xCD\xCD\xCD"; break;
				case -3: cout << " \xB3 "; break;
				case -4: cout << " \xBA "; break;
				default: cout << '(' << board[x][y] << ')' << "\033[0m";
				}
			}


		}
		cout << "\xBA"; // Rahmen rechts
		if (y <= 1 || y >= 6) {
			cout << "\n";
		}
		else {
			if (y == 2) cout << " Tastenbelegungen: \n";
			if (y == 3) cout << "  Cursor bewegen: [W],[A],[S],[D]\n";
			if (y == 4) cout << "  Bruecke bauen / veraendern / entfernen: [B]\n";
			if (y == 5) cout << "  Aufgeben und zurueck zum Hauptmenu: [#]\n";
		}
	}
	//Rahmen unten
	cout << "\xC8";
	for (int i = 0; i < boardSize; i++) cout << "\xCD\xCD\xCD";
	cout << "\xBC\n";
}