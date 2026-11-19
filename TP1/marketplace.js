// 1. Sélectionner ou créer la base de données
db = db.getSiblingDB("marketplaceDB");

// 2. Créer la collection "articles"
db.createCollection("articles");

// 3. Insérer des documents dans la collection "articles"

// Document 1 : iPhone
db.articles.insertOne({
  titre: "Apple iPhone 14 Pro Max",
  description: "iPhone 14 Pro Max, 256GB, état neuf, avec accessoires d'origine.",
  prix: 1200,
  categorie: "Electronique",
  vendeur: {
    id: "user1234",
    nom: "Diego Delavega",
    note: 4.8
  },
  details: {
    etat: "Neuf",
    couleur: "Noir",
    capacite: "256GB",
    fabricant: "Apple"
  },
  livraison: {
    type: "Standard",
    prix: 10,
    options: ["Suivi", "Assurance"]
  },
  localisation: {
    pays: "France",
    ville: "Paris",
    codePostal: "75001"
  },
  dateMiseEnLigne: new Date("2023-10-20T14:48:00Z"),
  tags: ["iPhone", "smartphone", "Apple", "electronique"],
  nombreVues: 120
});

// Document 2 : Chaise de bureau
db.articles.insertOne({
  titre: "Chaise de bureau ergonomique",
  description: "Chaise de bureau ergonomique avec accoudoirs et dossier réglable, en très bon état.",
  prix: 150,
  categorie: "Mobilier",
  vendeur: {
    id: "user5678",
    nom: "Elodie Durand",
    note: 4.6
  },
  details: {
    etat: "Très bon état",
    couleur: "Gris",
    materiau: "Tissu et métal"
  },
  livraison: {
    type: "Express",
    prix: 20,
    options: ["Suivi"]
  },
  localisation: {
    pays: "France",
    ville: "Lyon",
    codePostal: "69002"
  },
  dateMiseEnLigne: new Date("2023-09-10T10:20:00Z"),
  tags: ["chaise", "bureau", "ergonomique", "mobilier"],
  nombreVues: 85
});

// Document 3 : Montre Rolex
db.articles.insertOne({
  titre: "Montre Rolex Submariner",
  description: "Montre Rolex Submariner, modèle 2021, étanche jusqu'à 300 mètres.",
  prix: 9000,
  categorie: "Luxe",
  vendeur: {
    id: "user91011",
    nom: "Pierre Durand",
    note: 5.0
  },
  details: {
    etat: "Comme neuf",
    couleur: "Argent",
    materiau: "Acier inoxydable",
    marque: "Rolex"
  },
  livraison: {
    type: "Premium",
    prix: 50,
    options: ["Suivi", "Assurance", "Signature requise"]
  },
  localisation: {
    pays: "France",
    ville: "Nice",
    codePostal: "06000"
  },
  dateMiseEnLigne: new Date("2023-08-15T16:30:00Z"),
  tags: ["montre", "Rolex", "luxe", "accessoire"],
  nombreVues: 210
});


db.articles.insertOne({
  titre: "Table de salon en bois massif",
  description: "Table de salon en chêne massif, 120x60 cm, en bon état",
  prix:200,
  categorie: "Mobilier",
  vendeur: {
    nom : "Alice Dupont", 
    note : 4.7
  },
  livraison: { 
    type : "Standard", 
    prix : 15, 
    options : ["Suivi"]
  },
  location:{
    pays : "France",
    ville : "Marseille",
    codePostal : "13001"
  }});

//Trouvez tous les articles de la catégorie "Electronique" et affichez uniquement les champstitre, prix, et vendeur.nom (en excluant l'_id)

  db.articles.find({categorie: "Electronique"}, {titre:1,  prix:1, vendeur: {nom: 1}, _id: 0 } )

// Affichez les titres et descriptions de tous les articles dont le prix est supérieur à 500 euros, sans afficher les autres champs.

db. articles.find({prix:{$gt:500 }}, {prix:1, _id:0 })

// Mettez à jour le prix de l'article "Montre Rolex Submariner" pour le définir à 9500 euros

db.articles.update({titre: "Montre Rolex Submariner"}, {$set: {prix: 9500}})

// Ajoutez un champ etatLivraison avec la valeur "En stock" à tous les articles dont la ville est "Paris"

db.articles.updateMany({"localisation.ville":"Paris"}, {$set: {etatLivraison: "En stock"}})

// Incrémentez le champ nombreVues de tous les articles dans la catégorie "Luxe" de 50 vues supplémentaires

db.articles.updateMany({"categorie":"Luxe"},{ $inc: {nombreVues: 50} })

// Supprimez l'article "Chaise de bureau ergonomique" de la collection

db.articles.deleteOne({"titre": "Chaise de bureau ergonomique"})

// Supprimez tous les articles dont le prix est inférieur à 100 euros.

db.articles.deleteMany({prix: {$lt: 100}})

// Créez et insérez maintenant une collection « vendeurs » correspondant à ces petites annonces.

db.createCollection("vendeurs");

var papline = [
  {$match : {$exists: {vendeur: true}}},
  {$merge: { into: "vendeurs", on: "_id", whenMatched: "merge",whenNotMatched: "insert" } }
]

db.articles.aggregate(papline)