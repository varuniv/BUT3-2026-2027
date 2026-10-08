
 ssh -J o22306517@acces-tp.iut45.univ-orleans.fr -o StrictHostKeyChecking=no o22306517@172.16.5.142

 mdp : 3cii74


démarrer le serveur : sudo neo4j start (puis stop)

Dans un autre terminal : 
ssh -L 7474:172.16.5.142:7474 -L 7687:172.16.5.142:7687 -N o22306517@acces-tp.iut45.univ-orleans.fr

curl http://0.0.0.0:7474


juste a mettre en url : localhost:7474
Username : neo4j
psw : neo4jpw4neo4j


ctrl+D pour sortir de la VM