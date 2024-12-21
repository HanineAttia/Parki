#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "avisreclamation.h"




void
on_ha_ajouter_ajouter_avis_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
avis a;
GtkWidget *input1, *input2, *input3, *input5, *input6, *input7, *output;
GtkWidget *Jour, *Mois, *Annee, *note;
char msg[1000];
char formatted_msg[1024];
int x;

input1=lookup_widget(button,"ha_id_citoyen_ajouter_avis");
input2=lookup_widget(button,"ha_nom_ajouter_avis");
input3=lookup_widget(button,"ha_prenom_ajouter_avis");
input5=lookup_widget(button,"ha_id_avis_ajouter_avis");
input6=lookup_widget(button,"ha_id_parking_ajouter_avis");
input7=lookup_widget(button,"ha_description_ajouter_avis");
output=lookup_widget(button,"ha_output_ajouter_avis");
Jour=lookup_widget(button,"ha_jour_ajouter_avis");
Mois=lookup_widget(button,"ha_mois_ajouter_avis");
Annee=lookup_widget(button,"ha_anne_ajouter_avis");
note=lookup_widget(button,"ha_note_ajouter_avis");
strcpy(a.identifiant_citoyen,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(a.identifiant_avis,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(a.identifiant_parking,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(a.description,gtk_entry_get_text(GTK_ENTRY(input7)));
a.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Jour));
a.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Mois));
a.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Annee));
a.note_avis=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(note));
strcpy(msg,"Ajout fait avec succès!");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5); 
x=ajouteravis("avisreclamation.txt", a);

}




void
on_ha_afficher_dans_la_liste_modifier_avis_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ha_enregistrer_modifier_avis_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
avis a;
GtkWidget *input1, *input2, *input3, *input5, *input6, *input7, *output;
GtkWidget *Jour, *Mois, *Annee, *note;
char msg[1000];
int x;

input1=lookup_widget(button,"ha_id_cit_modifier_avis");
input2=lookup_widget(button,"ha_nom_modifier_avis");
input3=lookup_widget(button,"ha_prenom_modifier_avis");
input5=lookup_widget(button,"ha_id_avis_modifier_avis");
input6=lookup_widget(button,"ha_id_parking_modifier_avis");
input7=lookup_widget(button,"ha_description_modifier_avis");
output=lookup_widget(button,"ha_output_modifier_avis");
Jour=lookup_widget(button,"ha_jour_modifier_avis");
Mois=lookup_widget(button,"ha_mois_modifier_avis");
Annee=lookup_widget(button,"ha_annee_modifier_avis");
note=lookup_widget(button,"ha_note_modifier_avis");
strcpy(a.identifiant_citoyen,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(a.identifiant_avis,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(a.identifiant_parking,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(a.description,gtk_entry_get_text(GTK_ENTRY(input7)));
a.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Jour));
a.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Mois));
a.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Annee));
a.note_avis=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(note));
strcpy(msg,"modification faite avec succès!");
gtk_label_set_text(GTK_LABEL(output), msg);
x=modifieravis("avisreclamation.txt",a.identifiant_avis,a);

}




void
on_ha_rechercher_avis_modifier_avis_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
avis a;
GtkWidget *input1, *input2, *input3, *input5, *input6, *input7, *output;
GtkWidget *Jour, *Mois, *Annee, *note;
char msg[1000];
char formatted_msg[1024];
input5=lookup_widget(button,"ha_id_avis_modifier_avis");
strcpy(a.identifiant_avis,gtk_entry_get_text(GTK_ENTRY(input5)));
if (strlen(a.identifiant_avis)==0) {
strcpy(msg, "veuillez entrer un identifiant valide !");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
output=lookup_widget(button,"ha_output_modifier_avis");
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5);  
return;
}

a=chercheravis("avisreclamation.txt",a.identifiant_avis);
if (strcmp(a.identifiant_avis, "-1")!=0)
{
input1=lookup_widget(button,"ha_id_cit_modifier_avis");
input2=lookup_widget(button,"ha_nom_modifier_avis");
input3=lookup_widget(button,"ha_prenom_modifier_avis");
input5=lookup_widget(button,"ha_id_avis_modifier_avis");
input6=lookup_widget(button,"ha_id_parking_modifier_avis");
input7=lookup_widget(button,"ha_description_modifier_avis");
output=lookup_widget(button,"ha_output_modifier_avis");
Jour=lookup_widget(button,"ha_jour_modifier_avis");
Mois=lookup_widget(button,"ha_mois_modifier_avis");
Annee=lookup_widget(button,"ha_annee_modifier_avis");
note=lookup_widget(button,"ha_note_modifier_avis");
gtk_entry_set_text(GTK_ENTRY(input1),a.identifiant_citoyen);
gtk_entry_set_text(GTK_ENTRY(input2),a.nom);
gtk_entry_set_text(GTK_ENTRY(input3),a.prenom);
gtk_entry_set_text(GTK_ENTRY(input5),a.identifiant_avis);
gtk_entry_set_text(GTK_ENTRY(input6),a.identifiant_parking);
gtk_entry_set_text(GTK_ENTRY(input7),a.description);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(Jour),a.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(Mois),a.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(Annee),a.annee);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(note),a.note_avis);
strcpy(msg,"Avis trouvé! :)");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5);  
}
else
{
input1=lookup_widget(button,"ha_id_cit_modifier_avis");
input2=lookup_widget(button,"ha_nom_modifier_avis");
input3=lookup_widget(button,"ha_prenom_modifier_avis");
input5=lookup_widget(button,"ha_id_avis_modifier_avis");
input6=lookup_widget(button,"ha_id_parking_modifier_avis");
input7=lookup_widget(button,"ha_description_modifier_avis");
output=lookup_widget(button,"ha_output_modifier_avis");
Jour=lookup_widget(button,"ha_jour_modifier_avis");
Mois=lookup_widget(button,"ha_mois_modifier_avis");
Annee=lookup_widget(button,"ha_annee_modifier_avis");
note=lookup_widget(button,"ha_note_modifier_avis");
gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_entry_set_text(GTK_ENTRY(input6),"");
gtk_entry_set_text(GTK_ENTRY(input7),"");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(Jour),1);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(Mois),1);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(Annee),1850);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(note),1);
strcpy(msg,"Avis n'est pas trouvé! :( ");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5); 
}
}


void
on_ha_supprimer_avis_button_clicked    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_supp, *fenetre_msg;
fenetre_supp=lookup_widget(button,"avis");
fenetre_msg=create_supprimer_avis();
g_object_set_data(G_OBJECT(fenetre_msg),"avis",fenetre_supp);
gtk_widget_show(fenetre_msg);
}





void
on_ha_rechercher_avis_supprimer_avis_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
avis a;
GtkWidget *input1, *output;
char msg[1000];
char formatted_msg[1024];
input1=lookup_widget(button,"ha_id_avis_supprimer_avis");
strcpy(a.identifiant_avis,gtk_entry_get_text(GTK_ENTRY(input1)));
if (strlen(a.identifiant_avis)==0) {
strcpy(msg, "veuillez entrer un identifiant valide !");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
output=lookup_widget(button,"ha_output_supprimer_avis");
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5);  
return;
}

a=chercheravis("avisreclamation.txt",a.identifiant_avis);
if (strcmp(a.identifiant_avis, "-1")!=0)
{
output=lookup_widget(button,"ha_output_supprimer_avis");
strcpy(msg,"Avis trouvé! :)");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5);  
}
else
{
output=lookup_widget(button,"ha_output_supprimer_avis");
strcpy(msg,"Avis n'est pas trouvé! :( ");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5); 
}
}


void
on_ha_rechoisir_afficher_avis_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_choix, *fenetre_avis;
fenetre_avis=lookup_widget(button,"avis");
fenetre_choix=create_choisir();
gtk_widget_show(fenetre_choix);
gtk_widget_hide(fenetre_avis);
}



void
on_ha_mettre__jour_afficher_avis_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
    GtkWidget *treeview;
    GtkWidget *radiobutton_decroissant, *radiobutton_croissant, *radiobutton_sans_ordre, *combobox;
    GtkListStore *store;
    GtkTreeIter iter;
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeModelSort *sort_model;
    FILE *f;
    const gchar *selected_parking;

    // Récupérer le widget treeview
    treeview = lookup_widget(button, "ha_afficher_avis_treeview");

    // Récupérer les radiobuttons pour le tri
    radiobutton_decroissant = lookup_widget(button, "ha_ordre_decroissant_afficher_avis_radiobutton");
    radiobutton_croissant = lookup_widget(button, "ha_ordre_croissant_afficher_avis_radiobutton");
    radiobutton_sans_ordre = lookup_widget(button, "ha_sans_ordre_afficher_avis_radiobutton");

    combobox=lookup_widget(button,"ha_choisir_parking_afficher_avis_combo");

    // Définir les colonnes du treeview si ce n'est pas déjà fait
    if (gtk_tree_view_get_model(GTK_TREE_VIEW(treeview)) == NULL) {
        renderer = gtk_cell_renderer_text_new();

        column = gtk_tree_view_column_new_with_attributes("ID Citoyen", renderer, "text", 0, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", 1, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text", 2, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("ID Parking", renderer, "text", 3, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("ID avis", renderer, "text", 4, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("Description", renderer, "text", 5, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("Image", renderer, "text", 6, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("Note", renderer, "text", 7, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("Jour", renderer, "text", 8, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("Mois", renderer, "text", 9, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);

        column = gtk_tree_view_column_new_with_attributes("Annee", renderer, "text", 10, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
    }

    // Créer le modèle de données pour le treeview
    store = gtk_list_store_new(11,
        G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
        G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT,
        G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);

    // Lire les données depuis le fichier
    avis a;
    f = fopen("avisreclamation.txt", "r");
    if (f == NULL) {
        return;
    } else {
	if (gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)) == NULL || strcmp("Tous",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox))) == 0) {
        	while (fscanf(f, "%s %s %s %s %s %s %s %d %d %d %d\n",
                      	a.identifiant_citoyen, a.nom, a.prenom,
                      	a.identifiant_parking, a.identifiant_avis,
                      	a.description, a.image_path,
                      	&a.note_avis, &a.jour, &a.mois, &a.annee) != EOF) {
            		gtk_list_store_append(store, &iter);
            		gtk_list_store_set(store, &iter,
                               		0, a.identifiant_citoyen,
                               		1, a.nom,
                               		2, a.prenom,
                               		3, a.identifiant_parking,
                               		4, a.identifiant_avis,
                               		5, a.description,
                               		6, a.image_path,
                               		7, a.note_avis,
                               		8, a.jour,
                               		9, a.mois,
                               		10, a.annee,
                               		-1);
        	}
	}
	else if (strcmp("Zahra",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox))) == 0) {
        	while (fscanf(f, "%s %s %s %s %s %s %s %d %d %d %d\n",
                      	a.identifiant_citoyen, a.nom, a.prenom,
                      	a.identifiant_parking, a.identifiant_avis,
                      	a.description, a.image_path,
                      	&a.note_avis, &a.jour, &a.mois, &a.annee) != EOF) {
			if (strcmp(a.identifiant_parking,"Zahra") == 0) {
				gtk_list_store_append(store, &iter);
            			gtk_list_store_set(store, &iter,
                               			0, a.identifiant_citoyen,
                               			1, a.nom,
                               			2, a.prenom,
                               			3, a.identifiant_parking,
                               			4, a.identifiant_avis,
                               			5, a.description,
                               			6, a.image_path,
                               			7, a.note_avis,
                               			8, a.jour,
                               			9, a.mois,
                               			10, a.annee,
                               			-1);
			}
		}
	}
	else if (strcmp("Zaghouan",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox))) == 0) {
        	while (fscanf(f, "%s %s %s %s %s %s %s %d %d %d %d\n",
                      	a.identifiant_citoyen, a.nom, a.prenom,
                      	a.identifiant_parking, a.identifiant_avis,
                      	a.description, a.image_path,
                      	&a.note_avis, &a.jour, &a.mois, &a.annee) != EOF) {
			if (strcmp(a.identifiant_parking,"Zaghouan") == 0) {
				gtk_list_store_append(store, &iter);
            			gtk_list_store_set(store, &iter,
                               			0, a.identifiant_citoyen,
                               			1, a.nom,
                               			2, a.prenom,
                               			3, a.identifiant_parking,
                               			4, a.identifiant_avis,
                               			5, a.description,
                               			6, a.image_path,
                               			7, a.note_avis,
                               			8, a.jour,
                               			9, a.mois,
                               			10, a.annee,
                               			-1);
			}
		}
	}	
        fclose(f);
    }

    // Vérifier si le radiobutton "ha_ordre_croissant_afficher_avis" est activé
    if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton_croissant))) {
        // Créer un modèle trié basé sur le GtkListStore
        sort_model = GTK_TREE_MODEL_SORT(gtk_tree_model_sort_new_with_model(GTK_TREE_MODEL(store)));

        // Définir la colonne à utiliser pour le tri (colonne des notes)
        gtk_tree_sortable_set_sort_column_id(GTK_TREE_SORTABLE(sort_model), 7, GTK_SORT_ASCENDING);

        // Attacher le modèle trié au treeview
        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(sort_model));

        // Libérer les ressources inutilisées
        g_object_unref(store);
    }
    // Vérifier si le radiobutton "ha_ordre_decroissant_afficher_avis" est activé
    else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton_decroissant))) {
        // Créer un modèle trié basé sur le GtkListStore
        sort_model = GTK_TREE_MODEL_SORT(gtk_tree_model_sort_new_with_model(GTK_TREE_MODEL(store)));

        // Définir la colonne à utiliser pour le tri (colonne des notes)
        gtk_tree_sortable_set_sort_column_id(GTK_TREE_SORTABLE(sort_model), 7, GTK_SORT_DESCENDING);

        // Attacher le modèle trié au treeview
        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(sort_model));

        // Libérer les ressources inutilisées
        g_object_unref(store);
    } else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiobutton_sans_ordre))) {
        // Si aucun radiobutton sans ordre est activé, afficher les données sans tri
        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(store));

        // Libérer les ressources inutilisées
        g_object_unref(store);
    }
}

	




void
on_ha_oui_supprimer_reclamation_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
reclamation r;
GtkWidget *input1, *output;
GtkWidget *fenetre_supp, *fenetre_msg;
int x;
char msg[1000];
char formatted_msg[1024];
fenetre_msg=gtk_widget_get_toplevel(button);

fenetre_supp=g_object_get_data(G_OBJECT(fenetre_msg),"reclamation");
if (!fenetre_supp){
g_print("erreur: fentre supp introuvable\n");
return;
}
input1=lookup_widget(fenetre_supp,"ha_id_rec_supprimer_reclamtion");
if (!input1) { 
g_print("Erreur : Le widget input1 (ha_id_avis_supprimer_avis) n'a pas été trouvé.\n"); 
return;
} 
strcpy(r.identifiant_reclamation,gtk_entry_get_text(GTK_ENTRY(input1)));
x=supprimerreclamation("avisreclamation.txt",r.identifiant_reclamation);
output=lookup_widget(fenetre_supp,"ha_output_supprimer_reclamation");
 if (!output) {
g_print("Erreur : Le widget output (ha_output_supprimer_avis) n'a pas été trouvé.\n"); 
return;
}
if (x==1)
{
strcpy(msg,"suppression faite avec succes!");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5); 
}
else
{
strcpy(msg,"Échec de suppression!");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5); 
}
gtk_widget_hide(fenetre_msg);
}


void
on_ha_non_supprimer_reclamation_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
window1=lookup_widget(button,"supprimerreclamation");
gtk_widget_hide(window1);
}





void
on_ha_ajouter_reclamation_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
reclamation r;
GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *output;
GtkWidget *Jour, *Mois, *Annee, *combobox1;
char msg[1000];
char formatted_msg[1024];
int x;

input1=lookup_widget(button,"ha_id_cit_ajouter_reclmation");
input2=lookup_widget(button,"ha_nom_ajouter_reclamation");
input3=lookup_widget(button,"ha_prenom_ajouter_reclmation");
input4=lookup_widget(button,"ha_id_agent_ajouter_reclamation");
input5=lookup_widget(button,"ha_id_rec_ajouter_reclmation");
input6=lookup_widget(button,"ha_id_parking_ajouter_reclamation");
input7=lookup_widget(button,"ha_description_ajouter_reclamation");
output=lookup_widget(button,"ha_output_ajouter_reclamation");
Jour=lookup_widget(button,"ha_jour_ajouter_reclamlation");
Mois=lookup_widget(button,"ha_mois_ajouter_reclamation");
Annee=lookup_widget(button,"ha_annee_ajouter_reclmation");
combobox1=lookup_widget(button,"ha_type_reclmation_ajouter_reclamation_combo");
strcpy(r.identifiant_citoyen,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(r.identifiant_agent,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(r.identifiant_reclamation,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(r.identifiant_parking,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(r.description,gtk_entry_get_text(GTK_ENTRY(input7)));
r.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Jour));
r.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Mois));
r.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Annee));

if(strcmp("Delais d'attente",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Delais d'attente");
}
else if(strcmp("Qualite du Service",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Qualite du Service");
}
else if(strcmp("Disponibilite du Service",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Disponibilite du service");
}
else if(strcmp("Etat des Infrastructures",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Etat des Infrastructures");
}
else if(strcmp("Acceuil et Communication",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Acceuil et Communication");
}
else if(strcmp("Respect des Engagements",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Respect des Engagements");
}
else if(strcmp("Tarif ou Couts",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Tarif ou Couts");
}
else if(strcmp("Exactitude des informations",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Exactitude des informations");
}
else if(strcmp("Confidentialité et Securite des donnees",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Confidentialite et Securite des donnees");
}
else if(strcmp("Suivi et Resolution",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Suivi et Resolution");
}
else if(strcmp("Autre...",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Autre...");
}
strcpy(msg,"Ajout fait avec succès!");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5);  
x=ajouterreclamation("avisreclamation.txt", r);



}



void
on_ha_rechercher_id_rec_modifier_reclamation_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
reclamation r;
GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *output;
GtkWidget *Jour, *Mois, *Annee, *combobox1;
char msg[1000];
char formatted_msg[1024];
input5=lookup_widget(button,"ha_id_rec_modifier_reclamation");
strcpy(r.identifiant_reclamation,gtk_entry_get_text(GTK_ENTRY(input5)));
if (strlen(r.identifiant_reclamation)==0) {
strcpy(msg, "veuillez entrer un identifiant valide !");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
output=lookup_widget(button,"ha_output_modifier_reclamation");
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5);  
return;
}

r=chercherreclamation("avisreclamation.txt",r.identifiant_reclamation);
if (strcmp(r.identifiant_reclamation, "-1")!=0)
{
input1=lookup_widget(button,"ha_id_cit_modifier_reclmation");
input2=lookup_widget(button,"ha_nom_modifier_reclmation");
input3=lookup_widget(button,"ha_prenom_modifier_reclamation");
input4=lookup_widget(button,"ha_id_agent_modifier_reclmation");
input5=lookup_widget(button,"ha_id_rec_modifier_reclamation");
input6=lookup_widget(button,"ha_id_parking_modifier_reclamation");
input7=lookup_widget(button,"ha_description_modifier_reclamation");
output=lookup_widget(button,"ha_output_modifier_reclamation");
Jour=lookup_widget(button,"ha_jour_modifier_reclmation");
Mois=lookup_widget(button,"ha_mois_modifier_reclmation");
Annee=lookup_widget(button,"ha_annee_modifier_reclmation");
combobox1=lookup_widget(button,"ha_type_reclmation_modifier_reclamation_combo");
gtk_entry_set_text(GTK_ENTRY(input1),r.identifiant_citoyen);
gtk_entry_set_text(GTK_ENTRY(input2),r.nom);
gtk_entry_set_text(GTK_ENTRY(input3),r.prenom);
gtk_entry_set_text(GTK_ENTRY(input4),r.identifiant_agent);
gtk_entry_set_text(GTK_ENTRY(input5),r.identifiant_reclamation);
gtk_entry_set_text(GTK_ENTRY(input6),r.identifiant_parking);
gtk_entry_set_text(GTK_ENTRY(input7),r.description);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(Jour),r.jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(Mois),r.mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(Annee),r.annee);
if(strcmp(r.type_reclamation,"Autre...")==0){
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox1),10);
}
strcpy(msg,"Réclamation trouvée! :)");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5);  
}
else
{
input1=lookup_widget(button,"ha_id_cit_modifier_reclmation");
input2=lookup_widget(button,"ha_nom_modifier_reclmation");
input3=lookup_widget(button,"ha_prenom_modifier_reclamation");
input4=lookup_widget(button,"ha_id_agent_modifier_reclmation");
input5=lookup_widget(button,"ha_id_rec_modifier_reclamation");
input6=lookup_widget(button,"ha_id_parking_modifier_reclamation");
input7=lookup_widget(button,"ha_description_modifier_reclamation");
output=lookup_widget(button,"ha_output_modifier_reclamation");
Jour=lookup_widget(button,"ha_jour_modifier_reclmation");
Mois=lookup_widget(button,"ha_mois_modifier_reclmation");
Annee=lookup_widget(button,"ha_annee_modifier_reclmation");
combobox1=lookup_widget(button,"ha_type_reclmation_modifier_reclamation_combo");
gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input4),"");
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_entry_set_text(GTK_ENTRY(input6),"");
gtk_entry_set_text(GTK_ENTRY(input7),"");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(Jour),1);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(Mois),1);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(Annee),1850);
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox1),0);
strcpy(msg,"Réclamation n'est pas trouvée! :( ");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5); 
}
}



void
on_ha_enregistrer_modifier_reclamtion_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
reclamation r;
GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *output;
GtkWidget *Jour, *Mois, *Annee, *combobox1;
char msg[1000];
char formatted_msg[1024];
int x;

input1=lookup_widget(button,"ha_id_cit_modifier_reclmation");
input2=lookup_widget(button,"ha_nom_modifier_reclmation");
input3=lookup_widget(button,"ha_prenom_modifier_reclamation");
input4=lookup_widget(button,"ha_id_agent_modifier_reclmation");
input5=lookup_widget(button,"ha_id_rec_modifier_reclamation");
input6=lookup_widget(button,"ha_id_parking_modifier_reclamation");
input7=lookup_widget(button,"ha_description_modifier_reclamation");
output=lookup_widget(button,"ha_output_modifier_reclamation");
Jour=lookup_widget(button,"ha_jour_modifier_reclmation");
Mois=lookup_widget(button,"ha_mois_modifier_reclmation");
Annee=lookup_widget(button,"ha_annee_modifier_reclmation");
combobox1=lookup_widget(button,"ha_type_reclmation_modifier_reclamation_combo");
strcpy(r.identifiant_citoyen,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(r.identifiant_agent,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(r.identifiant_reclamation,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(r.identifiant_parking,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(r.description,gtk_entry_get_text(GTK_ENTRY(input7)));
r.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Jour));
r.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Mois));
r.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(Annee));

if(strcmp("Delais d'attente",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Delais d'attente");
}
else if(strcmp("Qualite du Service",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Qualite du Service");
}
else if(strcmp("Disponibilite du Service",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Disponibilite du service");
}
else if(strcmp("Etat des Infrastructures",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Etat des Infrastructures");
}
else if(strcmp("Acceuil et Communication",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Acceuil et Communication");
}
else if(strcmp("Respect des Engagements",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Respect des Engagements");
}
else if(strcmp("Tarif ou Couts",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Tarif ou Couts");
}
else if(strcmp("Exactitude des informations",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Exactitude des informations");
}
else if(strcmp("Confidentialité et Securite des donnees",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Confidentialite et Securite des donnees");
}
else if(strcmp("Suivi et Resolution",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Suivi et Resolution");
}
else if(strcmp("Autre...",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0){
strcpy(r.type_reclamation,"Autre...");
}
strcpy(msg,"Modification faite avec succes!");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5); 
x=modifierreclamation("avisreclamation.txt",r.identifiant_reclamation,r);

}




void
on_ha_afficher_liste_modifier_reclmation_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ha_supprimer_reclamtion_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_supp, *fenetre_msg;
fenetre_supp=lookup_widget(button,"reclamation");
fenetre_msg=create_supprimerreclamation();
g_object_set_data(G_OBJECT(fenetre_msg),"reclamation",fenetre_supp);
gtk_widget_show(fenetre_msg);
}





void
on_ha_rechercher_supprimer_reclmation_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
reclamation r;
GtkWidget *input1, *output;
char msg[1000];
char formatted_msg[1024];
input1=lookup_widget(button,"ha_id_rec_supprimer_reclamtion");
strcpy(r.identifiant_reclamation,gtk_entry_get_text(GTK_ENTRY(input1)));
if (strlen(r.identifiant_reclamation)==0) {
strcpy(msg, "veuillez entrer un identifiant valide !");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
output=lookup_widget(button,"ha_output_supprimer_reclamation");
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5);  
return;
}

r=chercherreclamation("avisreclamation.txt",r.identifiant_reclamation);
if (strcmp(r.identifiant_reclamation, "-1")!=0)
{
output=lookup_widget(button,"ha_output_supprimer_reclamation");
strcpy(msg,"Réclamation trouvée! :)");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5);  
}
else
{
output=lookup_widget(button,"ha_output_supprimer_reclamation");
strcpy(msg,"Réclamation n'est pas trouvée! :( ");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5); 
}
}


void
on_ha_rechoisir_afficher_reclamation_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_choix, *fenetre_rec;
fenetre_rec=lookup_widget(button,"reclamation");
fenetre_choix=create_choisir();
gtk_widget_show(fenetre_choix);
gtk_widget_hide(fenetre_rec);
}


void
on_ha_mettre__jour_afficher_reclamation_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
/*GtkWidget *notebook;
GtkWidget *treeview1;

notebook = lookup_widget(button, "ha_notebook_reclamation");
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),3);
treeview1 = lookup_widget(notebook, "ha_notebook_reclamation");
vider(treeview1);
afficherreclamation(treeview1);*/
}


void
on_ha_oui_supprimer_avis_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
avis a;
GtkWidget *input1, *output;
GtkWidget *fenetre_supp, *fenetre_msg;
int x;
char msg[1000];
char formatted_msg[1024];
fenetre_msg=gtk_widget_get_toplevel(button);

fenetre_supp=g_object_get_data(G_OBJECT(fenetre_msg),"avis");
if (!fenetre_supp){
g_print("erreur: fentre supp introuvable\n");
return;
}
input1=lookup_widget(fenetre_supp,"ha_id_avis_supprimer_avis");
if (!input1) { 
g_print("Erreur : Le widget input1 (ha_id_avis_supprimer_avis) n'a pas été trouvé.\n"); 
return;
} 
strcpy(a.identifiant_avis,gtk_entry_get_text(GTK_ENTRY(input1)));
x=supprimeravis("avisreclamation.txt",a.identifiant_avis);
output=lookup_widget(fenetre_supp,"ha_output_supprimer_avis");
 if (!output) {
g_print("Erreur : Le widget output (ha_output_supprimer_avis) n'a pas été trouvé.\n"); 
return;
}
if (x==1)
{
strcpy(msg,"suppression faite avec succes!");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5); 
}
else
{
strcpy(msg,"Échec de suppression!");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5); 
}
gtk_widget_hide(fenetre_msg);
}


void
on_ha_non_supprimer_avis_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window1;
window1=lookup_widget(button,"supprimer_avis");
gtk_widget_hide(window1);
}







void
on_ha_ordre_croissant_afficher_avis_radiobutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *button;
button=lookup_widget(GTK_WIDGET(togglebutton),"ha_mettre__jour_afficher_avis_button");
on_ha_mettre__jour_afficher_avis_button_clicked(button, user_data);
}


void
on_ha_ordre_decroissant_afficher_avis_radiobutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *button;
button=lookup_widget(GTK_WIDGET(togglebutton),"ha_mettre__jour_afficher_avis_button");
on_ha_mettre__jour_afficher_avis_button_clicked(button, user_data);
}





void
on_ha_afficher_dans_la_liste_button_ajouter_reclamation_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
/*GtkWidget *notebook;
GtkWidget *treeview1;

notebook = lookup_widget(button, "ha_notebook_reclamation");
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),3);
treeview1 = lookup_widget(notebook, "ha_notebook_reclamation");
afficherreclamation(treeview1);*/
}


void
on_ha_afficher_dans_la_liste_button_ajouter_avis_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
/*GtkWidget *notebook;
GtkWidget *treeview;
notebook=lookup_widget(GTK_WIDGET(button),"notebook1");
if (notebook==NULL){
g_print("erreur:gtknotebook introuvable");
return;
}
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),3);
treeview=lookup_widget(GTK_WIDGET(button),"ha_afficher_avis_treeview");
if (treeview ==NULL){
g_print("erreur:gtktreeview introuvable");
return;
}
afficheravis(treeview);*/
}


void
on_ha_afficher_avis_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_ha_liste_rec_afficher_reclamation_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
/*GtkTreeIter iter;
gchar* id_cit;
gchar* nomm;
gchar* prenomm;
gchar* id_park;
gchar* id_rec;
gchar* type_rec;
gchar* description_rec;
gchar* jourr;
gchar* moiss;
gchar* anneee;
reclamation r;
int x;

GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model, &iter, path)){
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id_cit, 1, &nomm, 2, &prenomm, 3, &id_park, 4, &id_rec, 5, &type_rec, 6, &description_rec, 7, &jourr, 8, &moiss, 9, &anneee, -1);
strcpy(r.identifiant_citoyen,id_cit);
strcpy(r.nom,nomm);
strcpy(r.prenom,prenomm);
strcpy(r.identifiant_parking,id_park);
strcpy(r.identifiant_reclamation,id_rec);
strcpy(r.type_reclamation,type_rec);
strcpy(r.description,description_rec);
strcpy(r.jour,jourr);
strcpy(r.mois,moiss);
strcpy(r.annee,anneee);
x=supprimerreclamation("avisreclamation.txt",r.identifiant_reclamation);
afficherreclamation(treeview);
}*/
}


void
on_ha_sans_ordre_afficher_avis_radiobutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
GtkWidget *button;
button=lookup_widget(GTK_WIDGET(togglebutton),"ha_mettre__jour_afficher_avis_button");
on_ha_mettre__jour_afficher_avis_button_clicked(button, user_data);
}

int choix[]={0,0};

void
on_ha_choisir_avis_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) {
choix[0]=1;
}
}


void
on_ha_choisir_reclamation_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)) {
choix[1]=1;
}
}




void
on_ha_effectuer_choix_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_choix, *fenetre_avis, *fenetre_rec, *output;
char msg[1000];
char formatted_msg[1024];
fenetre_choix=lookup_widget(button,"choisir");
fenetre_avis=create_avis();
fenetre_rec=create_reclamation();
if (choix[0]==1) {
gtk_widget_show(fenetre_avis);
gtk_widget_hide(fenetre_choix);
}
else if (choix[1]==1) {
gtk_widget_show(fenetre_rec);
gtk_widget_hide(fenetre_choix);
}
else if ((choix[0]==1) && (choix[1]==1)) {
gtk_widget_show_now(fenetre_rec);
gtk_widget_show_now(fenetre_avis);
gtk_widget_hide(fenetre_choix);
}
else if ((choix[0]==0) && (choix[1]==0)) {
output=lookup_widget(button,"ha_output_choisir");
strcpy(msg,"Vous n'avez pas fait un choix! :( ");
sprintf(formatted_msg, "<span color='red' weight='bold'>%s</span>", msg);
gtk_label_set_markup(GTK_LABEL(output), formatted_msg);
gtk_label_set_line_wrap(GTK_LABEL(output), TRUE);
gtk_misc_set_alignment(GTK_MISC(output),0.5, 0.5); 
}
}

