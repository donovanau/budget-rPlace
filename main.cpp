//
// to be added later
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
	char option = ' ';
	int pos1;
	int pos2;
	char input;

	int sideLength;
	cout << "Set the length of the canvas:" << endl;
	cin >> sideLength;
	vector<vector<char>> canvas(sideLength, vector<char>(sideLength, '_'));


	for (int i = 0; i < sideLength; i++)
	{
		for (int j = 0; j < sideLength; j++)
		{
			cout << canvas[i][j];
		}
		cout << endl;
	}


	while (option != 'q') {
		cout << "MENU" << endl;
		cout << "u - Place a character on a position" << endl; //UPDATE
		cout << "c - Place a character on a random position" << endl;
		cout << "r - Randomize the entire canvas" << endl;
		cout << "s - Resize the canvas" << endl; //does not reset
		cout << "p - Print canvas" << endl;
		cout << "q - Quit" << endl;
		cout << endl;

		cout << "Choose an option:" << endl;
		cin >> option;

		switch (option) {
		case 'u': //UPDATE
			cout << "Enter position 1 and 2: (1 - " << sideLength << ")" << endl;
			cin >> pos1 >> pos2;
			if (pos1 > sideLength || pos2 > sideLength) {
				cout << "Out of bounds: Cannot change position." << endl;
				break;
			}
			
			cout << "Enter character to add." << endl;
			cin >> input;
			canvas[static_cast<std::vector<std::vector<char, std::allocator<char>>, std::allocator<std::vector<char, std::allocator<char>>>>::size_type>(pos1) - 1][static_cast<std::vector<char, std::allocator<char>>::size_type>(pos2) - 1] = input;
			//visual studio made me do this i dont know why lol
			break;
		case 'c':
			cout << "Enter character to add." << endl;
			cin >> input;
			
			pos1 = rand() % sideLength;
			pos2 = rand() % sideLength;
			canvas[pos1][pos2] = input;
			break;
		case 'r':
			cout << "Enter a number 0 to 3:\n0 - All symbols\n1 - Numbers only\n2 - Uppercase Letters\n3 - Lowercase Letters:" << endl;
			cin >> input;

			for (int i = 0; i < sideLength; i++)
			{
				for (int j = 0; j < sideLength; j++)
				{
					switch (input) {
					case '0':
						canvas[i][j] = (char)(rand() % 94 + 33);
						break;
					case '1':
						canvas[i][j] = (char)(rand() % 10 + 48);
						break;
					case '2':
						canvas[i][j] = (char)(rand() % 26 + 65);
						break;
					case '3':
						canvas[i][j] = (char)(rand() % 26 + 97);
						break;
					}
					
				}
			}
			break;
		case 's':
			cout << "Enter new canvas size: (expanding the canvas will create empty spaces)" << endl; //will not reset
			cin >> sideLength;

			canvas.resize(sideLength);
			for (int i = 0; i < sideLength; ++i)
				canvas[i].resize(sideLength);

			for (int i = 0; i < sideLength; i++)
			{
				for (int j = 0; j < sideLength; j++)
				{
					if (canvas[i][j] == NULL)
						canvas[i][j] = '_';
				}
			}
			break;
		case 'p':
			for (int i = 0; i < sideLength; i++)
			{
				for (int j = 0; j < sideLength; j++)
				{
					cout << canvas[i][j];
				}
				cout << endl;
			}
			break;
		case 'q':
			break;
		default:
			break;
		}
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
