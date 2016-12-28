#ifndef QUAD_H_
#define QUAD_H_

#include "Shape.h"
#include "Vector3f.h"

/** \class Quad
 * \brief Classe héritant de #Shape, permet de définir un cube.
 * \details Le cube est défini par son centre (origine) et sa taille sous forme de vecteur 3D (cf #Vector3f).
 */
class Quad: public Shape {
public:
    /**
    * \brief Constructeur par défaut.
    * \details Créé un cube fait d'un matériel noir mat et initialise les composantes de ses vecteurs d'origine et de taille à 0.
    */
	Quad();

    /**
    * \brief Constructeur.
    * \details Crée un cube défini par l'origine, la taille et le matériel passés en argument.
    * \param  matter : Valeur initiale du matériel matter_ composant le cube.
    * \param origin : Valeur initiale du vecteur origin_.
    * \param nsize :  Valeur initiale du vecteur size_.
    */
	Quad(const Material& matter, Vector3f origin, Vector3f nsize);


	/**
    * \brief Destructeur.
    */
	~Quad();

	/**
    * \brief Accesseur pour le vecteur origin_.
    * \return Une référence constante vers la valeur du vecteur d'origine.
    */
	const Vector3f& getOrigin() const {
		return origin_;
	}

	/**
    * \brief Mutateur pour le vecteur origin_.
    * \param origin : nouvelle valeur pour le vecteur contenant l'origine origin_.
    */
	void setOrigin(const Vector3f& origin) {
		origin_ = origin;
	}

	/**
    * \brief Accesseur pour le vecteur size_.
    * \return Une référence constante vers la valeur du vecteur de taille.
    */
	const Vector3f& getSize() const {
		return size_;
	}

	/**
    * \brief Mutateur pour le vecteur size_.
    * \param nsize : nouvelle valeur pour le vecteur de taille size_.
    */
	void setSize(const Vector3f& nsize) {
		size_ = nsize;
	}

	/**
    * \brief Intersection entre le cube et un rayon.
    * \details Utilise l'algorithme de Brian Smits.
    * \param ray3f : rayon dont on teste l'intersection avec le cube
    * \param distance :
    * \param px :
    * \param py :
    * \param pz :
    * \return true si le rayon intersecte le cube sinon false
    */
	bool isHit(Ray3f ray3f, double* distance, double* px, double* py, double* pz);

private:
	Vector3f origin_; /*!< Vecteur 3D contenant l'origine du cube (centre)*/
	Vector3f size_; /*!< Vecteur 3D contenant la taille du cube */
};

#endif /* QUAD_H_ */
