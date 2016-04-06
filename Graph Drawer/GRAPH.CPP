 #include<iostream.h>
 #include<process.h>
 #include<graphics.h>
 #include<stdio.h>
 #include<conio.h>
 #include<dos.h>
 #include<math.h>
 #include<string.h>
 # define MAX 50
 # define NULL 0
 #define dx ( 0.0001 )
    struct NODE
    {
    int code;
    long double value;
    }arr[30],nay[30],stack[30],tann[30],bak[30];
	struct NODE2
    {
    int code;
    long double value;
    }stack2[30],arr2[3][20];
	int top=-1,top2=-1;
	
	/////////////////////////////SLR PARSING TABLE 50+ ARE SHIFT 100+ ARE REDUCE//////////////////////////
	/////////////////0   1 2 3 4 5 6 7  8 9 10  11 12 13 14 1516171819
	int SLR[23][20]={54,55,0,0,0,0,0,0,57,58,59,60,61,62,56,0,1,2,3,0,//////////0
					 0,0,90,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//////////////////1
					 0,0,102,64,65,66,67,68,0,0,0,0,0,0,0,0,0,0,0,13,///////////2
					 54,55,0,0,0,0,0,0,57,58,59,60,61,62,56,0,0,19,3,0,/////////3
					 0,0,106,106,106,106,106,106,0,0,0,0,0,0,0,106,0,0,0,0,///////4
					 0,0,107,107,107,107,107,107,0,0,0,0,0,0,0,107,0,0,0,0,///////5
					 54,55,0,0,0,0,0,0,57,58,59,60,61,62,56,0,0,20,3,0,//////////6
					 113,113,0,0,0,0,0,0,113,113,113,113,113,113,113,0,0,0,0,0,//7
					 114,114,0,0,0,0,0,0,114,114,114,114,114,114,114,0,0,0,0,0,//8
					 115,115,0,0,0,0,0,0,115,115,115,115,115,115,115,0,0,0,0,0,//9
					 116,116,0,0,0,0,0,0,116,116,116,116,116,116,116,0,0,0,0,0,//10
					 117,117,0,0,0,0,0,0,117,117,117,117,117,117,117,0,0,0,0,0,//11
					 118,118,0,0,0,0,0,0,118,118,118,118,118,118,118,0,0,0,0,0,//12
					 54,55,0,0,0,0,0,0,57,58,59,60,61,62,56,0,0,21,3,0,//////////13
					 108,108,0,0,0,0,0,0,108,108,108,108,108,108,108,0,0,0,0,0,//14
					 109,109,0,0,0,0,0,0,109,109,109,109,109,109,109,0,0,0,0,0,//15
					 110,110,0,0,0,0,0,0,110,110,110,110,110,110,110,0,0,0,0,0,//16
					 111,111,0,0,0,0,0,0,111,111,111,111,111,111,111,0,0,0,0,0,//17
					 112,112,0,0,0,0,0,0,112,112,112,112,112,112,112,0,0,0,0,0,//18
					 0,0,104,64,65,66,67,68,0,0,0,0,0,0,0,104,0,0,13,0,////////////19
					 0,0,0,64,65,66,67,68,0,0,0,0,0,0,0,72,0,0,13,0,/////////////20
					 0,0,103,103,103,103,103,103,0,0,0,0,0,0,0,103,0,0,13,0,///////////21
					 0,0,105,105,105,105,105,105,0,0,0,0,0,0,0,105,0,0,0,0};///////////22
	///////////////////////PRODUCTION RULES///////////
	int PROD[18][2]={5,1,			//0//////////S'-->S
					 1,1,			//1//////////S-->P
					 2,3,			//2//////////P-->POP
					 2,2,			//3//////////P-->FP
					 2,3,			//4//////////P-->(P)
					 2,1,			//5//////////P-->x
					 2,1,			//6//////////P-->n
					 3,1,			//7//////////O-->+
					 3,1,			//8//////////O-->-
					 3,1,			//9//////////O-->*
					 3,1,			//10//////////O-->/
					 3,1,			//11//////////O-->^
					 4,1,			//12//////////F-->s(sin)
					 4,1,			//13//////////F-->c(cos)
					 4,1,			//14//////////F-->t(tan)
					 4,1,			//15//////////F-->l(log)
					 4,1,			//16//////////F-->i(int)
					 4,1};			//17//////////F-->m(mod)
	class fileop
	{
	public:
	int posi;
	char ch,exps[30];
	FILE *fp,*ft;
	char showfile();
	void returnarray();
	int searchposition(char);
	};
	class graph
	{
	int index,start,end,inny;
    char exp[30];
	int num,lab,A,B,C,iA,iB,iC;
	public:
	int pub;
	NODE grtst;
	void init();
	void input();
	void input2(fileop);
	int inspect();
	int definenode(NODE);
	void start_automata();
	void install(int ,int );
	int distractint(int ,int );
	void printexp(int);
	void topostfix(int);
	void push(NODE);
	NODE pop();
	int popntimeskaro(int);
	NODE stacktop();
	NODE makenode(int,int);
	long double calculate_value(float);
	void push2(int,float);
	NODE2 pop2();
	NODE2 stacktop2();
	void printnodearray(int);
	void creategraph(int);
	void createfor2var();
	void inputforfactor();
	int generateprime();
	char primefactor(int);
	long double shadearea(float,float);
	void clear();
	void produceABC();
	void copycont(int,int,int,int,NODE);
	int findwhatinthere(int,int);
	void chalbhai();
	void diffrentiate();
	void backup(int);
	NODE mknode(int ,long double);
	};
	void graph::backup(int mn)
	{
		if(mn==1)
		{
		for(int l=0;l<30;l++)
		bak[l]=arr[l];
		}
		if(mn==2)
		{
		for(int l=0;l<30;l++)
		arr[l]=bak[l];
		}
	}
	void graph::diffrentiate()
	{

		float x,y,u,v;
	double i,p,q;
		long double xx=0;

		int x1=getmaxx();
		int y1=getmaxy();

		gotoxy(34,25);
		cout<<"\n       Enter any x-axis co-ordinate to draw tangent::";
		///outtextxy(x1/12,16*y1/20+20,"Enter any x-axis co-ordinate::");
		cin>>xx;
		backup(1);
		long double yy=calculate_value(xx);

		long double diff=calculate_value(xx+dx)-yy;//calculate_value(xx);
		diff=diff/dx;
		arr[0]=mknode(2,diff);
		arr[1]=mknode(1,1);
		arr[2]=mknode(2,xx);
		arr[3]=mknode(3,2);
		arr[4]=mknode(3,3);
		arr[5]=mknode(2,yy);
		arr[6]=mknode(3,1);
		index=7;
		//printexp(index);


	//setbkcolor(6);

	x=float(x1);y=float(y1);
	u=8.5*y/20;
		v=x/2;
	p=u-8*yy;
	q=u-8*calculate_value(-xx);
	setcolor(YELLOW);
	setlinestyle(DOTTED_LINE, 1, 1);
	line(x/2+8*xx,8.5*y/20,x/2+8*xx,p);
	line(x/2,p,x/2+8*xx,p);
	for(i=0.01;i<=11*x/12;i+=0.001)
	{
		p=u-8*calculate_value(i);
		q=u-8*calculate_value(-i);
		if((p>=y/20&&p<=16*y/20)&&(8*i+v<11*x/12))
			putpixel(8*i+v,p,RED);
		if((q>=y/20&&q<=16*y/20)&&(v-8*i>x/12))
			putpixel(v-8*i,q,RED);

	}

	setcolor(WHITE);
	}
	NODE graph :: mknode(int codec,long double values)
	{
	NODE nd;
	nd.code=codec;
	nd.value=values;
	return nd;
	}
	///////////////////////////////INITIALIZING DATA STRUCTURE/////////////////////////
	void graph::init()
	{
	for(int l=0;l<20;l++)
	{
	arr[l].code=0;arr[l].value=0;
	nay[l].code=0;nay[l].value=0;
	stack[l].code=0;stack[l].value=0;
	stack2[l].code=0;stack2[l].value=0;
	//arr2[l].code=0;arr2[l].value=0;
	}
	top=-1,top2=-1;
	start=0;end=0;index=0; pub=0;
	A=0;B=0;C=0;iA=0;iB=0;iC=0;
	}
	/////////////////////////INPUT OF THE FUNCTION/////////////////
	void graph :: input()
	{    int i;
	init();
	cout<<"\n Enter the expression  ";
       //	for (i=0;((exp[i]=getchar())!='\n');i++);
	 gets(exp);
	}
	//////////////////////////////INPUT THROUGH FILE/////////////////
	void graph :: input2(fileop fd)
	{    //int i=0;
	char nm;
	init();
	cleardevice();
	gotoxy(1,1);
	cout<<"\n You chose the expression = ";
	puts(fd.exps);
       /*	nm=fd.exps[i];
	for (i=1;i<fd.posi;i++)
	 {
	 exp[i]=nm;
	 nm=fd.exps[i];
	 if(nm=='\0')
	 break;
	 } */
	 strcpy(exp,fd.exps);

	}
	///////////////////CHECK THE INPUT FUNCTION IS SYNTACTICALLY CORRECT OR NOT///////////////////////////
	int graph :: inspect()
	{
	int valu,indi=index;
	NODE comp1,comp2;
	arr[indi].code=10;
	arr[indi].value=1;
	push(makenode(8,0));
	for (int h=0;h<=indi;h++)
		{
		valu=SLR[stacktop().value][definenode(arr[h])];
		if(valu==90)
			return 1;
		if(valu==0)
			return 0;
		if(valu>=50&&valu<100)
			{
			push(arr[h]);
			push(makenode(8,valu-50));
			}
		if(valu>=100)
			{
			popntimeskaro(PROD[valu-101][1]);
			comp1=stacktop();
			comp2=makenode(9,PROD[valu-101][0]);
			push(comp2);
			push(makenode(8,SLR[comp1.value][definenode(comp2)]));
			h-=1;
			}
		}
	}
	///////////////////////////////////////RETURNING INDEX FOR SLR PARSING TABLE///////////////////////////
	int graph::definenode(NODE sent)
	{
	if(sent.code==1&&sent.value==1)
			return 0;
		//if(sent.code==1&&sent.value==2)
			//printf("y");
		if(sent.code==2)
			return 1;
		if(sent.code==10)
			return 2;	
		if(sent.code==3)
			{
				if(sent.value==1)
					return 3;
				if(sent.value==2)
					return 4;
				if(sent.value==3)
					return 5;
				if(sent.value==4)
					return 6;
				if(sent.value==5)
					return 7;

			}
		if(sent.code==4)
			{
			 if(sent.value==1)
					return 14;
			 if(sent.value==2)
					return 15;
			
			}
		if(sent.code==5)
			{
			if(sent.value==1)
					return 8;
			if(sent.value==2)
					return 9;
			if(sent.value==3)
					return 10;
			if(sent.value==4)
					return 11;
			if(sent.value==5)
					return 12;
			if(sent.value==7)
					return 13;
			}		
		if(sent.code==9)
			{
			 if(sent.value==1)
					return 16;
			 if(sent.value==2)
					return 17;
			 if(sent.value==3)
					return 18;
			 if(sent.value==4)
					return 19;
			
			}
	}
	/////////////////////////////////TO POP N TIMES WHERE N IS AN INTEGER////////////////////
	int graph :: popntimeskaro(int k)
	{
		int d=2*k;
		NODE po;
		while(d!=0)
		{
		po=pop();
		d-=1;
		}
	}
	////////////////////////////////FUNCTION TO CREATE A NODE WITH ITS CONSTITUENT INTEGERS//////////
	NODE graph::makenode(int cod,int val)
	{
		NODE made;
		made.code=cod;
		made.value=val;
		return made;
	}
	/////////////////////////FINITE AUTOMATA TO EXTRACT TOKENS FORM THE FUNCTION/////////////////
	void graph :: start_automata()
	{
	 start=0;end=0;index=0;
	q0:
				if(exp[end]=='\0'||exp[end]=='\n')
					goto kh;
				if(exp[end]>='0'&&exp[end]<='9')
									{ goto q1;}
				if(exp[end]=='x')
								{
									install(1,1);
									end+=1;start=end;goto q0;
								}
				if(exp[end]=='y')
								{
									install(1,2);
									end+=1;start=end;pub=1;goto q0;
								}

				if(exp[end]=='s'||exp[end]=='c'||exp[end]=='t'||exp[end]=='l'||exp[end]=='i'||exp[end]=='g'||exp[end]=='m')
								{
									goto tri;
								}
				if(exp[end]=='+')
					{install(3,1);}
				if(exp[end]=='-')
					{install(3,2);}
				if(exp[end]=='*')
					{install(3,3);}
				if(exp[end]=='/')
					{install(3,4);}
				if(exp[end]=='^')
					{install(3,5);}
				if(exp[end]=='('||exp[end]=='{')
					{install(4,1);}
				if(exp[end]==')'||exp[end]=='}')
					{install(4,2);}
				if(exp[end]=='|')
					{install(4,3);}
				if(exp[end]=='[')
					{install(4,4);}
				if(exp[end]==']')
					{install(4,5);}
				end+=1;start=end;
				goto q0;

	q1:
				if(exp[end+1]>='0'&&exp[end+1]<='9')
						{end=end+1;goto q1;}
				else
				{
						install(2,distractint(start,end));
						end+=1;start=end;
						goto q0;

				}
	tri:
				if(exp[end]=='s'&&exp[end+1]=='i'&&exp[end+2]=='n')
								{
									install(5,1);
									end+=3;start=end;goto q0;
								}
				if(exp[end]=='l'&&exp[end+1]=='o'&&exp[end+2]=='g')
								{
									install(5,4);
									end+=3;start=end;goto q0;
								}
				if(exp[end]=='c'&&exp[end+1]=='o'&&exp[end+2]=='s')
								{
									install(5,2);
									end+=3;start=end;goto q0;

								}
				if(exp[end]=='t'&&exp[end+1]=='a'&&exp[end+2]=='n')
								{       install(5,3);
									end+=3;start=end;goto q0;
								}
				if(exp[end]=='i'&&exp[end+1]=='n'&&exp[end+2]=='t')
								{       install(5,5);
									end+=3;start=end;goto q0;
								}
				if(exp[end]=='g'&&exp[end+1]=='r'&&exp[end+2]=='t')
								{       install(5,6);
									end+=3;start=end;goto q0;
								}
				if(exp[end]=='m'&&exp[end+1]=='o'&&exp[end+2]=='d')
								{       install(5,7);
									end+=3;start=end;goto q0;
								}

    kh:
				printf("\n Analysis Done..........  ");
				printexp(index);
				cout<<endl;
				if(inspect()==1)
				{
					cout<<"\n\n Parsing was successful..";
				}
				else
				{
					pub=2;
					cout<<"\n Parsing ended with an error..";
					cout<<"\n\n Check out the following point...";
					cout<<"\n\n	a)Barces are balanced or not.";
					cout<<"\n\n	b)There is no spelling mistake";
					cout<<"\n\n	c)Operetor sequence is correct.";
				}
				//printnodearray(index);
				if(pub!=1&&pub!=2)
				{
				printf("\n\n Converted to POSTFIX ..  ");
				topostfix(index);
				}
				//printf("\n\n VALUE to POSTFIX ..  \n");
				//printnodearray(index);
				//for(float e=1;e<=0.1;e++)
				//cout<<"\n\t"<<calculate_value(e);
	}
	//////////////////////INSTALLS CODES AND VALUE FOR EACH TOKEN////////////////////
	void graph :: install(int code1,int value1)
	{

		arr[index].code=code1;
		arr[index].value=value1;
		index+=1;

	}
	/////////////////////////EXTRACTS INTEGER FROM THE GIVEN CHARACTER STREAM/////////////////
	int graph :: distractint(int start1,int end1)
	{
	int m,n,num=0,o;
	m=end1-start1+1;
	//cout<<"\n\t"<<m<<"\t"<<int(exp[start1])-48<<"\t"<<int(exp[end1])-48;
	n=m;
	while(m!=0)
		{ o=int(exp[end1])-48;
		num+=o*pow(10,(n-m));
		//cout<<"\n\tO="<<o<<"\tnum="<<num;
		end1=end1-1;
		m=m-1;
		}
		n++;
		//cout<<"\n\tnum="<<num;
	return num;
	}
	/////////////////////////PRINTS THE TOKEN FORM THE FUNCTION/////////////////
	void graph :: printexp(int last1)
	{
	int p=0;
	for(p=0;p<=last1;p++)
	{
		if(arr[p].code==1&&arr[p].value==1)
			printf("x");
		if(arr[p].code==1&&arr[p].value==2)
			printf("y");
		if(arr[p].code==2)
			cout<<arr[p].value;
		if(arr[p].code==3)
			{
				if(arr[p].value==1)
					printf("+");
				if(arr[p].value==2)
					printf("-");
				if(arr[p].value==3)
					printf("*");
				if(arr[p].value==4)
					printf("/");
				if(arr[p].value==5)
					printf("^");

			}
		if(arr[p].code==4)
			{
			 if(arr[p].value==1)
					printf("(");
			 if(arr[p].value==2)
					printf(")");
			 if(arr[p].value==3)
					printf("|");
			 if(arr[p].value==4)
					printf("[");
			 if(arr[p].value==5)
					printf("]");
			}
		if(arr[p].code==5)
			{
			if(arr[p].value==1)
					printf("sin");
			if(arr[p].value==2)
					printf("cos");
			if(arr[p].value==3)
					printf("tan");
			if(arr[p].value==4)
					printf("log");
			if(arr[p].value==5)
					printf("int");
			if(arr[p].value==6)
					printf("grt");
			if(arr[p].value==7)
					printf("mod");
			}
	printf(" ");
	}
	}
	/////////////////////////CONVERTS POSTFIX FORM GIVEN FUNCTION/////////////////cout<<"yipps";
	void graph :: topostfix(int last1)
	{
	int p=0;
	NODE q,o;
	inny=0;
	for (p=0;p<=last1;p++)
	{
	if(arr[p].code==1||arr[p].code==2)
		{ nay[inny]=arr[p];
		//nay[inny].code=arr[p].code;
		//nay[inny].value=arr[p].value;
		inny++;
		}
	if(arr[p].code==4&&(arr[p].value==1||arr[p].value==2))
		{
			if(arr[p].value==1)
			push(arr[p]);
			else if(arr[p].value==2)
			{
				q=pop();//stacktop();
				while(q.code!=4&&q.value!=1)
				{
				nay[inny]=q;//pop();
				inny++;
				q=pop();//stacktop();
				}
			//o=pop();

			//cout <<pop().value;
			}

		}
	if(arr[p].code==4&&(arr[p].value==4||arr[p].value==5))
		{
		if(arr[p].value==4)
			{cout<<"yippsiiii";
			push(arr[p]);
			}
		else if(arr[p].value==5)
			{cout<<"yippsoooo";
			q=pop();//stacktop();
				while(q.code!=4&&q.value!=4)
				{cout<<"yippsoppp";
				nay[inny]=q;//pop();
				inny++;
				q=pop();//stacktop();
				}
			}
		}
	if(arr[p].code==3)
		{
		q=stacktop();
		if(q.code==5)
			{
			    while(q.code==5)
			    {
				nay[inny]=pop();
				inny++;
				q=stacktop();
			    }
			push(arr[p]);
			}
		else
		    {
			while(q.value>arr[p].value)
					{
					nay[inny]=pop();
					inny++;
					q=stacktop();
					}
			push(arr[p]);
		    }
		}
	if(arr[p].code==5)
		{
		push(arr[p]);
		inny++;
		}
	}
	while(top!=-1)
	{
		nay[inny]=pop();
		inny++;
	}
	for (p=0;p<inny;p++)
		{
		arr[p]=nay[p];
		}
	printexp(inny-1);

	//printnodearray(inny-1);
	}
	/////////////////////////PRINTS ENCODED FORM OF THE FUNCTION/////////////////
	void graph::printnodearray(int p)
	{
	for(int y2=0;y2<=p;y2++)
	cout<<" "<<y2;
	cout<<"\n";

	for(y2=0;y2<=p;y2++)
	cout<<" "<<arr[y2].code;
	cout<<"\n";
	for(y2=0;y2<=p;y2++)
	cout<<" "<<arr[y2].value;
	}
	/////////////////////////STACK OPERATIONS STARTS HERE/////////////////
	NODE graph :: stacktop()
	{
	return stack[top];
	}
	void graph :: push(NODE w)
	{
	top++;
	stack[top].code=w.code;
	stack[top].value=w.value;
	}
	NODE graph :: pop()
	{
	top--;
	return stack[top+1];
	}
	NODE2 graph :: stacktop2()
	{
	return stack2[top2];
	}
	void graph :: push2(int w,float e)
	{
	top2++;
	stack2[top2].code=w;
	stack2[top2].value=e;
	}
	NODE2 graph :: pop2()
	{
	top2--;
	return stack2[top2+1];
	}

	/////////////////////////STACK OPERATIONS ENDS HERE/////////////////
	/////////////////////////////PRIME FACTOR CALCULATION STARTS HERE////////////////
	void graph :: inputforfactor()///////////////INPUT NUMBER//////////
	{
	num=0;lab=1;
	cout<<"\n Enter the number";
	cin>>num;
	}
	int graph :: generateprime()////////////////GENERATE A PRIME NUMBER/////////
	{
	int i,k,tk;
	carry:
	tk=0 ;
	for(i=lab+1;i<=num;i++)
	{
		for(k=2;k<i;k++)
		{
			if(i==k)
			{
			tk=1;
			break;
			}
			if(i%k==0)
			{
			tk=0;
			break;
			}
		}
		if(tk==1)
			{
			lab=i;
			break;
			}
	}
	if(primefactor(lab)=='>')
		{
		goto carry;
		}
	else if(primefactor(lab)=='#')
		return 1;
	}
	char graph :: primefactor(int p)/////////////////CALCULATE PRIME FACTOR///////////////
	{
	if(num==p)
	{
	return '#';
	}
	q:
	if(num%p==0)
		{
		num=num/p;
		cout<<p<<"X";
		goto q;
		}
	else
	{
	return '>';
	}
	}



	/////////////////////////CALCULATES THE VALUE OF GIVEN FUNCTION/////////////////
	long double graph::calculate_value(float x)
	{
	int p;
	float val;
	NODE2 a1,b1;
	float a,b;
	for (p=0;p<inny;p++)
		{
		if(arr[p].code==1||arr[p].code==2)
			push2(arr[p].code,float(arr[p].value));
		else
			{
				if(arr[p].code==3)
				{
				b1=pop2();a1=pop2();
					if(int(b1.code)==2||int(b1.code)==7)
					b=b1.value;
					else if(int(b1.code)==1)
					b=x;
					if(int(a1.code)==2||int(a1.code)==7)
					a=a1.value;
					else if(int(a1.code)==1)
					a=x;
					if(arr[p].value==1)
					push2(7,a+b);
					if(arr[p].value==2)
					push2(7,a-b);
					if(arr[p].value==3)
					push2(7,a*b);
					if(arr[p].value==4)
					{if(b==0)
					b=0.0001;
					push2(7,a/b);}
					if(arr[p].value==5)
					push2(7,pow(a,b));

				}
				if(arr[p].code==5)
				{
				b1=pop2();
					if(int(b1.code)==2||int(b1.code)==7)
					b=b1.value;
					else if(int(b1.code)==1)
					b=x;
					if(arr[p].value==1)
					push2(7,5*sin((40*b*3.1414)/180));
					if(arr[p].value==2)
					push2(7,5*cos((40*b*3.1414)/180));
					if(arr[p].value==3)
					push2(7,5*tan((40*b*3.1414)/180));
					if(arr[p].value==4)
						{
						if(b>0)
						push2(7,log(b));
						else
						push2(7,-506);
						}
					if(arr[p].value==5)
					push2(7,int(b));
					if(arr[p].value==6)
					push2(7,(int(b)+1));
					if(arr[p].value==7)
					push2(7,fabs(b));
				}
			}
		}
		return pop2().value;
	}
	////////////////////////////FUNCTION TO CREATE THE GRAPH OF FUNCTION///////////////////
	void graph::createfor2var()
	{

	float x,y,u,v;
	double i,p,q,ii,tt;

	int x1=getmaxx(),l;
	int y1=getmaxy();
	x=float(x1);y=float(y1);


		/*for(int kj=0;kj<=index;kj++)
		{
		    arr2[kj].code=arr[kj].code;
		    arr2[kj].value=arr[kj].value;
		}
		for(i=0;i<=10;i+=1)
			{
			for(l=0;l<=index;l++)
				if(arr2[l].code==1&&arr2[l].value==1)
				{
				 arr2[l].code=2;arr2[l].value=i;
				}
			produceABC();
			}*/

		produceABC();
		//cout<<" This="<<findwhatinthere(0,2);

		//cout<<"\n This2="<<findwhatinthere(4,8);
		cout<<"\n Its Done Sir!!";
	}
	void graph::produceABC()
	{
	int st=0,en=0,chk=0,pl=0;
	cout<<"\n Affirmative!!!!!!!!! and index="<<index;
	for(int c=0;c<=index-1;c++)
		{
		if(arr[c].code==3&&(arr[c].value==1||arr[c].value==2)||c==index-1)
			{
			 cout<<"\n index="<<findwhatinthere(st,c-1);
			 st=c+1;
			}
			 /*if(chk==0)  /////////////for y^2
			 {
				if(en-st==2&&st==0)
					//copy only (2,1)copycont(st-1,en,0);
				else if(en-st==2)
					 if(arr[st-1].code==3&&arr[st-1].value==2)
					     arr[st].value=arr[st].value*(-1);
				     //copy only (2,-1)	copycont();
				else if(en-st==4&&st==0))
					{
					 ///copy only arr[st]
				else if(en-st==4)
					 if(arr[st-1].code==3&&arr[st-1].value==2)
					     arr[st].value=arr[st].value*(-1);
					 copycont(st,st,0);
					}
			 }
			if(chk==1)
			 {
				if(en-st==4)    ///////h*x*y + f*y
				{
					if(st==0)
					{
						//////only copy h*x
					}
					else if(st==1)
					{
						/////only copy h*x with updated sign
					}
					else
					{
						/////copy h*x with updated sign
					}
				}
				else if(en-st==2)   /////////f*y
				{
					if(st==0)
					{
						/////copy only f
		      /*			}
					else if(st==1)
					{
						//////only copy f with updated sign
					}
					else
					{
						////////only copy f with updated sign
					}
				}
			 }
			 if(chk==2)	///////////for a*x^2+g*x+c
			 {
				if(en-st==4)      //////for a*x^2
				{
					if(st==0)
					{
						/////copy complete a*x^2
					}
					else if(st==1)
					{
						//////only copy a*x^2 with updated sign in a
					}
					else
					{
						////////only copy a*x^2  with updated sign
					}
				}
				else if(en-st==2)   //////for x^2 and g*x
				{
					if(arr[en].code==2)   ///////for x^2
					{
					   ////////deal carefully
					}
					else if(arr[en].code==1) ///////for g*x
					{
					   ////////deal carefully
					}
				}
			 }
			} */
		//en+=1;
		}
	}
	void graph::copycont(int st,int en,int ty,int ind,NODE no)
	{
	  //cout<<"\n index"<<ty;
		int var=0;
		switch(ty)
			{
			case 1:if(ind==2)
						var=iC;
					if(ind==1)
						var=iB;
					if(ind==0)
						var=iA;
					for (int j=0+var;j<=en-st+var;j++)
					{
						arr2[ty][j+1].code=arr[j+st].code;
						arr2[ty][j+1].value=double(arr[j+st].value);
						var+=1;
					}					
					if(ind==2)
						iC=var;
					if(ind==1)
						iB=var;
					if(ind==0)
						iA=var;
					break;
			case 2://////////////
					break;
			}
	  /*
	  


	     */
	}
	int graph::findwhatinthere(int st,int en)
	{
	cout<<"\n st="<<st<<" en="<<en;
	if(en+1==index-1)
		en=en+1;
	if(st>en)
		st=en;
	int retu=0;
	    if(st==en)
		{
			return 2;
		}

	    if(arr[en-2].code==1)   /////////////for variables//////
	    {
	      if((arr[en-1].code==3&&arr[en-1].value==5)&&(arr[en].code==2&&arr[en].value==2))///////////check for ^2////////
		{
			if(arr[en-2].value==1)  ///////for x^2///////
			{
			retu=2;
			}
			if(arr[en-2].value==2)  ///////for y^2////////
			{
			retu=0;
			}
		 }
	      else if((arr[en-1].code==3&&arr[en-1].value==3)&&(arr[en].code==1))/////////////check *x or *y//////
		 {
			retu=1;////////////////checked x*y or y*x /////////////
			if(arr[en-2].value==2&&arr[en].value==1)
			{
				arr[en-2].value=1;arr[en].value=2;
			}
		 }
	    }
	      if(arr[en].code==1)  ////////////for type 2*g*x and 2*f*y///////
		{
			cout<<"here";
			if(arr[en].value==1)
			{
			retu=2;
			}
			if(arr[en].value==2)
			{
			retu=1;
			}
		}

	return retu;
	}

	void graph::creategraph(int ok)
	{

	float x,y,u,v;
	double i,p,q,ii,tt;

	//setbkcolor(6);
	int x1=getmaxx();
	int y1=getmaxy();
	x=float(x1);y=float(y1);
	fflush(stdin);
	fflush(stdin);
	//clrscr();
	cleardevice();
	fileop fo;

	if(ok==2)
	 {
		fo.returnarray();
		input2(fo);
	 }
	else
	{
	 input();
	}
	 //if(inspect()==1)

	start_automata();
	if(pub==2)
		goto skip;
	if(pub!=1)
	{
	setlinestyle(SOLID_LINE, 1, 1);
	cout<<"\n\n Click to view Graph ..  \n";
	getch();
	cleardevice();
	line(x/12,y/20,11*x/12,y/20);////UPPER
	line(x/12,y/20,x/12,16*y/20);////////

	line(x/12,16*y/20,11*x/12,16*y/20);
	line(11*x/12,y/20,11*x/12,16*y/20);
	 for(i=x/12;i<=11*x/12;i+=0.1)
	{
		putpixel(i,8.5*y/20,WHITE);
	}
	for(i=y/20;i<=16*y/20;i+=0.1)
	{
		putpixel(x/2,i,WHITE);
	}
		u=8.5*y/20;
		v=x/2;
	for(i=0.01;i<=11*x/12;i+=0.001)
	{
		p=u-8*calculate_value(i);
		q=u-8*calculate_value(-i);
		if((p>=y/20&&p<=16*y/20)&&(8*i+v<11*x/12))
			putpixel(8*i+v,p,BLUE);
		if((q>=y/20&&q<=16*y/20)&&(v-8*i>x/12))
			putpixel(v-8*i,q,BLUE);

	}
	chalbhai();
	}
	else
	createfor2var();
	skip:

	getch();
	}
	void graph::chalbhai()
	{
	   double ii,tt;
	   char yt;
	 //  window(7,7,59,9);
	//cprintf(" Do you wish to calculate an area bounded by x-axix");


	//gotoxy(7,46);
	//outtextxy(getmaxx()/12,16*getmaxy()/20+20,"Do you wish to calculate an area bounded by x-axix::");
	//printf(" Do you wish to calculate an area bounded by x-axix") ;
	gotoxy(34,25);
	cout<<"\n      Do you wish to calculate an area bounded by x-axix";

	if(getch()=='y'||getch()=='Y')
	{
		clear();
		gotoxy(34,25);

		cout<<"\n      Enter points(Press tab to seperate)::";
		cin>>ii>>tt;
		clear();
		gotoxy(34,25);
		cout<<"\n      Area=";
		cout<<shadearea(ii,tt);
		getch();
		diffrentiate();
	}
	clear();
	}
	///////////////////////FUNCTION TO CALCULATE THE AREA FROM GIVEN POINTS///////////////////
	long double graph::shadearea(float xx,float yy)
	{
		int ct=0;
		float d,q,val,area=0,area2=0,p1=0,p2=0,q1=0,q2=0,p3=0,q3=0;
		d=getmaxx()/2;q=8.5*getmaxy()/20;
	   // xx=xx+d;//getmaxx()/2;
	   // yy=yy+q;//getmaxx()/2;
	for(float lp=xx;lp<=yy;lp+=0.0001)
		{
		val=q-8*calculate_value(lp);
		ct+=1;
		//p3=p3+lp;
			//if(val<q)
			//{
				if(val<getmaxy()/20)
					val=getmaxy()/20;
				if(val>16*getmaxy()/20)
					val=16*getmaxy()/20;
				line(d+8*lp,q,d+8*lp,val);
			//}

			if(ct==1)
			{

				p1=lp;
				//cout<<"\n p1="<<p1;
				q1=calculate_value(lp);
				//cout<<" q1="<<q1;
			}
			if(ct==4)
			{
				ct=0;
				p2=lp ;
				q2=calculate_value(lp);
				//cout<<" p2="<<p2<<" q2="<<q2<<"  ";
				//cout<<" p3="<<p3;
				area2=(p2-p1+0.0001)*(q1+q2)/2;
				if(area2<0)
					area2=area2*(-1);
				area+=area2;
				//cout<<" Area="<<area;
			}
		}
	return area;
	}
	////////////////////////////////CLASS GRAPH ENDS HERE//////////////////////////
	////////////////////////////////CLASS FILEOP STARTS HERE///////////////////
	/*
	void showfile();
	char *return array(char);
	int searchpositon();*/
	char fileop::showfile()
	{
	char ch;
	fp=fopen("C:\\TC\\BIN\\exps.txt","r");    /////////FILE CONTAING EXPRESSIONS///////
	gotoxy(1,1);
	while(1)
	{
	ch=fgetc(fp);
	if(ch==EOF)
	break;
	if(ch!='#')
	printf("%c",ch);
	}
	fclose(fp);
	cout<<"\n\n\t PRESS YOUR CHOICE";

	return getche();
	}
	void fileop::returnarray()
	{
	  posi=0;
	  posi=searchposition(showfile());
		cout<<"";
		if(posi>0)
		{cout<<"";
		//puts(exps);
		for(int v=0;v<posi;v++)
		{cout<<exps[posi]<<" ";}
		}
	}
	int fileop::searchposition(char t)
	{
	char ch1,ch2,ch3;
	int posi2=0;
	cout<<"";
	fp=fopen("C:\\TC\\BIN\\exps.txt","r");    /////////FILE CONTAING EXPRESSIONS///////
	ch1=fgetc(fp);
	ch2=fgetc(fp);

	do
	{
	cout<<"";
	if(ch1==EOF||ch2==EOF)
	{
	cout<<"";
	break;
	}
	if(ch1==t&&ch2==')')
	{
		ch2=fgetc(fp);
		cout<<"";
		while((ch3=fgetc(fp))!='#')
		{
		exps[posi2]=ch3;
		cout<<"";
		posi2++;
		}
	exps[posi2]='\0';
	break;
	}
	ch1=ch2;ch2=fgetc(fp);
	}
	while(1);
	fclose(fp);
	return posi2;
	}
	////////////////////////////////CLASS FILEOP ENDS HERE////////////////////
	void main()
    {

     clrscr();
	 void present(int ,int);
	 void mainmenu(graph);
	 void loading();

	 graph g;
	float e;
	char ar[30];
	int gd=DETECT,gm,x1,y1;
	initgraph(&gd,&gm,"c:\\tc\\bgi");

       loading();
       cleardevice();
       present(getmaxx(),getmaxy());
       cleardevice();

       do
       {
	   cleardevice();
	   fflush(stdin);
       mainmenu(g);
	gotoxy(1,1);
	cout<<"\n\n\n\n\n\t\t     Return to Main Menu (Y/N) ";

	}
	while(1);

	}
	/////////////////////////TO DISPLAY WELCOME SCREEN/////////////
	void present(int x1,int y1)
	{
	settextjustify(CENTER_TEXT, CENTER_TEXT);


      settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);


      outtextxy(x1/2, y1/4-40, "Welcome");
      outtextxy(x1/2, y1/3-8, "to");
       settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
      outtextxy(x1/2, y1/3+30, "Principia de Mathematica");
      settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);

      outtextxy(x1/2, y1/2+6, "(Simple Graph Viewer and Drawer)");
      settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);

      outtextxy(2*x1/3-30, y1/2+85, "Made by-");
      settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
      outtextxy(2*x1/3+10, y1/2+110, "Rohit Sharma");
      outtextxy(2*x1/3+77, y1/2+135, "Computer Science & Engg.");
       settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
       delay(800);
      outtextxy(x1/2, 3*y1/4+85, "Press any key....");
	getch();

	}
	////////////////////////////////DISPLAYING VARIOUS OPTIONS MENU////////////////////////
	void mainmenu(graph g)
	{float val;
	fileop fo;
	gotoxy(1,1);
	cout<<"\n\n\n\n\t\t     *****THE MAIN NAVIGATION MENU***** ";
	cout<<"\n\n\t\t\t     1-Create a Graph";
	cout<<"\n\n\t\t\t     2-Convert to Postfix";
	cout<<"\n\n\t\t\t     3-Evaluate an Expression (With x as variable)";
	cout<<"\n\n\t\t\t     4-Evaluate an Expression (Without x)";
	cout<<"\n\n\t\t\t     5-Use Predefined Function";
	cout<<"\n\n\t\t\t     6-About Principia de Mathematica";
	cout<<"\n\n\t\t\t     7-Developer";
	cout<<"\n\n\t\t\t     8-Help";
	cout<<"\n\n\t\t\t     9-Exit";
	cout<<"\n\n\n\t\t\t    PRESS YOUR CHOICE";
	switch(int(getche())-48)
	{
	case 1:cleardevice();
		gotoxy(1,1);
		g.creategraph(1);

		break;
	case 2: cleardevice();
		gotoxy(1,1);
		g.input();
		g.start_automata();
		cout<<"\n\n Click to Switch to Main Menu";
		getch();
		break;
	case 3: cleardevice();
		gotoxy(1,1);
		g.input();
		g.start_automata();
		do
		{
		cout<<"\n\n Please enter a value of 'x' to calulate::";

		fflush(stdin);
		cin>>val;
		cout<<"\n\n The Value is::"<<g.calculate_value(val);
		cout<<"\n\n Try with a new value(Y/N)";
		}
		while(getche()=='y'||getche()=='Y');
		cout<<"\n\n Click to Switch to Main Menu";
		break;
	case 4: cleardevice();
		gotoxy(1,1);
		g.input();
		g.start_automata();
		cout<<"\n\nThe Value is::"<<g.calculate_value(0);
		cout<<"\n\nClick to Switch to Main Menu";
		getch();
		break;
	case 5: cleardevice();
		gotoxy(1,1);
		g.creategraph(2);

		break;

case 6: cleardevice();
			gotoxy(1,1);
			cout<<"\n\n This 'Principia de Mathematica'-Simple Graph Viewer and Drawer, is dedicated to my favourite chemistry teacher 'Arun Pathak' and to my friends";
			getch();
			break;
	default: exit(0);
	}
	cleardevice();

	}
	////////////////////////////DISPALAYING LOADING ANIMATION///////////////////////////
	void loading()
	{
	printf("\n\n\n\n\n\n\n");
	for(int j=0;j<=79;j+=2)
	{

	printf(" %c",219);      }
	gotoxy(1,1);
	printf("\n\n\n	               		  PLEASE WAIT..");
	printf("\n\n		            	 -LOADING FILES-");
	printf("\n\n");
	for(int i=0;i<=79;i++)
	{
	printf("%c",219);
	delay(35);
	}
	delay(500);
	}
	///////////////////////FUNCTION TO CLEAR RESULTS///////////////////
	void graph :: clear()
	{
	float i,j;
	for(i=0;i<=getmaxx();i+=1)
	{
	for(j=16*getmaxy()/20+15;j<=getmaxy();j+=1)
	putpixel(i,j,BLACK);
	}
	}