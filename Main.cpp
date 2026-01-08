#include "Utils.h"

int main() {
	SetConsoleOutputCP(437);	// Für richtige Darstellung der ASCII-Zeichen
	srand(clock());				// Seed für Zufallsgenerator
	clearLog();					// Log Datei leeren
	logEvent("Hashi gestartet");
	int status;
	do {
		resetCursorPos();
		status = gameLoop();	   // Aufruf des gameLoops.
		if (status == 0) return 0; // Beenden wenn man will.
	} while (status == 1);
}
