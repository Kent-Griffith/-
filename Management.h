#include <windows.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <string>

#include "Vehicle.cpp"

using namespace std;
int SelectTypes()
{
    char str[10];
    cin >> str;
    while (str[1] != '\0' || (!(str[0] >= '1' && str[0] <= '3')))
    {
        cout << "�������!����������!" << endl;
        cin >> str;
    }

    return str[0] - '0';
}
int SelectTrue()
{
    char str[10];
    cin >> str;
    while (str[1] != '\0' || (!(str[0] >= '1' && str[0] <= '2')))
    {
        cout << "�������!����������!" << endl;
        cin >> str;
    }

    return str[0] - '0';
}

int SelectFunction()
{
    char str[10];
    cin >> str;
    while (str[1] != '\0' || (!(str[0] >= '1' && str[0] <= '6')))
    {
        cout << "�������!����������!" << endl;
        cin >> str;
    }

    return str[0] - '0';
}

void Management::add() //��ӳ���
{
    int a = 0, x, y;
    while (1)
    {
        if (current < N)
        {
            cout << "����������ӵĳ�����Ϣ" << endl;
            cout << "������ţ�";
            cin >> x;
            for (int j = 0; j < current; j++)
            {
                if (car[j].num == x) //����ظ�
                {
                    cout << "����ظ�,���ʧ��! ������ת������������" << endl;
                    a++;
                    break;
                }
            }
            if (a == 0) //��ʱ��Ų��ظ�
            {
                car[current].num = x;
                cout << "���ƺţ�";
                cin >> car[current].license;
                cout << "�������칫˾��";
                cin >> car[current].Manufacturer;
                cout << "����ʱ�䣺";
                cin >> car[current].PurchaseTime;
                cout << "��·�ѣ�";
                cin >> car[current].Toll;
                cout << "�����ͺ�(1-��ͳ�,2-С�γ�,3-����)��";
                car[current].type = SelectTypes();

                cout << "�ܹ�������";
                cin >> car[current].TotalMil;
                if (car[current].type == 1) //��ʱ��1-��ͳ�
                {
                    cout << "����ؿ�����";
                    cin >> carrying[current];
                    car[current].MaintenanceCost = 2000;
                    car[current].FuelPerKm = 0.1;
                }
                else if (car[current].type == 2) //��ʱ��2-С�γ�
                {
                    cout << "��������";
                    cin >> carriage[current];
                    car[current].MaintenanceCost = 1000;
                    car[current].FuelPerKm = 0.05;
                }
                else //��ʱ��3-����
                {
                    cout << "��������";
                    cin >> load[current];
                    car[current].MaintenanceCost = 1500;
                    car[current].FuelPerKm = 0.15;
                }
                car[current].SumCost = (OilPrice * car[current].FuelPerKm * car[current].TotalMil) + (car[current].PurchaseTime * car[current].MaintenanceCost); //�����ܷ���
                current++;                                                                                                                                       //����������һ
                write();                                                                                                                                         //���ó�����Ϣ���̺���
                cout << "�Ƿ������ӳ�����(1-��,2-��)��";
                y = SelectTypes();
                if (y == 2)
                {
                    cout << "����ɹ���������ת������������" << endl;
                    break;
                }
            }
            else //��ʱ����ظ�
                break;
        }
        else
        {
            cout << "������Ϣ������,��������ӳ���!" << endl;
            cout << "������ת������������" << endl;
            break;
        }
    }
    Sleep(1000); //�ӳ�1��
    index();     //���ý��溯��
}

void Management::search() //��ѯ����
{
    int m, n, a = 0;
    char t[20];
    int i;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*  1.���������칫˾��ѯ     *" << endl;
    cout << "*  2.����Ų�ѯ             *" << endl;
    cout << "*  3.������ѯ             *" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "                _____________   " << endl
         << "               /             \\ " << endl
         << "              (��ѡ���ѯ��ʽ!)  " << endl
         << "               \\_____________/ " << endl
         << "               ,,    __         " << endl
         << "           |`-.__   / /         " << endl
         << "           /\"  _/  /_/         " << endl
         << "          *===*    /            " << endl
         << "         /     )__//            " << endl
         << "    /|  /     /---`             " << endl
         << "    \\\\/`   \\ |               " << endl
         << "    `\\    /_\\\\_              " << endl
         << "      `_____``-`                " << endl
         << "�������ѯ��ʽ��ţ�";
    i = SelectTypes();
    if (i == 1)
    {
        cout << "���������ѯ���������칫˾:";
        cin >> t;
    }
    else if (i == 2)
    {
        cout << "���������ѯ�ĳ������:";
        cin >> n;
    }
    else if (i == 3)
    {
        cout << "���������ѯ�ĳ����ͺ�(1-��ͳ�,2-С�γ�,3-����):";
        m = SelectTypes();
    }
    for (int j = 0; j < current; j++)
        if (strcmp(car[j].Manufacturer, t) == 0 || car[j].num == n || car[j].type == m)
        {
            cout << setw(4) << "���" << setw(12) << "���ƺ�" << setw(10) << "������" << setw(10) << "����ʱ��" << setw(9) << "�ͺ�" << setw(18)
                 << "����" << setw(12) << "�ܹ���" << setw(12) << "��·��" << setw(12) << "ά����" << setw(12) << "�ͺ�" << setw(12) << "�ܷ���" << endl;
            break;
        }
    for (int j = 0; j < current; j++)
        if (strcmp(car[j].Manufacturer, t) == 0 || car[j].num == n || car[j].type == m)
        {
            cout << setw(4) << car[j].num << setw(12) << car[j].license << setw(10) << car[j].Manufacturer << setw(10) << car[j].PurchaseTime;
            if (car[j].type == 1)
                cout << setw(9) << "��ͳ�" << setw(10) << "�ؿ���:" << setw(8) << carrying[j];
            else if (car[j].type == 2)
                cout << setw(9) << "С�γ�" << setw(10) << "������: " << setw(8) << carriage[j];
            else
                cout << setw(9) << "�� ��" << setw(10) << "������:" << setw(8) << load[j];
            cout << setw(12) << car[j].TotalMil << setw(12) << car[j].Toll << setw(12) << car[j].MaintenanceCost << setw(12) << car[j].FuelPerKm << setw(12) << car[j].SumCost << endl;
            a++;
        }
    if (a != 0)
    {
        cout << "�Ƿ�����޸�?(1-��,2-��):";

        if (SelectTrue() == 1)
            edit();
    }
    else
    {
        if (i == '1')
            cout << "�ó������칫˾������!" << endl;
        if (i == '2')
            cout << "�ñ�Ų�����!" << endl;
        else if (i == '3')
            cout << "�����û�г���!" << endl;
    }
    cout << "����������ع���������" << endl;
    char zz = getch();
    index();
}

void Management::display() //��ʾ������Ϣ��
{
    if (current != 0)
    {
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << setw(4) << "���" << setw(12) << "���ƺ�" << setw(10) << "������" << setw(10) << "����ʱ��" << setw(9) << "�ͺ�" << setw(18)
             << "����" << setw(12) << "�ܹ���" << setw(12) << "��·��" << setw(12) << "ά����" << setw(12) << "�ͺ�" << setw(12) << "�ܷ���" << endl;

        for (int j = 0; j < current; j++)
        {
            cout << setw(4) << car[j].num << setw(12) << car[j].license << setw(10) << car[j].Manufacturer << setw(10) << car[j].PurchaseTime;
            if (car[j].type == 1)
                cout << setw(9) << "��ͳ�" << setw(10) << "�ؿ���:" << setw(8) << carrying[j];
            else if (car[j].type == 2)
                cout << setw(9) << "С�γ�" << setw(10) << "������:" << setw(8) << carriage[j];
            else
                cout << setw(9) << "�� �� " << setw(10) << "������:" << setw(8) << load[j];
            cout << setw(12) << car[j].TotalMil << setw(12) << car[j].Toll << setw(12) << car[j].MaintenanceCost << setw(12) << car[j].FuelPerKm << setw(12) << car[j].SumCost << endl;
        }
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    }
    else
        cout << "������Ϊ��!" << endl;
    cout << "�����������������";
    char z = getch();
    index();
}

void Management::edit() //�༭����
{
    int i, j, a = 0;
    cout << "������������Ҫ�޸ĵĳ�����Ϣ��" << endl;
    while (1)
    {
        cout << "������ţ�";
        cin >> i;
        for (j = 0; j < current; j++)
        {
            if (car[j].num == i) //�����д˱�ŵĳ�
            {
                cout << "���ƺţ�";
                cin >> car[j].license;
                cout << "���칫˾��";
                cin >> car[j].Manufacturer;
                cout << "����ʱ�䣺";
                cin >> car[j].PurchaseTime;
                cout << "�ͺ�(1-��ͳ���2-С�γ���3-����)��";
                car[j].type = SelectTypes();
                cout << "�ܹ�������";
                cin >> car[j].TotalMil;
                cout << "��·�ѣ�";
                cin >> car[j].Toll;
                if (car[j].type == 1) //��ʱ��1-��ͳ�
                {
                    cout << "����ؿ�����";
                    cin >> carrying[j];
                    car[j].MaintenanceCost = 2000;
                    car[j].FuelPerKm = 0.1;
                }
                else if (car[j].type == 2) //��ʱ��2-С�γ�
                {
                    cout << "��������";
                    cin >> carriage[j];
                    car[j].MaintenanceCost = 1000;
                    car[j].FuelPerKm = 0.05;
                }
                else //��ʱ��3-����
                {
                    cout << "��������";
                    cin >> load[j];
                    car[j].MaintenanceCost = 1500;
                    car[j].FuelPerKm = 0.15;
                }
                write();
                a++;
            }
        }
        if (a == 0)
            cout << "�˱�Ų����ڣ����ܽ����޸ģ����������룡" << endl;
        else
        {
            cout << "�޸ĳɹ���ϵͳ������������..." << endl;
            break;
        }
    }
    Sleep(1000); //�ӳ�1��
    index();
}

void Management::del() //////////////////ɾ������
{
    int i, j,y, a = 0;
    while (1)
    {
        if (current == 0)
        {
            cout << "������Ϣ��Ϊ�գ�ϵͳ�����ع��ܽ���..." << endl;
            break;
        }
        else
        {
            cout << "��������Ҫɾ���ĳ�����ţ�";
            cin >> i;
            cout << "ȷ���Ƿ�ɾ�����Ϊ" << i << "�ĳ�������1-ȷ�ϣ�2-ȡ����" << endl;
            y = SelectTrue();
            if (y == 2)
                break;
            if (y == 1)
            {
                for (j = 0; j < current; j++)
                {
                    if (car[j].num == i) //������Ŵ���
                    {
                        if (current == 1)
                            car[0].type = 0;
                        else
                        {
                            if (car[current - 1].type == 1)
                            {
                                carrying[j] = carrying[current - 1];
                                car[j].Toll = 2000;
                                car[j].FuelPerKm = 0.1;
                            }
                            else if (car[current - 1].type == 2)
                            {
                                carriage[j] = carriage[current - 1];
                                car[j].Toll = 1000;
                                car[j].FuelPerKm = 0.05;
                            }
                            else
                            {
                                load[j] = load[current - 1];
                                car[j].Toll = 1500;
                                car[j].FuelPerKm = 0.15;
                            }
                            car[j].num = car[current - 1].num;
                            car[j].license = car[current - 1].license;
                            strcpy(car[j].Manufacturer, car[current - 1].Manufacturer);
                            car[j].PurchaseTime = car[current - 1].PurchaseTime;
                            car[j].type = car[current - 1].type;
                            car[j].TotalMil = car[current - 1].TotalMil;
                            car[j].Toll = car[current - 1].Toll;
                            car[j].SumCost = car[current - 1].SumCost;
                        }
                        current--;
                        a++;
                        write();
                    }
                }
            }
            if (a == 0)
                cout << "�˱�Ų����ڣ����ܽ���ɾ�������������룡" << endl;
            else
            {
                cout << "ɾ���ɹ���ϵͳ�����ع��ܽ���..." << endl;
                break;
            }
        }
    }
    Sleep(1000); //�ӳ�1��
    index();
}

void Management::write() //������Ϣ����
{
    ofstream write;
    write.open("d:\\a.txt", ios::out);
    if (write)
    {
        for (int i = 0; i < current; i++)
        {   //���δ���  ���   ��     ���ƺ�     ��    ������     ��    ����ʱ��      ��    �ͺ�     ��
            //            write<<endl;
            write << car[i].num << " " << car[i].license << " " << car[i].Manufacturer << " " << car[i].PurchaseTime << " " << car[i].type << " ";
            if (car[i].type == 1)
                write << carrying[i]; //����   �ؿ���
            else if (car[i].type == 2)
                write << carriage[i]; //����    ������
            else
                write << load[i]; //����    ������
            //���δ���  �ܹ���   ��    ��·��      ��      ά����      ��    �ͺ�      ��     �ܷ���
            write << " " << car[i].TotalMil << " " << car[i].Toll << " " << car[i].MaintenanceCost << " " << car[i].FuelPerKm << " " << car[i].SumCost;
            write << endl;
        }
    }
    else
        cout << "write failed" << endl;
}

void Management::read() //����������Ϣ
{
    while (1)
    {
        ifstream read("d:\\a.txt", ios::in);
        if (read)
        {
            while (!read.eof())
            { //���ζ�ȡ    ���   ��     ���ƺ�    ��   ������    ��  ����ʱ��    ��   �ͺ�
                read >> car[current].num >> car[current].license >> car[current].Manufacturer >> car[current].PurchaseTime >> car[current].type;
                if (car[current].type == 1)
                    read >> carrying[current]; //��ȡ   �ؿ���
                else if (car[current].type == 2)
                    read >> carriage[current]; //��ȡ    ������
                else
                    read >> load[current]; //��ȡ    ������
                                           //���ζ�ȡ   �ܹ���   ��   ��·��   ��    ά����    ��   �ͺ�    ��   �ܷ���
                read >> car[current].TotalMil >> car[current].Toll >> car[current].MaintenanceCost >> car[current].FuelPerKm >> car[current].SumCost;
                if (car[current].type == 1 || car[current].type == 2 || car[current].type == 3)
                    current++;
            }
            read.close();
            break;
        }
        else
        {
            ofstream o("d:\\a.txt");
            o.close();
        }
    }
}

void Management::index1()
{
    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
    int car_number = 0, coach_number = 0, truck_number = 0;
    current = 0;
    read();

    for (int i = 0; i < current; i++)
    {
        if (car[i].type == 1)
            coach_number++;
        else if (car[i].type == 2)
            car_number++;
        else if (car[i].type == 3)
            truck_number++;
    }
    current = coach_number + car_number + truck_number;
    cout << "             ___________________________  " << endl
         << "          !/_________________________/!\\" << endl
         << "          !!welcome to use our       !! \\" << endl
         << "          !!Vehicle Management System!!  \\" << endl
         << "          !!   С���Ա��             !!  !" << endl
         << "          !!    ����                !!  !" << endl
         << "          !!      ��                !!  !" << endl
         << "          !!       ��˼Զ             !!  !" << endl
         << "          !!          ���            !!  !" << endl
         << "          !!             ����         !!  /" << endl
         << "          !!_________________________!! /" << endl
         << "          !/_________________________\\!/" << endl
         << "             __\\_________________/__/!_" << endl
         << "            !_______________________!/" << endl
         << "          ________________________" << endl
         << "         /oooo  oooo  oooo  oooo /!" << endl
         << "        /ooooooooooooooooooooooo/ /" << endl
         << "       /ooooooooooooooooooooooo/ /" << endl
         << "      /C=_____________________/_/" << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           1.�� �� �� ��               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           2.�� ѯ �� ��               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           3.�� ʾ �� ��               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           4.�� �� �� ��               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           5.ɾ �� �� ��               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           6.�� �� ϵ ͳ               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "��������Ҫʹ�õĹ��ܱ�ţ�" << endl;
    int i;
    i = SelectFunction();
    switch (i)
    {
    case 1:
        Management::add();
        break;
    case 2:
        Management::search();
        break;
    case 3:
        Management::display();
        break;
    case 4:
        Management::edit();
        break;
    case 5:
        Management::del();
        break;
    case 6:
        go();
        return;

        // default:
        // cout<<"��������ȷ�Ĺ��ܱ��(0~6),������ת�����档������"<<endl;
        // Sleep(2000);
        //     index1();
        //      break;
    }
}
void Management::index()
{
    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    int car_number = 0, coach_number = 0, truck_number = 0;
    current = 0;
    read();
    system("cls");
    for (int i = 0; i < current; i++)
    {
        if (car[i].type == 1)
            coach_number++;
        else if (car[i].type == 2)
            car_number++;
        else if (car[i].type == 3)
            truck_number++;
    }
    current = coach_number + car_number + truck_number;
    cout << "             ___________________________  " << endl
         << "          !/_________________________/!\\" << endl
         << "          !!                         !! \\" << endl
         << "          !!Vehicle Management System!!  \\" << endl
         << "          !!                         !!  !" << endl
         << "          !!        ��ӭ����ʹ��     !!  !" << endl
         << "          !!�ܳ�����:" << current << "               !!  !" << endl
         << "          !!�γ�������" << car_number << "              !!  !" << endl
         << "          !!�ͳ�������" << coach_number << "              !!  /" << endl
         << "          !!����������" << truck_number << "              !! /" << endl
         << "          !!_________________________!! /" << endl
         << "          !/_________________________\\!/" << endl
         << "             /___________________\\__!_" << endl
         << "            /_____________________\\__!/" << endl
         << "          ________________________" << endl
         << "         /oooo  oooo  oooo  oooo /!" << endl
         << "        /ooooooooooooooooooooooo/ /" << endl
         << "       /ooooooooooooooooooooooo/ /" << endl
         << "      /C=_____________________/_/" << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           1.�� �� �� ��               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           2.�� ѯ �� ��               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           3.�� ʾ �� ��               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           4.�� �� �� ��               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           5.ɾ �� �� ��               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           6.�� �� ϵ ͳ               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "�ܳ�����:" << current << "�γ�������" << car_number << "�ͳ�������" << coach_number << "����������" << truck_number << endl;
    cout << "��������Ҫʹ�õĹ��ܱ�ţ�" << endl;
    int i;
    i = SelectFunction();
    switch (i)
    {
    case 1:
        Management::add();
        break;
    case 2:
        Management::search();
        break;
    case 3:
        Management::display();
        break;
    case 4:
        Management::edit();
        break;
    case 5:
        Management::del();
        break;
    case 6:
        go();
        return;

        // default:
        // cout<<"��������ȷ�Ĺ��ܱ�š�"<<endl;
        // cout<<"��������ȷ�Ĺ��ܱ��(0~6),������ת�����档������"<<endl;
        // Sleep(2000);
        // index();
        //     break ;
    }
}
void Management::come()

{
    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    cout << " ::::::::::::::::::::::|������:::::::::::::::::::::::::::::::" << endl;
    cout << " ::::::::::::::::::������������������������������������������:::::::::::::::::::::" << endl;
    cout << " :::::::::::::::::||::::___::::::::___::\\:::::::::::::::::::" << endl;
    cout << " ::::::::::::::::||::::|##|:::::::|##|:::\\::::::::::::::::::" << endl;
    cout << " :::::::::::::::||:::::|__|:::::::|__|::::\\:::::::::::::::::" << endl;
    cout << " ::::::________========��������ϵͳ=========\\________:::::::::" << endl;
    cout << " :::: |::::::::::::(ooo)::::::::::::(ooo)::::::::::::|):::::::" << endl;
    cout << " :::==|___________(ooOoo)__________(ooOoo)___________|::::::::" << endl;
    cout << " ::::::::::::::::::(ooo)::::::::::::(ooo):::::::::::::::::::::" << endl;
    cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "                   ��������ϵͳ����������                         " << endl;

    Sleep(1500);
    system("cls");
}

void Management::go()
{
    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    cout << " ::::::::::::::::::::::|������:::::::::::::::::::::::::::::::" << endl;
    cout << " ::::::::::::::::::������������������������������������������:::::::::::::::::::::" << endl;
    cout << " :::::::::::::::::||::::___::::::::___::\\:::::::::::::::::::" << endl;
    cout << " ::::::::::::::::||::::|##|:::::::|##|:::\\::::::::::::::::::" << endl;
    cout << " :::::::::::::::||:::::|__|:::::::|__|::::\\:::::::::::::::::" << endl;
    cout << " ::::::________========��������ϵͳ=========\\________:::::::::" << endl;
    cout << " :::: |::::::::::::(ooo)::::::::::::(ooo)::::::::::::|):::::::" << endl;
    cout << " :::==|___________(ooOoo)__________(ooOoo)___________|::::::::" << endl;
    cout << " ::::::::::::::::::(ooo)::::::::::::(ooo):::::::::::::::::::::" << endl;
    cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "                             ��ӭ�ٴ�ʹ��                        " << endl;
    cout << "                             bye������������                          " << endl;
    Sleep(3000);
    system("cls");
}
