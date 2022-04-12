#ifndef nVehicle
#define nVehicle

#include <string>

using namespace std;  

#define N 20            //车辆最大存储量20  
#define OilPrice 7.45   //油价8元每升

class Management;
class Vehicle  
{  
private:  
    int num;                //编号 
    string license;         //车牌号   
    char Manufacturer[20];  //制造公司 
    double PurchaseTime;    //购买时间(月)
    int type;               //型号(1-大客车,2-小轿车,3-卡车)  
    double TotalMil;        //总公里数
    int MaintenanceCost;    //基本维护费用  
    int Toll;               //养路费 
    double FuelPerKm;       //耗油量/公里  
    double SumCost;         //累计总费用  
    friend class Management; 
};  

class Management
{
private:  
    Vehicle car[N];  
    int carrying[N];        //最大载客量（大客车）  
    int carriage[N];        //箱数（小轿车）  
    int load[N];            //载重量（卡车）  
    int current;            //记录当前车辆数量 
public:
    Management(){
        current = 0;
    }                       //车辆初始值为0  
    void add();             //添加车辆  
    void search();          //查询车辆  
    void display();         //显示车辆信息库  
    void edit();            //编辑功能
    void del();             //删除车辆
    void sum();             //统计信息
    void read();            //读出车辆信息  
    void write();           //车辆信息存盘  
    void index();           //总页面1
    void index1();         //总界面  
    void come();           //开始界面
    void go();            //结束界面
};

#endif