#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;
int main() {
    string text;

    cout << "Введите текст: ";
    getline(cin, text);

    // Создаем map для хранения количества вхождений каждого слова
    // Ключ - слово (string), значение - количество вхождений (int)
    map<string, int> wordCounts;

    // Создаем поток для обработки введенного текста
    stringstream ss(text);

    string word;        // Объявляем переменную word типа string для хранения каждого извлеченного слова
    int totalWords = 0; // Объявляем переменную totalWords типа int для хранения общего количества слов (инициализируем нулем)

    // Извлекаем слова из потока и подсчитываем их количество
    while (ss >> word) { // Пока есть слова в потоке ss

        string lowerWord = ""; // Создаем пустую строку lowerWord для хранения слова в нижнем регистре
        for (char c : word) {  // Проходим по каждому символу c в слове word
            lowerWord += tolower(c); // Преобразуем символ в нижний регистр и добавляем его в lowerWord
        }

        wordCounts[lowerWord]++; // Увеличиваем счетчик для слова в нижнем регистре (если слова нет, оно будет добавлено со значением 1)
        totalWords++;             // Увеличиваем общее количество слов
    }

    
    cout << "Частота встречи слов в тексте (в процентах):" << endl;
    // Проходим по всем элементам в map wordCounts
    for (const auto& pair : wordCounts) {
        // Вычисляем частоту встречаемости слова (в процентах)
        double frequency = (double)pair.second / totalWords * 100.0;

        cout.precision(2);
        cout << fixed << pair.first << ": " << frequency << "%" << endl;     
    }

    return 0; // Завершаем программу с кодом 0 (успешное завершение)
}
