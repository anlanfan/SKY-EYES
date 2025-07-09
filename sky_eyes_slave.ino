

int ty,tz,ch=1;
int chnum[8];
int p=0;
int u=0;
int p1=0;
int ty1=0;
int tz1=0;
void setup() 
{
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  while(ch<7)
  {
    chnum[ch]=1500;//将1~6通道赋值为100%(仅为了占位）
    ch++;
  }
}

void loop() 
{
  while (Serial.available())
  {                                     // 当串口接收到信息后 
    int serialData = Serial.read();  // 将接收到的信息使用read读取
   //Serial.println(serialData);
 if(serialData<200)
  {
    p1=serialData;
    //Serial.println(p1);
   p=p1%2;
   //Serial.println(p);
  if(p==0)
  {
    ty=p1;
    //Serial.println(ty);
  }
  else
  {
    tz=p1;
    //Serial.println(tz);
  }
     //Serial.println(ty);
     //Serial.println(tz);
  }
     
  
  }
  //Serial.println(ty);
  //Serial.println(tz);
  if(ty<200)
  {
   ty1=ty; 
  }
  

   if(tz<200)
  {
   tz1=tz; 
  }

  Serial.println(ty1);
  Serial.println(tz1);
  ty1=map(ty1,0,140,0,1500);//将角度数据处理为所要的高电平时间
  tz1=map(tz1,0,140,0,1500);
  ppmsig_post();
 }
  
  
  

  
 


void ppmsig_post()
{
  ch=1;
  chnum[7]=ty1;
  chnum[8]=tz1;
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
