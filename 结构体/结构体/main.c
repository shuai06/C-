#include "jiegouti.h"

void main()
{


}



void test()
{       
		/*
		Ϊʲô��Ҫ�ṹ�壿
			Ϊ�˱�ʾһЩ���ӵ��������ͨ�����������޷�����ʵ������


		�ṹ�壺
			��һЩ����������ϵ�һ���γɵ�һ���µķ�����������


		��С��
			�ṹ�壺�ܴ�Сһ������µ��ڸ���Ա��С֮��(�Ȳ������ڴ����)
			�����壺��С���ڳ�Ա�������Ǹ���С����ͨ���ͽṹ��һ��ʹ�ã�
		

		��ζ���(�Ƽ���һ��)��
			1. �Ƽ�����ֻ�Ƕ�����һ���µ��������ͣ���û�ж��������
			 struct student{
				int num;
				char name[20];
				int age;
			 };

			2. ����ֻ�ܶ���һ��
			 struct student{
				int num;
				char name[20];
				int age;
			 } st1;

			 3. ���Ͷ�ûд...
			 struct {
				int num;
				char name[20];
				int age;
			 } st1;

			 //��ֵ�ͳ�ʼ��(����ͬʱ�������帳ֵ,������֮��ֻ�ܵ�����ֵ)
				 ����ͬʱ��ʼ���� struct student s1 = {1,'xxx',18};
				 �ȶ��壬��ֵ��
								  struct student s2;
								  s2.num=1;
								  s2.name='yyy';
								  s2.age=19;


			 //ȡ���ṹ�������ÿһ����Ա���ص㡿
				1.�ṹ��ָ�������.��Ա��
				2.ָ�������->��Ա��    ���ڶ��ָ����ã�
							struct student *p = &s;  //ע����&
							p->name; //��һ�ַ�ʽ(ָ�����->��Ա������,�ڼ�����ڲ��ᱻת��Ϊ(*ָ�������).��Ա��)
							(*p).name; //�ڶ��ַ�ʽ���� s.name; �ȼ�


			//�ṹ�����������
				�ṹ�����������ӣ������Ҳ�����໥�˳���
				���ṹ����������໥��ֵ

			//�ṹ������ͽṹ�����ָ����Ϊ�����������ݵ�����

			//��̬����ṹ������

			//����
		
		*/

		int num;

	    struct student{
			int num;
			char name[20];
			char gender;
			int age;
			float score;
			char addr[30];
		} ss={1,'xx','nan',20,99.9,'hhh'};   // ss���Ǳ��� ����ֱ���������ʼ��

		//��ֵ�ͳ�ʼ��
		struct student ss2 = {2,'yy','bei',20,99.9,'zzz'};
		struct student s = {100,'lala','M',20,99.5, 'beij'};




		// �ṹ������
		struct student sArr[3];

		for (int i = 0; i < 3; i++)
		{
			scanf("%d%s %c%d%f%s", &sArr[i].num, sArr[i].name, &sArr[i].gender, &sArr[i].age,&sArr[i].score, &sArr[i].addr); // %c ���Կո�
		}


		// �ṹ��ָ��

		struct student *p = &s;  //ע����&
		//p = &s;
		// ��ȡ��Ա

		p->name; //��һ�ַ�ʽ(ָ�����->��Ա������,�ڼ�����ڲ��ᱻת��Ϊ(*ָ�������).��Ա��)
		(*p).name; //�ڶ��ַ�ʽ���� s.name; �ȼ�

		// p->name�ĺ��壺p��ָ����Ǹ��ṹ������е�name�����Ա


		num = p->num++;   // num = p->num, num=p->num+1;   //���ȼ�
		// ��һʱ��ȥ��++
		num = p++->num;    // û����, num=p->num,  p=p+1


		//������Ĭ����C��������double�����Ҫ�����float�����ں����f��F�� ���ǲ���׼ȷ�洢

}

///////////////////////////////////////////

struct Student{
	int num;
	char name[20];
	int age;
};

// ͨ��������ɶԽṹ���������������
void struc_func()
{

	struct Student st;

	InputStudent(&st);  //�Խṹ���������
	OutputStudent(st);  //�Խṹ��������
	OutputStudent2(&st);  //�Խṹ��������


}


void InputStudent(struct Student * pstu) //pstuֻռ4���ֽ�
{
	(*pstu).num=1;
	strcpy(pstu->name, "xxx");  
	pstu->age=18;

};

/*  �����޷��ı���������ֵ��
void InputStudent(struct Student stu)
{
	stu.num=1;
	strcpy(stu.name, "xxx");  
	stu.age=18;

};*/


////Ӧ�÷������ݻ��Ǵ��͵�ַ��
//������ݵ������ݣ��ڴ����Ĵ�
void OutputStudent(struct Student stu)
{
	printf("%d, %s %d", stu.num,stu.name, stu.age);
}

// ������ݵ��ǵ�ַ�����ܲ���ȫ������������ٶȣ���ʡ���ڴ棨�Ƽ����ַ�����
void OutputStudent2(struct Student *pstu)
{
	printf("%d, %s %d", pstu->num,pstu->name, pstu->age);
}



/*
��ָ���ŵ���ܽ᣺��

���ٵĴ������ݣ��������ڴ������ ���ص㡿
ʹ��������һ�����ϵ�ֵ  ���ص㡿
��ֱ�ӷ���Ӳ��
�ܷ���Ĵ����ַ���


**/


//������
void test_union()
{
	//�����壺��С���ڳ�Ա�������Ǹ���С��ͨ���ͽṹ��һ��ʹ�ã�

	// union ������name
	// {
	//     ��Ա����
	// } ��������;

	union data{
		int i;
		char c;
		float f;
	}u1;

	// ���������ʼ��ַ��ÿ����Ա����ʼ��ַ����ͬ��
	// һ��ʱ����ֻ�ܴ�ȡһ����Ա

	union data d; // �������ľ���4
	d.i = 4;
	d.c='A';
	d.f = 99.9;


}

