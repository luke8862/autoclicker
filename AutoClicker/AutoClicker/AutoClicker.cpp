#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include <chrono>
#include <thread>

using namespace std;

int x, y, choice;
int speed = 100;
int click = 1;

bool on,shutoff,clicker = false;
void check(){

	if (GetAsyncKeyState(VK_DELETE)) {
		on = false;
	}
	if (GetAsyncKeyState(VK_INSERT)) {
		on = true;
	}
}



int main() {
	cout << "\n\n	 --------------------AutoClicker--------------------\n	| 1. Set Speed(nanoseconds) Default 100 Nanoseconds |\n	| 2. Right or Left Click(Default Left)              |\n	| 3. Reset Values                                   |\n	| 4. Turn Autoclicker On                            |\n	 ---------------------------------------------------\n\ncmd>";
	cin >> choice;
	switch (choice) {
	case 1:
	{
		system("CLS");
		cout << "Enter Speed in Nanoseconds\n-----NO DECIMALS-----\ncmd>";
		cin >> speed;
		Sleep(1000);
		system("CLS");
		main();
	}
	case 2:
	{
		system("CLS");
		cout << "  1. LEFT CLICK\n  2. RIGHT CLICK\ncmd>";
		cin >> click;
		if (click != 1 && click != 2)
		{
			system("CLS");
			cout << "  INVALID INPUT\n  VALUE SET TO DEFAULT(LEFT CLICK)";
			click = 1;
			Sleep(2000);
			system("CLS");
			main();

		}
		Sleep(1000);
		system("CLS");
		main();
	}
	case 3: {
		speed = 100;
		click = 1;
		system("CLS");
		cout << "  RESET VALUES TO DEFAULT\n";
		Sleep(1000);
		system("CLS");
		main();
	}
	case 4:
	{
		clicker = true;
		system("CLS");
		cout << "  PRESS 'INSERT' TO START AUTOCLICKER || PRESS 'DELETE' TO STOP IT\n\n  PRESS 'END' AT ANY TIME TO GO BACK TO SETTINGS\n\n";
		break;
	}
	default:
	{
		if (cin.fail()) {
			system("CLS");
			cout << "  NUMBERS FROM 1-3 NOT LETTERS DUMBASS\n\n\n\n\n\n";
			return 0;
		}
		system("CLS");
		main();
	}
	}
	while (clicker) {
		if (GetAsyncKeyState(VK_END)) {
			system("CLS");
			on = false;
			cout << "  STOPPING AUTOCLICKER";
			Sleep(1500);
			system("CLS");
			clicker = false;
			main();
		}
		if (on && click == 1) {
			mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
			std::this_thread::sleep_for(std::chrono::nanoseconds(speed));
			mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);

		}
		if (on && click == 2) {
			mouse_event(MOUSEEVENTF_RIGHTDOWN, x, y, 0, 0);
			std::this_thread::sleep_for(std::chrono::nanoseconds(speed));
			mouse_event(MOUSEEVENTF_RIGHTUP, x, y, 0, 0);
			check();
		}
		check();
	}
}