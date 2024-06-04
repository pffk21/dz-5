
#include <iostream>
using namespace std;
class Account {
private:
    char* surname;
    char* nomershet;
    int procent;
    double sum;
    static int objCount;
public:
    Account();
    Account(const char* Surname, const char* Nomershet, int Procent, double Sum);
    ~Account();
    void NowVladeleh(const char* NowVladeleh);
    void Snatiedeneg(double Snatiedeneg);
    void Deposit(double Deposit);
    void Procent();
    double Dollars(double doll);
    double Euros(double euro);
    string SUMMA();
};
int Account::objCount = 0;
Account::Account()
{
    surname = 0;
    nomershet = 0;
    procent = 0;
    sum = 0;
    objCount++;
}
Account::Account(const char* Surname, const char* Nomershet, int Procent, double Sum)
{
    surname = new char[strlen(Surname) + 1];
    strcpy(surname, Surname);
    nomershet = new char[strlen(Nomershet) + 1];
    strcpy(nomershet, Nomershet);
    procent = Procent;
    sum = Sum;
    objCount++;
}
Account::~Account()
{
    delete[] surname;
    delete[] nomershet;
    objCount--;
}
void Account::NowVladeleh(const char* NowVladeleh)
{
    delete[] surname;
    surname = new char[strlen(NowVladeleh) + 1];
    strcpy(surname, NowVladeleh);
}
void Account::Snatiedeneg(double Snatiedeneg)
{
    if (sum >= Snatiedeneg)
    {
        sum = sum - Snatiedeneg;
    }
}
void Account::Deposit(double Deposit)
{
    sum = sum + Deposit;
}
void Account::Procent()
{
    sum = sum + sum * (procent / 100.0);
}
double Account::Dollars(double doll)
{
    return sum / doll;
}
double Account::Euros(double euro)
{
    return sum / euro;
}
string Account::SUMMA()
{
    char arr[50];
    int zhelaa = sum;
    int drobnaa = (sum - zhelaa) * 100;
    cout << zhelaa;
    cout << endl;
    cout << drobnaa;
    return string(arr);
}
int main() {
    Account a("Tina", "64397467549036", 20, 30000);
    Account b("Dima", "25446656687690", 40, 70000);
    cout << "Сумма на счете: " << a.SUMMA() << " грн" << endl;
    a.Deposit(5000);
    cout << "Сумма после пополнения на счете: " << a.SUMMA() << " грн" << endl;
    a.Snatiedeneg(10000);
    cout << "Сумма после снятия на счете: " << a.SUMMA() << " грн" << endl;
    a.Procent();
    cout << "Сумма после процентов на счете: " << a.SUMMA() << " грн" << endl;
    cout << "Сумма в долларах: " << a.Dollars(40) << " doll" << endl;
    cout << "Сумма в евро: " << a.Euros(45) << " euro" << endl;

