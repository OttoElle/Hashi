#include "Utils.h"
#include "Solver.h"


int solveBoard(int board[16][16], int boardSize) {

	int moves= 0;	// Anzahl der Züge
	int islandCount = 0;
	int totalIslands = 0;
	int attempts = 0;
	bool guessingMode = false;

	int islandCoords[64][2];		// Koordinaten aller Inslen auf dem Spielfeld
	int shadowBoard[16][16] = { 0 };	// speicher an den Koordinaten der Inseln die Anzahl der Brücken die bereits verbunden wurden

	for (int x = 0; x < boardSize; x++) { // Berechnet Die Koordinaten der Inseln
		for (int y = 0; y < boardSize; y++) {
			if (board[x][y] > 0) {
				islandCoords[totalIslands][0] = x;
				islandCoords[totalIslands][1] = y;
				totalIslands++;
			}
		}
	}

	while (true) { // läuft solange bis keine neuen Brücken gefunden wurden

		attempts++;

		// Solver iteriert über alle Inslen:
		int islandX = islandCoords[islandCount][0];
		int islandY = islandCoords[islandCount][1];
		// Fängt wieder bei der ersten Insel an wenn er einmal durch ist:
		if (islandCount >= (totalIslands - 1)) islandCount = 0;
		else islandCount++;

		if (attempts >= totalIslands) {

			if (!guessingMode) {
				guessingMode = true;
				attempts = 0;
			}
			else {
				break;
			}
		}

		if ((board[islandX][islandY] - shadowBoard[islandX][islandY]) == 0) continue;

		// Richtungen für den Scout:
		int xDir[4] = { 1, -1, 0, 0 };
		int yDir[4] = { 0, 0, 1, -1 };

		// Zwischenspeicher für alle Möglichen Verbindungen von der gewählten Insel
		int possCoords[64][4];
		int possCount = 0;

		// Scout läuft in alle 4 Richtungen um mögliche Verbindungen zu ermitteln
		for (int i = 0; i < 4; i++)
		{
			// Start an der gewählten Insel:
			int scoutX = islandX;
			int scoutY = islandY;

			// Abstand zur gewählten Insel:
			int dist = 0;

			while (true) {

				// Scout geht ein Feld weiter:
				scoutX += xDir[i];
				scoutY += yDir[i];
				dist++;

				// Stellt sicher das Scout im Spielfeld bleibt
				if (scoutX < 0 || scoutX > (boardSize - 1) || scoutY < 0 || scoutY > (boardSize - 1)) break;

				//if ((board[scoutX][scoutY] == 1) && (board[islandX][islandY] == 1)) break; -vermutlich überflüssig

				// Stopt wenn Brücke im Weg ist
				if (xDir[i] != 0) {
					if (board[scoutX][scoutY] == -2 || board[scoutX][scoutY] == -3 || board[scoutX][scoutY] == -4)
						break;
				}
				else if (yDir[i] != 0) {
					if (board[scoutX][scoutY] == -1 || board[scoutX][scoutY] == -2 || board[scoutX][scoutY] == -4)
						break;
				}

				if (board[scoutX][scoutY] > 0) { // andere Insel gefunden?
					if (((board[scoutX][scoutY] - shadowBoard[scoutX][scoutY]) > 0) && (dist >= 2)) { // noch freie Verbindungen und Mindestabsatnd eingehalten? -> mögliche Verbindung
						possCoords[possCount][0] = scoutX;
						possCoords[possCount][1] = scoutY;
						possCoords[possCount][2] = xDir[i]; // speichert Richtung in der die Insel gefunden wurde
						possCoords[possCount][3] = yDir[i];
						possCount++;
					}
					break;
				}
			}
		}

		if (possCount > 0) { // Wurden Verbindungen gefunden?

			int islandCap = board[islandX][islandY] - shadowBoard[islandX][islandY];	// noch offene Brücken-Kapazität der aktuellen Insel
			int neighborCaps[4] = { 0 };														// Brücken-Kapazität der einzelnen Nachbarinseln
			int totalNeighborCap = 0;													// gesamte Brücken-Kapazität aller Nachbarinseln

			for (int i = 0; i < possCount; i++) // Kapazitäten berechen
			{
				int neighborX = possCoords[i][0];
				int neighborY = possCoords[i][1];
			

				int checkX = islandX + possCoords[i][2];
				int checkY = islandY + possCoords[i][3];

				int rawBridgeVal = board[checkX][checkY];
				int bridgeVal = 2;

				if (rawBridgeVal == -1 || rawBridgeVal == -3) {
					bridgeVal = 1;
				}
				else if (rawBridgeVal == -2 || rawBridgeVal == -4) {
					bridgeVal = 0;
				}

				int neighborNeed = board[neighborX][neighborY] - shadowBoard[neighborX][neighborY];

				if (neighborNeed < bridgeVal) {
					bridgeVal = neighborNeed;
				}

				neighborCaps[i] = bridgeVal;
				totalNeighborCap += bridgeVal;
				
			}

			int capDiff = totalNeighborCap - islandCap; // Überschiüssige Kapazität der Nachbarn

			for (int i = 0; i < possCount; i++)
			{
				bool randomError = false; //(rand() % 1000) < 5; // zufällige platzierung mit 5% Wahrscheinlichkeit

				bool strictCondition = (neighborCaps[i] > capDiff);
				bool looseCondition = (guessingMode && (neighborCaps[i] >= capDiff));

				if (strictCondition || looseCondition || randomError) {	// Wenn die Kapazität einer nachabrinsel die Überschüssige übertrifft, 
													// dann ist eine Brücke zu dieser Insel eindeutig notwendig um den Bedarf der Insel zu erfüllen

					int selX = possCoords[i][0];
					int selY = possCoords[i][1];
					bool doubleBridge = false;

					if ((board[islandX + possCoords[i][2]][islandY + possCoords[i][3]]) < 0) doubleBridge = true; // doppelte Brücke falls einfache bereits vorhanden

					shadowBoard[islandX][islandY]++; // Werte auf dem shadowBoard anpassen
					shadowBoard[selX][selY]++;
					moves++;
					drawBridge(board, boardSize, islandX, islandY, selX, selY, true, doubleBridge, true);
					printBoard(board, boardSize, selX, selY);
					//Sleep(200);

					if (randomError) {
						logEvent("Computer macht einen Fehler");
						if (doubleBridge) drawBridge(board, boardSize, islandX, islandY, selX, selY, true, false, true);
						else drawBridge(board, boardSize, islandX, islandY, selX, selY, false, false, true);
						shadowBoard[islandX][islandY]--; // Werte auf dem shadowBoard anpassen
						shadowBoard[selX][selY]--;
						moves++;
					}

					// Reset nach erfolgreicher Verbindung
					attempts = 0;
					guessingMode = false;
				}
				if (looseCondition) break;
			}
		}
		//if ((rand() % 10000) == 0) break; // zufällig aufgeben
	}
	return moves;
}
