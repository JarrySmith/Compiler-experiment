#ifndef TOOL_H_INCLUDED
#define TOOL_H_INCLUDED

#define KeyWordnum 9
//自增++ 29 -- 30 +=31 -=32 *= 33 /= 34
char prog[100],token[20],ch,char_statement[20];
char *rwtab[KeyWordnum]={"begin","if","then","else","while","do","end","int","char","float"};
int syn,p,m,n,sum;
int ck_aly=0;
int success=1;

void statement(void)
{

    if(syn==2)//如果是if
    {
        scaner();        /*读下一个单词符号*/
        expression();
        if(syn!=3) {success=0; printf("不是合法的判定条件!\n");}
        else{
                if(success){
                scaner();
                statement();
                if(syn==4){
                        scaner();
                        statement();
                        }
                }
            }
    }
        else {
            var();

          if(success){  if(syn!=18) {printf("缺少：=  !\n");success=0;}}
            else{
                scaner();
                expression();
                }
    }
       if(success)
       printf("it is a statement\n");

}
void var()
{
 if(success){
 if(syn!=10) {success=0;printf("非法的变量名！\n");}
 else{
        scaner();
        if(syn==27)
            {
                 expression(); //为左括号
                 if (syn!=28)   //为右括号
                 printf("括号不完整，请检查！\n");
                 else scaner();
            }
       printf("it is a variable!\n");
     }
 }
}
void expression(void)
{
    if(success){
    term();
    while(syn==13)
    {
        scaner();             /*读下一个单词符号*/
        term();               /*调用函数term();*/
    }
    if(success)printf("it is a expression!\n");
    }
}
void term(void)
{
    if(success){
    factor();

    while(syn==15) //为*
    {
        scaner();             /*读下一个单词符号*/
        factor();              /*调用函数factor(); */
    }
  if(success)printf("it is a term!\n");
    }
}

void factor(void)
{
    if(success){
    if(syn==10)
    {
        var();
    }
    else if(syn==27)
    {
        scaner();           /*读下一个单词符号*/
        expression();        /*调用函数statement();*/

        if(syn==28)
        {
            scaner();          /*读下一个单词符号*/
        }
        else
        {
            printf("the error on '('\n");

        }
    }
    else
    {
        integer();
    }
   if(success) printf("it is a factor!\n",token);}
    return;
}
void integer()
{
    if(success){
     integer_num();
     while(syn==11) integer_num();
     if(success)printf("this is a integer\n");
    }
     return;
}
void integer_num()
{
    if(ch>='0'&&ch<='9') scaner();
    if(success)printf("this is a integer_num\n");
}
void cleartoken()
{
    for(m=0;m<20;m++)
        token[m++]=NULL;
}
void clear(char m[])
{
    int i=0;
    for(i=0;i<20;i++)
        m[i++]=NULL;
}
void scaner()
{
    sum=0;
    cleartoken();
    m=0;
    ch=prog[p++];

    while(ch==' ')
        ch=prog[p++];
  //首字符为字母
    if(((ch<='z')&&(ch>='a'))||((ch<='Z')&&(ch>='A')))
    {
        while(((ch<='z')&&(ch>='a'))||((ch<='Z')&&(ch>='A'))||((ch>='0')&&(ch<='9')))
        {
            token[m++]=ch;
            ch=prog[p++];
        }
        p--;
        syn=10;
        token[m++]='\0';   //读取完毕
        for(n=0;n<KeyWordnum;n++)   //查询是否为关键字
        if(strcmp(token,rwtab[n])==0)
        {
            syn=n+1;
            break;
        }
    }
// 数字字符转换程序
    else if((ch>='0')&&(ch<='9'))
    {

       if (ck_aly==1){
            while((ch>='0')&&(ch<='9'))
        {
            sum=sum*10+ch-'0';
            ch=prog[p++];
        }
        p--; //回退
        syn=11;}
       else syn=11;
    }
    else
    switch(ch)
    {
        case '<':
            m=0;
             token[m++]=ch;
            ch=prog[p++];

            if(ch=='>')
            {
                syn=21;
                token[m++]=ch;
            }
            else if(ch=='=')
            {
                syn=22;
                token[m++]=ch;
            }
            else
            {
                syn=20;
                p--;
            }
        break;

        case '>':
            m=0;
            token[m++]=ch;
            ch=prog[p++];

            if(ch=='=')
            {
                syn=24;
                token[m++]=ch;
            }
            else
            {
                syn=23;
                p--;
            }
        break;

        case ':':
            m=0;
            token[m++]=ch;
            ch=prog[p++];
            if(ch=='=')
            {
                syn=18;
                token[m++]=ch;

            }
            else
            {
                syn=17;
                p--;
            }
            break;

        case '+':
                m=0;
                token[m++]=ch;
                syn=13;
        break;

        case '-':
            m=0;
            token[m++]=ch;
            syn=14;
        break;

        case '*':
            m=0;
            token[m++]=ch;
            syn=15;
        break;

        case '/':
            m=0;
            token[m++]=ch;
            syn=16;
        break;

        case '(':
            syn=27;
        break;

        case ')':
            syn=28;
        break;

        case '=':
            syn=25;
        break;

        case ';':
            syn=26;
        break;

        case '#':
            syn=0;
        break;

        default:
            syn=-1;
        break;
    }
}


#endif // TOOL_H_INCLUDED
