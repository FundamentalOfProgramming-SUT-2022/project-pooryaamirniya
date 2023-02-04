#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fileapi.h>
#include <dirent.h>

#define SIZE 500     //order
#define SIZE2 1000   //""

void spscan_number(char a[SIZE2],int n);
void sscan(char a[]);
void spscanm(char a[SIZE]);
void spscanl(char a[SIZE2]);
void slashscan(char a[]);
void createfile();
void insertstr();
void cat();
void removetstr();
void copystr();
void cutstr();
void pastestr();
void find();
void fcopy(FILE *fptr,char a[]);
void sorting(char a[SIZE2],char b[SIZE2]);
void counter(char a[],char b[]);
void atnumber(char a[],char b[]);
void byword(char a[],char b[]);
void allnumber(char a[],char b[]);
void undo();
void fund(char a[]);
void ditree();

int whatslash(char a[],char b[]);

char cscan(char a);


int nscan(int a);
int file_(char a[]);
int pos_(char a[]);
int str_(char a[]);
int size_(char a[]);
int b_f(char a[]);

struct moze copyfile();

char copypaste[SIZE2];

struct moze{
    int i;
    int j;
};

int main(){
    char a[SIZE],b[]="createfile",c[]="insertstr",d[]={"cat"},e[]={"removetstr"},f[]={"copystr"},g[]={"cutstr"},h[]={"pastestr"},i[]={"find"},j[]={"undo"},k[]={"tree"};
    while(1){
        sscan(a);
        if(strcmp(a,b)==0)
            createfile();
        else if(strcmp(a,c)==0)
            insertstr();
        else if(strcmp(a,d)==0)
            cat();
        else if(strcmp(a,e)==0)
            removetstr();
        else if(strcmp(a,f)==0)
            copystr();
        else if(strcmp(a,g)==0)
            cutstr();
        else if(strcmp(a,h)==0)
            pastestr();
        else if(strcmp(a,i)==0)
            find();
        else if(strcmp(a,j)==0)
            undo();
        else if(strcmp(a,k)==0)
            ditree();
        else
            printf("invalid order\n");
    }
    return 0;
}
void sscan(char a[]){
    scanf("%s",a);
}
char cscan(char a){
    scanf("%c",&a);
    return a;
}
int nscan(int a){
    scanf("%d",&a);
    return a;
}
void spscanm(char a[]){
    int i;
    for(i=0;i<SIZE && a[i]!='"';i++){
        scanf("%c",&a[i]);
        if(a[i]=='"'){
            break;
        }
    }
    if(a[i]=='"'){
        a[i]='\0';
    }
}
void spscanl(char a[]){
    int i;
    for(i=0;i<SIZE2 && a[i]!='"';i++){
        scanf("%c",&a[i]);
        if(a[i]=='"'){
            break;
        }
    }
    if(a[i]=='"'){
        a[i]='\0';
    }
}
void spscan_number(char a[],int n){
    int i;
    for(i=n;i<SIZE2 && a[i]!=' ';i++){
        scanf("%c",&a[i]);
        if(a[i]==' '){
            break;
        }
    }
    if(a[i]==' '){
        a[i]='\0';
    }
}
void slashscan(char a[]){
    int i;
    for(i=0;i<SIZE2 && a[i]!='\n' && a[i]!=' ';i++){
        scanf("%c",&a[i]);
        if(a[i]=='\n' || a[i]==' '){
            break;
        }
    }
    if(a[i]=='\n' || a[i]==' '){
        a[i]='\0';
    }
}
void faddres(char a[]){
    char first;
    first=cscan(first);
    first=cscan(first);
    if(first=='/'){
        sscan(a);
    }
    if(first=='"'){
        first=cscan(first);
        if(first=='/')
            spscanm(a);
    }
}
void finside(char a[]){
    char first;
    first=cscan(first);
    first=cscan(first);
    if(first=='"'){
        spscanl(a);
    }
    else{
        a[0]=first;
    spscan_number(a,1);
    }

}
int file_(char a[]){
    char b[7]="--file";
    if(strcmp(a,b)==0)
        return 1;
    else
        return 0;
}
int pos_(char a[]){
    char b[6]="--pos";
    if(strcmp(a,b)==0)
        return 1;
    else
        return 0;
}
int str_(char a[]){
    char b[6]="--str";
    if(strcmp(a,b)==0)
        return 1;
    else
        return 0;
}
int size_(char a[]){
    char b[6]="-size";
    if(strcmp(a,b)==0)
        return 1;
    else
        return 0;
}
int b_f(char a[]){
    char b[3]="-b",c[3]={"-f"};
    if(strcmp(a,c)==0)
        return 1;
    else if(strcmp(a,b)==0)
        return -1;
    else
        return 0;
}
void createfile(){
    FILE *fptr;
    char a[SIZE],c[SIZE]={0},d[7],hide[]={"hidden"},v[SIZE],v2[]={"/"};
    int z,j=0;
    sscan(d);
    if(file_(d)){
        faddres(a);
        for(int i=0;1;i++){
            if(a[i]=='/'){
                mkdir(c);
            }
            c[i]=a[i];
            if(a[i]=='\0'){
                fptr=fopen(c,"w");
                fclose(fptr);
                break;
            }
        }
        z=whatslash(c,v2);
        for(int i=0;a[i]!='\0';i++,j++){
            if(i==z){
                v[j]='h';
                j++;
            }
            v[j]=a[i];

        }
        v[j]='\0';
        fptr=fopen(v,"w");
        fclose(fptr);
        SetFileAttributes(v,FILE_ATTRIBUTE_HIDDEN);
    }
    else
        printf("you should write --file\n");
}
void insertstr(){
    char a[SIZE],d[7],e[6],f[SIZE2],g[6],first,half1[SIZE2],half2[SIZE2],c,v[SIZE];
    int i=0,j=0,z,r=0;
    struct moze pose;

    sscan(d);
    if(file_(d)){
        faddres(a);
        FILE *fptr;
        if((fptr=fopen(a,"r"))== NULL){
            printf("File could not open");
        }
        else{
            sscan(e);
            if(str_(e)){
                finside(f);
                sscan(g);
                if(pos_(g)){
                    first=cscan(first);
                    i=nscan(i);
                    first=cscan(first);
                    if(first==':'){
                        j=nscan(j);
                        pose=copyfile(fptr,half1,half2,i,j);
                        fclose(fptr);
                        fund(a);
                        fptr=fopen(a,"w");
                        if(pose.i!=i || pose.j!=j){
                            printf("file doesn't long enough,maybe the file is messed up\n");
                        }
                        if(half1[0]!='\0'){
                            fprintf(fptr,"%s",half1);
                        }
                        while(pose.i<i){
                            fprintf(fptr,"\n");
                            pose.i++;
                        }
                        while(pose.j<j){
                            fprintf(fptr," ");
                            pose.j++;
                        }
                        z=strlen(f);
                        while(r<z){
                            c=f[r];
                            if(f[r]=='\\' && f[r+1]=='n' && r<z-1){
                                fprintf(fptr,"\n");
                                r=r+2;
                            }
                            else if(f[r]=='\\' && f[r+1]=='\\' && f[r+2]=='n' && r<z-2){
                                fprintf(fptr,"\\n");
                                r=r+3;
                            }
                            else{
                                fprintf(fptr,"%c",c);
                                r++;
                            }
                        }
                        if(half2[0]!='\0'){
                            fprintf(fptr,"%s",half2);
                        }
                        fclose(fptr);
                    }
                    else
                        printf("you should write i:j\n");
                }
                else
                    printf("you should write --pos\n");
            }
            else
                printf("you should write --str\n");
        }
    }
    else
        printf("you should write --file\n");
}
struct moze copyfile(FILE *fptr,char half1[SIZE2],char half2[SIZE2],int d,int e){
    char c,answer[2];
    int i=0,j=0,z=0;
    struct moze pose;
    while(i<d-1 && !feof(fptr)){
        c=fgetc(fptr);
        half1[z]=c;
        if(half1[z]=='\n'){
            i++;
        }
        z++;
    }
    while(j<e && !feof(fptr)){
        c=fgetc(fptr);
        half1[z]=c;
        z++;
        j++;
    }
    half1[z]='\0';
    z=0;
    while(!feof(fptr)){
        c=fgetc(fptr);
        half2[z]=c;
        z++;
    }
    half2[z]='\0';
    if(z!=0){
        half2[z-1]='\0';
    }
    pose.i=i+1;
    pose.j=j;
    return pose;
}
void cat(){
    char a[SIZE],b[7],c;
    sscan(b);
    if(file_(b)){
        faddres(a);
        FILE *fptr;
        if((fptr=fopen(a,"r"))== NULL){
            printf("File could not open\n");
        }
        else{
            while(!feof(fptr)){
            c=fgetc(fptr);
            printf("%c",c);
            }
            printf("\n");
        }
    }
    else
        printf("you should write --file\n");
}
void removetstr(){
    char a[SIZE],b[7],half1[SIZE2],half2[SIZE2],c[6],first,d[6],e[3],f,v[SIZE];
    int i=0,j=0,s,p,z,t=0;
    struct moze pose;
    sscan(b);
    if(file_(b)){
        faddres(a);

        FILE *fptr;
        if((fptr=fopen(a,"r"))== NULL){
            printf("File could not open\n");
        }
        else{
            sscan(c);
            if(pos_(c)){
                first=cscan(first);
                i=nscan(i);
                first=cscan(first);
                if(first==':'){
                    j=nscan(j);
                    sscan(d);
                    if(size_(d)){
                        s=nscan(s);
                        sscan(e);
                        p=b_f(e);
                        pose=copyfile(fptr,half1,half2,i,j);
                        fclose(fptr);
                        if(pose.i!=i || pose.j!=j){
                            printf("file doesn't long enough\n");
                        }
                        else{
                            fund(a);
                            if(p==1){
                                fptr=fopen(a,"w");
                                if(half1[0]!='\0'){
                                    fprintf(fptr,"%s",half1);
                                }
                                z=strlen(half2);
                                for(int ii=0;ii<s;ii++){
                                    if(half2[ii]=='\0')
                                        t=1;
                                }
                                for(int k=s;k<z;k++){
                                    if(t){
                                        break;
                                    }
                                    f=half2[k];
                                    fprintf(fptr,"%c",f);
                                    if(f=='\0'){
                                        break;
                                    }
                                }
                                fclose(fptr);

                            }
                            else if(p==-1){
                                fptr=fopen(a,"w");
                                z=strlen(half1);
                                for(int k=0;half1[k]!='\0' && k<z-s;k++){
                                    f=half1[k];
                                    fprintf(fptr,"%c",f);
                                }
                                if(half2[0]!='\0'){
                                    fprintf(fptr,"%s",half2);
                                }
                                fclose(fptr);
                            }
                            else
                            printf("you should write -b or -f\n");
                        }
                    }
                    else
                        printf("you should write -size\n");
                }
            else
                printf("you should write i:j\n");
            }
        else
            printf("you should write --pos\n");
        }
    }
    else
        printf("you should write --file\n");
}
void copystr(){
    char a[SIZE],half1[SIZE2],half2[SIZE2],b[7],c[6],first,d[6],e[3];
    int i,j,s,p,z,k=0,t=0;
    struct moze pose;
    sscan(b);
    if(file_(b)){
        faddres(a);
        FILE *fptr;
        if((fptr=fopen(a,"r"))== NULL){
            printf("File could not open\n");
        }
        else{
            sscan(c);
            if(pos_(c)){
                first=cscan(first);
                i=nscan(i);
                first=cscan(first);
                if(first==':'){
                    j=nscan(j);
                    sscan(d);
                    if(size_(d)){
                        s=nscan(s);
                        sscan(e);
                        p=b_f(e);
                        pose=copyfile(fptr,half1,half2,i,j);
                        fclose(fptr);
                        if(pose.i!=i || pose.j!=j){
                            printf("file doesn't long enough\n");
                        }
                        else{
                            if(p==1){
                                for(k=0;k<s;k++){
                                    copypaste[k]=half2[k];
                                }
                                copypaste[k+1]='\0';
                            }
                            else if(p==-1){
                                z=strlen(half1);
                                for(k=z-s;half2[k]!='\0';k++,t++){
                                    copypaste[t]=half1[k];
                                }
                            }
                            else{
                                printf("you should write -b or -f\n");
                            }
                        }
                    }
                    else
                        printf("you should write -size\n");
                }
            else
                printf("you should write i:j\n");
            }
        else
            printf("you should write --pos\n");
        }
    }
    else
        printf("you should write --file\n");

}
void cutstr(){
    char a[SIZE],half1[SIZE2],half2[SIZE2],b[7],c[6],first,d[6],e[3],f,v[SIZE];
    int i=0,j=0,s,p,z,k=0,t=0;
    struct moze pose;
    sscan(b);
    if(file_(b)){
        faddres(a);
        FILE *fptr;
        if((fptr=fopen(a,"r"))== NULL){
            printf("File could not open\n");
        }
        else{
            sscan(c);
            if(pos_(c)){
                first=cscan(first);
                i=nscan(i);
                first=cscan(first);
                if(first==':'){
                    j=nscan(j);
                    sscan(d);
                    if(size_(d)){
                        s=nscan(s);
                        sscan(e);
                        p=b_f(e);
                        pose=copyfile(fptr,half1,half2,i,j);
                        fclose(fptr);
                        if(pose.i!=i || pose.j!=j){
                            printf("file doesn't long enough\n");
                        }
                        else{
                            fund(a);
                            if(p==1){
                                for(k=0;k<s;k++){
                                    copypaste[k]=half2[k];
                                }
                                copypaste[k+1]='\0';
                                fptr=fopen(a,"w");
                                if(half1[0]!='\0'){
                                    fprintf(fptr,"%s",half1);
                                }
                                z=strlen(half2);
                                for(int ii=0;ii<s;ii++){
                                    if(half2[ii]=='\0')
                                        t=1;
                                }
                                for(int k=s;k<z;k++){
                                    if(t){
                                        break;
                                    }
                                    f=half2[k];
                                    fprintf(fptr,"%c",f);
                                    if(f=='\0'){
                                        break;
                                    }
                                }
                                fclose(fptr);

                            }
                            else if(p==-1){
                                k=0;
                                t=0;
                                z=strlen(half1);
                                for(k=z-s;half2[k]!='\0';k++,t++){
                                    copypaste[t]=half1[k];
                                }
                                fptr=fopen(a,"w");
                                z=strlen(half1);
                                for(int k=0;half1[k]!='\0' && k<z-s;k++){
                                    f=half1[k];
                                    fprintf(fptr,"%c",f);
                                }
                                if(half2[0]!='\0'){
                                    fprintf(fptr,"%s",half2);
                                }
                                fclose(fptr);
                            }
                            else
                            printf("you should write -b or -f\n");
                        }
                    }
                    else
                        printf("you should write -size\n");
                }
            else
                printf("you should write i:j\n");
            }
        else
            printf("you should write --pos\n");
        }
    }
    else
        printf("you should write --file\n");


}
void pastestr(){
    char a[SIZE],half1[SIZE2],half2[SIZE2],b[7],c[6],first,v[SIZE];
    int i=0,j=0;
    struct moze pose;
    sscan(b);
    if(file_(b)){
        faddres(a);
        FILE *fptr;
        if((fptr=fopen(a,"r"))== NULL){
            printf("File could not open\n");
        }
        else{
            sscan(c);
            if(pos_(c)){
                first=cscan(first);
                i=nscan(i);
                first=cscan(first);
                if(first==':'){
                    j=nscan(j);
                    pose=copyfile(fptr,half1,half2,i,j);
                        fclose(fptr);
                        if(pose.i!=i || pose.j!=j){
                            printf("file doesn't long enough\n");
                        }
                        else{
                            fund(a);
                            fptr=fopen(a,"w");
                            if(half1[0]!='\0'){
                                fprintf(fptr,"%s",half1);
                            }
                            fprintf(fptr,"%s",copypaste);
                            if(half2[0]!='\0'){
                                fprintf(fptr,"%s",half2);
                            }
                            fclose(fptr);
                        }
                }
            else
                printf("you should write i:j\n");
            }
        else
            printf("you should write --pos\n");
        }
    }
    else
        printf("you should write --file\n");

}
void find(){
    FILE *fptr;
    char a[SIZE],b[6],c[7],d[SIZE2],f[SIZE2],dsort[SIZE2],model[SIZE],counting[]={"-count"},first,atnum[]={"-at"},word[]={"-byword"},all[]={"-all"};
    char *start;
    int n,z;
    sscan(b);
    if(str_(b)){
        finside(d);
        sscan(c);
        if(file_(c)){
            faddres(a);
            if((fptr=fopen(a,"r"))== NULL){
            printf("File could not open\n");
            }
            else{
                fcopy(fptr,f);
                fclose(fptr);
                sorting(d,dsort);
                z=strlen(dsort);
                if((start=strstr(f,dsort))==NULL){
                    printf("-1\n");
                }
                else{
                    first=cscan(first);
                    if(first!='\n'){
                        slashscan(model);
                        if(strcmp(model,counting)==0){
                            counter(f,dsort);
                        }
                        if(strcmp(model,atnum)==0){
                            atnumber(f,dsort);
                        }
                        if(strcmp(model,word)==0){
                            byword(f,dsort);
                        }
                        if(strcmp(model,word)==0){
                            byword(f,dsort);
                        }
                        if(strcmp(model,all)==0){
                            allnumber(f,dsort);
                        }
                    }
                    else{
                        n=start-f;
                        printf("%d\n",n);
                    }
                }
            }
        }
        else
            printf("you should write --file\n");
    }
    else
        printf("you should write --str\n");
}
void fcopy(FILE *fptr,char a[SIZE2]){
    char c;
    int i=0;
    for(i=0;!feof(fptr);i++){
        c=fgetc(fptr);
        a[i]=c;
    }
    a[i]='\0';
}
void sorting(char a[SIZE2],char b[SIZE2]){
    int z,i=0,j=0;
    z=strlen(a);
    for(i=0,j=0;i<z;i++,j++){
        if(a[i]=='\\'){
            if(a[i+1]=='*'){
                i++;
                b[j]=a[i];
            continue;
            }
        }
        if(a[i]=='*'){
            i++;
        }
        b[j]=a[i];
    }
    b[j]='\0';
}
void counter(char a[],char b[]){
    int n=0,answer=0,z=0,tol=0,j=0,i=0;
    char c[SIZE2];
    char *start;
    tol=strlen(b);
    strcpy(c,a);
    start=strstr(c,b);
    while(start!=NULL){
        answer++;
        z=start-c;
        n=n+z+tol;
        for(i=n,j=0;i<SIZE2 && a[i]!='\0';i++,j++){
            c[j]=a[i];
        }
        c[j]='\0';
        start=strstr(c,b);
    }
    printf("%d\n",answer);
}
void atnumber(char a[],char b[]){
    int n=0,answer=0,z=0,tol=0,j=0,i=0,k=0,shomare[SIZE],kodam;
    char c[SIZE2];
    char *start;
    kodam=nscan(kodam);
    tol=strlen(b);
    strcpy(c,a);
    start=strstr(c,b);
    while(start!=NULL){
        answer++;
        z=start-c;
        n=n+z+tol;
        shomare[k]=n;
        k++;
        for(i=n,j=0;i<SIZE2 && a[i]!='\0';i++,j++){
            c[j]=a[i];
        }
        c[j]='\0';
        start=strstr(c,b);
    }
    if(kodam<=answer && kodam>0){
        printf("%d\n",shomare[kodam-1]-tol);
    }
    else
        printf("-1\n");
}
void byword(char a[],char b[]){
    int n=0,answer=0,z=0,tol=0,j=0,i=0,k=0,shomare[SIZE],fasele=1;
    char c[SIZE2];
    char *start;
    tol=strlen(b);
    strcpy(c,a);
    start=strstr(c,b);
    while(start!=NULL){
        answer++;
        z=start-c;
        n=n+z+tol;
        shomare[k]=n;
        k++;
        for(i=n,j=0;i<SIZE2 && a[i]!='\0';i++,j++){
            c[j]=a[i];
        }
        c[j]='\0';
        start=strstr(c,b);
    }
    for(int t=0;t<shomare[0];t++){
        if(a[t]=='\n' || a[t]==' '){
            fasele++;
        }
    }
    printf("%d\n",fasele);
}
void allnumber(char a[],char b[]){
    int n=0,answer=0,z=0,tol=0,j=0,i=0,k=0,shomare[SIZE];
    char c[SIZE2];
    char *start;
    tol=strlen(b);
    strcpy(c,a);
    start=strstr(c,b);
    while(start!=NULL && answer<10){
        answer++;
        z=start-c;
        n=n+z+tol;
        shomare[k]=n;
        k++;
        for(i=n,j=0;i<SIZE2 && a[i]!='\0';i++,j++){
            c[j]=a[i];
        }
        c[j]='\0';
        start=strstr(c,b);
    }
    for(int t=0;t<k;t++){
        if(t<k-1)
            printf("%d,",shomare[t]);
        if(t==k-1)
            printf("%d",shomare[t]);
    }
}
void undo(){
    FILE *aptr;
    FILE *bptr;
    char a[SIZE],negahdara[SIZE2],b[SIZE],v[7],c[]={"/"},negahdar;
    int z,j=0;
    sscan(v);
    if(file_(v)){
        faddres(a);
        z=whatslash(a,c);
        for(int i=0;a[i]!='\0';i++,j++){
            if(i==z){
                b[j]='h';
                j++;
            }
            b[j]=a[i];

        }
        b[j]='\0';
        if((aptr=fopen(a,"r"))==NULL){
            printf("File could not open");
        }
        else{
            fcopy(aptr,negahdara);
            fclose(aptr);
            if((aptr=fopen(a,"w"))!=NULL){
                SetFileAttributes(b,FILE_ATTRIBUTE_NORMAL);
                bptr=fopen(b,"r");
                while(!feof(bptr)){
                    negahdar=fgetc(bptr);
                    fprintf(aptr,"%c",negahdar);
                }
                fclose(aptr);
                fclose(bptr);
            }
        }
        bptr=fopen(b,"w");
        fprintf(bptr,"%s",negahdara);
        fclose(bptr);
        SetFileAttributes(b,FILE_ATTRIBUTE_HIDDEN);
    }
    else
        printf("you should write --file");
}
void fund(char a[]){
    FILE *aptr;
    FILE *bptr;
    char b[SIZE],c[]={"/"},negahdar;
    int j=0;
    int z=whatslash(a,c);
    for(int i=0;a[i]!='\0';i++,j++){
            if(i==z){
                b[j]='h';
                j++;
            }
            b[j]=a[i];

        }
        b[j]='\0';

        if((aptr=fopen(a,"r"))!=NULL){
            SetFileAttributes(b,FILE_ATTRIBUTE_NORMAL);
            bptr=fopen(b,"w");
            while(!feof(aptr)){
                negahdar=fgetc(aptr);
                fprintf(bptr,"%c",negahdar);
            }
            fclose(aptr);
            fclose(bptr);
            SetFileAttributes(b,FILE_ATTRIBUTE_HIDDEN);
        }
}
int whatslash(char a[],char b[]){
    int n=0,answer=0,z=0,tol=0,j=0,i=0,k=0,shomare[SIZE];
    char c[SIZE2];
    char *start;
    tol=strlen(b);
    strcpy(c,a);
    start=strstr(c,b);
    while(start!=NULL && answer<10){
        answer++;
        z=start-c;
        n=n+z+tol;
        shomare[k]=n;
        k++;
        for(i=n,j=0;i<SIZE2 && a[i]!='\0';i++,j++){
            c[j]=a[i];
        }
        c[j]='\0';
        start=strstr(c,b);
    }
    for(int t=0;t<k;t++){
        if(t==k-1)
            return shomare[t];
    }
}
void ditree(){
    int shomar;
    shomar=nscan(shomar);
    char path[]={"root"};
    tree(path, 0);
}
void tree(char *basePath, const int root){
    int i;
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            for (i=0; i<root; i++)
            {
                if (i%2 == 0 || i == 0)
                    printf("%c", 179);
                else
                    printf(" ");

            }

            printf("%c%c%s\n", 195, 196, dp->d_name);

            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            tree(path, root + 2);
        }
    }

    closedir(dir);
}
