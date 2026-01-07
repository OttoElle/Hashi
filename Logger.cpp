#include "Utils.h"

void clearLog() {
	ofstream logFile;
	logFile.open("hashi_log.txt");
	logFile.close();
}

void printLog() {
	char c;
	ifstream logFile("hashi_log.txt");
	string line;
	cout << "\n================ LOG PROTOKOLL ================" << endl;

	while (getline(logFile, line)) {
		cout << line << endl;
	}

	cout << "===============================================" << endl;
	logFile.close();
	cout << "Geben sie ein beliebiges Zeichen ein um Fortzufahren..." << endl;
	cin >> c;
}

void logEvent(string message) {
	ofstream logFile;

	logFile.open("hashi_log.txt", ios::app);

	if (logFile.is_open()) {
		logFile << message << endl;
		logFile.close();
	}
	else {
		cout << "Fehler beim output in die Log-Datei" << endl;
	}
}

void logBoard(int board[16][16], int boardSize) {
	int cursorX = 0, cursorY = 0;
	ofstream logFile;

	logFile.open("hashi_log.txt", ios::app);

	if (logFile.is_open()) {
		//Rahmen oben
		logFile << "+";
		for (int i = 0; i < boardSize; i++) logFile << "+++";
		logFile << "+\n";

		for (int y = 0; y < boardSize; y++) {
			logFile << "+"; // Rahmen links
			for (int x = 0; x < boardSize; x++) {

				//if (board[x][y] > 0) {
				//	if (board[x][y] == countBridges(board, boardSize, x, y)) logFile << "\033[92m";	// Insel wird grün wenn sie genug Verbindungen hat
				//	if (board[x][y] < countBridges(board, boardSize, x, y)) logFile << "\033[91m";		// Insel wird rot  wenn sie zu viele Verbindungen hat
				//}

				if (x == cursorX && y == cursorY) {
					switch (board[x][y]) {
					case  0: logFile << "[ ]"; break;
					case -1: logFile << "[-]"; break;
					case -2: logFile << "[=]"; break;
					case -3: logFile << "[|]"; break;
					case -4: logFile << "[H]"; break;
					default: logFile << '[' << board[x][y] << ']';
					}
				}
				else {
					switch (board[x][y]) {
					case  0: logFile << "   "; break;
					case -1: logFile << "---"; break;
					case -2: logFile << "==="; break;
					case -3: logFile << " | "; break;
					case -4: logFile << " H "; break;
					default: logFile << '(' << board[x][y] << ')';
					}
				}


			}
			logFile << "+"; // Rahmen rechts
			logFile << "\n";
		}
		//Rahmen unten
		logFile << "+";
		for (int i = 0; i < boardSize; i++) logFile << "+++";
		logFile << "+\n";
		logFile.close();
	}
	else {
		cout << "Fehler beim output in die Log-Datei" << endl;
	}
}