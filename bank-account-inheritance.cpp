class account{
protected:
    string n;
    int bal;
    int acNo;
public:
    account(){ n = " "; bal = 0; acNo = 0; }
    account(string a=" ", int b=0,int c=0)
    {
        n = a;
        bal = b;
        acNo = c;
    }
    void setN(string a){n = a;}
    void setB(int b){bal = b;}
    void setAcNo(int c){acNo = c;}
    string getN(){return n;}
    int getBal(){return bal;}
    int getAcNo(){return acNo;}
    virtual void display()
    {
        cout << n << "\t";
        cout << bal << "\t";
        cout << acNo << "\t";
    }
    virtual int credit(int){ return 0; }
    virtual int debit(int){ return 0; }
    virtual int interest(int){ return 0; }
    virtual float interest(float){ return 0; }
    virtual int minus(){ return 0; }
};

class saving :public account{
public:
    saving(string a = " ", int b = 0, int c = 0) :account(a, b, c){}
    int credit(int temp)
    {
        if (temp > 0){
            bal += temp;
            return bal;
        }
    }
    int debit(int temp)
    {
        if (temp > 0 && temp<bal)
        {
            if (bal - temp < 50000) { cout << "Transaction Not Allowed!\n"; }
            else {bal -= temp;}
            return bal;
        }
    }
    float interest(float temp)
    {
        float inter;
        inter = (temp*bal)/ 100;
        bal += inter;
        return inter;
    }
    int minus()
    {
        float min;
        min = (2.5*bal) / 100;
        bal -= (2.5*bal) / 100;
        return min;
    }
    void display()
    {
        account::display();
        cout << "Saving";
    }
};

class current :public account{
public:
    current(string a = " ", int b = 0, int c = 0) :account(a, b, c){}
    int credit(int temp)
    {
        if (temp > 0)
        {
            bal += temp-20; //20 fee deduct
            return bal;
        }
    }
    int debit(int temp)
    {
        if (temp > 0 && temp<bal)
        {
            bal -= temp-20;
            return bal;
        }
    }
    int interest(int temp)
    {
        bal += temp;
        return bal;
    }
    void display()
    {
        account::display();
        cout << "Current";
    }
};


int main()
{
    account*p[10];
    char ch;
    int bal=100000;
    int acNo = 1235423;
    float sav; int cur;


    cout << "Interest % for Saving: "; cin >> sav;
    cout << "Interest Ammount for Current: "; cin >> cur;

    for (int i = 0; i < 10; i++)
    {
        cout << "Enter Account type (S/C): ";
        cin >> ch;
        if (ch == 'S' || ch == 's')
        {
            p[i] = new saving("Ali",bal,acNo);
        }
        else if (ch == 'C'||ch == 'c')
        {
            p[i] = new current("Parkash", bal, acNo);
        }
        bal += 1000;
        acNo++;
        system("CLS");
    }

    cout << "Testing Program for First Account!\n";
    cout << "\nIntial stage: \n"; p[0]->display();
    cout << "\nBalance after Credit of 2000: " << p[0]->credit(2000) << endl;
    cout << "Balance after Debit of 1000: " << p[0]->debit(1000) << endl;
    cout << "After Interest: \n";
    p[0]->interest(sav); p[0]->interest(cur);
    p[0]->display();

    cout << "\n\nIn the end of the year: \n";
    for (int i = 0; i < 10; i++)
    {
        p[i]->interest(sav);
        p[i]->interest(cur);
        p[i]->minus();
        p[i]->display();
        cout << endl;
    }
    system("pause");
}
