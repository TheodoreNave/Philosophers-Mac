Manger != penser / dormir Dormir != manger / penser; Penser != manger / dormir;

Fourchettes = nb_philo

nb_philo = thread

2 Fourchettes pour manger

manger -> dormir -> penser

Fin si un philosopher meurt (de faim)

Programmes prend [nb_philo] [time_to_die] [time_to_eat] [time_to_sleep] [nb_times_each_philo_must_eat]

[nb_philo] = nb_philo et de fourchettes [time_to_die] = Si philo pas commence a manger [time_to_die]] ms apres le debut de son repas d'avant ou depuis le debut il meurt. [time_to_eat] = Le temps qu'un philo prend a manger. pendant ce temps un philo doit garder ses deux fourchettes. [time_to_sleep] = Le temps qu'un philo passe a dormir [nb_times_each_philo_must_eat] = Si tt les philo ont mange au moins [nb_times_each_philo_must_eat] cela prend fin mais si cet argument n'est pas specifie alors cela prend fin a la mort d'un philo

Chaque philo a un numero entre 1 et [nb_philo]

Le philo num. 1 est assis a cote du philo num. [nb_philo].

[Graphique_table_insert]

◦ timestamp_in_ms X has taken a fork ◦ timestamp_in_ms X is eating ◦ timestamp_in_ms X is sleeping ◦ timestamp_in_ms X is thinking ◦ timestamp_in_ms X died

remplacez timestamp par le timestamp en ms et X par le num. du philo

Chaque message ne doit pas se melanger avec un autre

pas + de 10ms entre la mort d'un philo et l'affichage du message annoncant sa mort

Chaque fourchettes proteger avec un fork pour ne pas dupliquer les fourchettes.