#include <stdio.h>
#include <Windows.h>
#include <time.h>
int main()
{
	if (MessageBox(NULL,"测试版，功能不完善，可能存在bug\n--------------\n本程序仅供娱乐，请勿滥用。\n作者不对后果负责，点“是”即表示同意，否则请点“否”退出。","注意",MB_ICONINFORMATION|MB_YESNO)==IDNO) return 1; 
	int i;
	char name[100];
	printf("输入你要轰炸的对象名称：");
	gets (name);
	printf("输入你要轰炸的次数:");
	scanf_s("%d", &i);
	char str1[400];
	sprintf (str1,"你选择的对象是：%s\n你设置的次数为：%d\n开始前请注意：\n1.将轰炸的内容复制\n2.打开轰炸对象的聊天窗口\n点击“确定”开始。",name,i);
	MessageBox (NULL,str1,"提示",MB_OK|MB_ICONINFORMATION) ;
	HWND H=0;
	long long int judge =(long long int)FindWindow(0,name);//HWND占用8字节，如果使用int虽然不影响，但是编译器会提示warning 
	if(judge)	H=FindWindow(0,name);
	else 
	{
		int ii=1;
		char nname[120];
		judge=0;
		while (ii++<10&&(!judge))
		{
			sprintf( nname,"%s等%d个会话",name,ii);
			H=FindWindow(0,nname);
			judge=(long long int)H;	
		}	
	}
	if (judge)
	{
		clock_t t1=clock();
		while (i-- > 0)    
		{
			SendMessage(H, WM_PASTE, 0, 0);           //粘贴内容 
			SendMessage(H, WM_KEYDOWN, VK_RETURN, 0); //回车发送
		}
		clock_t t2=clock();
		double time=((double)(t2-t1))/CLOCKS_PER_SEC;
		char str2[100];
		sprintf (str2,"已完成\n用时%lf秒",time);
		MessageBox(NULL,str2,"提示",MB_OK|MB_ICONINFORMATION) ;return 0; 
	}
	else
	{
		MessageBox(NULL,"找不到窗口！","错误",MB_ICONSTOP) ;return 2; 
	}

}

