List all possible permutation from 12345 to 54321
Code:
//交换a,b两数 
void Swap(int &a,int &b)  
{
    int temp=a;
    a=b;
    b=temp;
}

//将数组区间转化为数字 
int getNum(int list[], int f, int r)  
{  
    int i = 0, num = 0;  
    for (i = f; i <= r; i++)   
        num = list[i] + num * 10; //进位 
    return num;  
}  

//进行全排列并对每种排列结果进行处理 
// arange the k-th to m-th number
void Prim(int list[], int k, int m)
{
    if(k==m) //前缀是最后一个位置,此时出现一种排列数. 不需要再递归
    {
        // perform your algorithm here
        printf("%d\n", getNum(list, 0, n-1));
    }
    else
    {
        for(int i=k;i<=m;i++) //全排列数组list[] 
        {
            //交换前缀,使之产生下一个前缀.
            Swap(list[k],list[i]);
            Prim(list,k+1,m);
            //将前缀换回来,继续做上一个的前缀排列.
            Swap(list[k],list[i]);
        }
    }
}



Ans to this question:




#include <stdio.h>
/*思路：将list[1,2,3,4,5,6,7,8,9]数组进行全排列，然后对于每一种排列进行处理
处理方法：将list数组划分为三部分a,b,c，判断是否满足number == a+b/c && b%c == 0; 
具体见分析......... 
*/
int x = 0, number = 0, count = 0;
 
//交换a,b两数 
void Swap(int &a,int &b)  
{
	int temp=a;
	a=b;
	b=temp;
}
//将数组区间转化为数字 
int getNum(int list[], int f, int r)  
{  
    int i = 0, num = 0;  
    for (i = f; i <= r; i++)   
        num = list[i] + num * 10; //进位 
    return num;  
}  
//进行全排列并对每种排列结果进行处理 
void Prim(int list[], int k, int m)
{
	if(k==m-1) //前缀是最后一个位置,此时出现一种排列数.
	{
		int a = 0, b = 0, c = 0, bLast = 0;   //带分数：a+b/c 
		for (int i = 0; i < x; i++)           //i表示a的末尾位置，不会超过number位数  
        {  
            a = getNum(list, 0, i);           //将list数组中的[0-i]转化为数字，赋值给a 
            bLast=((number-a)*list[8])%10;    //确定b最后一个数字   
            for (int j =i+(8-i)/2; j < 8; j++)//从list数组中间位置开始找b末尾位置 
            {                               
                if(list[j]==bLast)            //找到b尾部 
                {  
                    b = getNum(list, i+1, j); //将list数组中的[i+1-j]转化为数字，赋值给b
                    c = getNum(list, j+1, 8); //将list数组中的[j+1-8]转化为数字，赋值给c 
                    if (b % c == 0 && a + b / c == number)  //判断合理性 
					{   
					//	printf("%d+%d/%d\n",a,b,c);     //打印每种情况 
                        ++count; 
					} 
                    break;  
                }  
            }      
        }  		 
	}
	else
	{
		for(int i=k;i<m;i++)      //全排列数组list[] 
		{
			//交换前缀,使之产生下一个前缀.
			Swap(list[k],list[i]);                //>>A
			Prim(list,k+1,m);                     //>>B
			//将前缀换回来,继续做上一个的前缀排列.//>>C
			Swap(list[k],list[i]);
		}
	}
}
//主函数 
int main()
{
	int temp = 0;
	int list[] = {1,2,3,4,5,6,7,8,9};  //定义全排列数组 
	scanf("%d",&number);               
	temp = number;
	while (temp != 0)      //统计number总共多少位 
    {  
        ++x;  
        temp /= 10;  
    }  
    Prim(list,0,9);    
    printf("%d", count);   //打印总共多少种 
	return 0;
}
