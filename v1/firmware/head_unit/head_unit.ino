#include "Wire.h"
#include <MPU6050_light.h>
MPU6050 mpu(Wire);
float y,z;
int ty,tz,ch=1;
int chnum[8];
int p=0;
int p1=0;
void setup() 
{
  
  Serial.begin(9600);
  Wire.begin();
  while(mpu.begin()!=0){ }
  delay(100);
  mpu.calcOffsets(); // gyro and accelero 
  delay(500);
  pinMode(2,OUTPUT);
  while(ch<7)
  {
    chnum[ch]=1500;//将1~6通道赋值为100%(仅为了占位）
    ch++;
  }
 
}

void loop() 
{
  informget();
  //ppmsig_post();
}



void informget()
{
  mpu.update();
  y=mpu.getAngleY();
  z=mpu.getAngleZ();
  y+=90;
  z+=90;
  ty=(int)y;
  tz=(int)z;
  p=ty%2;
  if(p==0)//make ty odd number 
  {
    ty=ty;
  }
  else
  {
    ty=ty+1;
  }
  Serial.write(ty);
  delay(8);
  p1=tz%2;
  if(p1==0) //make tz even number
  {
    tz=tz+1;
  }
  else
  {
    tz=tz;
  }
  Serial.write(tz);
  delay(8);

  
  ty=map(ty,0,180,0,1500);//将角度数据处理为所要的高电平时间
  tz=map(tz,0,180,0,1500);
}

void ppmsig_post()
{
  ch=1;
  chnum[7]=ty;
  chnum[8]=tz;
  while(ch<=8)
  {
    digitalWrite(2,LOW);
    delayMicroseconds(500);
    digitalWrite(2,HIGH);
    delayMicroseconds(chnum[ch]);
    ch++;
  }
  digitalWrite(2,LOW);
  delayMicroseconds(500);
  digitalWrite(2,HIGH);
  delayMicroseconds(20000-500*9-1500*6-chnum[7]-chnum[8]);  
}
