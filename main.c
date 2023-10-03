#include<stdio.h>

//#include<stdlib.h>
//int int_cmp(const void* p1,const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);
//}
//int main()
//{
//	int arr[] = { 6,8,12,5,2,46,9,4,23,55,7,99 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	qsort(arr,length,sizeof(int),int_cmp);
//	for (i = 0; i < length; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

int int_cmp(const void* p1, const void* p2)
{
	return (*(int*)p1 - *(int*)p2);
	//p1 > p2:返回值 > 0
	//p1 = p2:返回值 = 0
	//p1 < p2 : 返回值 < 0
	//(int*)p1：将p1强制转换成int * 类型
	//* (int*)p1：解引用p1
}
void swap(char* p1,char* p2,int size)
{
	int i = 0;
	for ( i = 0; i < size; i++)
	{
		char temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		p1++;
		p2++;
	}
}
void bubble(int* base,int length, int size,int(*cmp)(void*,void*))
{
	//void bubble：void原因是设计冒泡排序的程序员是无法预知未来要调用该函数是要排序什么类型的参数
	//int* base：传指针。最好是void*
	//int(*cmp)(void*,void*)：cmp是函数指针名字，指向的函数是int_cmp
	int i = 0;
	int j = 0;
	for ( i = 0; i < length-1; i++)
	{
		for (j = 0; j < length - i - 1; j++)
		{
			if (cmp((char*)base + j * size, (char*) base + (j + 1) * size) > 0)
			{
				//(char*)base：char：让每个元素进行比较（万一将来传的参数不是int而是char，这里用int会导致有四个字节的元素不能被比较）
				//j * size，(j + 1) * size，跳过下一个字节
				swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
				//size：要能看到比较的对数（有几对元素要进行比较）
			}
		}
	}
}
//#include<stdlib.h>
//int main()
//{
//	int arr[] = { 1,4,5,2,6,11,35,22,86,24,78,91,13 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	bubble(arr, length, sizeof(int), int_cmp);
//	//arr：目标数组起始位置，length：数组长度，sizeof（int）：数组中的元素大小，int_cmp：比较函数的函数名
//	for (i = 0; i < length; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));//sizeof(数组名)=int*数组个数=16
//	printf("%d\n", sizeof(a+0));//首元素地址=8
//	printf("%d\n", sizeof(*a));//解引用数组首元素的大小=4
//	printf("%d\n", sizeof(a+1));//第二个元素地址=8
//	printf("%d\n", sizeof(a[1]));//第二个元素大小=4
//	printf("%d\n", sizeof(&a));//取数组地址=8
//	printf("%d\n", sizeof(*&a));//数组=16
//	printf("%d\n", sizeof(&a+1));//下一个数组的地址=8
//	printf("%d\n", sizeof(&a[0]));//第一个元素的地址=8
//	printf("%d\n", sizeof(&a[0]+1));//第二个元素的地址=8
//	return 0;
//}

//#include<string.h>
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	//printf("%d\n", sizeof(arr));//数组=char*元素个数=6
//	//printf("%d\n", sizeof(arr+0));//首元素地址+0=8
//	//printf("%d\n", sizeof(*arr));//首元素地址解引用=首元素=1
//	//printf("%d\n", sizeof(arr[1]));//第二个数组元素=1（字符在内存是以ASⅡ码形式存储）
//	//printf("%d\n", sizeof(&arr));//取数组地址=8
//	//printf("%d\n", sizeof(&arr+1));//下一个数组地址=8
//	//printf("%d\n", sizeof(&arr[0] + 1));//第二个元素的地址=8
//
//	printf("%d\n", strlen(arr));//找到'\0'则停止计数，但没有'\0',所以结果=随机数
//	printf("%d\n", strlen(arr+0));//随机数。arr+0=首元素地址，当传递给strlen函数时，它会计算从该地址开始到遇到第一个空字符(‘\0’)的长度。
//	//在这种情况下，从字符’a’开始到字符’f’结束的字符串长度为6，加上字符串末尾的空字符，总长度为7。
//	//但是，由于在计算长度时没有考虑数组的大小，因此该函数会继续读取内存中的值，直到遇到一个空字符或者程序崩溃为止。
//	//printf("%d\n", strlen(*arr));
//	//首元素地址解引用=首元素=97（字符在内存中是按照ASCⅡ码存储）
//	//程序会将“97”当做地址来访问数组，因此程序崩溃报错
//	//printf("%d\n", strlen(arr[1]));//同上
//	printf("%d\n", strlen(&arr));//=arr=arr+0=随机数。
//	printf("%d\n", strlen(&arr+1));//下一个数组地址，=上一个随机值-6
//	printf("%d\n", strlen(&arr[0]+1));//比arr的随机数-1
//	//计算从该地址开始到遇到第一个空字符(‘\0’)的长度。
//	//在这种情况下，从字符’b’开始到字符’f’结束的字符串长度为5，加上字符串末尾的空字符，总长度为6。
//	//由于在计算长度时没有考虑数组的大小，因此该函数会继续读取内存中的值，直到遇到一个空字符或者程序崩溃为止。
//	return 0;
//}

//#include<string.h>
//int main()
//{
//	char arr[] = "abcdef";
//	//printf("%d\n", sizeof(arr));//数组名=数组元素＋'\0'=7
//	//printf("%d\n", sizeof(arr+0));//首元素地址=8
//	//printf("%d\n", sizeof(*arr));//解引用首元素地址=首元素=1
//	//printf("%d\n", sizeof(arr[1]));//第二个元素=1
//	//printf("%d\n", sizeof(&arr));//取整个数组地址=8
//	//printf("%d\n", sizeof(&arr+1));//下一个数组地址=8
//	//printf("%d\n", sizeof(&arr[0] + 1));//第二个元素地址=8
//
//	printf("%d\n", strlen(arr));//元素个数=6
//	printf("%d\n", strlen(arr+0));//首元素地址=6
//	//函数用于计算字符串的长度。它从字符串的开头位置依次往后面计数，直到遇到 \0 停止
//	printf("%d\n", strlen(*arr));//首元素=“97”-报错
//	printf("%d\n", strlen(arr[1]));//同上
//	printf("%d\n", strlen(&arr));//取数组地址=数组指针=6
//	printf("%d\n", strlen(&arr+1));//下一个数组地址=随机值
//	//&arr 开始往后计数，遇到 \0 停止，并且返回\0 前面的计数，因此为6个字节
//	printf("%d\n", strlen(&arr[0] + 1));//第二个元素的地址=5
//	return 0;
//}

//#include<string.h>
//int main()
//{
//	char* p = "abcdef";
//	printf("%d\n", sizeof(p));//指针=指向首元素的地址=8
//	printf("%d\n", sizeof(p+1));//第二个元素的地址=8
//	printf("%d\n", sizeof(*p));//解引用地址=首元素=1
//	printf("%d\n", sizeof(p[0]));//首元素=1
//	printf("%d\n", sizeof(&p));//取指针的地址=8
//	printf("%d\n", sizeof(&p+1));//下一个指针地址=8
//	printf("%d\n", sizeof(&p[0] + 1));//首元素地址加一=地址=8
//	//strlen用于计算字符串的长度。它从字符串的开头位置依次往后面计数，直到遇到 \0 停止
//	printf("%d\n", strlen(p));//总元素=6
//	printf("%d\n", strlen(p+1));//首元素地址加一到\0=5
//	printf("%d\n", strlen(*p));//解引用指针地址=首元素=“97”=报错
//	printf("%d\n", strlen(p[0]));//首元素=“97”=报错
//	printf("%d\n", strlen(&p));//&p 是一个指向未定义变量 p 的指针，报错
//	printf("%d\n", strlen(&p+1));//报错
//	printf("%d\n", strlen(&p[0] + 1));//第二个元素=5
//	return 0;
//}

//int main()
//{
//	int a[3][4] = { 0 };
//	//0000 0000 0000 
//	//sizeof内部表达式不参与计算
//	printf("%d\n", sizeof(a));//数组大小=元素个数*int=12*4=48
//	printf("%d\n", sizeof(a[0][0]));//首元素=4
//	printf("%d\n", sizeof(a[0]));//首行大小=16
//	printf("%d\n", sizeof(a[0]+1));//指针指向的a[0]数组中的第二个元素=指针类型大小=8
//	printf("%d\n", sizeof(*(a[0] + 1)));//第二行第一个元素=4
//	printf("%d\n", sizeof(a + 1));//第二行一维数组的地址=8
//	printf("%d\n", sizeof(&a[0] + 1));//8
//	//&a[0]是一个指向a[0]数组的指针，它的类型是 int (*)[4]。因此，&a[0] + 1指向 a[1]数组，即 a[1][0]。
//	//由于&a[0] + 1 是一个指针，因此 sizeof(&a[0] + 1) 返回指针类型的大小，即8字节
//	printf("%d\n", sizeof(*(a + 1)));//数组大小=4*int=16
//	printf("%d\n", sizeof(*(&a[0] + 1)));//第二行大小=16
//	printf("%d\n", sizeof(*a));//第一行=首元素地址=该行大小=16
//	printf("%d\n", sizeof(a[3]));//4个int的一维数组=16
//	return 0;
//}

//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);
//	//&a+1:取下一个数组地址
//	printf("%d，%d", *(a + 1), *(ptr - 1));
//	//*(a + 1)：首元素地址加一，在解引用=第二个元素=2
//	//*(ptr - 1)：指向5之后的指针往左边移动一位之后再解引用=5
//	return 0;
//}


//#include <stdio.h>
//#include <stddef.h>
//#pragma (8)
//struct MyStruct
//{
//	int num;
//	char* pcname;
//	short sdate;
//	char cha[2];
//	short sba[4];
//}*p;
//#pragma ()
//int main()
//{
//	printf("num: %ld\n", (long)&(p->num) - (long)p);
//	printf("pcname: %ld\n", (long)&(p->pcname) - (long)p);
//	printf("sdate: %ld\n", (long)&(p->sdate) - (long)p);
//	printf("cha: %ld\n", (long)&(p->cha) - (long)p);
//	printf("sba: %ld\n", (long)&(p->sba) - (long)p);
//
//	return 0;
//}

//#define MY_OFFSRTOF(struct_name,member_name) (int)&(((struct_name*)0)->member_name)
//typedef struct MyStruct
//{
//	int num;
//	char* pcname;
//	short sdate;
//	char cha[2];
//	short sba[4];
//}*p,s;
//int main()
//{
//	printf("%d\n", MY_OFFSRTOF(s, num));
//	printf("%d\n", MY_OFFSRTOF(s, pcname));
//	printf("%d\n", MY_OFFSRTOF(s, cha[2]));
//	printf("%d\n", MY_OFFSRTOF(s, sba[4]));
//	return 0;
//}
struct MyStruct
{
	int num; 
	char* pcname;
	short sdate;
	char cha[2];
	short sba[4];
}*p;

//假设p=0x100000，
int main()
{
	printf("%d\n", sizeof(*p));
	//该结构体大小=32
	printf("%p\n", p + 0x1);
	//p：结构体指针，指针+1
	printf("%p\n", (unsigned long)p + 0x1);
	//无符号长整型
	printf("%p\n", (unsigned int*)p + 0x1);
	return 0;
}