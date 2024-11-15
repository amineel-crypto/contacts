#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct cell{
    char nom[20];
    char prenom[20];
    char num[20];
    struct cell *suivant;
}contact;
contact *ajoutcontact(contact *tete,char nom[],char prenom[],char num[]){
    contact *newcontact=(contact *)malloc(sizeof(contact));
    if(newcontact==NULL){
        printf("il y'a un erruer.\n");
        exit(1);
    }
    strcpy(newcontact->nom,nom);
    strcpy(newcontact->prenom,prenom);
    strcpy(newcontact->num,num);
    if(tete==NULL){
        newcontact->suivant=NULL;
    }
    newcontact->suivant=tete;
    return newcontact;
}
void affichage(contact *tete){
    contact *p=tete;
    int i=0;
    while(p!=NULL){
        printf("le %d contact est:\n",i);
        printf("le nom: ");
        puts(p->nom);
        printf("le prenom: ");
        puts(p->prenom);
        printf("le numero: ");
        puts(p->num);
        p=p->suivant;
        i++;
    }
}
contact *ajoutfin(contact *tete,char nom[],char prenom[],char num[]){
    contact *newfin=(contact *)malloc(sizeof(contact));
    if(newfin==NULL){
        printf("il y'a un errur.\n");
        exit(1);
    }
    strcpy(newfin->nom,nom);
    strcpy(newfin->prenom,prenom);
    strcpy(newfin->num,num);
    newfin->suivant=NULL;
    if(tete==NULL){
        tete=newfin;
        return tete;
    }
    contact *p=tete;
    while(p->suivant!=NULL){
        p=p->suivant;
    }
    p->suivant=newfin;
    return tete;
}
contact *suppremerelem(contact *tete, char nom[],char prenom[],char num[]){
    if(tete==NULL){
        printf("l'allocation n'est pas fait.\n");
        exit(1);
    }
    if(strcmp(tete->nom,nom)==0 && strcmp(tete->prenom,prenom)==0 && strcmp(tete->num,num)==0){
        contact *temp=tete;
        tete=tete->suivant;
        free(temp);
        return tete;
    }
    contact *p=tete;
    while(p->suivant!=NULL && strcmp(p->suivant->nom,nom)==0 && strcmp(p->suivant->prenom,prenom)==0 && strcmp(p->suivant->num,num)==0){
        p=p->suivant;
    }
    if(p->suivant==NULL){
        printf("le contact n'existe pas.\n");
        exit(1);
    }
    contact *contactsupp=p->suivant;
    p->suivant=contactsupp->suivant;
    free(contactsupp);
    return tete;
}
int main()
{
    printf("-----------bonjour----------\n");
    printf("1.----ajouter debut------.\n");
    printf("2.-----ajouter a la fin-------.\n");
    printf("3.----suppremer---.\n");
    printf("4.------affichage----.\n");
    return 0;
}
