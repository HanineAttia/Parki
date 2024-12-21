#include "avisreclamation.h"
#include <string.h>
//#include <gtk/gtk.h>

/*enum
{
	ID_CIT_REC,
	NOM_REC,
	PRENOM_REC,
	ID_PARK_REC,
	ID_REC,
	TYPE_REC,
	DESCRIPTION_REC,
	JOUR_REC,
	MOIS_REC,
	ANNEE_REC,
	COLUMNS_A
};
enum
{
	ID_CIT_AVIS,
	NOM_AVIS,
	PRENOM_AVIS,
	ID_PARK_AVIS,
	ID_AVIS,
	DESCRIPTION_AVIS,
	IMAGE,
	NOTE,
	JOUR_AVIS,
	MOIS_AVIS,
	ANNEE_AVIS,
	COLUMNS
};*/
int ajouterreclamation(char * filename, reclamation r)
{
	FILE * f=fopen(filename, "a");
	if (f!=NULL)
	{
		fprintf(f,"%s %s %s %s %s %d %d %d %s %s %s\n", r.identifiant_citoyen,r.nom,r.prenom,r.type_reclamation,r.identifiant_agent,r.jour,r.mois,r.annee,r.identifiant_reclamation,r.description,r.identifiant_parking);
		fclose(f);
		return 1;
	}
	else return 0;
}

int ajouteravis(char * filename, avis a)
{
	FILE * f=fopen(filename, "a");
	if (f!=NULL)
	{
		fprintf(f,"%s %s %s %s %s %s %s %d %d %d %d\n",a.identifiant_citoyen,a.nom, a.prenom,a.identifiant_parking,a.identifiant_avis,a.description,a.image_path,a.note_avis,a.jour,a.mois,a.annee);
		fclose(f);
		return 1;
	}
	else return 0;
}


int anonymeavis(char * filename, avis a)
{
 	FILE * f=fopen(filename, "a");
	if (f!=NULL)
	{
		fprintf(f,"%s %s %s %s %s %d %d %d %d\n",a.identifiant_citoyen,a.identifiant_parking,a.identifiant_avis,a.description,a.image_path,a.note_avis,a.jour,a.mois,a.annee);
		fclose(f);
		return 1;
	}
	else return 0;
}

int anonymereclamation(char * filename, reclamation r)
{
 	FILE * f=fopen(filename, "a");
	if (f!=NULL)
	{
		fprintf(f,"%s %s %s %d %d %d %s %s %s\n", r.identifiant_citoyen,r.type_reclamation,r.identifiant_agent,r.jour,r.mois,r.annee,r.identifiant_reclamation,r.description,r.identifiant_parking);
		fclose(f);
		return 1;
	}
	else return 0;
}


int modifierreclamation(char * filename, char * identifiant, reclamation nouv)
{
	int tr=0;
	reclamation r;
	FILE * f=fopen(filename, "r");
	FILE * f2=fopen("nouv.txt", "w");
	if (f!=NULL && f2!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s\n",r.identifiant_citoyen,r.nom,r.prenom,r.type_reclamation,r.identifiant_agent,&r.jour,&r.mois,&r.annee,r.identifiant_reclamation,r.description,r.identifiant_parking)!=EOF)
		{
			if (strcmp(r.identifiant_reclamation,identifiant)==0) 
			{
				fprintf(f2,"%s %s %s %s %s %d %d %d %s %s %s\n", nouv.identifiant_citoyen,nouv.nom,nouv.prenom,nouv.type_reclamation,nouv.identifiant_agent,nouv.jour,nouv.mois,nouv.annee,nouv.identifiant_reclamation,nouv.description,nouv.identifiant_parking);
				tr=1;
			}
			else 
			{
				fprintf(f2,"%s %s %s %s %s %d %d %d %s %s %s\n", r.identifiant_citoyen,r.nom,r.prenom,r.type_reclamation,r.identifiant_agent,r.jour,r.mois,r.annee,r.identifiant_reclamation,r.description,r.identifiant_parking);
			}
		}
		fclose(f);
		fclose(f2);
	}
	remove(filename);
	rename("nouv.txt",filename);
	return tr;
}
int modifieravis(char * filename, char * identifiant, avis nouv)
{
	int tr=0;
	avis a;
	FILE * f=fopen(filename,"r");
	FILE * f1=fopen("nouv.txt","w");
	
	if (f!=NULL && f1!=NULL)
	{
		while (fscanf(f,"%s %s %s %s %s %s %s %d %d %d %d\n",a.identifiant_citoyen,a.nom,a.prenom,a.identifiant_parking,a.identifiant_avis,a.description,a.image_path,&a.note_avis,&a.jour,&a.mois,&a.annee)!=EOF)
		{
			if (strcmp(a.identifiant_avis, identifiant)==0)
			{
				fprintf(f1,"%s %s %s %s %s %s %s %d %d %d %d\n",nouv.identifiant_citoyen,nouv.nom,nouv.prenom,nouv.identifiant_parking,nouv.identifiant_avis,nouv.description,nouv.image_path,nouv.note_avis,nouv.jour,nouv.mois,nouv.annee);
				tr=1;			
			}
			else
			{
				fprintf(f1,"%s %s %s %s %s %s %s %d %d %d %d\n",a.identifiant_citoyen,a.nom,a.prenom,a.identifiant_parking,a.identifiant_avis,a.description,a.image_path,a.note_avis,a.jour,a.mois,a.annee);
			}
		}
	
		fclose(f);
		fclose(f1);
		remove(filename);
		rename("nouv.txt",filename);
	}
	else
	{	
		printf("Erreur lors de l'ouverture du fixhier\n");
		return 0;
	}
		
	
	return tr;
}
int supprimeravis( char * filename, char * identifiant)
{
	int tr=0;
	avis a;
	FILE * f=fopen(filename,"r");
	FILE * f2=fopen("nouv.txt","w");
	if (f!=NULL && f2!=NULL)
	{
		while (fscanf(f,"%s %s %s %s %s %s %s %d %d %d %d\n",a.identifiant_citoyen,a.nom,a.prenom,a.identifiant_parking,a.identifiant_avis,a.description,a.image_path,&a.note_avis,&a.jour,&a.mois,&a.annee)!=EOF)
		{
			if (strcmp(a.identifiant_avis,identifiant)==0)
			{
				tr=1;
			}
			else
			{
				fprintf(f2,"%s %s %s %s %s %s %s %d %d %d %d\n",a.identifiant_citoyen,a.nom,a.prenom,a.identifiant_parking,a.identifiant_avis,a.description,a.image_path,a.note_avis,a.jour,a.mois,a.annee);
			}
		}
		fclose(f);
		fclose(f2);
	}
	remove(filename);
	rename("nouv.txt",filename);
	return tr;
}

int supprimerreclamation( char * filename, char * identifiant)
{
	int tr=0;
	reclamation r;
	FILE * f=fopen(filename,"r");
	FILE * f2=fopen("nouv.txt","w");
	if (f!=NULL && f2!=NULL)
	{
		while (fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s\n",r.identifiant_citoyen,r.nom,r.prenom,r.type_reclamation,r.identifiant_agent,&r.jour,&r.mois,&r.annee,r.identifiant_reclamation,r.description,r.identifiant_parking)!=EOF)
		{
			if (strcmp(r.identifiant_reclamation,identifiant)==0)
			{
				tr=1;
			}
			else
			{
				fprintf(f2,"%s %s %s %s %s %d %d %d %s %s %s\n",r.identifiant_citoyen,r.nom,r.prenom,r.type_reclamation,r.identifiant_agent,r.jour,r.mois,r.annee,r.identifiant_reclamation,r.description,r.identifiant_parking);
			}
		}
		fclose(f);
		fclose(f2);
	}
	remove(filename);
	rename("nouv.txt",filename);
	return tr;
}


reclamation chercherreclamation (char * filename, char * identifiant)
{
	reclamation r;
	int tr=0;
	FILE * f=fopen(filename, "r");
	if (f!=NULL)
	{
		while (tr==0 && fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s\n",r.identifiant_citoyen,r.nom,r.prenom,r.type_reclamation,r.identifiant_agent,&r.jour,&r.mois,&r.annee,r.identifiant_reclamation,r.description,r.identifiant_parking)!=EOF)
		{
			if (strcmp(r.identifiant_reclamation, identifiant)==0)
			{
				tr=1;
			}
		}
		fclose(f);
	}
	if (tr==0)
	{
		strcpy(r.identifiant_reclamation,"-1");
	}
	return r;
}


avis chercheravis (char * filename, char * identifiant)
{
	avis a;
	int tr=0;
	FILE * f=fopen(filename, "r");
	if (f!=NULL)
	{
		while (tr==0 && fscanf(f,"%s %s %s %s %s %s %s %d %d %d %d\n",a.identifiant_citoyen,a.nom,a.prenom,a.identifiant_parking,a.identifiant_avis,a.description,a.image_path,&a.note_avis,&a.jour,&a.mois,&a.annee)!=EOF)
		{
			if (strcmp(a.identifiant_avis, identifiant)==0)
			{
				tr=1;
			}
		}
		fclose(f);
	}
	if (tr==0)
	{
		strcpy(a.identifiant_avis,"-1");
	}
	return a;
}

/*void afficheravis (GtkWidget *liste)
{


	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter	iter;
	GtkListStore *store;
	
	char id_cit[50];
	char nom[50];
	char prenom[50];
	char id_park[50];
	char id_avis[50];
	char description[50];
	char jour[50];
	char mois[50];
	char annee[50];
	char image[50];
	char note[50];

	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL) 
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Identifiant du citoyen", renderer, "text", ID_CIT_AVIS, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", NOM_AVIS, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text", PRENOM_AVIS, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("identifiant du parking", renderer, "text", ID_PARK_AVIS, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Identifiant de l'avis", renderer, "text", ID_AVIS, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Description", renderer, "text", DESCRIPTION_AVIS, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Image", renderer, "text", IMAGE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Note", renderer, "text", IMAGE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Jour", renderer, "text", JOUR_AVIS, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Mois", renderer, "text", MOIS_AVIS, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Annee", renderer, "text", ANNEE_AVIS, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("avisreclamation.txt", "r");
	if (f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("avisreclamation.txt","a+");
		while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",id_cit,nom,prenom,id_park,id_avis,description,image,note,jour,mois,annee)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter, ID_CIT_AVIS, id_cit, NOM_AVIS, nom,  PRENOM_AVIS, prenom, ID_PARK_AVIS, id_park, ID_AVIS, id_avis, DESCRIPTION_AVIS, description, IMAGE, image, NOTE, note, JOUR_AVIS, jour, MOIS_AVIS, mois, ANNEE_AVIS, annee, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}
}*/


/*void afficherreclamation (GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter	iter;
	GtkListStore *store;
	reclamation r;
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
	if (store==NULL) 
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Identifiant du citoyen", renderer, "text", ID_CIT_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", NOM_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text", PRENOM_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("identifiant du parking", renderer, "text", ID_PARK_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Identifiant de la reclamation", renderer, "text", ID_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Type de la reclamation", renderer, "text", TYPE_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Description", renderer, "text", DESCRIPTION_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Jour", renderer, "text", JOUR_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Mois", renderer, "text", MOIS_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Annee", renderer, "text", ANNEE_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("avisreclamation.txt", "r");
	if (f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("avisreclamation.txt","a+");
		while (fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s\n",r.identifiant_citoyen,r.nom,r.prenom,r.type_reclamation,r.identifiant_agent,&r.jour,&r.mois,&r.annee,r.identifiant_reclamation,r.description,r.identifiant_parking)!=EOF)
		{
			gtk_list_store_append (store, &iter);
			gtk_list_store_set (store, &iter, ID_CIT_REC, r.identifiant_citoyen, NOM_REC, r.nom,  PRENOM_REC, r.prenom, ID_PARK_REC, r.identifiant_parking, ID_REC, r.identifiant_reclamation, TYPE_REC, r.type_reclamation, DESCRIPTION_REC, r.description, JOUR_REC, &r.jour, MOIS_REC, &r.mois, ANNEE_REC, &r.annee, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
		g_object_unref (store);
	}
}



void vider(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter	iter;
	GtkListStore *store;
	reclamation r;
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL) 
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Identifiant du citoyen", renderer, "text", ID_CIT_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", NOM_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text", PRENOM_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("identifiant du parking", renderer, "text", ID_PARK_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Identifiant de la reclamation", renderer, "text", ID_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Type de la reclamation", renderer, "text", TYPE_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Description", renderer, "text", DESCRIPTION_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Jour", renderer, "text", JOUR_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Mois", renderer, "text", MOIS_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Annee", renderer, "text", ANNEE_REC, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);	
	gtk_list_store_append (store, &iter);	
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
}*/	

void afficheravistridecroissante(char * filename)
{
    avis avi[100];
    int count = 0;
    FILE *f = fopen(filename, "r");
    if (f != NULL)
    {
        
        while (fscanf(f, "%s %s %s %s %s %s %s %d %d %d %d\n", avi[count].identifiant_citoyen, avi[count].nom, avi[count].prenom, avi[count].identifiant_parking, avi[count].identifiant_avis, avi[count].description, avi[count].image_path, &avi[count].note_avis, &avi[count].jour, &avi[count].mois, &avi[count].annee) != EOF)
        {
            count++;
        }
        fclose(f);

        
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - i - 1; j++)
            {
                if (avi[j].note_avis < avi[j + 1].note_avis)  
                {
                    avis temp = avi[j];
                    avi[j] = avi[j + 1];
                    avi[j + 1] = temp;
                }
            }
        }

        
        FILE *f_temp = fopen("avis_trie.txt", "w+");
        if (f_temp != NULL)
        {
            for (int i = 0; i < count; i++)
            {
                fprintf(f_temp, "%s %s %s %s %s %s %s %d %d %d %d\n", avi[i].identifiant_citoyen, avi[i].nom, avi[i].prenom, avi[i].identifiant_parking, avi[i].identifiant_avis, avi[i].description, avi[i].image_path, avi[i].note_avis, avi[i].jour, avi[i].mois, avi[i].annee);
            }

            
            rewind(f_temp);

            avis a;
            while (fscanf(f_temp, "%s %s %s %s %s %s %s %d %d %d %d\n", a.identifiant_citoyen, a.nom, a.prenom, a.identifiant_parking, a.identifiant_avis, a.description, a.image_path, &a.note_avis, &a.jour, &a.mois, &a.annee) != EOF)
            {
                printf("ID Citoyen: %s\n", a.identifiant_citoyen);
                printf("Nom: %s\n", a.nom);
		printf("Prenom: %s\n", a.prenom);
                printf("ID Parking: %s\n", a.identifiant_parking);
                printf("ID Avis: %s\n", a.identifiant_avis);
                printf("La Description: %s\n", a.description);
                printf("Image: %s\n", a.image_path);
                printf("La note: %d\n", a.note_avis);
                printf("La date: %d/%d/%d\n", a.jour, a.mois, a.annee);
            }
            fclose(f_temp);
        }
    }
}


void afficheravistricroissante(char * filename)
{
    avis avi[100];
    int count = 0;
    FILE *f = fopen(filename, "r");
    if (f != NULL)
    {
        
        while (fscanf(f, "%s %s %s %s %s %s %s %d %d %d %d\n", avi[count].identifiant_citoyen, avi[count].nom, avi[count].prenom, avi[count].identifiant_parking, avi[count].identifiant_avis, avi[count].description, avi[count].image_path, &avi[count].note_avis, &avi[count].jour, &avi[count].mois, &avi[count].annee) != EOF)
        {
            count++;
        }
        fclose(f);

        
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - i - 1; j++)
            {
                if (avi[j].note_avis > avi[j + 1].note_avis)
                {
                    avis temp = avi[j];
                    avi[j] = avi[j + 1];
                    avi[j + 1] = temp;
                }
            }
        }

       
        FILE *f_temp = fopen("avis_trie.txt", "w+");
        if (f_temp != NULL)
        {
            for (int i = 0; i < count; i++)
            {
                fprintf(f_temp, "%s %s %s %s %s %s %s %d %d %d %d\n", avi[i].identifiant_citoyen, avi[i].nom, avi[i].prenom, avi[i].identifiant_parking, avi[i].identifiant_avis, avi[i].description, avi[i].image_path, avi[i].note_avis, avi[i].jour, avi[i].mois, avi[i].annee);
            }

           
            rewind(f_temp);

            avis a;
            while (fscanf(f_temp, "%s %s %s %s %s %s %s %d %d %d %d\n", a.identifiant_citoyen, a.nom, a.prenom, a.identifiant_parking, a.identifiant_avis, a.description, a.image_path, &a.note_avis, &a.jour, &a.mois, &a.annee) != EOF)
            {
                printf("ID Citoyen: %s\n", a.identifiant_citoyen);
                printf("Nom: %s\n", a.nom);
		printf("Prenom: %s\n", a.prenom);
                printf("ID Parking: %s\n", a.identifiant_parking);
                printf("ID Avis: %s\n", a.identifiant_avis);
                printf("La Description: %s\n", a.description);
                printf("Image: %s\n", a.image_path);
                printf("La note: %d\n", a.note_avis);
                printf("La date: %d/%d/%d\n", a.jour, a.mois, a.annee);
            }
            fclose(f_temp);
        }
    }
}


void afficheravisselonparking(char * filename, char * idparking)
{
	int tr=0;
	avis a;
	FILE * f=fopen(filename, "r");
	if (f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %s %s %d %d %d %d\n",a.identifiant_citoyen,a.nom,a.prenom,a.identifiant_parking,a.identifiant_avis,a.description,a.image_path,&a.note_avis,&a.jour,&a.mois,&a.annee)!=EOF)
		{
			if (strcmp(a.identifiant_parking, idparking)==0)
			{
				printf("ID Citoyen: %s\n",a.identifiant_citoyen);
				printf("Nom: %s\n",a.nom);
				printf("Prenom: %s\n",a.prenom);
				printf("ID Parking: %s\n",a.identifiant_parking);
				printf("ID Avis: %s\n",a.identifiant_avis);
				printf("La Description: %s\n",a.description);
				printf("Image: %s\n",a.image_path);
				printf("La note: %d\n",a.note_avis);
				printf("La date: %d/%d/%d\n",a.jour,a.mois,a.annee);
				tr=1;
				break;
			}
		}
		fclose(f);
	}
	if (tr==0)
	{
		printf("le Parking d'ID %s est non trouvé\n",idparking);
	}
}


void afficherreclamationselonagent(char * filename, char * idagent)
{
	int tr=0;
	reclamation r;
	FILE * f=fopen(filename, "r");
	if (f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s\n",r.identifiant_citoyen,r.nom,r.prenom,r.type_reclamation,r.identifiant_agent,&r.jour,&r.mois,&r.annee,r.identifiant_reclamation,r.description,r.identifiant_parking)!=EOF)
		{
			if (strcmp(r.identifiant_agent, idagent)==0)
			{
				printf("ID Citoyen: %s\n",r.identifiant_citoyen);
				printf("Nom: %s\n",r.nom);
				printf("Prenom: %s\n",r.prenom);
				printf("le type de reclamation: %s\n",r.type_reclamation);
				printf("ID Agent: %s\n",r.identifiant_agent);
				printf("ID Reclamation: %s\n",r.identifiant_reclamation);
				printf("La Description: %s\n",r.description);
				printf("ID Parking: %s\n",r.identifiant_parking);
				printf("La date: %d/%d/%d\n",r.jour,r.mois,r.annee);
				tr=1;
				break;
			}
		}
		fclose(f);
	}
	if (tr==0)
	{
		printf("l'agent d'ID %s est non trouvé\n",idagent);
	}
}


void afficherreclamationselonparking(char * filename, char * idparking)
{
	int tr=0;
	reclamation r;
	FILE * f=fopen(filename, "r");
	if (f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s\n",r.identifiant_citoyen,r.nom,r.prenom,r.type_reclamation,r.identifiant_agent,&r.jour,&r.mois,&r.annee,r.identifiant_reclamation,r.description,r.identifiant_parking)!=EOF)
		{
			if (strcmp(r.identifiant_parking, idparking)==0)
			{
				printf("ID Citoyen: %s\n",r.identifiant_citoyen);
				printf("Nom: %s\n",r.nom);
				printf("Prenom: %s\n",r.prenom);
				printf("le type de reclamation: %s\n",r.type_reclamation);
				printf("ID Agent: %s\n",r.identifiant_agent);
				printf("ID Reclamation: %s\n",r.identifiant_reclamation);
				printf("La Description: %s\n",r.description);
				printf("ID Parking: %s\n",r.identifiant_parking);
				printf("La date: %d/%d/%d\n",r.jour,r.mois,r.annee);
				tr=1;
				break;
			}
		}
		fclose(f);
	}
	if (tr==0)
	{
		printf("le parking d'ID %s est non trouvé\n",idparking);
	}
}



		 		
	

			
			

