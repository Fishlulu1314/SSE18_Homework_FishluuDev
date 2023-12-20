#include <dht11.h>
#include <LiquidCrystal_I2C.h>
//#include<Wire.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);//����LCD�ĵ�ַ��2�У�ÿ��16�ַ�
dht11 DHT;
#define DHT11_PIN 4


void setup() {
    // put your setup code here, to run once:
    lcd.init();      // LCD��ʼ������
    lcd.backlight();// �� LCD����
    Serial.begin(9600);// ���ô��ڲ�����9600
    Serial.println("Type,\tstatus,\t,humidity(%),\tTemperature\t");    //���������Type, status, Humidity(%), Temperature(C)��
    
    lcd.print("Humidity(%):"); //LCD����ʾ�� Humidity(%):��
    lcd.setCursor(0, 1);  //����Ƶ���2�У���һ���ַ�
    lcd.print("Temp(C):");//LCD����ʾ��Temp(C):��
}

void loop() {
    // put your main code here, to run repeatedly:
    int chk;  //chk���ڴ洢DHT11������������
    Serial.print("DHT11, \t");
    //��ȡ DHT11������������
    chk = DHT.read(DHT11_PIN);
    switch (chk) {
    case DHTLIB_OK:
        Serial.print("OK,\t");
        break;
    case DHTLIB_ERROR_CHECKSUM:
        Serial.print("Checksum error,\t");
        break;
    case DHTLIB_ERROR_TIMEOUT:
        Serial.print("Time out error,\t");        break;
    default:
        Serial.print("Unknown error,\t");
        break;
    }
    //������ʾ��ʪ��ֵ
    Serial.print(DHT.humidity, 1);
    Serial.print(",\t");
    Serial.println(DHT.temperature, 1);
    //LCD��ʾ��ʪ��ֵ
    lcd.setCursor(12, 0);  // lcd ����ƶ�����1��ĳ��λ��
    lcd.print(DHT.humidity); // ��ӡʪ��ֵ
    lcd.setCursor(8, 1);// ��ӡ�¶�ֵ
    lcd.print(DHT.temperature);// lcd ����ƶ�����2��ĳ��λ��
    delay(1000);
}
