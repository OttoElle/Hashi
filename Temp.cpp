
/*void solveBoard(int board[8][8], int difficulty) {
	int bridgesNeeded = 0;
	int bridgesMade = 0;
	int islandCount = 0;
	int attempts = 0;

	int islandCoords[64][2];
	int shadowBoard[8][8] = { 0 };

	for (int x = 0, i = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			if (board[x][y] > 0) {
				bridgesNeeded += board[x][y];
				islandCoords[i][0] = x;
				islandCoords[i][1] = y;
				i++;
			}
		}
	}
	bridgesNeeded /= 2;

	while ((bridgesMade < bridgesNeeded) && (attempts <= difficulty)) { // läuft bis gewünschte Anzahl an Inseln erzeugt wurde

		attempts++;

		int islandX = islandCoords[islandCount][0];
		int islandY = islandCoords[islandCount][1];

		if (islandCount == difficulty) islandCount = 0;
		else islandCount++;

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


			while (true) {

				// Scout geht ein Feld weiter:
				scoutX += xDir[i];
				scoutY += yDir[i];

				// Stellt sicher das Scout im Spielfeld bleibt
				if (scoutX < 0 || scoutX > 7 || scoutY < 0 || scoutY > 7) break;

				if ((board[scoutX][scoutY] == 1) && (board[islandX][islandY] == 1)) break;

				// Stopt wenn Brücke im Weg ist
				if (xDir != 0) {
					if (board[scoutX][scoutY] == -2 || board[scoutX][scoutY] == -3 || board[scoutX][scoutY] == -4)
						break;
				}
				else if (yDir != 0) {
					if (board[scoutX][scoutY] == -1 || board[scoutX][scoutY] == -2 || board[scoutX][scoutY] == -4)
						break;
				}

				if (board[scoutX][scoutY] > 0) { // andere Insel gefunden?
					if (board[scoutX][scoutY] - shadowBoard[scoutX][scoutY] > 0) { // Mindestabsatnd eingehalten? -> mögliche Verbindung
						possCoords[possCount][0] = scoutX;
						possCoords[possCount][1] = scoutY;
						possCoords[possCount][2] = xDir[i];
						possCoords[possCount][3] = yDir[i];
						possCount++;
					}
					break;
				}
			}
		}

		if (possCount > 0) { // Wurden Verbindungen gefunden?

			if (((possCount * 2) - board[islandX][islandY]) <= 1) {
				shadowBoard[islandX][islandY]++;
				for (int i = 0; i < possCount; i++)
				{
					int selX = possCoords[i][0];
					int selY = possCoords[i][1];
					bool doubleBridge;

					shadowBoard[selX][selY]++;
					switch (board[islandX + possCoords[i][2]][islandY + possCoords[i][3]]) {
					case -1:
					case -3: doubleBridge = true;
						break;
					default: doubleBridge = false;
						break;
					}

					drawBridge(board, islandX, islandY, selX, selY, true, doubleBridge);
					printBoard(board, 0, 0);
				}
			}

			// Reset nach erfolgreicher Verbindung
			attempts = 0;
		}
	}

}
*/