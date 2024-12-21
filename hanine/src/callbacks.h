#include <gtk/gtk.h>



void
on_ha_ajouter_ajouter_avis_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);



void
on_ha_afficher_dans_la_liste_modifier_avis_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_ha_enregistrer_modifier_avis_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);


void
on_ha_rechercher_avis_modifier_avis_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);


void
on_ha_supprimer_avis_button_clicked    (GtkWidget       *button,
                                        gpointer         user_data);


void
on_ha_rechercher_avis_supprimer_avis_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ha_rechoisir_afficher_avis_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ha_mettre__jour_afficher_avis_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ha_oui_supprimer_reclamation_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ha_non_supprimer_reclamation_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);


void
on_ha_ajouter_reclamation_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);


void
on_ha_rechercher_id_rec_modifier_reclamation_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);



void
on_ha_enregistrer_modifier_reclamtion_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);


void
on_ha_afficher_liste_modifier_reclmation_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_ha_supprimer_reclamtion_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ha_rechercher_supprimer_reclmation_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ha_rechoisir_afficher_reclamation_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ha_mettre__jour_afficher_reclamation_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ha_oui_supprimer_avis_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ha_non_supprimer_avis_button_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);


void
on_ha_ordre_croissant_afficher_avis_radiobutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ha_ordre_decroissant_afficher_avis_radiobutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_ha_afficher_dans_la_liste_button_ajouter_reclamation_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ha_afficher_dans_la_liste_button_ajouter_avis_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ha_afficher_avis_treeview_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ha_liste_rec_afficher_reclamation_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ha_sans_ordre_afficher_avis_radiobutton_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ha_choisir_avis_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ha_choisir_reclamation_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ha_choisir_les_deux_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ha_effectuer_choix_clicked          (GtkWidget       *button,
                                        gpointer         user_data);
