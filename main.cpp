#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "TextTable.h"
using namespace std;
int printMainMenu();
string inputLoginCode(fstream &login);
void veTKB(string arr[12][6]);
void veTKB1(string arr[12][6], int m, int n);
void change(string arr[12][6], int m, string tenGV);
void clear();
void Menu1(fstream &schedule, string arr[12][6], string &tenGV);
void Menu2(fstream &schedule, string arr[12][6], string tenGV);
void Menu3(string arr[12][6]);
void Menu4(string tenGV, fstream &schedule);
int choose(int choose, fstream &schedule, string arr[12][6], string &tenGV, fstream &login, int &chon);

int main()
{
    system("clear");
    fstream login("Data/login.txt"); // Mo file de doc
    string arr[12][6];               // Mang chua tkb
    string tenGV;                    // Bien chua username
    tenGV = inputLoginCode(login);
again:
    fstream schedule("Data/" + tenGV + ".txt");
    system("clear");
    int chon;
    chon = choose(printMainMenu(), schedule, arr, tenGV, login, chon);
    if (chon == 0)
        goto again;
    if (chon == 1)
    {
        char n;
        cout << "Ban muon co muon tiep tuc ? - Nhap Y de tiep tuc hoac N de dung: ";
        cin >> n;
        if (n == 'Y')
        {
            system("clear");
            goto again;
        }
        else
        {
            goto again;
        }
    }
    if (chon == 2)
    {
        char n;
    again2:
        fstream schedule("Data/" + tenGV + ".txt");
        cout << "Ban muon co muon tiep tuc ? - Nhap Y de tiep tuc hoac N de dung: ";
        cin >> n;
        system("clear");
        if (n == 'Y')
        {
            system("clear");
            choose(2, schedule, arr, tenGV, login, chon);
            schedule.close();
            goto again2;
        }
        else
        {
            goto again;
        }
    }
    if (chon == 3)
    {
        char n;
    again3:
        cout << endl;
        cout << "Ban muon co muon tiep tuc ? - Nhap Y de tiep tuc hoac N de dung: ";
        cin >> n;
        if (n == 'Y')
        {
            if (tenGV == "Admin")
            {
                choose(3, schedule, arr, tenGV, login, chon);
                goto again3;
            }
            else
            {
                goto again;
            }
        }
        else
        {
            goto again;
        }
    }
    if (chon == 4)
    {
        char n;
    again4:
        cout << "Ban muon co muon tiep tuc ? - Nhap Y de tiep tuc hoac N de dung: ";
        cin >> n;
        if (n == 'Y')
        {
            if (tenGV == "Admin")
            {
                choose(4, schedule, arr, tenGV, login, chon);
                goto again4;
            }
            else
            {
                goto again;
            }
        }
        else
        {
            goto again;
        }
    }
    login.close();
    schedule.close();
    return 0;
}

// Nhap vao tkb mau de tao user moi
void inputSchedule_ex(string arr[12][6])
{
    fstream schedule_ex("Data/schedule_ex.txt");
    string temp;
    for (int i = 0; i <= 11; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            getline(schedule_ex, arr[i][j], '-');
        }
        getline(schedule_ex, temp);
    }
}

// In ra menu
int printMainMenu()
{
    int choose;
    cout << "\tWelcome !!!!" << endl;
    cout << "1. Xem thoi khoa bieu da xep" << endl;
    cout << "2. Dat lich thoi khoa bieu moi" << endl;
    cout << "3. Tao user moi" << endl;
    cout << "4. Xoa user" << endl;
    cout << "5. Thoat" << endl;
    cout << "Xin moi chon 1 chuc nang: ";
    cin >> choose;
    return choose;
}
// Nhan vao ten dang nhap va kiem tra voi file "login.txt"
string inputLoginCode(fstream &login)
{
    login.clear();
    string str, code;
    bool check = true;
    while (check == true)
    {
        login.seekg(0, ios::beg);
        cout << "Moi ban nhap ho va ten de tiep tuc: ";
        getline(cin, str);
        while (login.eof() != true)
        {
            getline(login, code);
            if (str == code)
            {
                check = false;
                break;
            }
            else
                cout << "Sai ten dang nhap !\n";
        }
    }
    return code;
}
// Ve TKB vao khung
void veTKB(string arr[12][6])
{
    TextTable t('=', '|', '=');
    for (int i = 0; i <= 11; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            t.add(arr[i][j]);
        }
        t.endOfRow();
    }
    std::cout << t;
}
// Ve TKB vao khung
void veTKB1(string arr[12][6], int m, int n)
{
    TextTable t('=', '|', '=');
    for (int i = m; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            t.add(arr[i][j]);
        }
        t.endOfRow();
    }
    std::cout << t;
}
// thuc hien chuc nang chinh sua tkb
void change(string arr[12][6], int m, string tenGV)
{
    int index;
    string temp;
    veTKB1(arr, m, 5);
    cout << "Nhap tiet can dieu chinh: ";
    cin >> index;
    cout << "Nhap noi dung can dieu chinh: ";
    cin.ignore();
    getline(cin, arr[m][index]);
    cout << "TKB moi" << endl;
    veTKB(arr);
    ofstream schedule("Data/" + tenGV + ".txt", ios_base::trunc);
    schedule << tenGV << endl;
    for (int i = 0; i <= 11; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            schedule << arr[i][j] << "-";
        }
        schedule << endl;
    }
}
// Xoa noi dung cua file login.txt
void clear()
{

    remove("login.txt");
    ofstream file("Data/login.txt");
    file.close();
}
// Menu de xem TKB da sap xep
void Menu1(fstream &schedule, string arr[12][6], string &tenGV)
{
    string temp;

    for (int i = 0; i <= 11; i++)
    {
        getline(schedule, temp);
        for (int j = 0; j <= 5; j++)
        {
            getline(schedule, arr[i][j], '-');
        }
    }
    veTKB(arr);
}
// Menu 2
void Menu2(fstream &schedule, string arr[12][6], string tenGV)
{
    int thu, buoi;
    string temp, temp1;
    cout << "Thoi khoa bieu hien tai cua ban" << endl;
    Menu1(schedule, arr, tenGV);
again:
    cout << "Vui long chon thu muon dieu chinh TKB: ";
    cin >> thu;
    cout << "Vui long chon buoi muon dieu chinh TKB (Sang hoac Chieu): ";
    cin >> temp;
    if (temp == "Sang")
        buoi = 1;
    if (temp == "Chieu")
        buoi = 2;
    int index;
    switch (thu)
    {
    case 2:
        switch (buoi)
        {
        case 1:
            change(arr, 0, tenGV);
            break;
        case 2:
            change(arr, 1, tenGV);
        default:
            cout << "Thu nhap vao khong hop le vui long chon lai !" << endl;
            goto again;
            break;
        }
        break;
    case 3:
        switch (buoi)
        {
        case 1:
            change(arr, 2, tenGV);
            break;
        case 2:
            change(arr, 3, tenGV);
            break;
        default:
            cout << "Thu nhap vao khong hop le vui long chon lai !" << endl;
            goto again;
            break;
        }
        break;
    case 4:
        switch (buoi)
        {
        case 1:
            change(arr, 4, tenGV);
            break;
        case 2:
            change(arr, 5, tenGV);
            break;
        default:
            cout << "Thu nhap vao khong hop le vui long chon lai !" << endl;
            goto again;
            break;
        }
        break;
    case 5:
        switch (buoi)
        {
        case 1:
            change(arr, 6, tenGV);
            break;
        case 2:
            change(arr, 7, tenGV);
            break;
        default:
            cout << "Thu nhap vao khong hop le vui long chon lai !" << endl;
            goto again;
            break;
        }
        break;
    case 6:
        switch (buoi)
        {
        case 1:
            change(arr, 8, tenGV);
            break;
        case 2:
            change(arr, 9, tenGV);
            break;
        default:
            cout << "Thu nhap vao khong hop le vui long chon lai !" << endl;
            goto again;
            break;
        }
        break;
    case 7:
        switch (buoi)
        {
        case 1:
            change(arr, 10, tenGV);
            break;
        case 2:
            change(arr, 11, tenGV);
            break;
        default:
            cout << "Thu nhap vao khong hop le vui long chon lai !" << endl;
            goto again;
            break;
        }
        break;
    default:
        cout << "Thu nhap vao khong hop le vui long chon lai !" << endl;
        goto again;
        break;
    }
}
// Tao user moi cho admin
void Menu3(string arr[12][6])
{
    fstream login("Data/login.txt");
    login.seekg(0, ios_base::end);
    string n;
    cin.ignore();
    cout << "Nhap ten nguoi dung can tao: ";
    getline(cin, n);
    login.clear();
    login << endl;
    login << n;
    fstream newUser("Data/" + n + ".txt");
    if (!newUser.is_open())
    {
        ofstream newUser("Data/" + n + ".txt");
        newUser << n;
        newUser << endl;
        inputSchedule_ex(arr);
        for (int i = 0; i <= 11; i++)
        {
            for (int j = 0; j <= 5; j++)
            {
                newUser << arr[i][j] << "-";
            }
            newUser << endl;
        }
    }
    else
    {
        cout << "Ten user da ton tai !. Vui long chon ten khac";
    }
    login.close();
}
// Xoa user
void Menu4(string tenGV, fstream &schedule)
{
    fstream login("Data/login.txt");
    string name, deletename;
    char filename[100];
    cout << "Cac user hien co: " << endl;
    login.seekg(0, ios::beg);
    vector<string> uname;
    while (login.eof() == false)
    {
        getline(login, name);
        cout << name << endl;
        uname.push_back(name);
    }
    cin.ignore();
    cout << "Nhap ten user can xoa: ";
    getline(cin, deletename);
    remove((deletename + ".txt").c_str());
    clear();
    login.close();
    fstream file("Data/login.txt");
    for (int i = 0; i < uname.size(); i++)
    {
        if (deletename == uname[i] || uname[i] == "")
            uname[i].erase();
        else
        {
            file << uname[i];
            if (i != (uname.size()))
            {
                file << endl;
            }
        }
    }
    login.close();
}
// Lua chon cua nguoi dung
int choose(int choose, fstream &schedule, string arr[12][6], string &tenGV, fstream &login, int &chon)
{
    switch (choose)
    {
    case 1:
        Menu1(schedule, arr, tenGV);
        return 1;
        break;
    case 2:
        Menu2(schedule, arr, tenGV);
        return 2;
        break;
    case 3:
        if (tenGV == "Admin")
        {
            Menu3(arr);
        }
        else
        {
            cout << "Lien he admin de tao user moi" << endl;
        }
        return 3;
        break;
    case 4:
        if (tenGV == "Admin")
        {
            Menu4(tenGV, schedule);
        }
        else
        {
            cout << "Lien he admin de xoa user" << endl;
        }
        return 4;
        break;
    case 5:
    exit:
        cout << "Cam on ban da su dung chuong trinh" << endl;
        chon = 0;
        return 5;
        break;
    default:
        cout << "Lua chon khong hop le vui long chon lai !" << endl;
        return 0;
        break;
    }
    return 0;
}