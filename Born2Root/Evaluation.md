## Comment fonctionne une machine virtuelle

Une machine virtuelle (VM) est un environnement logiciel qui simule un ordinateur physique.
Elle fonctionne comme un ordinateur réel, avec un système d'exploitation (OS) propre, mais
elle est hébergée sur un autre ordinateur appelé hôte. Utiliser les ressources de la machine
hôte (CPU, RAM).

## Choix du système d'exploitation

Debian : Flexible, stable, adapté aux débutants

## Les différences de base entre Rocky et Debian

Débian :
    Simplifié, polyvalent, gestionnaire de paquets basé sur APT.
Rocky :
    Orienté entreprises, gestionnaire de paquets basé sur DNF/YUM.

## Le but des machines virtuelles

Les VM peuvent être déployées pour répondre à différents niveaux de besoins en puissance de traitement, pour exécuter des logiciels nécessitant un système d'exploitation différent, ou pour tester des applications dans un environnement sûr et isolé.

## La différence entre `aptitude` et `apt`

Aptitude est un gestionnaire de paquets de haut niveau tandis qu'APT est un gestionnaire de paquets de bas niveau qui peut être utilisé par d'autres gestionnaires de paquets de haut niveau.

Aptitude est plus vaste en fonctionnalités qu'**apt-get** et intègre les fonctionnalités de **apt-get** et de ses autres variantes, y compris **apt-mark** et **apt-cache**.

[En savoir plus](https://www.tecmint.com/difference-between-apt-and-aptitude/)

## Qu'est-ce qu'APPArmor

Vérifier le statut d'APPArmor

```bash
sudo aa-status
```

AppArmor ("Application Armor") est un module de sécurité du noyau Linux qui permet à l'administrateur système de restreindre les capacités des programmes avec des profils par programme.

Les profils peuvent autoriser des capacités comme l'accès au réseau, l'accès aux sockets brutes, et la permission de lire, écrire ou exécuter des fichiers sur des chemins correspondants.

[En savoir plus](https://en.wikipedia.org/wiki/AppArmor)

## Vérification

- [x] Script s'exécutant toutes les 10 minutes
- [x] Pas d'interface graphique
- [x] Mot de passe demandé au démarrage
- [x] Connexion avec `lobenard`
- [x] Le mot de passe doit suivre des règles

## Vérifier que le service UFW est démarré

```bash
sudo ufw status
```

## Vérifier que le service SSH est démarré

```bash
sudo service ssh status
```

## Vérifier que le système d'exploitation est Debian

```bash
cat /etc/os-release | grep PRETTY_NAME
```

## Vérifier que `lobenard` est membre des groupes `sudo` et `user42`

```bash
groups lobenard
```

## Vérifier les règles de politique de mot de passe

Expiration du mot de passe

```bash
vi /etc/login.defs
```

Politique de mot de passe

```bash
vi /etc/pam.d/common-password
```

### Créer un nouvel utilisateur

```bash
sudo adduser new_user
```

### Attribuer un mot de passe

Confirmer qu'il suit la politique de mot de passe

### Expliquer comment les règles de mot de passe ont été configurées

```bash
vi /etc/pam.d/common-password
```

## Créer un groupe `evaluating` et ajouter l'utilisateur créé

```bash
sudo addgroup evaluating
sudo adduser new_user evaluating
```

### Vérifier que l'utilisateur appartient au nouveau groupe

```bash
groups new_user
```

## Expliquer les avantages de la politique de mot de passe et les avantages et inconvénients de la mise en œuvre de la politique

En théorie, le principal avantage des règles de complexité des mots de passe est qu'elles imposent l'utilisation de mots de passe uniques qui sont plus difficiles à craquer. Plus vous imposez de contraintes, plus le nombre de combinaisons possibles de lettres, chiffres et caractères est élevé.

Les règles de complexité des mots de passe tentent d'imposer cette exigence de "difficulté à craquer", mais elles ne sont pas toujours couronnées de succès. Cela est en partie dû aux rendements décroissants impliqués dans l'augmentation de la complexité.

À quel point un mot de passe de 15 caractères est-il meilleur qu'un mot de passe de 30 caractères si les pirates savent que ce mot de passe plus long est fréquemment utilisé ? Et est-il meilleur si l'utilisateur ne peut pas s'en souvenir ? La complexité des mots de passe ne s'échelonne que jusqu'à un certain point. Au-delà d'un certain point, un mot de passe complexe peut être difficile à craquer si le nombre de combinaisons possibles est extrêmement élevé, mais il peut aussi être trop complexe pour être utile aux utilisateurs.

## Vérifier que le nom d'hôte de la machine est `lobenard42`

```bash
uname -n
# ou
hostname
```

## Modifier le nom d'hôte avec la connexion de l'évaluateur et redémarrer pour confirmer le changement

```bash
sudo adduser new_user sudo
sudo login new_user
sudo vi /etc/hostname # changer en new_user42
sudo reboot
```

### Restaurer le nom d'hôte d'origine

```bash
sudo vi /etc/hostname # changer en lobenard42
sudo reboot
```

## Comment afficher les partitions

```bash
lsblk
```

### Comparer la sortie des partitions avec l'exemple dans le sujet

```bash
NAME                    MAJ:MIN RM  SIZE RO TYPE  MOUNTPOINT
sda                       8:0    0    8G  0 disk
|-sda1                    8:1    0  476M  0 part  /boot
|-sda2                    8:2    0    1K  0 part
`-sda5                    8:5    0  7.5G  0 part
  `-sda5_crypt          254:0    0  7.5G  0 crypt
    |-LVMGroup-root     254:1    0  1.9G  0 lvm   /
    |-LVMGroup-swap     254:2    0  952M  0 lvm   [SWAP]
    |-LVMGroup-home     254:3    0  952M  0 lvm   /home
    |-LVMGroup-var      254:4    0  952M  0 lvm   /var
    |-LVMGroup-srv      254:5    0  952M  0 lvm   /srv
    |-LVMGroup-tmp      254:6    0  952M  0 lvm   /tmp
    `-LVMGroup-var--log 254:7    0    1G  0 lvm   /var/log
sr0                      11:0    1 1024M  0 rom
```

## Brève explication du fonctionnement de LVM

Il fonctionne en découpant les volumes physiques (PV) en extensions physiques (PE). Les PE sont mappées sur des extensions logiques (LE) qui sont ensuite regroupées en groupes de volumes (VG). Ces groupes sont liés entre eux en volumes logiques (LV) qui agissent comme des partitions de disque virtuelles et qui peuvent être gérées comme telles en utilisant LVM.

[En savoir plus](https://searchdatacenter.techtarget.com/definition/logical-volume-management-LVM)

## Qu'est-ce que LVM ?

La gestion des volumes logiques (LVM) est une forme de virtualisation du stockage qui offre aux administrateurs système une approche plus flexible pour gérer l'espace de stockage sur disque que le partitionnement traditionnel. L'objectif de LVM est de faciliter la gestion des besoins de stockage parfois conflictuels de plusieurs utilisateurs finaux.

## Vérifier que le programme `sudo` est correctement installé

```bash
dpkg -l | grep sudo
```

## Attribuer le nouvel utilisateur au groupe `sudo`

```bash
sudo adduser new_user sudo
```

## Expliquer la valeur et le fonctionnement de sudo en utilisant des exemples

Sudo signifie SuperUser DO et est utilisé pour accéder à des fichiers et opérations restreints. Par défaut, Linux restreint l'accès à certaines parties du système, empêchant ainsi la compromission de fichiers sensibles.

La commande sudo élève temporairement les privilèges, permettant aux utilisateurs de terminer des tâches sensibles sans se connecter en tant qu'utilisateur root.

```bash
apt-get update # Erreur 13 : Permission refusée
sudo apt-get update
```

[En savoir plus](https://phoenixnap.com/kb/linux-sudo-command)

## Montrer la mise en œuvre des règles du sujet

```bash
vi /etc/sudoers.d/sudoconfig
```

[Qu'est-ce que TTY](https://www.howtogeek.com/428174/what-is-a-tty-on-linux-and-how-to-use-the-tty-command/)

## Vérifier que le dossier `/var/log/sudo/` existe et contient un fichier

```bash
sudo ls /var/log/sudo/
```

Contient le fichier `seq`.

### Vérifier le contenu des fichiers dans ce dossier

```bash
sudo ls /var/log/sudo/00/00
# exécuter une commande sudo
sudo ls /var/log/sudo/00/00/<nouveau_dossier>
```

### Vérifier qu'il y a un historique des commandes utilisant sudo

```bash
sudo cat /.../log # Journal d'entrée
sudo cat /.../ttyout # Journal de sortie
```

### Exécuter une commande en utilisant sudo et vérifier si les fichiers ont été mis à jour

```bash
sudo apt update
sudo ls /var/log/sudo/00/00 # devrait avoir un nouveau dossier
```

## Vérifier que UFW est correctement installé

```bash
dpkg -l | grep ufw
```

### Vérifier qu'il fonctionne correctement

```bash
sudo ufw status
```

### Expliquer ce qu'est UFW et la valeur de son utilisation

Uncomplicated Firewall est un programme de gestion de pare-feu netfilter conçu pour être facile à utiliser. Il utilise une interface en ligne de commande constituée d'un petit nombre de commandes simples et utilise iptables pour la configuration.

UFW vise à fournir une interface facile à utiliser pour les personnes non familières avec les concepts de pare-feu, tout en simplifiant les commandes iptables compliquées pour aider un administrateur qui sait ce qu'il fait.

[En savoir plus](https://wiki.ubuntu.com/UncomplicatedFirewall)

### Lister les règles actives devrait inclure une pour le port 4242

```bash
sudo ufw status | grep 4242
```

### Ajouter une nouvelle règle pour le port 8080

```bash
sudo ufw allow 8080
sudo ufw status
```

### Supprimer la nouvelle règle

Lister les règles numérotées

```bash
sudo ufw status numbered
```

Supprimer la règle

```bash
sudo ufw delete $NUMBER
```

## Vérifier que le service SSH est correctement installé

```bash
dpkg -l | grep openssh-server
```

### Vérifier qu'il fonctionne correctement

```bash
sudo service ssh status
```

### Expliquer ce qu'est SSH et la valeur de son utilisation

Secure Shell (SSH) est un protocole de réseau cryptographique permettant d'exploiter des services réseau de manière sécurisée sur un réseau non sécurisé. Les applications typiques incluent la ligne de commande à distance, la connexion et l'exécution de commandes à distance, mais tout service réseau peut être sécurisé avec SSH.

SSH fournit une authentification par mot de passe ou par clé publique et chiffre les connexions entre deux points de terminaison réseau. C'est une alternative sécurisée aux protocoles de connexion hérités (comme telnet, rlogin) et aux méthodes de transfert de fichiers non sécurisées (comme FTP).

[En savoir plus](https://en.wikipedia.org/wiki/Secure_Shell)

### Vérifier que le service SSH n'utilise que le port 4242

```bash
sudo service ssh status | grep listening
# ou vérifier les configurations
sudo vi /etc/ssh/sshd_config
sudo vi /etc/ssh/ssh_config
```

### Connexion avec SSH depuis la machine hôte

```bash
ssh lobenard@127.0.0.1 -p 4242 # ou
ssh lobenard@0.0.0.0 -p 4242 # ou
ssh lobenard@localhost -p 4242
```

### Assurez-vous de ne pas pouvoir vous connecter en SSH avec l'utilisateur root

```bash
lobenard@lobenard42:~$ login root
login: Impossible de fonctionner sans root effectif
```
## Qu'est-ce que `cron`

L'utilitaire en ligne de commande cron, également connu sous le nom de tâche cron, est un planificateur de tâches sur les systèmes d'exploitation de type Unix. Les utilisateurs qui configurent et maintiennent des environnements logiciels utilisent cron pour planifier des tâches (commandes ou scripts shell) à exécuter périodiquement à des heures, dates ou intervalles fixes. Il automatise généralement la maintenance ou l'administration du système – bien que sa nature polyvalente le rende utile pour des choses comme le téléchargement de fichiers depuis Internet et le téléchargement d'emails à intervalles réguliers.

[En savoir plus](https://en.wikipedia.org/wiki/Cron)

### Comment configurer le script pour qu'il s'exécute toutes les 10 minutes

```bash
sudo crontab -e
```

Ajouter la ligne suivante

```
*/10 * * * * /home/monitoring.sh
```

### Vérifier le bon fonctionnement du script

Vérifier l'affichage dans la console.

### Changer l'exécution du script à chaque minute

```bash
sudo crontab -e
```

Ajouter la ligne suivante

```
*/1 * * * * /home/monitoring.sh
```

### Faire en sorte que le script cesse de s'exécuter après le redémarrage sans le modifier

Supprimer la ligne de planification dans le crontab

```bash
sudo crontab -e
```

Supprimer la/les ligne(s) suivante(s)

```
@reboot /home/monitoring.sh
*/1 * * * * /home/monitoring.sh
```

- [x] Redémarrer le serveur
- [x] Vérifier que le script existe toujours au même endroit
- [x] Vérifier que ses droits sont restés les mêmes
- [x] Vérifier qu'il n'a pas été modifié »

Recommencer
```
