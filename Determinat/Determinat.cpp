#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int getValueInt()
{
    while (true)
    {
        int a;
        cin >> a;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Значение не того типа, введите число!" << endl;
        }
        else
        {
            cin.ignore(32767, '\n');

            return a;
        }
    }
}
double getValueDouble()
{
    while (true)
    {
        double a;
        cin >> a;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Значение не того типа, введите число!" << endl;
        }
        else
        {
            cin.ignore(32767, '\n');

            return a;
        }
    }
}


int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    int size;
    cout << "Введите порядок определителя" << endl;
    while (true)
    {
        size = getValueInt();
        if (size < 2)
        {
            cout << "Всё херня, давай по новой!" << endl;
        }
        else
        {
            break;
        }
    }

    double** arr = new double* [size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = new double[size];
    }

    int own_or_not;
    cout << "Введите число! Если хотите ввести определитель с клавиатуры нажмите 1, иначе он составится автоматически" << endl;
    own_or_not = getValueInt();
    if (own_or_not == 1)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << "Элемент с индексом " << i + 1 << j + 1 << " = ";
                arr[i][j] = getValueDouble();
                cout << endl;
            }
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                arr[i][j] = rand() % 7 - 3;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(10) << arr[i][j];
        }
        cout << endl;
    }
    int delta = 0;
    int leave = 0;
    while (delta < size - 1)
    {
        if (arr[0 + delta][0 + delta] == 0)
        {
            for (int i = 1 + delta; i < size; i++)
            {
                if (arr[i][0 + delta] != 0)
                {
                    double* arr2; // = new double[size];
                    arr2 = arr[i];
                    arr[i] = arr[0 + delta];
                    arr[0 + delta] = arr2;
                    arr2 = nullptr;
                    break;
                }
                if (i == size - 1)
                {
                    leave = 1;
                }
                
            }
            if (leave == 1)
            {
                delta++;
                continue;
            }
        }
        for (int i = 1 + delta; i < size; i++)
        {
            double d = arr[i][0 + delta] / arr[0 + delta][0 + delta];
            for (int j = 0; j < size; j++)
            {
                arr[i][j] = arr[i][j] - arr[0 + delta][j] * d;
            }
        }
        delta++;
        cout << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << setw(10) << arr[i][j];
            }
            cout << endl;
        }
    }
   

    /*
    for (int i = 2; i < size; i++)
    {
        double d = arr[i][1] / arr[1][1];
        for (int j = 1; j < size; j++)
        {
            arr[i][j] = arr[i][j] - arr[1][j] * d;
        }
    }
    */
    double det = 1;
    for (int i = 0; i < size; i++)
    {
      //  for (int j = 0; j < size; j++)
        {
//if (i == j)
            {
                det = det * arr[i][i];
            }
        }
    }

    cout << "Определитель равен = " << det << endl;





    for (int i = 0; i < size; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}