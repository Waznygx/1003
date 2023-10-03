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
	//p1 > p2:����ֵ > 0
	//p1 = p2:����ֵ = 0
	//p1 < p2 : ����ֵ < 0
	//(int*)p1����p1ǿ��ת����int * ����
	//* (int*)p1��������p1
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
	//void bubble��voidԭ�������ð������ĳ���Ա���޷�Ԥ֪δ��Ҫ���øú�����Ҫ����ʲô���͵Ĳ���
	//int* base����ָ�롣�����void*
	//int(*cmp)(void*,void*)��cmp�Ǻ���ָ�����֣�ָ��ĺ�����int_cmp
	int i = 0;
	int j = 0;
	for ( i = 0; i < length-1; i++)
	{
		for (j = 0; j < length - i - 1; j++)
		{
			if (cmp((char*)base + j * size, (char*) base + (j + 1) * size) > 0)
			{
				//(char*)base��char����ÿ��Ԫ�ؽ��бȽϣ���һ�������Ĳ�������int����char��������int�ᵼ�����ĸ��ֽڵ�Ԫ�ز��ܱ��Ƚϣ�
				//j * size��(j + 1) * size��������һ���ֽ�
				swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
				//size��Ҫ�ܿ����ȽϵĶ������м���Ԫ��Ҫ���бȽϣ�
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
//	//arr��Ŀ��������ʼλ�ã�length�����鳤�ȣ�sizeof��int���������е�Ԫ�ش�С��int_cmp���ȽϺ����ĺ�����
//	for (i = 0; i < length; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));//sizeof(������)=int*�������=16
//	printf("%d\n", sizeof(a+0));//��Ԫ�ص�ַ=8
//	printf("%d\n", sizeof(*a));//������������Ԫ�صĴ�С=4
//	printf("%d\n", sizeof(a+1));//�ڶ���Ԫ�ص�ַ=8
//	printf("%d\n", sizeof(a[1]));//�ڶ���Ԫ�ش�С=4
//	printf("%d\n", sizeof(&a));//ȡ�����ַ=8
//	printf("%d\n", sizeof(*&a));//����=16
//	printf("%d\n", sizeof(&a+1));//��һ������ĵ�ַ=8
//	printf("%d\n", sizeof(&a[0]));//��һ��Ԫ�صĵ�ַ=8
//	printf("%d\n", sizeof(&a[0]+1));//�ڶ���Ԫ�صĵ�ַ=8
//	return 0;
//}

//#include<string.h>
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	//printf("%d\n", sizeof(arr));//����=char*Ԫ�ظ���=6
//	//printf("%d\n", sizeof(arr+0));//��Ԫ�ص�ַ+0=8
//	//printf("%d\n", sizeof(*arr));//��Ԫ�ص�ַ������=��Ԫ��=1
//	//printf("%d\n", sizeof(arr[1]));//�ڶ�������Ԫ��=1���ַ����ڴ�����AS������ʽ�洢��
//	//printf("%d\n", sizeof(&arr));//ȡ�����ַ=8
//	//printf("%d\n", sizeof(&arr+1));//��һ�������ַ=8
//	//printf("%d\n", sizeof(&arr[0] + 1));//�ڶ���Ԫ�صĵ�ַ=8
//
//	printf("%d\n", strlen(arr));//�ҵ�'\0'��ֹͣ��������û��'\0',���Խ��=�����
//	printf("%d\n", strlen(arr+0));//�������arr+0=��Ԫ�ص�ַ�������ݸ�strlen����ʱ���������Ӹõ�ַ��ʼ��������һ�����ַ�(��\0��)�ĳ��ȡ�
//	//����������£����ַ���a����ʼ���ַ���f���������ַ�������Ϊ6�������ַ���ĩβ�Ŀ��ַ����ܳ���Ϊ7��
//	//���ǣ������ڼ��㳤��ʱû�п�������Ĵ�С����˸ú����������ȡ�ڴ��е�ֵ��ֱ������һ�����ַ����߳������Ϊֹ��
//	//printf("%d\n", strlen(*arr));
//	//��Ԫ�ص�ַ������=��Ԫ��=97���ַ����ڴ����ǰ���ASC����洢��
//	//����Ὣ��97��������ַ���������飬��˳����������
//	//printf("%d\n", strlen(arr[1]));//ͬ��
//	printf("%d\n", strlen(&arr));//=arr=arr+0=�������
//	printf("%d\n", strlen(&arr+1));//��һ�������ַ��=��һ�����ֵ-6
//	printf("%d\n", strlen(&arr[0]+1));//��arr�������-1
//	//����Ӹõ�ַ��ʼ��������һ�����ַ�(��\0��)�ĳ��ȡ�
//	//����������£����ַ���b����ʼ���ַ���f���������ַ�������Ϊ5�������ַ���ĩβ�Ŀ��ַ����ܳ���Ϊ6��
//	//�����ڼ��㳤��ʱû�п�������Ĵ�С����˸ú����������ȡ�ڴ��е�ֵ��ֱ������һ�����ַ����߳������Ϊֹ��
//	return 0;
//}

//#include<string.h>
//int main()
//{
//	char arr[] = "abcdef";
//	//printf("%d\n", sizeof(arr));//������=����Ԫ�أ�'\0'=7
//	//printf("%d\n", sizeof(arr+0));//��Ԫ�ص�ַ=8
//	//printf("%d\n", sizeof(*arr));//��������Ԫ�ص�ַ=��Ԫ��=1
//	//printf("%d\n", sizeof(arr[1]));//�ڶ���Ԫ��=1
//	//printf("%d\n", sizeof(&arr));//ȡ���������ַ=8
//	//printf("%d\n", sizeof(&arr+1));//��һ�������ַ=8
//	//printf("%d\n", sizeof(&arr[0] + 1));//�ڶ���Ԫ�ص�ַ=8
//
//	printf("%d\n", strlen(arr));//Ԫ�ظ���=6
//	printf("%d\n", strlen(arr+0));//��Ԫ�ص�ַ=6
//	//�������ڼ����ַ����ĳ��ȡ������ַ����Ŀ�ͷλ�����������������ֱ������ \0 ֹͣ
//	printf("%d\n", strlen(*arr));//��Ԫ��=��97��-����
//	printf("%d\n", strlen(arr[1]));//ͬ��
//	printf("%d\n", strlen(&arr));//ȡ�����ַ=����ָ��=6
//	printf("%d\n", strlen(&arr+1));//��һ�������ַ=���ֵ
//	//&arr ��ʼ������������� \0 ֹͣ�����ҷ���\0 ǰ��ļ��������Ϊ6���ֽ�
//	printf("%d\n", strlen(&arr[0] + 1));//�ڶ���Ԫ�صĵ�ַ=5
//	return 0;
//}

//#include<string.h>
//int main()
//{
//	char* p = "abcdef";
//	printf("%d\n", sizeof(p));//ָ��=ָ����Ԫ�صĵ�ַ=8
//	printf("%d\n", sizeof(p+1));//�ڶ���Ԫ�صĵ�ַ=8
//	printf("%d\n", sizeof(*p));//�����õ�ַ=��Ԫ��=1
//	printf("%d\n", sizeof(p[0]));//��Ԫ��=1
//	printf("%d\n", sizeof(&p));//ȡָ��ĵ�ַ=8
//	printf("%d\n", sizeof(&p+1));//��һ��ָ���ַ=8
//	printf("%d\n", sizeof(&p[0] + 1));//��Ԫ�ص�ַ��һ=��ַ=8
//	//strlen���ڼ����ַ����ĳ��ȡ������ַ����Ŀ�ͷλ�����������������ֱ������ \0 ֹͣ
//	printf("%d\n", strlen(p));//��Ԫ��=6
//	printf("%d\n", strlen(p+1));//��Ԫ�ص�ַ��һ��\0=5
//	printf("%d\n", strlen(*p));//������ָ���ַ=��Ԫ��=��97��=����
//	printf("%d\n", strlen(p[0]));//��Ԫ��=��97��=����
//	printf("%d\n", strlen(&p));//&p ��һ��ָ��δ������� p ��ָ�룬����
//	printf("%d\n", strlen(&p+1));//����
//	printf("%d\n", strlen(&p[0] + 1));//�ڶ���Ԫ��=5
//	return 0;
//}

//int main()
//{
//	int a[3][4] = { 0 };
//	//0000 0000 0000 
//	//sizeof�ڲ����ʽ���������
//	printf("%d\n", sizeof(a));//�����С=Ԫ�ظ���*int=12*4=48
//	printf("%d\n", sizeof(a[0][0]));//��Ԫ��=4
//	printf("%d\n", sizeof(a[0]));//���д�С=16
//	printf("%d\n", sizeof(a[0]+1));//ָ��ָ���a[0]�����еĵڶ���Ԫ��=ָ�����ʹ�С=8
//	printf("%d\n", sizeof(*(a[0] + 1)));//�ڶ��е�һ��Ԫ��=4
//	printf("%d\n", sizeof(a + 1));//�ڶ���һά����ĵ�ַ=8
//	printf("%d\n", sizeof(&a[0] + 1));//8
//	//&a[0]��һ��ָ��a[0]�����ָ�룬���������� int (*)[4]����ˣ�&a[0] + 1ָ�� a[1]���飬�� a[1][0]��
//	//����&a[0] + 1 ��һ��ָ�룬��� sizeof(&a[0] + 1) ����ָ�����͵Ĵ�С����8�ֽ�
//	printf("%d\n", sizeof(*(a + 1)));//�����С=4*int=16
//	printf("%d\n", sizeof(*(&a[0] + 1)));//�ڶ��д�С=16
//	printf("%d\n", sizeof(*a));//��һ��=��Ԫ�ص�ַ=���д�С=16
//	printf("%d\n", sizeof(a[3]));//4��int��һά����=16
//	return 0;
//}

//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);
//	//&a+1:ȡ��һ�������ַ
//	printf("%d��%d", *(a + 1), *(ptr - 1));
//	//*(a + 1)����Ԫ�ص�ַ��һ���ڽ�����=�ڶ���Ԫ��=2
//	//*(ptr - 1)��ָ��5֮���ָ��������ƶ�һλ֮���ٽ�����=5
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

//����p=0x100000��
int main()
{
	printf("%d\n", sizeof(*p));
	//�ýṹ���С=32
	printf("%p\n", p + 0x1);
	//p���ṹ��ָ�룬ָ��+1
	printf("%p\n", (unsigned long)p + 0x1);
	//�޷��ų�����
	printf("%p\n", (unsigned int*)p + 0x1);
	return 0;
}