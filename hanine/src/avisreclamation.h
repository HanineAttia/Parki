#ifndef AVISRECLAMATION_H_INCLUDED
#define AVISRECLAMATION_H_INCLUDED
#include <stdio.h>
//#include <gtk/gtk.h>
typedef struct
{
	char identifiant_avis[50];
	char identifiant_citoyen[50];
	char identifiant_parking[50];
	char nom[50];
	char prenom[50];
	char description[1000];
	int note_avis;
	int jour, mois, annee;
	char image_path[100];
} avis;

typedef struct 
{
	char identifiant_reclamation[50];
	char identifiant_citoyen[50];
	char identifiant_parking[50];
	char identifiant_agent[50];
	char nom[50];
	char prenom[50];
	char description[1000];
	int jour, mois, annee;
	char type_reclamation[50];
} reclamation;
	

avis chercheravis(char*, char *);
reclamation chercherreclamation(char *, char *);
int ajouteravis(char *,avis);
int ajouterreclamation(char *,reclamation);
int modifierreclamation(char *,char *,reclamation);
int modifieravis(char *,char *,avis);
int supprimeravis(char *, char *);
int supprimerreclamation(char *,char *);
//void afficheravis(GtkWidget *liste);
//void afficherreclamation(GtkWidget *liste);
//void vider(GtkWidget *liste);
void afficheravistricroissante(char *);
void afficheravistridecroissante(char *);
int anonymeavis(char *,avis);
int anonymereclamation(char *,reclamation);
void afficheravisselonparking(char *, char *);
void afficherreclamationselonagent(char *, char *);
void afficherreclamationselonparking(char *, char *);
#endif

