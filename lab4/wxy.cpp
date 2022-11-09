//1.哈希表_线性探测再散列 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<iostream>
using namespace std;

#define HASHSIZE 50//定义哈希表长
#define M 19 //定义除留余数法中的质因数
#define SUCCESS 1//查找成功 
#define UNSUCCESS 0//查找失败 
#define DUPLICATE -1//表中已有与e有相同关键字的元素

typedef struct {
  char *ID;
  char *key;
  char *major;
  char *gender;
}Elemtype;
typedef struct {
  Elemtype r[HASHSIZE];
  int length;
}Hashtable;

int p;//哈希地址 

int Hash(char *k)//哈希函数 
{
	int len=strlen(k);
	int h[len];
	h[0]=0;
	for(int i=1;i<len;i++){
		h[i]=(h[i-1]*13+k[i])%50;
	}
	return h[len-1];
}

int SearchHash(Hashtable& H,char *K)//查找 
{
  printf("%d", p);
  p=Hash(K);  //求得哈希地址
  printf("%d", H.r[p].key);
  while(H.r[p].key==K&&H.r[p].key!=NULL)
  // printf("%d", K);
  // while((!strcmp(H.r[p].key,K))&&H.r[p].key!=NULL)
 	p=(p+1)%50;//线性探测再散列处理冲突 
 	if (H.r[p].key==K) return SUCCESS;//查找成功 
 	else return UNSUCCESS;//查找失败 
} 

int InsertHash(Hashtable& H,Elemtype e)//插入 
{
  // printf("%d", SearchHash(H, e.key));
  if (SearchHash(H, e.key) == SUCCESS)
    return DUPLICATE; //表中已有与e有相同关键字的元素
	H.r[p].ID=e.ID;
    H.r[p].key=e.key;
	H.r[p].major=e.major;
	H.r[p].gender=e.gender;
	++H.length; 
}

void CreateHashTable(Hashtable& H)//创建哈希表

{
	for(int i=0;i<HASHSIZE;i++) {
	H.r[i].ID=NULL;
	H.r[i].key=NULL;
	H.r[i].major=NULL;
	H.r[i].gender=NULL;
	} //初始化哈希表 
	//printf("ok");
	Elemtype e;
	//printf("ok");
	char id[13] ;
	char key[30];
	char major[30];
	char gender[30];
	strcpy(id,"19300740005");strcpy(key,"chenglibin");strcpy(major,"huanjinggongcheng");strcpy(gender,"nan");//scanf("%s",&e.key);
	e.ID= (char *) malloc(50);e.major= (char *) malloc(50);e.gender= (char *) malloc(50);e.key= (char *) malloc(50);
		e.ID=id;e.key=key;e.major=major;e.gender=gender;
	//	printf("ok");
        InsertHash(H,e);
//printf("ok");
	strcpy(id,"19302016002");strcpy(key,"jinzhiwu");strcpy(major,"huanjinggongcheng");strcpy(gender,"nan");
	e.ID= (char *) malloc(50);e.major= (char *) malloc(50);e.gender= (char *) malloc(50);e.key= (char *) malloc(50);
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e); 
	strcpy(id,"20300750093");strcpy(key,"yukexin");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nv");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"20302010022");strcpy(key,"zhangzhongwen");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"20302016002");strcpy(key,"lintin");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"20307110123");strcpy(key,"zhangyihan");strcpy(major,"wulixue");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"20307110125");strcpy(key,"chenyuhang");strcpy(major,"wulixue");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"20307110126");strcpy(key,"chenyukai");strcpy(major,"wulixue");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"20307110258");strcpy(key,"shenhaoqi");strcpy(major,"wulixue");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	/*strcpy(id,"20307110305");strcpy(key,"lisaitie");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"20307110370");strcpy(key,"huiyuyao");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nv");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"20307110388");strcpy(key,"jinzhnegting");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nv");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"20307130045");strcpy(key,"yangjiahang");strcpy(major,"guangdianxinxikexuegongcheng");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010005");strcpy(key,"herui");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan"); 
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010007");strcpy(key,"liwenhao");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010011");strcpy(key,"shenyuanzhe");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010015");strcpy(key,"tangrunze");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan"); 
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010021");strcpy(key,"zhangshengkai");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010024");strcpy(key,"zhengyingqi");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010025");strcpy(key,"zhongjiecheng");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010027");strcpy(key,"zhouyue");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010032");strcpy(key,"zhulekang");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010034");strcpy(key,"chenyanan");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010035");strcpy(key,"hongchunyu");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010038");strcpy(key,"lvlexiang");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010040");strcpy(key,"yetianyi");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010041");strcpy(key,"yexuan");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010043");strcpy(key,"younianhao");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010046");strcpy(key,"yiyang");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010047");strcpy(key,"chenguanxu");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010048");strcpy(key,"qiujunchang");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010052");strcpy(key,"yangchengqi");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010057");strcpy(key,"lijiangwei");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010058");strcpy(key,"youzheheng");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010059");strcpy(key,"xuweiqi");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010066");strcpy(key,"xuboya");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nv");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010068");strcpy(key,"libo");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nv");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010069");strcpy(key,"zhongsiqi");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nv");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010073");strcpy(key,"zouyi");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nv");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21302010077");strcpy(key,"wangjunru");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21307110081");strcpy(key,"wangxiaoyong");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21307110084");strcpy(key,"zhangwenqing");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21307110149");strcpy(key,"zhouzhiming");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21307130013");strcpy(key,"huangzixiao");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21307130286");strcpy(key,"linzhaoxiang");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nan");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
    InsertHash(H,e);
	strcpy(id,"21307130470");strcpy(key,"chenpeiyi");strcpy(major,"ruanjiangongchneg");strcpy(gender,"nv");
	e.ID=id;e.key=key;e.major=major;e.gender=gender;
	InsertHash(H,e);*/
}


int main()
{
	// char *name;
  char name[100];
  Hashtable H;
	Elemtype x;
	
	CreateHashTable(H);
	while(1)
	{
    cout << "test" << endl;
    printf("%d", *H.r[30].ID);
    printf("输入要查找的值：");
    printf("%d", *H.r[30].ID);
		scanf("%s",name);
		if(SearchHash(H,name)) printf("查找成功");
		else printf("查找失败\n");
		printf("输入要插入的值：");
		scanf("%d",&x.ID);
		scanf("%s",x.key);
		scanf("%s",x.major);
		scanf("%s",x.gender);
		InsertHash(H,x); 
	}
}

