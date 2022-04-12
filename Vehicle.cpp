#ifndef nVehicle
#define nVehicle

#include <string>

using namespace std;  

#define N 20            //�������洢��20  
#define OilPrice 7.45   //�ͼ�8Ԫÿ��

class Management;
class Vehicle  
{  
private:  
    int num;                //��� 
    string license;         //���ƺ�   
    char Manufacturer[20];  //���칫˾ 
    double PurchaseTime;    //����ʱ��(��)
    int type;               //�ͺ�(1-��ͳ�,2-С�γ�,3-����)  
    double TotalMil;        //�ܹ�����
    int MaintenanceCost;    //����ά������  
    int Toll;               //��·�� 
    double FuelPerKm;       //������/����  
    double SumCost;         //�ۼ��ܷ���  
    friend class Management; 
};  

class Management
{
private:  
    Vehicle car[N];  
    int carrying[N];        //����ؿ�������ͳ���  
    int carriage[N];        //������С�γ���  
    int load[N];            //��������������  
    int current;            //��¼��ǰ�������� 
public:
    Management(){
        current = 0;
    }                       //������ʼֵΪ0  
    void add();             //��ӳ���  
    void search();          //��ѯ����  
    void display();         //��ʾ������Ϣ��  
    void edit();            //�༭����
    void del();             //ɾ������
    void sum();             //ͳ����Ϣ
    void read();            //����������Ϣ  
    void write();           //������Ϣ����  
    void index();           //��ҳ��1
    void index1();         //�ܽ���  
    void come();           //��ʼ����
    void go();            //��������
};

#endif