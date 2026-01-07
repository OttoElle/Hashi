#include "Utils.h"

void drawSplashScreen() {
	system("cls");
	cout << "\xC9" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xBB" << endl;
	cout << "\xBA" << "\t\t\t\t\t\t\t" << "\xBA" << endl;
	cout << "\xBA" << "\t" << " __    __                      __        __" << "\t" << "\xBA" << endl;
	cout << "\xBA" << "\t" << "/  |  /  |                    /  |      /  |" << "\t" << "\xBA" << endl;
	cout << "\xBA" << "\t" << "$$ |  $$ |  ______    _______ $$ |____  $$/ " << "\t" << "\xBA" << endl;
	cout << "\xBA" << "\t" << "$$ |__$$ | /      \\  /       |$$      \\ /  |" << "\t" << "\xBA" << endl;
	cout << "\xBA" << "\t" << "$$    $$ | $$$$$$  |/$$$$$$$/ $$$$$$$  |$$ |" << "\t" << "\xBA" << endl;
	cout << "\xBA" << "\t" << "$$$$$$$$ | /    $$ |$$      \\ $$ |  $$ |$$ |" << "\t" << "\xBA" << endl;
	cout << "\xBA" << "\t" << "$$ |  $$ |/$$$$$$$ | $$$$$$  |$$ |  $$ |$$ |" << "\t" << "\xBA" << endl;
	cout << "\xBA" << "\t" << "$$ |  $$ |$$    $$ |/     $$/ $$ |  $$ |$$ |" << "\t" << "\xBA" << endl;
	cout << "\xBA" << "\t" << "$$/   $$/  $$$$$$$/ $$$$$$$/  $$/   $$/ $$/ " << "\t" << "\xBA" << endl;
	cout << "\xBA" << "\t\t\t\t\t\t\t" << "\xBA" << endl;
	cout << "\xBA" << "Hausarbeitsprojekt von Markus Wunderlich und Otto Elle " << "\xBA" << endl;
	cout << "\xBA" << "\t\t\t\t\t\t\t" << "\xBA" << endl;
	cout << "\xCC" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xB9" << endl;
}
void drawMenu() {
	drawSplashScreen();
	cout << "\xBA" << "\t\t\t\t\t\t\t" << "\xBA" << endl;
	cout << "\xBA" << "[1]" << ": Neues Spiel\t\t\t\t\t" << "\xBA" << endl;
	cout << "\xBA" << "[2]" << ": Spiel Beenden\t\t\t\t\t" << "\xBA" << endl;
	cout << "\xBA" << "[3]" << ": Regeln Anzeigen\t\t\t\t\t" << "\xBA" << endl;
	cout << "\xBA" << "\t\t\t\t\t\t\t" << "\xBA" << endl;
	cout << "\xC8" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xBC" << endl;
}

void drawDifficultySelect() {
	drawSplashScreen();
	cout << "\xBA" << "\t\t\t\t\t\t\t" << "\xBA" << endl;
	cout << "\xBA" << "Spielfeldgroesse auswaehlen!\t\t\t\t" << "\xBA" << endl;
	cout << "\xBA" << "Eingabebeispiel: '10' -> 10x10" << "\t\t\t\t" << "\xBA" << endl;
	cout << "\xBA" << "\t\tMindestens 8, maximal 16.\t\t" << "\xBA" << endl;
	cout << "\xC8" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xBC" << endl;
}

void drawPlayerSelect() {
	drawSplashScreen();
	cout << "\xBA" << "\t\t\t\t\t\t\t" << "\xBA" << endl;
	cout << "\xBA" << "Spielart auswaehlen!\t\t\t\t\t" << "\xBA" << endl;
	cout << "\xBA" << "[1]: Mensch spielt.\t\t\t\t\t" << "\xBA" << endl;
	cout << "\xBA" << "[2]: Computer spielt.\t\t\t\t\t" << "\xBA" << endl;
	cout << "\xC8" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xBC" << endl;
}

void drawRules() {
	char c;
	drawSplashScreen();
	//	cout << "\xBA" << "\t\t\t\t\t\t\t" << "\xBA" << endl;
	cout << "\xBA" << "Spielregeln Hashi:\t\t\t\t\t" << "\xBA" << endl;
	cout << "\xC8" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xCD\xCD\xCD\xCD\xCD" << "\xBC" << endl;
	cout << "        [ZIEL]: Verbinde alle Inseln (Kreise mit Zahlen) zu einem einzigen, zusammenhaengenden Brueckennetz." << endl;
	cout << "    [BRUECKEN]: - Verlaufen nur horizontal oder vertikal." << endl;
	cout << "\t        - Duerfen sich nicht kreuzen und nicht ueber andere Inseln fuehren." << endl;
	cout << "\t        - Zwischen zwei Inseln sind maximal zwei Bruecken erlaubt (eine einfache oder eine doppelte)." << endl;
	cout << "      [ZAHLEN]: - Die Zahl in einer Insel gibt exakt an, wie viele Bruecken dort starten bzw. enden muessen." << endl;
	cout << "[ZUSAMMENHANG]: - Am Ende muessen alle Inseln miteinander verbunden sein; es darf keine isolierten Inselgruppen geben." << endl;
	cout << endl << "Geben sie ein beliebiges Zeichen ein um Fortzufahren..." << endl;
	cin >> c;
}

int MenuInput() {
	int input;
	do {
		cin >> input;
		if (cin.fail()) {
			cout << "Falscheingabe! Nur positive zahlen >0 erlaubt.\n";
			cin.clear();
			input = -1;
			cin.ignore(512, '\n');
		}
	} while (input <= 0);
	return input;
}

int mainMenuFunction() {
	drawMenu();
	bool invalid, invalid2;
	int boardSize = 12;
	do { //// do while schleife für hauptmenü
		drawMenu();
		switch (MenuInput()) {
		case 1: // Fall "Neues Spiel":
			do { //// do while schleife für feldgröße
				drawDifficultySelect();
				////////start switch case
				int difficultyInput = MenuInput();
				switch (difficultyInput) { // NOCHMAL MenuInput switchen für Feldgröße
				case 8:
				case 9:
				case 10:
				case 11:
				case 12:
				case 13:
				case 14:
				case 15:
				case 16:
					boardSize = difficultyInput;
					invalid2 = false;
					break;
				default:
					invalid2 = true;
					break;
				} //////// end switch case
			} while (invalid2); // end do while feldgröße
			invalid = false;
			break; //######################
		case 2:
			// ############## Logger save file 
			return 0;
			// ############## exit/close program function!
			invalid = false;
			cout << "Wird beendet...\n";
			break;
		case 3:
			drawRules();
			return 2;
			break;
		default:
			invalid = true;
		}
	} while (invalid);
	return boardSize;
}

int getPlayerMode() {

	drawPlayerSelect();
	switch (MenuInput()) {
	case 1:
		return 1; // 1 fuer mensch
		break;
	case 2:
		return 2; // 2 fuer computer
		break;
	default:
		return 0;
		break;
	}
}
string getName() {
	string Username;
	cin.ignore();
	getline(cin, Username);
	return Username;
}

void drawNameInput() {
	system("cls");
	cout << "Geben sie den Namen fuer den Spieler ein: ";
}