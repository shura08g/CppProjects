#include <iostream>
#include <fstream>

using namespace std;

int getWhatYouWant();
void displayItems(int choise);

int main()
{
    int whatYouWant;

    whatYouWant = getWhatYouWant();

    while (whatYouWant != 4){
        switch(whatYouWant){
            case 1:
                displayItems(1);
                break;
            case 2:
                displayItems(2);
                break;
            case 3:
                displayItems(3);
                break;
            default:
                cout << "Nothing" << '\n';
        }
        whatYouWant = getWhatYouWant();
    }

    return 0;
}


int getWhatYouWant(){
    int choise;

    cout << "1 - just plain items." << '\n';
    cout << "2 - helpful items." << '\n';
    cout << "3 - harmful items" << '\n';
    cout << "4 - quit program" << '\n';

    cin >> choise;

    return choise;

}

void displayItems(int choise){
    ifstream objectFile("objects.txt");
    string name;
    double power;

    if (choise == 1){
        while (objectFile >> name >> power){
            if (power == 0){
                cout << name << " " << power << '\n';
            }
        }
    }

    if (choise == 2){
        while (objectFile >> name >> power){
            if (power > 0){
                cout << name << " " << power << '\n';
            }
        }
    }

    if (choise == 3){
        while (objectFile >> name >> power){
            if (power < 0){
                cout << name << " " << power << '\n';
            }
        }
    }
}
