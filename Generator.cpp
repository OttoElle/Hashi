#include "Utils.h"
#include "Generator.h"

// Generator erzeugt einen lösbaren Graphen aus Inseln
void generateBoard(int board[16][16], int boardSize) {

	int setIslands[64][2];

	// Zufällige Auswahl einer Startkoordinate für den Graphen
	setIslands[0][0] = rand() % boardSize;
	setIslands[0][1] = rand() % boardSize;

	int islandCount = 1;
	int attempts = 0;

	while (attempts <= islandCount) { // läuft bis keine neuen Inseln mehr platziert werden können
																		
		attempts++;

		// Wählt eine gesetzte Insel zufällig aus:
		int selIsland = rand() % islandCount;
		int islandX = setIslands[selIsland][0];
		int islandY = setIslands[selIsland][1];

		// Richtungen für den Scout:
		int xDir[4] = { 1, -1, 0, 0 };
		int yDir[4] = { 0, 0, 1, -1 };

		// Zwischenspeicher für alle Möglichen Verbindungen von der gewählten Insel
		int possCoords[64][2];
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

				// Stopt wenn Brücke im Weg ist
				if (board[scoutX][scoutY] < 0) break;

				bool noDirectNeighbor = true;

				for (int j = 0; j < 4; j++) // Überprüft ob die Insel eine andere "berührt"
				{
					if (board[scoutX + xDir[j]][scoutY + yDir[j]] > 0) noDirectNeighbor = false;
				}

				if (board[scoutX][scoutY] == 0) { // leeres Feld gefunden?
					if (dist >= 2 && noDirectNeighbor) { // Mindestabsatnd eingehalten? -> mögliche Verbindung
						possCoords[possCount][0] = scoutX;
						possCoords[possCount][1] = scoutY;
						possCount++;
					}
				}

				else if (board[scoutX][scoutY] > 0) { // andere Insel gefunden?
					if (dist >= 2) { // Mindestabsatnd eingehalten? -> mögliche Verbindung
						possCoords[possCount][0] = scoutX;
						possCoords[possCount][1] = scoutY;
						possCount++;
					}
					break; // Keine weiteren Verbindung in der Richtung möglich
				}
			}
		}

		if (possCount > 0) { // Wurden Verbindungen gefunden?

			// Wählt zufällige Verbindung aus
			int selCoords = rand() % possCount;
			int selX = possCoords[selCoords][0];
			int selY = possCoords[selCoords][1];

			if (board[selX][selY] == 0) { // Muss eine neue Insel erstellt werden?
				setIslands[islandCount][0] = selX;
				setIslands[islandCount][1] = selY;
				islandCount++;
			}

			// Zufällig zwischen einfacher und doppelter Verbindung wählen
			bool doubleBridge = (rand() % 2) == 0;

			// Werte der Inseln anpassen ( (0 + 1 = 1) für einfache Brücke, (1 + 1 = 2) für doppelte Verbindung)
			board[selX][selY] += (doubleBridge + 1);
			board[islandX][islandY] += (doubleBridge + 1);

			// Brücken einzeichnen für nächsten Durchlauf
			drawBridge(board, boardSize, islandX, islandY, selX, selY, true, doubleBridge, false);

			// Reset nach erfolgreicher Verbindung
			attempts = 0;
		}
	}
}