#include <iostream>
#include <string>
#include <Windows.h>
#include <random>
using namespace std;
//ТЗ:
//Создать меню  с выбором четырех действий :
//1.Слово выводится задом наперед.
//2.Вывести слово без гласных.
//3.Вывести слово без согласных.
//4. Рандомно раскидывать буквы заданного слова.
//
//
//- reverse: переворачивает слово задом наперед.
//- removeVowels : удаляет гласные буквы из слова.
//- removeConsonants : удаляет согласные буквы из слова.
//- shuffle : перемешивает буквы в слове.

void ZadomNapered(const string& slovo)
{
    string ZadomNapered = slovo;
    reverse(ZadomNapered.begin(), ZadomNapered.end());
    cout << "Слово задом наперед: " << ZadomNapered << endl;
}

void removeVowels(const string& slovo)
{
    string result = "";
    for (char simbol : slovo)
    {
        if (string("уеыаэояиюУЕЫАЭЯИЮ").find(simbol) == string::npos)
        {
            result += simbol;
        }
    }
    cout << "Слово без гласных: " << result << endl;
}

void removeConsonants(const string& slovo)
{
    string result = "";
    for (char simbol : slovo)
    {
        if (string("йцкнгшщзхфвпрлджчсмтбЙЦКНГШЩЗХФВПРЛДЖССМТБ").find(simbol) == string::npos) {
            result += simbol;
        }
    }
    cout << "Слово без согласных: " << result << endl;
}

void shuffleWord(const string& slovo)
{
    string shuffledWord = slovo;
    random_device rd;
    mt19937 g(rd());
    shuffle(shuffledWord.begin(), shuffledWord.end(), g);
    cout << "Рандомно раскиданное по буквам слово: " << shuffledWord << endl;
}

int main()

{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Rus");

    string slovo;
    cout << "Введите слово: ";
    cin >> slovo;
    int choice;
    do
    {
        //cout << "======== ЭТО НАША МЕНЮШКА ==============\n";
        cout << "\tВЫ МОЖЕТЕ:\n 1.Вывести слово задом наперед\n 2.Вывести слово без гласных\n 3.Вывести слово без СОгласных\n 4.Рандомно раскидать буквы введенного слова\n 5.Выйти из программы";
        cout << "(вводите цифорки!)\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            ZadomNapered(slovo);
            break;
        case 2:
            removeVowels(slovo);
            break;
        case 3:
            removeConsonants(slovo);
            break;
        case 4:
            shuffleWord(slovo);
            break;
        default:
            cout << "Пока-пока!!!" << endl;
        }
    } while (choice != 5);

    return 0;
}