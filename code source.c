#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct produit
    {
        char nom[12];
        float prix;
        char code[6];
    };
typedef struct produit produit;
struct index
{
    char code[6];
    int index;
};
typedef struct index index;
produit* allouertableau(int n);
index *allouerindex(int n,produit *s);
index *trier(index *v,int n);
void affichaget(index *v,produit* t,int n);
void existe(index *v,int n,produit *t);
void mettre_en_texte(produit *t,index *v,int n);

int main()
{
//definition de structre

    int n;
    printf("entrer n=");
    scanf("%d",&n);
    produit *t;
    //question 1
    t=allouertableau(n);
    //question 2
    index *v;
    v=allouerindex(n,t);
    //afficher v et t
    int i;
    for(i=0;i<n;i++)
    {
        printf("le nom t est %s \t",t[i].nom);
        printf("le prix t est %f \t",t[i].prix);
        printf("le code t est %s \t",t[i].code);
         printf("\n");
    }
    printf("\n");
     printf("\n");
      printf("\n");
     for(i=0;i<n;i++)
    {
        printf("le code v est %s \t",v[i].code);
        printf("l'index v est %d \t",v[i].index);
         printf("\n");
    }
    v=trier(v,n);
    printf("\n");
    printf("\n");
    //affichage de v
     for(i=0;i<n;i++)
    {
        printf("le code v est %s \t",v[i].code);
        printf("l'index v est %d \t",v[i].index);
         printf("\n");
    }
    //question 6
    affichaget(v,t,n);
    printf("\n");
    mettre_en_texte(t,v,n);


    return 0;




}

produit* allouertableau(int n)
// produit* = les cases du tableau sont de type produit
{
    produit* t;
    t=(produit*)malloc(n*sizeof(produit));
    int i;
    for(i=0;i<n;i++)
    {
        printf("entrer t[%d].nom=\n",i);
        scanf("%s",&t[i].nom);
        printf("entrer t[%d].prix=\n",i);
        scanf("%f",&t[i].prix);
        printf("entrer t[%d].code=\n",i);
        scanf("%s",&t[i].code);
    }
    return t;

}









index *allouerindex(int n,produit *s)
{

    index* t;
    t=(index*)malloc(n*sizeof(index));
    int i;
    for(i=0;i<n;i++)
    {
        strcpy(t[i].code,s[i].code);
        t[i].index=i;


    }
    return t;

}

















index* trier(index *v,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(strcmp((v[j].code),v[j+1].code)>0)
            {
                char temp[6];
                strcpy(temp,v[j].code);
                strcpy((v[j].code),v[j+1].code);
                strcpy(v[j+1].code,temp);
                int temp1;
                temp1=v[j].index;
                v[j].index=v[j+1].index;
                v[j+1].index=temp1;
            }
        }
    }

    return v;
}





//question 6
void affichaget(index *v,produit* t,int n)
{
    int i;
    for(i=0;i<n;i++)
        {printf("%s\t",t[v[i].index].nom);
         printf("%f\t",t[v[i].index].prix);
          printf("%s\t",t[v[i].index].code);
          printf("\n");
        }
}




void existe(index *v,int n,produit *t)
{
    char x[6];
    printf("enter x");
    scanf("%s",&x);
    if((strcmp((v[0].code),x)>0)&&strcmp((v[n].code),x)<0)
    {
        printf("n existe pas");
    }
    int a=0;
    int b=n;
    int m=(a+b)/2;
    while(m>1)
    {
        if(strcmp(x,v[m].code)==0)
        {
            printf("existe et sa position %d\n",m);
            printf("le nom est %s",t[v[m].index].nom);
            printf("le prix est %f",t[v[m].index].prix);
            break;
        }
        if(strcmp(v[m].code,x)<0)
        {
            a=m+1;
            m=(a+b)/2;

        }
        else
            {
                b=m-1;
                m=(a+b)/2;
            }
    }

}









void mettre_en_texte(produit *t,index *v,int n)
{
     FILE* fichier = NULL;

    fichier = fopen("code.txt","w");
    for(int k=0;k<n;k++)
    {
     fprintf(fichier,t[v[k].index].nom);
     fprintf(fichier,"\t");

     fprintf(fichier,"%f",t[v[k].index].prix);
     fprintf(fichier,"\t");

     fprintf(fichier,"%s",t[v[k].index].code);
     fprintf(fichier,"\n");

    }

    fclose(fichier);


}
