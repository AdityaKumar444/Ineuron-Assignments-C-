#include<bits/stdc++.h>
using namespace std ;
char empfile[30] = "D:/New folder/Employee.dat";
char ITfile[30] = "D:/New folder/IT.dat";
char Adminfile[30] = "D:/New folder/Admin.dat";
char Prodfile[30] = "D:/New folder/Production.dat";
char Salesfile[30] = "D:/New folder/Sales.dat";
class emp
{
    protected:
        int empid , age ;
        char name[30] , address[60];
    public:
        char dept[15];
        char * getdept() { return dept; }
        void setData()
        {
           cout << "\n Enter Employee Id     :  ";
            cin >> empid;
            cout << "\n Enter Name            :  ";
            fflush(stdin);
            fgets(name,30,stdin);
            cout << "\n Enter Address         :  ";
            fflush(stdin);
            fgets(address,60,stdin);
            cout << "\n Enter Department Name:(Admin/Sales/IT/Production)  :  ";
            cin >> dept;
            cout << "\n Enter Age   :  ";
            cin >> age;
        }
};
void insert()
{
    emp e;
    ofstream fout;
    fout.open("D:/New folder/Employee.dat", ios::in | ios::out | ios::app);
    if (fout.fail())
    {
        cout << "\n Unable to Open the File!!!";
        fout.close();
    }
    e.setData();                           
    fout.write((char *)&e, sizeof(e)); 
    if (fout.tellp() % sizeof(e) == 0)
    {
        cout << "\n Record Inserted !!!" << endl;
    }
    else
    {
        cout << "\n Insertion Failed !!!";
        fout.close();
    }
}
void sort() 
{
    emp e;
    ofstream adm, sal, pro, it; 
    ifstream fin;              
    adm.open(Adminfile, ios::out | ios::app);
    sal.open(Salesfile, ios::out | ios::app);
    pro.open(Prodfile, ios::out | ios::app);
    it.open(ITfile, ios::out | ios::app);
    fin.open(empfile, ios::in);
    while (fin.read((char *)&e, sizeof(e))) 
    {
        if (strcmp(e.getdept(), "Admin") == 0)
        {
            adm.write((char *)&e, sizeof(e));
            cout << "\n Record Inserted into ADMIN File!!!";
        }
        else if (strcmp(e.getdept(), "Sales") == 0)
        {
            sal.write((char *)&e, sizeof(e));
            cout << "\n Record Inserted into SALES File!!!";
        }
        else if (strcmp(e.getdept(), "IT") == 0)
        {
            it.write((char *)&e, sizeof(e));
            cout << "\n Record Inserted into IT File!!!";
        }
        else if (strcmp(e.getdept(), "Production") == 0)
        {
            pro.write((char *)&e, sizeof(e));
            cout << "\n Record Inserted into Production File!!!";
        }
        else
            cout << "\n Insert Correct Record!!!";
    }
    fin.close();
    adm.close();
    sal.close();
    it.close();
    pro.close();
}
int main () 
{
    int n;
    cout << "\n Enter No. of Records You Want? : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    insert();
    sort();
    return 0;
}
