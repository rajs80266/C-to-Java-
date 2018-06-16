#include<stdio.h>
#include<string.h>

int tab;

void printing(char s1[], int n, char S[])
{
    int i,j,k,K;

    if(s1[n-3]!='\"')
    {
        for(k=n-4;;k--)
        {
            if(s1[k]=='\"')
                break;
        }
    }
    else
        k=n-3;
    K=k;
    k++;
    strcpy(S,"System.out.print(\"");
    for(i=18,j=8 ; j<K ; )
    {
        if(s1[j]!='%')
        {
            S[i++]=s1[j++];
        }
        else
        {
            S[i++]='\"';
            S[i++]='+';
            k++;
            while(s1[k]!=',' && s1[k]!=')')
            {
                S[i++]=s1[k++];
            }
            S[i++]='+';
            S[i++]='\"';
            j++;
            j++;
        }
    }
    S[i++]='\"';
    S[i++]=')';
    S[i++]=';';
    S[i]='\0';
}

void scanning(char s1[],int n,char S[])
{
    int i,j,k,K,x;

    for(k=n-4;;k--)
    {
        if(s1[k]=='\"')
            break;
    }
    K=k;
    k++;
    for(i=0,j=7;j<K;j++)
    {
        if(s1[j]=='%')
        {
            j++;
            while(s1[k]==','||s1[k]==' '||s1[k]=='&')
                k++;
            while(s1[k]!=',' && s1[k]!=')')
            {
                S[i++]=s1[k++];
            }

            S[i++]='=';
            S[i++]='s';
            S[i++]='c';
            S[i++]='.';
            S[i++]='n';
            S[i++]='e';
            S[i++]='x';
            S[i++]='t';
            if(s1[j]=='d')
            {
                S[i++]='I';
                S[i++]='n';
                S[i++]='t';
            }
            else if(s1[j]=='f')
            {
                S[i++]='F';
                S[i++]='l';
                S[i++]='o';
                S[i++]='a';
                S[i++]='t';
            }
            else if(s1[j]=='l')
            {
                j++;
                if(s1[j]=='f')
                {
                    S[i++]='D';
                    S[i++]='o';
                    S[i++]='u';
                    S[i++]='b';
                    S[i++]='l';
                    S[i++]='e';
                }
                else
                {
                    S[i++]='L';
                    S[i++]='o';
                    S[i++]='n';
                    S[i++]='g';
                }
            }
            S[i++]='(';
            S[i++]=')';
            S[i++]=';';
            S[i++]='\n';
            for(x=0;x<tab;x++)
                S[i++]='\t';
        }
    }
    S[i]='\0';
}

int bcount(char var[])
{
    int i,n=0;
    for(i=0;var[i]!='\0';i++)
        if(var[i]=='[')
            n++;
    return n;
}

void declaration(char s1[],int n,char S[])
{
    int i,j,k,x,l,m,nd;
    char dt[10],var[100];

    for(j=0;s1[j-1]!=' ';j++)
        dt[j]=s1[j];
    dt[j]='\0';

    strcpy(S,"");

    for(i=j;s1[i]!='\0';i++)
    {
        while(1)
        {
            if(s1[i]!=' ' || s1[i]!=',' || s1[i]!=';')
                break;
        }
        if(s1[i]==';')
            break;
        for(k=i;s1[k]!=';'&&s1[k]!=','&&s1[k]!=' ';k++)
        {
            var[k-i]=s1[k];
        }
        var[k-i]='\0';
        if(var[k-i-1]!=']')
        {
            strcat(S,dt);
            strcat(S,var);
            strcat(S,";\n");
            for(x=0;x<tab;x++)
                strcat(S,"\t");

        }
        else
        {
            strcat(S,dt);
            nd=bcount(var);
            for(x=0;x<nd;x++)
                strcat(S,"[]");
            for(l=0;S[l]!='\0';l++);
            for(m=0;var[m]!='[';m++)
                S[l++]=var[m];
            S[l]='\0';
            strcat(S," = new ");
            strcat(S,dt);
            for(l=0;S[l]!='\0';l++);
            for(;var[m]!='\0';m++)
                S[l++]=var[m];
            S[l]='\0';
            strcat(S,";\n");
            for(x=0;x<tab;x++)
                strcat(S,"\t");
        }
        i=k;
    }
}

void struct_declaration(char s1[],int n,char S[])
{
    int i,j;
    strcpy(S,"class ");
    for(i=7,j=6;s1[i]!='\0';i++,j++)
        S[j]=s1[i];
    S[j]='\0';
}

void struct_var_declaration(char s1[],int n,char S[])
{

}

void check(char s1[],int n,char S[])
{
    int x;

    if(s1[0]=='p' && s1[1]=='r' && s1[2]=='i' && s1[3]=='n' && s1[4]=='t' && s1[5]=='f' && s1[6]=='(')
    {
        printing(s1,n,S);
    }
    else if(s1[0]=='s' && s1[1]=='c' && s1[2]=='a' && s1[3]=='n' && s1[4]=='f' && s1[5]=='(')
    {
        scanning(s1,n,S);
    }
    else if( (s1[0]=='i' && s1[1]=='n' && s1[2]=='t' && s1[3]==' ') || (s1[0]=='c' && s1[1]=='h' && s1[2]=='a' && s1[3]=='r' && s1[4]==' ') || (s1[0]=='f' && s1[1]=='l' && s1[2]=='o' && s1[3]=='a' && s1[2]=='t' && s1[3]==' ') || (s1[0]=='l' && s1[1]=='o' && s1[2]=='n' && s1[3]=='g' && s1[4]==' ') || (s1[0]=='d' && s1[1]=='o' && s1[2]=='u' && s1[3]=='b' && s1[2]=='l' && s1[2]=='e' && s1[3]==' ') )
    {
        if(s1[n-1]==';')
            declaration(s1,n,S);
        else
        {
            strcpy(S,"static ");
            strcat(S,s1);
        }
    }
    else if(s1[0]=='#')
    {
        strcpy(S," ");
    }
    else if( strcmp(s1,"void main()")==0 || strcmp(s1,"int main()")==0 || strcmp(s1,"void main(){")==0 || strcmp(s1,"int main(){")==0 )
    {
        strcpy(S,"public static void main(String args[])");
        for(x=0;s1[x]!='\0';x++);
        if(s1[x-1]=='{')
            strcat(S,"{");
    }
    else if(s1[0]=='s' && s1[1]=='t' && s1[2]=='r' && s1[3]=='u' && s1[4]=='c' && s1[5]=='t' && s1[6]==' ')
    {
        if(s1[n-1]!=';')
            struct_declaration(s1,n,S);
        else
            struct_var_declaration(s1,n,S);
    }
    else
    {
        strcpy(S,s1);
    }
}

void main()
{

	FILE *r,*w;
	char s1[100],s2,S[100];
    int i,x;

	r=fopen("C_Code.txt","r");
	w=fopen("Java_Code.txt","w");

	fprintf(w,"import java.util.*;\nimport java.io.*;\n\nclass main\n{\n\tstatic Scanner sc=new Scanner(System.in);");
    tab=1;
	while(!feof(r))
    {
        fscanf(r,"%s",s1);
        for(i=0;s1[i]!='\0';i++);
        while(1)
        {
            fscanf(r,"%c",&s2);
            if(s2!='\n' && s2!='\0' && !feof(r))
            {
                s1[i]=s2;
                i++;
            }
            if(s2=='\n' || feof(r))
                break;
        }
        s1[i]='\0';
        check(s1,i,S);
        if(s1[i-1]=='}' || s1[i-2]=='}')
        {
            tab--;
        }
        for(x=0;x<tab;x++)
            fprintf(w,"\t");
        fprintf(w,"%s\n",S);
        if(s1[i-1]=='{')
            tab++;
    }
	fprintf(w,"}");
}
