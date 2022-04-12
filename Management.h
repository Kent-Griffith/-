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
        cout << "输入错误!请重新输入!" << endl;
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
        cout << "输入错误!请重新输入!" << endl;
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
        cout << "输入错误!请重新输入!" << endl;
        cin >> str;
    }

    return str[0] - '0';
}

void Management::add() //添加车辆
{
    int a = 0, x, y;
    while (1)
    {
        if (current < N)
        {
            cout << "请输入需添加的车辆信息" << endl;
            cout << "车辆编号：";
            cin >> x;
            for (int j = 0; j < current; j++)
            {
                if (car[j].num == x) //编号重复
                {
                    cout << "编号重复,添加失败! 即将跳转至功能主界面" << endl;
                    a++;
                    break;
                }
            }
            if (a == 0) //此时编号不重复
            {
                car[current].num = x;
                cout << "车牌号：";
                cin >> car[current].license;
                cout << "车辆制造公司：";
                cin >> car[current].Manufacturer;
                cout << "购买时间：";
                cin >> car[current].PurchaseTime;
                cout << "养路费：";
                cin >> car[current].Toll;
                cout << "车辆型号(1-大客车,2-小轿车,3-卡车)：";
                car[current].type = SelectTypes();

                cout << "总公里数：";
                cin >> car[current].TotalMil;
                if (car[current].type == 1) //此时是1-大客车
                {
                    cout << "最大载客量：";
                    cin >> carrying[current];
                    car[current].MaintenanceCost = 2000;
                    car[current].FuelPerKm = 0.1;
                }
                else if (car[current].type == 2) //此时是2-小轿车
                {
                    cout << "车厢数：";
                    cin >> carriage[current];
                    car[current].MaintenanceCost = 1000;
                    car[current].FuelPerKm = 0.05;
                }
                else //此时是3-卡车
                {
                    cout << "载重量：";
                    cin >> load[current];
                    car[current].MaintenanceCost = 1500;
                    car[current].FuelPerKm = 0.15;
                }
                car[current].SumCost = (OilPrice * car[current].FuelPerKm * car[current].TotalMil) + (car[current].PurchaseTime * car[current].MaintenanceCost); //计算总费用
                current++;                                                                                                                                       //车辆总数加一
                write();                                                                                                                                         //调用车辆信息存盘函数
                cout << "是否继续添加车辆？(1-是,2-否)：";
                y = SelectTypes();
                if (y == 2)
                {
                    cout << "保存成功！即将跳转至功能主界面" << endl;
                    break;
                }
            }
            else //此时编号重复
                break;
        }
        else
        {
            cout << "车辆信息库已满,不能再添加车辆!" << endl;
            cout << "即将跳转至功能主界面" << endl;
            break;
        }
    }
    Sleep(1000); //延迟1秒
    index();     //调用界面函数
}

void Management::search() //查询车辆
{
    int m, n, a = 0;
    char t[20];
    int i;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*  1.按车辆制造公司查询     *" << endl;
    cout << "*  2.按编号查询             *" << endl;
    cout << "*  3.按类别查询             *" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "                _____________   " << endl
         << "               /             \\ " << endl
         << "              (请选择查询方式!)  " << endl
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
         << "请输入查询方式编号：";
    i = SelectTypes();
    if (i == 1)
    {
        cout << "请输入需查询车辆的制造公司:";
        cin >> t;
    }
    else if (i == 2)
    {
        cout << "请输入需查询的车辆编号:";
        cin >> n;
    }
    else if (i == 3)
    {
        cout << "请输入需查询的车辆型号(1-大客车,2-小轿车,3-卡车):";
        m = SelectTypes();
    }
    for (int j = 0; j < current; j++)
        if (strcmp(car[j].Manufacturer, t) == 0 || car[j].num == n || car[j].type == m)
        {
            cout << setw(4) << "编号" << setw(12) << "车牌号" << setw(10) << "制造商" << setw(10) << "购买时间" << setw(9) << "型号" << setw(18)
                 << "特性" << setw(12) << "总公里" << setw(12) << "养路费" << setw(12) << "维护费" << setw(12) << "油耗" << setw(12) << "总费用" << endl;
            break;
        }
    for (int j = 0; j < current; j++)
        if (strcmp(car[j].Manufacturer, t) == 0 || car[j].num == n || car[j].type == m)
        {
            cout << setw(4) << car[j].num << setw(12) << car[j].license << setw(10) << car[j].Manufacturer << setw(10) << car[j].PurchaseTime;
            if (car[j].type == 1)
                cout << setw(9) << "大客车" << setw(10) << "载客量:" << setw(8) << carrying[j];
            else if (car[j].type == 2)
                cout << setw(9) << "小轿车" << setw(10) << "车厢数: " << setw(8) << carriage[j];
            else
                cout << setw(9) << "卡 车" << setw(10) << "载重量:" << setw(8) << load[j];
            cout << setw(12) << car[j].TotalMil << setw(12) << car[j].Toll << setw(12) << car[j].MaintenanceCost << setw(12) << car[j].FuelPerKm << setw(12) << car[j].SumCost << endl;
            a++;
        }
    if (a != 0)
    {
        cout << "是否进行修改?(1-是,2-否):";

        if (SelectTrue() == 1)
            edit();
    }
    else
    {
        if (i == '1')
            cout << "该车辆制造公司不存在!" << endl;
        if (i == '2')
            cout << "该编号不存在!" << endl;
        else if (i == '3')
            cout << "该类别没有车辆!" << endl;
    }
    cout << "按任意键返回功能主界面" << endl;
    char zz = getch();
    index();
}

void Management::display() //显示车辆信息库
{
    if (current != 0)
    {
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << setw(4) << "编号" << setw(12) << "车牌号" << setw(10) << "制造商" << setw(10) << "购买时间" << setw(9) << "型号" << setw(18)
             << "特性" << setw(12) << "总公里" << setw(12) << "养路费" << setw(12) << "维护费" << setw(12) << "油耗" << setw(12) << "总费用" << endl;

        for (int j = 0; j < current; j++)
        {
            cout << setw(4) << car[j].num << setw(12) << car[j].license << setw(10) << car[j].Manufacturer << setw(10) << car[j].PurchaseTime;
            if (car[j].type == 1)
                cout << setw(9) << "大客车" << setw(10) << "载客量:" << setw(8) << carrying[j];
            else if (car[j].type == 2)
                cout << setw(9) << "小轿车" << setw(10) << "车厢数:" << setw(8) << carriage[j];
            else
                cout << setw(9) << "卡 车 " << setw(10) << "载重量:" << setw(8) << load[j];
            cout << setw(12) << car[j].TotalMil << setw(12) << car[j].Toll << setw(12) << car[j].MaintenanceCost << setw(12) << car[j].FuelPerKm << setw(12) << car[j].SumCost << endl;
        }
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    }
    else
        cout << "车辆库为空!" << endl;
    cout << "按任意键返回主界面";
    char z = getch();
    index();
}

void Management::edit() //编辑功能
{
    int i, j, a = 0;
    cout << "请依次输入需要修改的车辆信息：" << endl;
    while (1)
    {
        cout << "车辆编号：";
        cin >> i;
        for (j = 0; j < current; j++)
        {
            if (car[j].num == i) //车库有此编号的车
            {
                cout << "车牌号：";
                cin >> car[j].license;
                cout << "制造公司：";
                cin >> car[j].Manufacturer;
                cout << "购买时间：";
                cin >> car[j].PurchaseTime;
                cout << "型号(1-大客车，2-小轿车，3-卡车)：";
                car[j].type = SelectTypes();
                cout << "总公里数：";
                cin >> car[j].TotalMil;
                cout << "养路费：";
                cin >> car[j].Toll;
                if (car[j].type == 1) //此时是1-大客车
                {
                    cout << "最大载客量：";
                    cin >> carrying[j];
                    car[j].MaintenanceCost = 2000;
                    car[j].FuelPerKm = 0.1;
                }
                else if (car[j].type == 2) //此时是2-小轿车
                {
                    cout << "车厢数：";
                    cin >> carriage[j];
                    car[j].MaintenanceCost = 1000;
                    car[j].FuelPerKm = 0.05;
                }
                else //此时是3-卡车
                {
                    cout << "载重量：";
                    cin >> load[j];
                    car[j].MaintenanceCost = 1500;
                    car[j].FuelPerKm = 0.15;
                }
                write();
                a++;
            }
        }
        if (a == 0)
            cout << "此编号不存在，不能进行修改，请重新输入！" << endl;
        else
        {
            cout << "修改成功！系统将返回主界面..." << endl;
            break;
        }
    }
    Sleep(1000); //延迟1秒
    index();
}

void Management::del() //////////////////删除车辆
{
    int i, j,y, a = 0;
    while (1)
    {
        if (current == 0)
        {
            cout << "车辆信息库为空！系统将返回功能界面..." << endl;
            break;
        }
        else
        {
            cout << "请输入需要删除的车辆编号：";
            cin >> i;
            cout << "确认是否删除编号为" << i << "的车辆？（1-确认，2-取消）" << endl;
            y = SelectTrue();
            if (y == 2)
                break;
            if (y == 1)
            {
                for (j = 0; j < current; j++)
                {
                    if (car[j].num == i) //车辆编号存在
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
                cout << "此编号不存在，不能进行删除，请重新输入！" << endl;
            else
            {
                cout << "删除成功！系统将返回功能界面..." << endl;
                break;
            }
        }
    }
    Sleep(1000); //延迟1秒
    index();
}

void Management::write() //车辆信息存盘
{
    ofstream write;
    write.open("d:\\a.txt", ios::out);
    if (write)
    {
        for (int i = 0; i < current; i++)
        {   //依次存入  编号   、     车牌号     、    制造商     、    购买时间      、    型号     、
            //            write<<endl;
            write << car[i].num << " " << car[i].license << " " << car[i].Manufacturer << " " << car[i].PurchaseTime << " " << car[i].type << " ";
            if (car[i].type == 1)
                write << carrying[i]; //存入   载客量
            else if (car[i].type == 2)
                write << carriage[i]; //存入    车厢数
            else
                write << load[i]; //存入    载重量
            //依次存入  总公里   、    养路费      、      维护费      、    油耗      、     总费用
            write << " " << car[i].TotalMil << " " << car[i].Toll << " " << car[i].MaintenanceCost << " " << car[i].FuelPerKm << " " << car[i].SumCost;
            write << endl;
        }
    }
    else
        cout << "write failed" << endl;
}

void Management::read() //读出车辆信息
{
    while (1)
    {
        ifstream read("d:\\a.txt", ios::in);
        if (read)
        {
            while (!read.eof())
            { //依次读取    编号   、     车牌号    、   制造商    、  购买时间    、   型号
                read >> car[current].num >> car[current].license >> car[current].Manufacturer >> car[current].PurchaseTime >> car[current].type;
                if (car[current].type == 1)
                    read >> carrying[current]; //读取   载客量
                else if (car[current].type == 2)
                    read >> carriage[current]; //读取    车厢数
                else
                    read >> load[current]; //读取    载重量
                                           //依次读取   总公里   、   养路费   、    维护费    、   油耗    、   总费用
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
         << "          !!   小组成员：             !!  !" << endl
         << "          !!    杨解瀚                !!  !" << endl
         << "          !!      柴靖                !!  !" << endl
         << "          !!       龚思远             !!  !" << endl
         << "          !!          杨风            !!  !" << endl
         << "          !!             汪琨         !!  /" << endl
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
    cout << "*           1.添 加 车 辆               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           2.查 询 车 辆               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           3.显 示 车 辆               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           4.编 辑 车 辆               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           5.删 除 车 辆               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           6.退 出 系 统               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "请输入您要使用的功能编号：" << endl;
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
        // cout<<"请输入正确的功能编号(0~6),即将跳转主界面。。。。"<<endl;
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
         << "          !!        欢迎继续使用     !!  !" << endl
         << "          !!总车辆数:" << current << "               !!  !" << endl
         << "          !!轿车数量：" << car_number << "              !!  !" << endl
         << "          !!客车数量：" << coach_number << "              !!  /" << endl
         << "          !!卡车数量：" << truck_number << "              !! /" << endl
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
    cout << "*           1.添 加 车 辆               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           2.查 询 车 辆               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           3.显 示 车 辆               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           4.编 辑 车 辆               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           5.删 除 车 辆               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "*           6.退 出 系 统               * " << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "总车辆数:" << current << "轿车数量：" << car_number << "客车数量：" << coach_number << "卡车数量：" << truck_number << endl;
    cout << "请输入您要使用的功能编号：" << endl;
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
        // cout<<"请输入正确的功能编号。"<<endl;
        // cout<<"请输入正确的功能编号(0~6),即将跳转主界面。。。。"<<endl;
        // Sleep(2000);
        // index();
        //     break ;
    }
}
void Management::come()

{
    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    cout << " ::::::::::::::::::::::|》》》:::::::::::::::::::::::::::::::" << endl;
    cout << " ::::::::::::::::::—————————————————————:::::::::::::::::::::" << endl;
    cout << " :::::::::::::::::||::::___::::::::___::\\:::::::::::::::::::" << endl;
    cout << " ::::::::::::::::||::::|##|:::::::|##|:::\\::::::::::::::::::" << endl;
    cout << " :::::::::::::::||:::::|__|:::::::|__|::::\\:::::::::::::::::" << endl;
    cout << " ::::::________========车辆管理系统=========\\________:::::::::" << endl;
    cout << " :::: |::::::::::::(ooo)::::::::::::(ooo)::::::::::::|):::::::" << endl;
    cout << " :::==|___________(ooOoo)__________(ooOoo)___________|::::::::" << endl;
    cout << " ::::::::::::::::::(ooo)::::::::::::(ooo):::::::::::::::::::::" << endl;
    cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "                   即将进入系统。。。。。                         " << endl;

    Sleep(1500);
    system("cls");
}

void Management::go()
{
    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    cout << " ::::::::::::::::::::::|》》》:::::::::::::::::::::::::::::::" << endl;
    cout << " ::::::::::::::::::—————————————————————:::::::::::::::::::::" << endl;
    cout << " :::::::::::::::::||::::___::::::::___::\\:::::::::::::::::::" << endl;
    cout << " ::::::::::::::::||::::|##|:::::::|##|:::\\::::::::::::::::::" << endl;
    cout << " :::::::::::::::||:::::|__|:::::::|__|::::\\:::::::::::::::::" << endl;
    cout << " ::::::________========车辆管理系统=========\\________:::::::::" << endl;
    cout << " :::: |::::::::::::(ooo)::::::::::::(ooo)::::::::::::|):::::::" << endl;
    cout << " :::==|___________(ooOoo)__________(ooOoo)___________|::::::::" << endl;
    cout << " ::::::::::::::::::(ooo)::::::::::::(ooo):::::::::::::::::::::" << endl;
    cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "                             欢迎再次使用                        " << endl;
    cout << "                             bye——————                          " << endl;
    Sleep(3000);
    system("cls");
}
