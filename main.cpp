#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Account
{
public:
    float balance;
    int no_of_deposit = 0;
    int no_of_withdraws = 0;
    float annual_interested;
    float monthly_ser_charges = 0;

    Account(float b, float ann_inter)
    {
        this->balance = b;
        this->annual_interested = ann_inter;
    }

    virtual void deposit(float amount)
    {
        balance += amount;
        no_of_deposit++;
    }

    virtual void Withdraw(float amount)
    {
        balance -= amount;
        no_of_withdraws++;
    }

    virtual void calclnt()
    {
        float Monthly_interested_Rate = annual_interested / 12;
        float Monthly_interested = balance * Monthly_interested_Rate;
        balance = balance + Monthly_interested;
    }

    virtual void monthlyProc()
    {
        balance -= monthly_ser_charges;
        calclnt();
        no_of_withdraws = 0;
        no_of_deposit = 0;
        monthly_ser_charges = 0;
    }
};

class Saving_Account : public Account
{
    bool status;

public:
    bool Check()
    {
        if (balance > 25)
        {
            status = true;
            return status;
        }
        else
        {
            status = false;
            return status;
        }
    }

    void Withdraw(float amount)
    {
        if (Check())
        {
            Account::Withdraw(amount);
        }
        else
        {
            cout << "Balace less than 25 $ your accont uis inactive ";
        }
    }

    void deposit(float amount)
    {
        if (Check())

        {
            Account::deposit(amount);
        }
        else
        {
            Account::deposit(amount);
            // status=true;
            Check();
        }
    }

    void monthlyProc()
    {
        if (no_of_withdraws < 4)
        {
            Account::monthlyProc();
            Check();
        }
        else
        {
            monthly_ser_charges += 1;
            Account::monthlyProc();
            Check();
        }
    }
};

class Checking_Account : public Account
{

public:
    void Withdraw(float amount)
    {
        if (amount > balance)
        {
            monthly_ser_charges += 15;
        }
        else
        {
            Account::Withdraw(amount);
        }
    }

    void monthlyProc()
    {
        float monthly_fee = 5;
        monthly_ser_charges += monthly_fee + (0.10 * no_of_withdraws);
        Account::monthlyProc();
    }
};
int main()
{
    float d, w, a;
    cout << "Enter a amount of Deposit for Saving Account";
    cin >> d;

    cout << "Enter a Annual interested ";
    cin >> a;
    Account A1(d, a);
    return 0;
}