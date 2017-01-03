#ifndef SRC_IMAGE_H_
#define SRC_IMAGE_H_

#include <iostream>

#include "Pixel.h"

/** \class Image
 * \brief Classe permettant de définir une image.
 * \details L'image est définie par sa hauteur, sa largeur et les pixels la composant.
 */
class Image {
public:
    /**
    * \brief Constructeur par défaut.
    * \details Créé une image de largeur 20 pixels, de hauteur 15 pixels et contenant donc 300 pixels.
    * Les pixels sont de couleur blanche (3 niveaux de couleurs initialisés à 255).
    */
	Image();

    /**
    * \brief Constructeur.
    * \details Créé une image définie par la hauteur et la largeur passées en argument.
    * Le tableau de pixels correspondant est créé et rempli de pixels de couleur blanche (255,255,255).
    * \exception std::runtime_error si la largeur ou la hauteur est inférieure à 1.
    * \param width Valeur initiale de la largeur de l'image width_.
    * \param height  Valeur initiale de la hauteur de l'image height_.
    */
	Image(int width, int height);

	/**
    * \brief Constructeur de copie.
    * \param image Référence vers l'image à copier.
    */
	Image(const Image & image);

	/**
    * \brief Destructeur.
    * \details Libère la mémoire allouée au tableau de Pixel pixels_.
    */
	~Image();

	/**
    * \brief Accesseur pour la hauteur de l'image height_.
    * \return Un \e entier contenant la hauteur de l'image height_.
    */
	int getHeight() const {
		return height_;
	}

    /**
    * \brief Mutateur pour la hauteur de l'image height_.
    * \param height nouvelle valeur pour la hauteur de l'image height_.
    */
	void setHeight(int height) {
		height_ = height;
	}

    /**
    * \brief Modifier un Pixel de l'image.
    * \details Permet de remplacer un pixel de l'image à partir de ses coordonnées 2D (x,y) et en précisant le pixel de remplacement.
    * \param x abscisse du Pixel à remplacer.
    * \param y ordonnée du Pixel à remplacer.
    * \param pixel : Pixel de remplacement.
    */
	void setOnePixel (int x, int y, Pixel pixel) {
	    //On calcule l'emplacement du pixel dans le tableau à une dimension à partir de x et y
	    pixels_[width_*y+x] = pixel;
	}

	/**
    * \brief Sélectionner un Pixel de l'image (2D).
    * \details Permet d'obtenir un Pixel de l'image à partir de ses coordonnées 2D (x, y).
    * \param x abscisse du Pixel sélectionné.
    * \param y ordonnée du Pixel sélectionné.
    * \return Le Pixel de l'image correspandant aux coordonnées passées en argument.
    */
	Pixel getOnePixel (int x, int y) {
		return pixels_[width_*y+x];
	}

	/**
    * \brief Sélectionner un Pixel de l'image (1D).
    * \details Permet d'obtenir un Pixel de l'image à partir de son indice de placement dans le tableau pixels_.
    * \param i indice de placement du Pixel dans le tableau de Pixel pixels_.
    * \return Le Pixel de l'image correspandant à l'indice passé en argument.
    */
	Pixel getOnePixel (int i) const {
		return pixels_[i];
	}

	/**
    * \brief Accesseur pour la largeur de l'image width_.
    * \return Un \e entier contenant la largeur de l'image width_.
    */
	int getWidth() const {
		return width_;
	}

    /**
    * \brief Mutateur pour la largeur de l'image width_.
    * \param width nouvelle valeur pour la largeur de l'image width_.
    */
	void setWidth(int width) {
		width_ = width;
	}

	/**
    * \brief Accesseur pour le tableau de Pixel pixels_.
    * \return Une référence vers un tableau de Pixel avec le contenu de pixels_.
    */
	Pixel*& getPixels() {
		return pixels_;
	}

	/**
    * \brief Opérateur d'affectation.
    * \param image Une référence constante vers l'Image que l'on souhaite copier.
    */
	Image & operator=(const Image & image);

	/**
    * \brief Opérateur de flux pour l'affichage.
    * \details Méthode amie permettant d'afficher l'ensemble des pixels de l'image sous le format [r,v,b] séparés par une virgule.
    * Un retour à la ligne est effectué après que width_ pixels ont été affichés.
    * \param st Une référence vers le flux où l'on souhaite afficher l'image.
    * \param image Une référence constante vers l'image à afficher.
    * \return Une référence vers un flux std::ostream contenant l'affichage de l'image.
    */
	friend std::ostream & operator << (std::ostream & st, const Image & image);

public:
	int width_; /*!< Entier représentant la largeur de l'image*/
	int height_; /*!< Entier représentant la hauteur de l'image*/
	Pixel* pixels_; /*!< Tableau contenant les pixels de l'image*/
};

#endif /* SRC_IMAGE_H_ */
