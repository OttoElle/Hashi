#include "Utils.h"

int main() {
	SetConsoleOutputCP(437);
	srand(clock());
	clearLog();
	logEvent("Hashi gestartet");
	int status;
	do {
		resetCursorPos();
		status = gameLoop();	   // Aufruf des gameLoops.
		if (status == 0) return 0; // Beenden wenn man will.
	} while (status == 1);
}
