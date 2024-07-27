#include <iostream>
#include <iomanip>
#include <cctype>
#include <vector>
#include <string>

using namespace std;
class Diabetes {
private:
    std::string name;
    float age;
    int wt;
    float ht;
    char sex;
    vector<char> symptoms;

public:
    void welcomeScreen();
    void getValue();
    void getLevel1Symptoms();
    void getLevel2Symptoms();
    void getLevel3Symptoms();
    int analyzeSymptoms(int level);
    char displayMessage(int level, int result);
};

void Diabetes::welcomeScreen() {
    std::cout << "********* W E L C O M E *********\n";
    std::cout << " MEDICAL DIAGNOSIS SOFTWARE\n";
    std::cout << "DONE BY: NV Manoj\n";
    std::cout << "**** PRESS ANY KEY TO CONTINUE ****\n";
    std::cin.get();
}

void Diabetes::getValue() {
    std::cout << "  P E R S O N A L   I N F O R M A T I O N  \n";
    std::cout << "N A M E        : ";
    std::getline(std::cin, name);
    std::cout << "A G E          : ";
    std::cin >> age;
    std::cout << "W E I G H T    : ";
    std::cin >> wt;
    std::cout << "H E I G H T    : ";
    std::cin >> ht;
    std::cout << "S E X (M/F)    : ";
    std::cin >> sex;
    std::cin.ignore();
}

void Diabetes::getLevel1Symptoms() {
    symptoms.resize(10);
    std::cout << "*** MEDICAL DIAGNOSIS FORM ***\n";
    std::cout << "APPETITE (H/HIGH, L/LOW, N/NORMAL): ";
    std::cin >> symptoms[0];
    std::cout << "FREQUENCY OF THIRST (H/HIGH, L/LOW, N/NORMAL): ";
    std::cin >> symptoms[1];
    std::cout << "FREQUENCY OF URINATION (H/HIGH, L/LOW, N/NORMAL): ";
    std::cin >> symptoms[2];
    std::cout << "VISION (I/IMPAIRMENT, N/NORMAL): ";
    std::cin >> symptoms[3];
    std::cout << "URINE SUGAR (P/PASSIVE, A/ACTIVE): ";
    std::cin >> symptoms[4];
    std::cout << "KETONUREA (P/PASSIVE, A/ACTIVE): ";
    std::cin >> symptoms[5];
    std::cout << "FASTING BLOOD SUGAR (H/HIGH, L/LOW, N/NORMAL): ";
    std::cin >> symptoms[6];
    std::cout << "R B S (H/HIGH, L/LOW, N/NORMAL): ";
    std::cin >> symptoms[7];
    std::cout << "FAMILY HISTORY OF DIABETES (P/PASSIVE, A/ACTIVE): ";
    std::cin >> symptoms[8];
    std::cout << "OGTT (D/Diabetic, N/Normal): ";
    std::cin >> symptoms[9];
}

void Diabetes::getLevel2Symptoms() {
    symptoms.resize(18);
    std::cout << "PANCREATITIS (P/A): ";
    std::cin >> symptoms[10];
    std::cout << "CARCINOMA (P/A): ";
    std::cin >> symptoms[11];
    std::cout << "CIRHHOSIS (P/A): ";
    std::cin >> symptoms[12];
    std::cout << "HCTS (H/L/N): ";
    std::cin >> symptoms[13];
    std::cout << "HEPATITIS (P/A): ";
    std::cin >> symptoms[14];
    std::cout << "HORMONAL DISORDER (P/A): ";
    std::cin >> symptoms[15];
    std::cout << "PANCREATECTOMY (P/A): ";
    std::cin >> symptoms[16];
}

void Diabetes::getLevel3Symptoms() {
    symptoms.resize(23);
    std::cout << "AGE (Y/Young, M/Middle aged, E/Elderly): ";
    std::cin >> symptoms[17];
    std::cout << "BODY WEIGHT (N/Normal, A/Above normal, B/Below normal, O/Obese): ";
    std::cin >> symptoms[18];
    std::cout << "DURATION (W/Weeks, M/Months, Y/Years): ";
    std::cin >> symptoms[19];
    std::cout << "KETONUREA (P/A): ";
    std::cin >> symptoms[20];
    std::cout << "AUTO ANTIBODIES (P/A): ";
    std::cin >> symptoms[21];
}

int Diabetes::analyzeSymptoms(int level) {
    int count = 0;

    switch (level) {
        case 1:
            if (symptoms[9] == 'D') return -1;
            if (symptoms[5] == 'P' && symptoms[6] == 'P' && symptoms[7] == 'H') return -1;
            for (int i = 0; i < 10; ++i) {
                if (symptoms[i] == 'H' || symptoms[i] == 'P' || symptoms[i] == 'D' || symptoms[i] == 'I') count++;
            }
            return count > 5 ? -1 : 0;

        case 2:
            for (int i = 0; i < 7; ++i) {
                if (symptoms[10 + i] == 'P') return -1;
            }
            return 0;

        case 3:
            if ((symptoms[17] == 'Y' && symptoms[18] == 'N' && symptoms[19] == 'W' && symptoms[20] == 'P' && symptoms[21] == 'P') ||
                (symptoms[17] == 'Y' && symptoms[18] == 'B' && symptoms[19] == 'W' && symptoms[20] == 'P' && symptoms[21] == 'P') ||
                (symptoms[17] == 'Y' && symptoms[18] == 'M' && symptoms[19] == 'P' && symptoms[20] == 'P' && symptoms[21] == 'P') ||
                (symptoms[17] == 'Y' && symptoms[18] == 'N' && symptoms[19] == 'Y' && symptoms[20] == 'P' && symptoms[21] == 'P')) {
                return 0;
            }
            return -1;

        default:
            return 0;
    }
}

char Diabetes::displayMessage(int level, int result) {
    char choice;
    std::cout << "\n";
    switch (level) {
        case 1:
            if (result == 0) {
                std::cout << "THE PERSON IS NOT DIABETIC\n";
                std::cout << "PRESS ANY KEY TO QUIT.\n";
                std::cin.get();
                exit(0);
            } else if (result == -1) {
                std::cout << "THE PERSON IS DIABETIC\n";
                std::cout << "PROCEED (Y/N)? ";
                std::cin >> choice;
            }
            break;
        case 2:
            if (result == 0) {
                std::cout << "IT IS PRIMARY DIABETES.\n";
                std::cout << "Proceed (Y/N)? ";
                std::cin >> choice;
            } else if (result == -1) {
                std::cout << "IT IS SECONDARY DIABETES.\n";
                std::cout << "PRESS ANY KEY TO QUIT.\n";
                std::cin.get();
            }
            break;
        case 3:
            if (result == 0) {
                std::cout << "IT IS INSULIN DEPENDENT DIABETES.\n";
                std::cout << "PRESS ANY KEY TO QUIT.\n";
                std::cin.get();
            } else if (result == -1) {
                std::cout << "IT IS NON INSULIN DEPENDENT DIABETES.\n";
                std::cout << "PRESS ANY KEY TO QUIT.\n";
                std::cin.get();
            }
            break;
        default:
            break;
    }
    return toupper(choice);
}

int main() {
    char choice;
    int level = 1;
    float result;

    Diabetes dts;
    dts.welcomeScreen();
    dts.getValue();

    dts.getLevel1Symptoms();
    result = dts.analyzeSymptoms(level);
    choice = dts.displayMessage(level, result);
    choice = toupper(choice);

    if (choice == 'Y') {
        ++level;
        dts.getLevel2Symptoms();
        result = dts.analyzeSymptoms(level);
        choice = dts.displayMessage(level, result);
        choice = toupper(choice);

        if (choice == 'Y') {
            ++level;
            dts.getLevel3Symptoms();
            result = dts.analyzeSymptoms(level);
            choice = dts.displayMessage(level, result);
        }
    }

    return 0;
}
