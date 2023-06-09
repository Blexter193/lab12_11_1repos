#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct Bus
{
    string number;
    string driver;
    string route;
};

typedef vector<Bus> BusList;

BusList CreateBusList()
{
    BusList buses;
    
    int amount;
    cout << "Введіть кількість автобусів: ";
    cin >> amount;
    
    for (int i = 0; i < amount; ++i)
    {
        Bus bus;
        
        cout << "Введіть номер автобуса: ";
        cin >> bus.number;
        
        cout << "Введіть прізвище і ініціали водія: ";
        cin >> bus.driver;
        
        cout << "Введіть номер маршруту: ";
        cin >> bus.route;
        
        cout << "\n ";
        cin >> bus.route;
        
        buses.push_back(bus);
    }
    
    return buses;
}

void DeleteBusesFromPark(BusList& buses)
{
    string number;
    cout << "Введіть номер автобуса, який видаляється з парку: ";
    cin >> number;
    
    for (auto it = buses.begin(); it != buses.end(); ++it)
    {
        if (it->number == number)
        {
            buses.erase(it);
            cout << "Автобус успішно видалений з парку.\n";
            return;
        }
    }
    
    cout << "Автобус з таким номером не знайдений в парку.\n";
}

void AddBusesToPark(BusList& buses, BusList& route)
{
    string number;
    cout << "Введіть номер автобуса, який додається до парку: ";
    cin >> number;
    
    for (auto it = route.begin(); it != route.end(); ++it)
    {
        if (it->number == number)
        {
            buses.push_back(*it);
            route.erase(it);
            cout << "Автобус успішно доданий до парку.\n";
            return;
        }
    }
    
    cout << "Автобус з таким номером не знайдений на маршруті.\n";
}

void ShowBusNumber(const BusList& buses, bool isPark)
{
    if (isPark)
    {
        cout << "Автобуси, що знаходяться в парку:\n";
    }
    else
    {
        cout << "Автобуси, що знаходяться на маршруті:\n";
    }
    
    for (const auto& bus : buses)
    {
        cout << "Номер: " << bus.number << ", Водій: " << bus.driver << ", Маршрут: " << bus.route << endl;
    }
}

void SaveToFile(const BusList& buses, const string& fileName)
{
    ofstream file("/Users/user/text12_11.txt");
    
    if (file.is_open())
    {
        for (const auto& bus : buses)
        {
            file << bus.number << " " << bus.driver << " " << bus.route << "\n";
        }
        
        file.close();
        cout << "Дані успішно збережені у файл " << fileName << ".\n";
    }
    else
    {
        cout << "Не вдалося відкрити файл " << fileName << " для запису.\n";
    }
}

void LoadFromFile(BusList& buses, const string& fileName)
{
    ifstream file("/Users/user/text12_11.txt");
    
    if (file.is_open())
    {
        buses.clear();
        
        string line;
        while (getline(file, line))
        {
            istringstream iss(line);
            Bus bus;
            iss >> bus.number >> bus.driver >> bus.route;
            buses.push_back(bus);
        }
        
        file.close();
        cout << "Дані успішно завантажені з файлу " << fileName << ".\n";
    }
    else
    {
        cout << "Не вдалося відкрити файл " << fileName << " для читання.\n";
    }
}

int main()
{
    BusList buses;
    BusList route;
    
    int choice;
    while (true)
    {
        cout << "\n1. Створити список автобусів\n";
        cout << "2. Видалити автобус з парку\n";
        cout << "3. Додати автобус до парку\n";
        cout << "4. Відобразити список автобусів в парку\n";
        cout << "5. Відобразити список автобусів на маршруті\n";
        cout << "6. Зберегти дані у файл\n";
        cout << "7. Завантажити дані з файлу\n";
        cout << "8. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        
        if (choice == 1)
        {
            buses = CreateBusList();
        }
        else if (choice == 2)
        {
            DeleteBusesFromPark(buses);
        }
        else if (choice == 3)
        {
            AddBusesToPark(buses, route);
        }
        else if (choice == 4)
        {
            ShowBusNumber(buses, true);
        }
        else if (choice == 5)
        {
            ShowBusNumber(route, false);
        }
        else if (choice == 6)
        {
            string fileName;
            cout << "Введіть ім'я файлу: ";
            cin >> fileName;
            SaveToFile(buses, fileName);
        }
        else if (choice == 7)
        {
            string fileName;
            cout << "Введіть ім'я файлу: ";
            cin >> fileName;
            LoadFromFile(buses, fileName);
        }
        else if (choice == 8)
        {
            break;
        }
        else
        {
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    }
    
    return 0;
}

